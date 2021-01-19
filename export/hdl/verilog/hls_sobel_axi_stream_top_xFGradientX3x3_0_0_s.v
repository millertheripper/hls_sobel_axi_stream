// ==============================================================
// RTL generated by Vitis HLS - High-Level Synthesis from C, C++ and OpenCL
// Version: 2020.1
// Copyright (C) 1986-2020 Xilinx, Inc. All Rights Reserved.
// 
// ===========================================================

`timescale 1 ns / 1 ps 

module hls_sobel_axi_stream_top_xFGradientX3x3_0_0_s (
        ap_clk,
        ap_rst,
        t0,
        t2,
        m0,
        m2,
        b0,
        b2,
        ap_return,
        ap_ce
);


input   ap_clk;
input   ap_rst;
input  [7:0] t0;
input  [7:0] t2;
input  [7:0] m0;
input  [7:0] m2;
input  [7:0] b0;
input  [7:0] b2;
output  [7:0] ap_return;
input   ap_ce;

reg[7:0] ap_return;

wire   [10:0] out_pix_fu_146_p2;
reg   [10:0] out_pix_reg_204;
wire    ap_block_state1_pp0_stage0_iter0;
wire    ap_block_state2_pp0_stage0_iter1;
wire    ap_block_pp0_stage0_11001;
reg   [0:0] tmp_reg_209;
reg   [2:0] tmp_2_reg_215;
wire    ap_block_pp0_stage0;
wire   [8:0] M00_fu_70_p3;
wire   [8:0] M01_fu_82_p3;
wire   [8:0] zext_ln215_fu_94_p1;
wire   [8:0] zext_ln215_4_fu_98_p1;
wire   [8:0] ret_V_fu_102_p2;
wire   [8:0] zext_ln215_5_fu_112_p1;
wire   [8:0] zext_ln215_6_fu_116_p1;
wire   [8:0] ret_V_2_fu_120_p2;
wire   [9:0] zext_ln60_fu_90_p1;
wire   [9:0] zext_ln59_fu_78_p1;
wire   [9:0] out_pix_7_fu_130_p2;
wire   [10:0] zext_ln61_fu_108_p1;
wire  signed [10:0] sext_ln66_fu_136_p1;
wire   [10:0] out_pix_8_fu_140_p2;
wire   [10:0] zext_ln62_fu_126_p1;
wire   [0:0] xor_ln72_fu_178_p2;
wire   [0:0] icmp_ln74_fu_173_p2;
wire   [0:0] or_ln72_fu_191_p2;
wire   [7:0] select_ln72_fu_183_p3;
wire   [7:0] trunc_ln302_fu_170_p1;
wire   [7:0] select_ln72_1_fu_196_p3;
reg    ap_ce_reg;
reg   [7:0] ap_return_int_reg;

always @ (posedge ap_clk) begin
    ap_ce_reg <= ap_ce;
end

always @ (posedge ap_clk) begin
    if ((1'b1 == ap_ce_reg)) begin
        ap_return_int_reg <= select_ln72_1_fu_196_p3;
    end
end

always @ (posedge ap_clk) begin
    if (((1'b0 == ap_block_pp0_stage0_11001) & (1'b1 == 1'b1))) begin
        out_pix_reg_204 <= out_pix_fu_146_p2;
        tmp_2_reg_215 <= {{out_pix_fu_146_p2[10:8]}};
        tmp_reg_209 <= out_pix_fu_146_p2[32'd10];
    end
end

always @ (*) begin
    if ((1'b0 == ap_ce_reg)) begin
        ap_return = ap_return_int_reg;
    end else if ((1'b1 == ap_ce_reg)) begin
        ap_return = select_ln72_1_fu_196_p3;
    end
end

assign M00_fu_70_p3 = {{m0}, {1'd0}};

assign M01_fu_82_p3 = {{m2}, {1'd0}};

assign ap_block_pp0_stage0 = ~(1'b1 == 1'b1);

assign ap_block_pp0_stage0_11001 = ~(1'b1 == 1'b1);

assign ap_block_state1_pp0_stage0_iter0 = ~(1'b1 == 1'b1);

assign ap_block_state2_pp0_stage0_iter1 = ~(1'b1 == 1'b1);

assign icmp_ln74_fu_173_p2 = (($signed(tmp_2_reg_215) > $signed(3'd0)) ? 1'b1 : 1'b0);

assign or_ln72_fu_191_p2 = (tmp_reg_209 | icmp_ln74_fu_173_p2);

assign out_pix_7_fu_130_p2 = (zext_ln60_fu_90_p1 - zext_ln59_fu_78_p1);

assign out_pix_8_fu_140_p2 = ($signed(zext_ln61_fu_108_p1) + $signed(sext_ln66_fu_136_p1));

assign out_pix_fu_146_p2 = (out_pix_8_fu_140_p2 - zext_ln62_fu_126_p1);

assign ret_V_2_fu_120_p2 = (zext_ln215_5_fu_112_p1 + zext_ln215_6_fu_116_p1);

assign ret_V_fu_102_p2 = (zext_ln215_fu_94_p1 + zext_ln215_4_fu_98_p1);

assign select_ln72_1_fu_196_p3 = ((or_ln72_fu_191_p2[0:0] === 1'b1) ? select_ln72_fu_183_p3 : trunc_ln302_fu_170_p1);

assign select_ln72_fu_183_p3 = ((xor_ln72_fu_178_p2[0:0] === 1'b1) ? 8'd255 : 8'd0);

assign sext_ln66_fu_136_p1 = $signed(out_pix_7_fu_130_p2);

assign trunc_ln302_fu_170_p1 = out_pix_reg_204[7:0];

assign xor_ln72_fu_178_p2 = (tmp_reg_209 ^ 1'd1);

assign zext_ln215_4_fu_98_p1 = b2;

assign zext_ln215_5_fu_112_p1 = t0;

assign zext_ln215_6_fu_116_p1 = b0;

assign zext_ln215_fu_94_p1 = t2;

assign zext_ln59_fu_78_p1 = M00_fu_70_p3;

assign zext_ln60_fu_90_p1 = M01_fu_82_p3;

assign zext_ln61_fu_108_p1 = ret_V_fu_102_p2;

assign zext_ln62_fu_126_p1 = ret_V_2_fu_120_p2;

endmodule //hls_sobel_axi_stream_top_xFGradientX3x3_0_0_s
