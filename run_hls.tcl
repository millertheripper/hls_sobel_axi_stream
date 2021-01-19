# ------------------------------------------------------------------------------
# Vitis Vision and OpenCV Libary Path Information
# ------------------------------------------------------------------------------
set XF_PROJ_ROOT [lindex $argv 1]
set OPENCV_INCLUDE "/usr/local/include"
set OPENCV_LIB "/usr/local/lib"

# ------------------------------------------------------------------------------
# Vitis HLS Project Information
# ------------------------------------------------------------------------------
set PROJ_DIR [lindex $argv 0]
set SOURCE_DIR "$PROJ_DIR/"
set PROJ_NAME [lindex $argv 2]
set PROJ_TOP "${PROJ_NAME}_top"
set SOLUTION_NAME "solution_1"
set SOLUTION_PART "xc7z020clg400-1"
set SOLUTION_CLKP 8
set INPUT_IMAGE_FILE_SIM [lindex $argv 3]

# ------------------------------------------------------------------------------
# OpenCV C Simulation / CoSimulation Library References
#------------------------------------------------------------------------------
set VISION_INC_FLAGS "-I$XF_PROJ_ROOT/L1/include -std=c++0x"
set OPENCV_INC_FLAGS "-I$OPENCV_INCLUDE"
set OPENCV_LIB_FLAGS "-L $OPENCV_LIB"

# Windows OpenCV Include Style:
#set OPENCV_LIB_REF   "-lopencv_imgcodecs3411 -lopencv_imgproc3411 -lopencv_core3411 -lopencv_highgui3411 -lopencv_flann3411 -lopencv_features2d3411"

# Linux OpenCV Include Style:
set OPENCV_LIB_REF   "-lopencv_imgcodecs -lopencv_imgproc -lopencv_core -lopencv_highgui -lopencv_flann -lopencv_features2d"

# ------------------------------------------------------------------------------
# Create Project
# ------------------------------------------------------------------------------
open_project -reset $PROJ_NAME

# ------------------------------------------------------------------------------
# Add C++ source and Testbench files with Vision and OpenCV includes
# ------------------------------------------------------------------------------
add_files "${PROJ_DIR}/${PROJ_NAME}.cpp" -cflags "${VISION_INC_FLAGS}" -csimflags "${VISION_INC_FLAGS}"
add_files "${PROJ_DIR}/${PROJ_NAME}.hpp" -cflags "${VISION_INC_FLAGS}" -csimflags "${VISION_INC_FLAGS}"
add_files -tb "${PROJ_DIR}/${PROJ_NAME}_tb.cpp" -cflags "${OPENCV_INC_FLAGS} ${VISION_INC_FLAGS}" -csimflags "${OPENCV_INC_FLAGS} ${VISION_INC_FLAGS}"

# ------------------------------------------------------------------------------
# Create Project and Solution
# ------------------------------------------------------------------------------
set_top $PROJ_TOP
open_solution -reset $SOLUTION_NAME
set_part $SOLUTION_PART
create_clock -period $SOLUTION_CLKP

# ------------------------------------------------------------------------------
# Run Vitis HLS Stages
# Note: CSim and CoSim require datafiles to be included 
# ------------------------------------------------------------------------------
csim_design -ldflags "-L ${OPENCV_LIB} ${OPENCV_LIB_REF}" -argv "${PROJ_DIR}/${INPUT_IMAGE_FILE_SIM}"
csynth_design
#cosim_design -ldflags "-L ${OPENCV_LIB} ${OPENCV_LIB_REF}" -argv "${PROJ_DIR}/${INPUT_IMAGE_FILE_SIM}"
export_design -flow syn -rtl verilog
export_design -flow impl -rtl verilog