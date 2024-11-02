#ifndef _MIPI_TX_PARAM_DUMMY_H_
#define _MIPI_TX_PARAM_DUMMY_H_

#ifndef __UBOOT__
#include <linux/vo_mipi_tx.h>
#include <linux/cvi_comm_mipi_tx.h>
#else
#include <cvi_mipi.h>
#endif

#define DUMMY_VACT  1080
#define DUMMY_VSA   5
#define DUMMY_VBP   23
#define DUMMY_VFP   3

#define DUMMY_HACT  1920
#define DUMMY_HSA   32
#define DUMMY_HBP   80
#define DUMMY_HFP   48

#define DUMMY_PIXEL_CLK(x) ((x##_VACT + x##_VSA + x##_VBP + x##_VFP) \
        * (x##_HACT + x##_HSA + x##_HBP + x##_HFP) * 60 / 1000)

struct combo_dev_cfg_s dev_cfg_dummy_1920x1080 = {
        .devno = 0,
        .lane_id = {MIPI_TX_LANE_0, MIPI_TX_LANE_CLK, MIPI_TX_LANE_1, -1, -1},
        .lane_pn_swap = {false, false, false, false, false},
        .output_mode = OUTPUT_MODE_DSI_VIDEO,
        .video_mode = BURST_MODE,
        .output_format = OUT_FORMAT_RGB_24_BIT,
        .sync_info = {
                .vid_hsa_pixels = DUMMY_HSA,
                .vid_hbp_pixels = DUMMY_HBP,
                .vid_hfp_pixels = DUMMY_HFP,
                .vid_hline_pixels = DUMMY_HACT,
                .vid_vsa_lines = DUMMY_VSA,
                .vid_vbp_lines = DUMMY_VBP,
                .vid_vfp_lines = DUMMY_VFP,
                .vid_active_lines = DUMMY_VACT,
                .vid_vsa_pos_polarity = false,
                .vid_hsa_pos_polarity = true,
        },
        .pixel_clk = DUMMY_PIXEL_CLK(DUMMY),
};

const struct hs_settle_s hs_timing_cfg_dummy_1920x1080 = { .prepare = 6, .zero = 32, .trail = 1 };

#else
#error "MIPI_TX_PARAM multi-delcaration!!"
#endif // _MIPI_TX_PARAM_DUMMY_H_
