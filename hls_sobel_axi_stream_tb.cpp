/* Manual bugfixes in Vitis Library 2020.1 (TAG : v2020.1_update1)
 * 	When using AXI Stream interfaces the compiler is not implementing the interface parameters correctly.
 * 	To workaround, use the "hls::stream" and "ap_axiu" templates from <ap_axi_sdata.h> instead of
 * 	"xf_axi_sdata.hpp". Replace this include in the following files:
 * 	  "common/xf_infra.hpp"
 * 	  "common/xf_axi.hpp"
 * 	See also https://github.com/Xilinx/Vitis_Libraries/issues/28 for detailed description
 */

#include "hls_sobel_axi_stream.hpp"
#include "common/xf_headers.hpp"
#include "common/xf_axi.hpp"

using namespace std;

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Invalid Number of Arguments!\nUsage: <executable> <image>\n");
        return -1;
    }

    cv::Mat img, diff;
    img = cv::imread(argv[1], 1);
    if (img.data == NULL) {
        fprintf(stderr, "Cannot open image at %s\n", argv[1]);
        return 0;
    }

    int rows = img.rows;
    int cols = img.cols;
    cv::Mat out_img(rows, cols, CV_8UC3);

    // convert input to axiStream
    hls::stream<ap_axiu<AXIS_W, 1, 1, 1> > _src;
    xf::cv::cvMat2AXIvideoxf<XF_NPPC1, AXIS_W>(img, _src);

    // output axiStream
    hls::stream<ap_axiu<AXIS_W, 1, 1, 1> > _dst;

    // Launch the kernel
    hls_sobel_axi_stream_top(_src, _dst, rows, cols);

    xf::cv::AXIvideo2cvMatxf<XF_NPPC1>(_dst, out_img);

    // Write output image
    cv::imwrite("output.png", out_img);

    return 0;
}
