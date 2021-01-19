// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2020.1 (64-bit)
// Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef XHLS_SOBEL_AXI_STREAM_TOP_H
#define XHLS_SOBEL_AXI_STREAM_TOP_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xhls_sobel_axi_stream_top_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
    u16 DeviceId;
    u32 Control_BaseAddress;
} XHls_sobel_axi_stream_top_Config;
#endif

typedef struct {
    u32 Control_BaseAddress;
    u32 IsReady;
} XHls_sobel_axi_stream_top;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XHls_sobel_axi_stream_top_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XHls_sobel_axi_stream_top_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XHls_sobel_axi_stream_top_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XHls_sobel_axi_stream_top_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
int XHls_sobel_axi_stream_top_Initialize(XHls_sobel_axi_stream_top *InstancePtr, u16 DeviceId);
XHls_sobel_axi_stream_top_Config* XHls_sobel_axi_stream_top_LookupConfig(u16 DeviceId);
int XHls_sobel_axi_stream_top_CfgInitialize(XHls_sobel_axi_stream_top *InstancePtr, XHls_sobel_axi_stream_top_Config *ConfigPtr);
#else
int XHls_sobel_axi_stream_top_Initialize(XHls_sobel_axi_stream_top *InstancePtr, const char* InstanceName);
int XHls_sobel_axi_stream_top_Release(XHls_sobel_axi_stream_top *InstancePtr);
#endif

void XHls_sobel_axi_stream_top_Start(XHls_sobel_axi_stream_top *InstancePtr);
u32 XHls_sobel_axi_stream_top_IsDone(XHls_sobel_axi_stream_top *InstancePtr);
u32 XHls_sobel_axi_stream_top_IsIdle(XHls_sobel_axi_stream_top *InstancePtr);
u32 XHls_sobel_axi_stream_top_IsReady(XHls_sobel_axi_stream_top *InstancePtr);
void XHls_sobel_axi_stream_top_EnableAutoRestart(XHls_sobel_axi_stream_top *InstancePtr);
void XHls_sobel_axi_stream_top_DisableAutoRestart(XHls_sobel_axi_stream_top *InstancePtr);

void XHls_sobel_axi_stream_top_Set_rows(XHls_sobel_axi_stream_top *InstancePtr, u32 Data);
u32 XHls_sobel_axi_stream_top_Get_rows(XHls_sobel_axi_stream_top *InstancePtr);
void XHls_sobel_axi_stream_top_Set_cols(XHls_sobel_axi_stream_top *InstancePtr, u32 Data);
u32 XHls_sobel_axi_stream_top_Get_cols(XHls_sobel_axi_stream_top *InstancePtr);

void XHls_sobel_axi_stream_top_InterruptGlobalEnable(XHls_sobel_axi_stream_top *InstancePtr);
void XHls_sobel_axi_stream_top_InterruptGlobalDisable(XHls_sobel_axi_stream_top *InstancePtr);
void XHls_sobel_axi_stream_top_InterruptEnable(XHls_sobel_axi_stream_top *InstancePtr, u32 Mask);
void XHls_sobel_axi_stream_top_InterruptDisable(XHls_sobel_axi_stream_top *InstancePtr, u32 Mask);
void XHls_sobel_axi_stream_top_InterruptClear(XHls_sobel_axi_stream_top *InstancePtr, u32 Mask);
u32 XHls_sobel_axi_stream_top_InterruptGetEnabled(XHls_sobel_axi_stream_top *InstancePtr);
u32 XHls_sobel_axi_stream_top_InterruptGetStatus(XHls_sobel_axi_stream_top *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
