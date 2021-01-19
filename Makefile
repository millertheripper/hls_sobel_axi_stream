SHELL := /bin/bash
WORK_DIR := $(shell pwd)
VIVADO := source /opt/Xilinx/Vivado/2020.1/settings64.sh
VITIS_HLS := vitis_hls

# Set this to match your vitis video library path
XF_PROJ_ROOT := ~/git/xilinx/Vitis_Libraries/vision

# Set input image for test bench simulation
INPUT_IMAGE_FILE_SIM := test_image_128x128.png
#INPUT_IMAGE_FILE_SIM := test_image_1920x1080.bmp

# Set project name to match cpp file names
PROJECT_NAME := hls_sobel_axi_stream

.PHONY: all
all: clean hls export_ip

.PHONY: clean
clean: 
	@rm -rf $(PROJECT_NAME) *.str *.log *.jou .Xil output*.png export

.PHONY: hls
hls:
	$(VIVADO) && $(VITIS_HLS) run_hls.tcl $(WORK_DIR) $(XF_PROJ_ROOT) $(PROJECT_NAME) $(INPUT_IMAGE_FILE_SIM)
	@echo ""
	@echo "Finished building HLS project: $(PROJECT_NAME)"
	@cp -f $(WORK_DIR)/$(PROJECT_NAME)/solution_1/csim/build/output.png output_csim.png
	#@cp -f $(WORK_DIR)/$(PROJECT_NAME)/solution_1/sim/wrapc/output.png output_sim.png
	@echo "CSIM output image copied to: $(WORK_DIR)/output_csim.png"
	#@echo "SIM  output image copied to: $(WORK_DIR)/output_sim.png"


.PHONY: export_ip
export_ip:
	@rm -Rf export && mkdir export
	@cp -f $(WORK_DIR)/$(PROJECT_NAME)/solution_1/impl/export.zip .
	@unzip export.zip -d export && rm export.zip
	@rm -Rf $(WORK_DIR)/$(PROJECT_NAME)/solution_1/impl/ip
	@echo "Exported IP to $(WORK_DIR)/export"

	
