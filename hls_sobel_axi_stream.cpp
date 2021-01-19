/* Manual bugfixes in Vitis Library 2020.1 (TAG : v2020.1_update1)
 * 	When using AXI Stream interfaces the compiler is not implementing the interface parameters correctly.
 * 	To workaround, use the "hls::stream" and "ap_axiu" templates from <ap_axi_sdata.h> instead of
 * 	"xf_axi_sdata.hpp". Replace this include in the following files:
 * 	  "common/xf_infra.hpp"
 * 	  "common/xf_axi.hpp"
 * 	See also https://github.com/Xilinx/Vitis_Libraries/issues/28 for detailed description
 */

#include "hls_sobel_axi_stream.hpp"
#include "imgproc/xf_sobel.hpp"
#include "imgproc/xf_cvt_color.hpp"
#include "imgproc/xf_add_weighted.hpp"

void hls_sobel_axi_stream_top(hls::stream<ap_axiu<AXIS_W,1,1,1> >& _src,
                   hls::stream<ap_axiu<AXIS_W,1,1,1> >& _dst,
                   int rows,
                   int cols) {

    #pragma HLS INTERFACE axis port=_src
    #pragma HLS INTERFACE axis port=_dst 
    #pragma HLS INTERFACE s_axilite port=rows     bundle=control
    #pragma HLS INTERFACE s_axilite port=cols     bundle=control
    #pragma HLS INTERFACE s_axilite port=return   bundle=control

    xf::cv::Mat<XF_8UC3, XF_HEIGHT, XF_WIDTH, XF_NPPC1> img_buf_0(rows, cols);
    xf::cv::Mat<XF_8UC1, XF_HEIGHT, XF_WIDTH, XF_NPPC1> img_buf_1(rows, cols);
    xf::cv::Mat<XF_8UC1, XF_HEIGHT, XF_WIDTH, XF_NPPC1> img_buf_1a(rows, cols);
    xf::cv::Mat<XF_8UC1, XF_HEIGHT, XF_WIDTH, XF_NPPC1> img_buf_1b(rows, cols);
    xf::cv::Mat<XF_8UC1, XF_HEIGHT, XF_WIDTH, XF_NPPC1> img_buf_2(rows, cols);
    xf::cv::Mat<XF_8UC3, XF_HEIGHT, XF_WIDTH, XF_NPPC1> img_buf_3(rows, cols);

    #pragma HLS dataflow

    xf::cv::AXIvideo2xfMat(_src, img_buf_0);
    xf::cv::bgr2gray<XF_8UC3, XF_8UC1, XF_HEIGHT, XF_WIDTH, XF_NPPC1>(img_buf_0, img_buf_1);
    xf::cv::Sobel<0, 3, XF_8UC1, XF_8UC1, XF_HEIGHT, XF_WIDTH, XF_NPPC1, false>(img_buf_1, img_buf_1a, img_buf_1b);
    xf::cv::addWeighted<XF_8UC1, XF_8UC1, XF_HEIGHT, XF_WIDTH, XF_NPPC1>(img_buf_1a, 0.5, img_buf_1b, 0.5, 0, img_buf_2);
    xf::cv::gray2bgr<XF_8UC1, XF_8UC3, XF_HEIGHT, XF_WIDTH, XF_NPPC1>(img_buf_2, img_buf_3);
    xf::cv::xfMat2AXIvideo(img_buf_3, _dst);

    return;
}
