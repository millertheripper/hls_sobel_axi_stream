// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xhls_sobel_axi_stream_top.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XHls_sobel_axi_stream_top_CfgInitialize(XHls_sobel_axi_stream_top *InstancePtr, XHls_sobel_axi_stream_top_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Control_BaseAddress = ConfigPtr->Control_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XHls_sobel_axi_stream_top_Start(XHls_sobel_axi_stream_top *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHls_sobel_axi_stream_top_ReadReg(InstancePtr->Control_BaseAddress, XHLS_SOBEL_AXI_STREAM_TOP_CONTROL_ADDR_AP_CTRL) & 0x80;
    XHls_sobel_axi_stream_top_WriteReg(InstancePtr->Control_BaseAddress, XHLS_SOBEL_AXI_STREAM_TOP_CONTROL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XHls_sobel_axi_stream_top_IsDone(XHls_sobel_axi_stream_top *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHls_sobel_axi_stream_top_ReadReg(InstancePtr->Control_BaseAddress, XHLS_SOBEL_AXI_STREAM_TOP_CONTROL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XHls_sobel_axi_stream_top_IsIdle(XHls_sobel_axi_stream_top *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHls_sobel_axi_stream_top_ReadReg(InstancePtr->Control_BaseAddress, XHLS_SOBEL_AXI_STREAM_TOP_CONTROL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XHls_sobel_axi_stream_top_IsReady(XHls_sobel_axi_stream_top *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHls_sobel_axi_stream_top_ReadReg(InstancePtr->Control_BaseAddress, XHLS_SOBEL_AXI_STREAM_TOP_CONTROL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XHls_sobel_axi_stream_top_EnableAutoRestart(XHls_sobel_axi_stream_top *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHls_sobel_axi_stream_top_WriteReg(InstancePtr->Control_BaseAddress, XHLS_SOBEL_AXI_STREAM_TOP_CONTROL_ADDR_AP_CTRL, 0x80);
}

void XHls_sobel_axi_stream_top_DisableAutoRestart(XHls_sobel_axi_stream_top *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHls_sobel_axi_stream_top_WriteReg(InstancePtr->Control_BaseAddress, XHLS_SOBEL_AXI_STREAM_TOP_CONTROL_ADDR_AP_CTRL, 0);
}

void XHls_sobel_axi_stream_top_Set_rows(XHls_sobel_axi_stream_top *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHls_sobel_axi_stream_top_WriteReg(InstancePtr->Control_BaseAddress, XHLS_SOBEL_AXI_STREAM_TOP_CONTROL_ADDR_ROWS_DATA, Data);
}

u32 XHls_sobel_axi_stream_top_Get_rows(XHls_sobel_axi_stream_top *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHls_sobel_axi_stream_top_ReadReg(InstancePtr->Control_BaseAddress, XHLS_SOBEL_AXI_STREAM_TOP_CONTROL_ADDR_ROWS_DATA);
    return Data;
}

void XHls_sobel_axi_stream_top_Set_cols(XHls_sobel_axi_stream_top *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHls_sobel_axi_stream_top_WriteReg(InstancePtr->Control_BaseAddress, XHLS_SOBEL_AXI_STREAM_TOP_CONTROL_ADDR_COLS_DATA, Data);
}

u32 XHls_sobel_axi_stream_top_Get_cols(XHls_sobel_axi_stream_top *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XHls_sobel_axi_stream_top_ReadReg(InstancePtr->Control_BaseAddress, XHLS_SOBEL_AXI_STREAM_TOP_CONTROL_ADDR_COLS_DATA);
    return Data;
}

void XHls_sobel_axi_stream_top_InterruptGlobalEnable(XHls_sobel_axi_stream_top *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHls_sobel_axi_stream_top_WriteReg(InstancePtr->Control_BaseAddress, XHLS_SOBEL_AXI_STREAM_TOP_CONTROL_ADDR_GIE, 1);
}

void XHls_sobel_axi_stream_top_InterruptGlobalDisable(XHls_sobel_axi_stream_top *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHls_sobel_axi_stream_top_WriteReg(InstancePtr->Control_BaseAddress, XHLS_SOBEL_AXI_STREAM_TOP_CONTROL_ADDR_GIE, 0);
}

void XHls_sobel_axi_stream_top_InterruptEnable(XHls_sobel_axi_stream_top *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XHls_sobel_axi_stream_top_ReadReg(InstancePtr->Control_BaseAddress, XHLS_SOBEL_AXI_STREAM_TOP_CONTROL_ADDR_IER);
    XHls_sobel_axi_stream_top_WriteReg(InstancePtr->Control_BaseAddress, XHLS_SOBEL_AXI_STREAM_TOP_CONTROL_ADDR_IER, Register | Mask);
}

void XHls_sobel_axi_stream_top_InterruptDisable(XHls_sobel_axi_stream_top *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XHls_sobel_axi_stream_top_ReadReg(InstancePtr->Control_BaseAddress, XHLS_SOBEL_AXI_STREAM_TOP_CONTROL_ADDR_IER);
    XHls_sobel_axi_stream_top_WriteReg(InstancePtr->Control_BaseAddress, XHLS_SOBEL_AXI_STREAM_TOP_CONTROL_ADDR_IER, Register & (~Mask));
}

void XHls_sobel_axi_stream_top_InterruptClear(XHls_sobel_axi_stream_top *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XHls_sobel_axi_stream_top_WriteReg(InstancePtr->Control_BaseAddress, XHLS_SOBEL_AXI_STREAM_TOP_CONTROL_ADDR_ISR, Mask);
}

u32 XHls_sobel_axi_stream_top_InterruptGetEnabled(XHls_sobel_axi_stream_top *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XHls_sobel_axi_stream_top_ReadReg(InstancePtr->Control_BaseAddress, XHLS_SOBEL_AXI_STREAM_TOP_CONTROL_ADDR_IER);
}

u32 XHls_sobel_axi_stream_top_InterruptGetStatus(XHls_sobel_axi_stream_top *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XHls_sobel_axi_stream_top_ReadReg(InstancePtr->Control_BaseAddress, XHLS_SOBEL_AXI_STREAM_TOP_CONTROL_ADDR_ISR);
}

