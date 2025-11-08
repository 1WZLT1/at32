#ifndef __fdi_parame_h
#define __fdi_parame_h

#include "stdint.h"
#include "float.h"

extern void Load$$FDI_PARAME$$Limit;
extern void Load$$FDI_PARAME$$Base;
extern void Image$$FDI_PARAME$$Base;


extern void Load$$FDI_FLASH_PARAM$$Base;

#define FDI_PARAME_LoadSection_Len \
(uint32_t)&Load$$FDI_PARAME$$Limit - (uint32_t)&Load$$FDI_PARAME$$Base

#define FDI_FLASH_PARAME_BASE 0x080FF804
#define FDI_SRAM_PARAME_BASE  0x2005F804

#define FDI_PARAM_MAX_MIN(_name,_max,_min,_type)                                                  \
extern _type _name; 																																						\
__attribute__((section("fdi_parame"), used)) _type _name                                          


#define  FDI_PARAM_U8(name)  FDI_PARAM_MAX_MIN(name,UINT8_MAX ,0,uint8_t)
#define  FDI_PARAM_U16(name) FDI_PARAM_MAX_MIN(name,UINT16_MAX,0,uint16_t)
#define  FDI_PARAM_U32(name) FDI_PARAM_MAX_MIN(name,UINT32_MAX,0,uint32_t)
#define  FDI_PARAM_U64(name) FDI_PARAM_MAX_MIN(name,UINT64_MAX,0,uint64_t)

#define  FDI_PARAM_S8 (name) FDI_PARAM_MAX_MIN(name,INT8_MAX,0,int8_t)
#define  FDI_PARAM_S16(name) FDI_PARAM_MAX_MIN(name,INT16_MAX,0,int16_t)
#define  FDI_PARAM_S32(name) FDI_PARAM_MAX_MIN(name,INT32_MAX,0,int32_t)
#define  FDI_PARAM_S64(name) FDI_PARAM_MAX_MIN(name,INT64_MAX,0,int64_t)

#define  FDI_PARAM_F32(name) FDI_PARAM_MAX_MIN(name,FLT_MAX,0,float)
#define  FDI_PARAM_F64(name) FDI_PARAM_MAX_MIN(name,DBL_MAX,0,double) 
	

 
#endif

