#ifndef __flash_h
#define __flash_h

#include "fdi_parame.h"
#include "fconfig.h"
#include "at32f435_437.h"

#define block_address(num) 0x08000000 + num * 0x10000

/***********************************************Flash State Get*****************************************************/
/*
 *@explain Starting from this position indicates that the flash memory operation is in progress
           ,and clearing this bit indicates that the operation has ended
*/
typedef enum
{
	NBusy = 0,
	Busy,
}Flash_Operation_Busy_State_E;
#define Flash1_Operation_Busy_State FLASH->sts_bit.obf
#define Flash2_Operation_Busy_State FLASH->sts2_bit.obf

/*
 *@explain When the value of the flash memory address being programmed is in a non-erasable state,
					 the hardware will set this bit, and the software can write '1' to clear it.
*/
typedef enum
{
	Program_NotError  = 0,
	Program_Error     = 1,
	Program_Soft_Rest = 1
}Flash_Program_Error_State_E;
#define Flash1_Program_Error_State FLASH->sts_bit.prgmerr
#define Flash2_Program_Error_State FLASH->sts2_bit.prgmerr

/*
 *@explain When an erase or program operation targets a flash memory address within the write/erase protection range, 
					 the hardware sets this bit. Software can clear it by writing '1'.
*/
typedef enum
{
	EraseProgram_NotError  = 0,
	EraseProgram_Error     = 1,
	EraseProgram_Soft_Rest = 1
}Flash_EraseProgram_Error_State_E;
#define Flash1_EraseProgram_Error_State FLASH->sts_bit.epperr
#define Flash2_EraseProgram_Error_State FLASH->sts2_bit.epperr

/*
 *@explain When a flash memory operation (program/erase) completes successfully, the hardware sets this bit, 
					 which can be cleared by software writing '1'.
*/

typedef enum
{
	Flash_Operatop_UnderWay = 0,
	Flash_Operation_Done    = 1,
}Flash_Operation_Done_Flag_E;
#define Flash1_Operation_Done_Flag_State FLASH->sts_bit.odf
#define Flash2_Operation_Done_Flag_State FLASH->sts2_bit.odf

/*******************************************************************************************************************/

/****************************************************typedef abstrct************************************************/
typedef confirm_state        confirm_state_abstract;
typedef flash_status_type    flash_status_type_abstract;
/******************************************flash_lock_abstract_assemble*********************************************/
typedef struct
{
	struct
	{
		void (*flash_bank1_lock)  (void);
		void (*flash_bank2_lock)  (void);

		void (*flash_bank1_unlock)(void);
		void (*flash_bank2_unlock)(void);

		void (*flash_unlock)      (void);
		void (*flash_lock)        (void);
	}func;
}flash_lock_t;
/*******************************************************************************************************************/
/***********************************************flash_mode_config_assemble******************************************/
typedef struct
{
	struct
	{
			void  (*flash_interrupt_enable)    (uint32_t,confirm_state_abstract);
			void  (*flash_nzw_boost_enable)    (confirm_state_abstract);
			void  (*flash_continue_read_enable)(confirm_state_abstract);
	}func;
}flash_mode_config_t;
/*******************************************************************************************************************/
/**************************************************flash_erase_assemble*********************************************/
typedef struct
{
		struct
		{
				flash_status_type_abstract (*flash_sector_erase)(uint32_t);
				flash_status_type_abstract (*flash_block_erase)(uint32_t);
			  flash_status_type_abstract (*flash_bank1_erase)(void);
				flash_status_type_abstract (*flash_bank2_erase)(void);
				flash_status_type_abstract (*flash_user_system_data_erase)(void);
		}func;
}flash_erase_t;
/*******************************************************************************************************************/
/************************************************flash_adddress_get_assemble****************************************/
typedef struct
{
	struct
	{
			uint32_t (*sector_address_get)(uint16_t);
			uint32_t (*block_address_get) (uint16_t);
			uint32_t (*bank_address_get)  (uint16_t);
	}func;
}flash_address_get_t;
/*******************************************************************************************************************/
/**************************************************flash_program_assemble*******************************************/
typedef struct
{
	struct
	{
		flash_status_type_abstract (*flash_word_program)                     (uint32_t,uint32_t);
		flash_status_type_abstract (*flash_halfword_program)                 (uint32_t,uint16_t);
		flash_status_type_abstract (*flash_byte_program)                     (uint32_t,uint8_t);
		flash_status_type_abstract (*flash_user_system_data_program_abstract)(uint32_t,uint8_t);
	}func;
}flash_program_t;
/*******************************************************************************************************************/
/**************************************************flash_external_interface*****************************************/
typedef struct
{
	flash_lock_t        flash_lock_config;
	flash_mode_config_t flash_mode_config;
	flash_erase_t       flash_erase;
	flash_address_get_t flash_adderess_get;
	flash_program_t     flash_program;
}flash_t;
extern flash_t flash;

typedef struct
{
	flash_status_type_abstract flash_return_status;
}flash_special_variable_t;

void FDI_Flash_Init(void);
extern flash_special_variable_t flash_special_type_variable_box;
/*******************************************************************************************************************/
#endif
