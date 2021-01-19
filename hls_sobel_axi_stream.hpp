#include "hls_stream.h"
#include "common/xf_common.hpp"
#include "common/xf_utility.hpp"
#include "common/xf_infra.hpp"


/* config width and height */
#define XF_HEIGHT   1080
#define XF_WIDTH    1920
#define AXIS_W      24

void hls_sobel_axi_stream_top(hls::stream<ap_axiu<AXIS_W,1,1,1> >& _src,
                   hls::stream<ap_axiu<AXIS_W,1,1,1> >& _dst,
                   int rows,
                   int cols);
