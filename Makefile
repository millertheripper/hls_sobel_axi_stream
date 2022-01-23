SHELL := /bin/bash
WORK_DIR := $(shell pwd)
VIVADO := source /opt/Xilinx/Vivado/2020.2/settings64.sh
VITIS_HLS := vitis_hls

# Set this to match your vitis video library path
XF_PROJ_ROOT := ~/git/xilinx/Vitis_Libraries/vision

# Set input image for test bench simulation
INPUT_IMAGE_FILE := test_image_128x128.png
#INPUT_IMAGE_FILE := test_image_1920x1080.bmp

# Set project name to match cpp file names
PROJECT_NAME := hls_sobel_axi_stream

SRC_FILES := \
	$(PROJECT_NAME).cpp \
	$(PROJECT_NAME).hpp \
	$(PROJECT_NAME)_tb.cpp \
	$(INPUT_IMAGE_FILE)

CSIM := $(PROJECT_NAME)/solution_1/csim
CSYNTH := $(PROJECT_NAME)/solution_1/syn

.PHONY: all
all: export_ip

.PHONY: clean
clean: 
	@rm -rf $(PROJECT_NAME) *.str *.log *.jou .Xil output*.png export_ip

$(PROJECT_NAME): 
	$(VIVADO) && $(VITIS_HLS) run_hls.tcl $(WORK_DIR) $(XF_PROJ_ROOT) $(PROJECT_NAME) $(INPUT_IMAGE_FILE) "create"

$(CSIM): $(PROJECT_NAME) $(SRC_FILES)
	@rm -f output*
	@$(VIVADO) && $(VITIS_HLS) run_hls.tcl $(WORK_DIR) $(XF_PROJ_ROOT) $(PROJECT_NAME) $(INPUT_IMAGE_FILE) "csim"
	@cp ./$(PROJECT_NAME)/solution_1/csim/build/output.* ./output_csim.png
	@echo "CSIM output image copied to: $(WORK_DIR)/output_csim.png"

$(CSYNTH): $(PROJECT_NAME) $(CSIM)
	$(VIVADO) && $(VITIS_HLS) run_hls.tcl $(WORK_DIR) $(XF_PROJ_ROOT) $(PROJECT_NAME) $(INPUT_IMAGE_FILE) "csynth"

export_ip: $(CSYNTH) $(PROJECT_NAME)
	$(VIVADO) && $(VITIS_HLS) run_hls.tcl $(WORK_DIR) $(XF_PROJ_ROOT) $(PROJECT_NAME) $(INPUT_IMAGE_FILE) "export"
	@rm -Rf $@ && mkdir $@
	@cp -f ./$(PROJECT_NAME)/solution_1/impl/export.zip .
	@unzip export.zip -d $(@) && rm export.zip
	@rm -Rf ./$(PROJECT_NAME)/solution_1/impl/ip

.PHONY: csim
csim : $(CSIM)