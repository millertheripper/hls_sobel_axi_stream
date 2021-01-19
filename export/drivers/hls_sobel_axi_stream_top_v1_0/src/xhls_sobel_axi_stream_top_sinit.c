// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xhls_sobel_axi_stream_top.h"

extern XHls_sobel_axi_stream_top_Config XHls_sobel_axi_stream_top_ConfigTable[];

XHls_sobel_axi_stream_top_Config *XHls_sobel_axi_stream_top_LookupConfig(u16 DeviceId) {
	XHls_sobel_axi_stream_top_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XHLS_SOBEL_AXI_STREAM_TOP_NUM_INSTANCES; Index++) {
		if (XHls_sobel_axi_stream_top_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XHls_sobel_axi_stream_top_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XHls_sobel_axi_stream_top_Initialize(XHls_sobel_axi_stream_top *InstancePtr, u16 DeviceId) {
	XHls_sobel_axi_stream_top_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XHls_sobel_axi_stream_top_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XHls_sobel_axi_stream_top_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

