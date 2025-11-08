/*
 * Copyright (c) Development Team
 * Change Logs:
 * 2025-11-3  Lighting Build the basic framework
*/

#include "flash.h"
#include <at32f435_437_flash.h>

/**************************************************flash_external_interface*****************************************/
flash_t flash;
flash_special_variable_t flash_special_type_variable_box;
/*******************************************************************************************************************/

/******************************************flash_lock_abstract_assemble*********************************************/
/*
 * @brief   flash bank1 unlock abstract function
 * @param   none
 * @explain This function is the abstraction layer unlocked by flash bank1.
 * 					If you need to replace the chip, please add macro definitions 
 * 					and corresponding functions according to the format
 * @example flash.flash_lock_config.func.flash_bank1_unlock_abstract();
*/
void flash_bank1_unlock_abstract()
{
	#ifdef AT32_Enable
		flash_bank1_unlock();
	#endif
}
/*
 * @brief   flash bank2 unlock abstract function
 * @param   none
 * @explain This function is the abstraction layer unlocked by flash bank2.
 * 					If you need to replace the chip, please add macro definitions 
 * 					and corresponding functions according to the format
 * @example flash.flash_lock_config.func.flash_bank2_unlock_abstract();
*/
void flash_bank2_unlock_abstract()
{
	#ifdef AT32_Enable
		flash_bank2_unlock();
	#endif
}

/*
 * @brief   flash bank1 lock abstract function
 * @param   none
 * @explain This function is the abstraction layer locked by flash bank1.
 * 					If you need to replace the chip, please add macro definitions 
 * 					and corresponding functions according to the format
 * @example flash.flash_lock_config.func.flash_bank1_lock_abstract();
 */
void flash_bank1_lock_abstract()
{
	#ifdef AT32_Enable
		flash_bank1_lock();
	#endif
}

/*
 * @brief   flash bank2 lock abstract function
 * @param   none
 * @explain This function is the abstraction layer locked by flash bank2.
 * 					If you need to replace the chip, please add macro definitions
 * 					and corresponding functions according to the format
 * @example flash.flash_lock_config.func.flash_bank2_lock_abstract();
 */
void flash_bank2_lock_abstract()
{
	#ifdef AT32_Enable
		flash_bank2_lock();
	#endif
}

/*
 * @brief   flash all bank lock abstract function
 * @param   none
 * @explain This function is the abstraction layer locked by all flash banks.
 * 					If you need to replace the chip, please add macro definitions
 * 					and corresponding functions according to the format
 * @example flash.flash_lock_config.func.flash_allbank_lock_abstract();
 */
void flash_allbank_lock_abstract()
{
	#ifdef AT32_Enable
		flash_lock();
	#endif
}

/*
 * @brief   flash all bank unlock abstract function
 * @param   none
 * @explain This function is the abstraction layer unlocked by all flash banks.
 * 					If you need to replace the chip, please add macro definitions
 * 					and corresponding functions according to the format
 * @example flash.flash_lock_config.func.flash_allbank_unlock_abstract();
 */
void flash_allbank_unlock_abstract()
{
	#ifdef AT32_Enable
		flash_unlock();
	#endif
}

/*
 * @brief   flash lock or unlock The function then points to the initialization function
 * @param   none
 * @explain This function is used to initialize the flash lock and unlock function pointers.
 * 					After calling this function, the flash lock and unlock functions can be used through the
 * 					flash.flash_lock_config structure.
 * @example Flash_Lock_Switch_Init();
 */
void Flash_Lock_Switch_Init()
{
		flash.flash_lock_config.func.flash_bank1_lock   = flash_bank1_lock_abstract;
		flash.flash_lock_config.func.flash_bank2_lock   = flash_bank2_lock_abstract;
		flash.flash_lock_config.func.flash_bank1_unlock = flash_bank1_unlock_abstract;
		flash.flash_lock_config.func.flash_bank2_unlock = flash_bank2_unlock_abstract;
		flash.flash_lock_config.func.flash_lock         = flash_allbank_lock_abstract;
		flash.flash_lock_config.func.flash_unlock       = flash_allbank_unlock_abstract;
}
/*******************************************************************************************************************/

/***********************************************flash_mode_config_assemble******************************************/
/*
  *@brief   flash interrupt enable abstract function
  *@param   flash_int: specifies the flash interrupt sources to be enabled or disabled.
            this parameter can be any combination of the following values:
	*				  - FLASH_BANK1_ERR_INT
  *         - FLASH_BANK1_ODF_INT
  *         - FLASH_BANK2_ERR_INT
  *         - FLASH_BANK2_ODF_INT
  *         new_state: new state of the specified flash interrupts.
	* 				- FALSE = 0
	* 				- TRUE = !FALSE
	*@explain This function is the abstraction layer of flash interrupt enable.
	*					If you need to replace the chip, please add macro definitions 
	*					and corresponding functions according to the format
	*@example flash.flash_mode_config.func.flash_interrupt_enable_abstract(FLASH_BANK1_ERR_INT,TRUE);
*/
void flash_interrupt_enable_abstract(uint32_t flash_int, confirm_state_abstract new_state)
{
	#ifdef AT32_Enable
		flash_interrupt_enable(flash_int,new_state);
	#endif
}

/*
 * @brief   flash zero wait boost enable or disable abstract function
 * @param   new_state: new state of the specified flash zero wait boost.
 *          - FALSE = 0
 *          - TRUE = !FALSE
 * @explain This function is the abstraction layer of flash zero wait boost enable or disable.
 * 					If you need to replace the chip, please add macro definitions
 * 					and corresponding functions according to the format
 * @example flash.flash_mode_config.func.flash_nzw_boost_enable_abstract(TRUE);
 */
void flash_nzw_boost_enable_abstract(confirm_state_abstract new_state)
{
	#ifdef AT32_Enable
		flash_nzw_boost_enable(new_state);
	#endif
}

/*
 * @brief   flash continue read enable or disable abstract function
 * @param   new_state: new state of the specified flash continue read enable.
 *          - FALSE = 0
 *          - TRUE = !FALSE
 * 	@explain This function is the abstraction layer of flash continue read enable or disable.
 * 					 If you need to replace the chip, please add macro definitions
 * 					 and corresponding functions according to the format
 * 	@example flash.flash_mode_config.func.flash_continue_read_enable_abstract(TRUE);
 */
void flash_continue_read_enable_abstract(confirm_state_abstract new_state)
{
	#ifdef AT32_Enable
		flash_continue_read_enable(new_state);
	#endif
}

/*
 * @brief   flash mode configuration initialization function The function then points to the initialization function
 * @param   none
 * @explain This function is used to initialize the flash mode configuration function pointers.
 * 					After calling this function, the flash mode configuration functions can be used through the
 * 					flash.flash_mode_config structure.
 * @example Flash_Mode_Config_Init();
*/
void Flash_Mode_Config_Init()
{
	flash.flash_mode_config.func.flash_interrupt_enable     = flash_interrupt_enable_abstract;
	flash.flash_mode_config.func.flash_nzw_boost_enable     = flash_nzw_boost_enable_abstract;
	flash.flash_mode_config.func.flash_continue_read_enable = flash_continue_read_enable_abstract;
}
/*******************************************************************************************************************/
/**************************************************flash_erase_assemble*********************************************/
/*
 * @brief   flash sector erase abstract function
 * @param   sector_address: the sector address to be erased.please cooperate sector_address_get_abstract() to get the sector address
 * @return  flash_status_type_abstract The returned value can be:
 * 					-FLASH_OPERATE_BUSY
 * 					-FLASH_PROGRAM_ERROR
 * 					-FLASH_EPP_ERROR
 * 					-FLASH_OPERATE_DONE
 * 					-FLASH_OPERATE_TIMEOUT   
 * @explain This function is the abstraction layer of flash sector erase.
 * 					If you need to replace the chip, please add macro definitions
 * 					and corresponding functions according to the format
 * @example flash.flash_erase.func.flash_sector_erase(flash.flash_adderess_get.func.sector_address_get(511));
 */
flash_status_type_abstract flash_sector_erase_abstract(uint32_t sector_address)
{
	#ifdef AT32_Enable
		return(flash_status_type_abstract)flash_sector_erase(sector_address);
	#endif
}

/*
 * @brief   flash block erase abstract function
 * @param   block_address: the block address to be erased.please cooperate block_address_get_abstract() to get the block address
 * @return	flash_status_type_abstract The returned value can be:
 * 					-FLASH_OPERATE_BUSY
 * 					-FLASH_PROGRAM_ERROR
 * 					-FLASH_EPP_ERROR
 * 					-FLASH_OPERATE_DONE
 * 					-FLASH_OPERATE_TIMEOUT
 * @explain This function is the abstraction layer of flash block erase.
 * 					If you need to replace the chip, please add macro definitions
 * 					and corresponding functions according to the format
 * @example flash.flash_erase.func.flash_block_erase(flash.flash_adderess_get.func.block_address_get(15));
 */
flash_status_type_abstract flash_block_erase_abstract(uint32_t block_address) 
{
	#ifdef AT32_Enable
		return(flash_status_type_abstract)flash_block_erase(block_address);
	#endif
}

/*
 * @brief   flash bank1 erase abstract function
 * @param   none
 * @return  flash_status_type_abstract The returned value can be:
 * 					-FLASH_OPERATE_BUSY
 * 					-FLASH_PROGRAM_ERROR
 * 					-FLASH_EPP_ERROR
 * 					-FLASH_OPERATE_DONE
 * 					-FLASH_OPERATE_TIMEOUT
 * @explain This function is the abstraction layer of flash bank1 erase.
 * 					If you need to replace the chip, please add macro definitions
 * 					and corresponding functions according to the format
 * @example flash.flash_erase.func.flash_bank1_erase();
 */
flash_status_type_abstract flash_bank1_erase_abstract()
{
	#ifdef AT32_Enable
		return(flash_status_type_abstract)flash_bank1_erase();
	#endif
}

/*
 * @brief   flash bank2 erase abstract function
 * @param   none
 * @return  flash_status_type_abstract The returned value can be:
 * 					-FLASH_OPERATE_BUSY
 * 					-FLASH_PROGRAM_ERROR
 * 					-FLASH_EPP_ERROR
 * 					-FLASH_OPERATE_DONE
 * 					-FLASH_OPERATE_TIMEOUT
 * @explain This function is the abstraction layer of flash bank2 erase.
 * 					If you need to replace the chip, please add macro definitions
 * 					and corresponding functions according to the format
 * @example flash.flash_erase.func.flash_bank2_erase();
 */
flash_status_type_abstract flash_bank2_erase_abstract()
{
	#ifdef AT32_Enable
		return(flash_status_type_abstract)flash_bank2_erase();
	#endif
}

/*
 * @brief   flash user system data erase abstract function
 * @param   none
 * @return  flash_status_type_abstract The returned value can be:
 * 					-FLASH_OPERATE_BUSY
 * 					-FLASH_PROGRAM_ERROR
 * 					-FLASH_EPP_ERROR
 * 					-FLASH_OPERATE_DONE
 * 					-FLASH_OPERATE_TIMEOUT
 * @explain This function is the abstraction layer of flash user system data erase.
 * 					If you need to replace the chip, please add macro definitions
 * 					and corresponding functions according to the format
 * @example flash.flash_erase.func.flash_user_system_data_erase();
 */
flash_status_type_abstract flash_user_system_data_erase_abstract()
{
	#ifdef AT32_Enable
		return(flash_status_type_abstract)flash_user_system_data_erase();
	#endif
}


/*
 * @brief   flash erase function The function then points to the initialization function
 * @param   none
 * @explain This function is used to initialize the flash erase function pointers.
 * 					After calling this function, the flash erase functions can be used through the
 * 					flash.flash_erase structure.
 * @example Flash_Erase_Init();
*/
void Flash_Erase_Init()
{
	flash.flash_erase.func.flash_block_erase            = flash_block_erase_abstract;
	flash.flash_erase.func.flash_sector_erase           = flash_sector_erase_abstract;
	flash.flash_erase.func.flash_bank1_erase            = flash_bank1_erase_abstract;
	flash.flash_erase.func.flash_bank2_erase            = flash_bank2_erase_abstract;
	flash.flash_erase.func.flash_user_system_data_erase = flash_user_system_data_erase_abstract;
}
/*******************************************************************************************************************/
/**************************************************flash_program_assemble*******************************************/
/*
 * @brief   flash word program abstract function
 * @param   address: the address to be programmed.Its range of values :
 * 					- 4032kB (0x08000000~0x083FFFFF)
 * 					- 1024kB (0x08000000~0x080FFFFF)
 * 					- 448kB  (0x08000000~0x0806FFFF)
 * 					- 256kB  (0x08000000~0x0803FFFF)
 *          - 128kB  (0x08000000~0x0801FFFF)
 * @param   data: the word data to be programmed.
 * 					- uint32_t data (0x00000000~0xFFFFFFFF)
 * @return  flash_status_type_abstract The returned value can be:
 * 					-FLASH_OPERATE_BUSY
 * 					-FLASH_PROGRAM_ERROR
 * 					-FLASH_EPP_ERROR
 * 					-FLASH_OPERATE_DONE
 * 					-FLASH_OPERATE_TIMEOUT
 * @explain This function is the abstraction layer of flash word program.
 * 					If you need to replace the chip, please add macro definitions
 * 					and corresponding functions according to the format
 * @example flash.flash_program.func.flash_word_program(0x08000000,1);
 */
flash_status_type_abstract flash_word_program_abstract(uint32_t address, uint32_t data)
{
	#ifdef AT32_Enable
		return(flash_status_type_abstract)flash_word_program(address,data);
	#endif
}

/*
 * @brief   flash halfword program abstract function
 * @param   address: the address to be programmed.Its range of values :
 * 					- 4032kB (0x08000000~0x083FFFFF)
 * 					- 1024kB (0x08000000~0x080FFFFF)
 * 					- 448kB  (0x08000000~0x0806FFFF)
 * 					- 256kB  (0x08000000~0x0803FFFF)
 *          - 128kB  (0x08000000~0x0801FFFF)
 * @param   data: the halfword data to be programmed.
 * 					- uint16_t data (0x0000~0xFFFF)
 * @return  flash_status_type_abstract The returned value can be:
 * 					-FLASH_OPERATE_BUSY
 * 					-FLASH_PROGRAM_ERROR
 * 					-FLASH_EPP_ERROR
 * 					-FLASH_OPERATE_DONE
 * 					-FLASH_OPERATE_TIMEOUT
 * @explain This function is the abstraction layer of flash halfword program.
 * 					If you need to replace the chip, please add macro definitions
 * 					and corresponding functions according to the format
 * @example flash.flash_program.func.flash_halfword_program(0x08000000,1);
 */
flash_status_type_abstract flash_halfword_program_abstract(uint32_t address, uint16_t data)
{
	#ifdef AT32_Enable
		return(flash_status_type_abstract)flash_halfword_program(address,data);
	#endif
}

/*
 * @brief   flash byte program abstract function
 * @param   address: the address to be programmed.Its range of values :
 * 					- 4032kB (0x08000000~0x083FFFFF)
 * 					- 1024kB (0x08000000~0x080FFFFF)
 * 					- 448kB  (0x08000000~0x0806FFFF)
 * 					- 256kB  (0x08000000~0x0803FFFF)
 * @param   data: the byte data to be programmed.
 * 					- uint8_t data (0x00~0xFF)
 * @return  flash_status_type_abstract The returned value can be:
 * 					-FLASH_OPERATE_BUSY
 * 					-FLASH_PROGRAM_ERROR
 */
flash_status_type_abstract flash_byte_program_abstract(uint32_t address, uint8_t data)
{
	#ifdef AT32_Enable
		return(flash_status_type_abstract)flash_byte_program(address,data);
	#endif
}

/*
 * @brief   flash user system data program abstract function
 * @param   address: the user system data address to be programmed.Its range of values :
 * 	        - 4032kB (0x1FFFC04C~0x1FFFCFFF)
 * 					- 1024kB (0x1FFF804C~0x1FFFC1FF)
 * 					- 448kB  (0x1FFF604C~0x1FFFCFFF)
 * 					- 256kB  (0x1FFF404C~0x1FFFC1FF)
 * 					data: the byte data to be programmed.
 * 					- uint8_t data (0x00~0xFF)
 * @return  flash_status_type_abstract The returned value can be:
 * 					-FLASH_OPERATE_BUSY	
 * 					-FLASH_PROGRAM_ERROR
 * 					-FLASH_EPP_ERROR
 * 					-FLASH_OPERATE_DONE
 * 					-FLASH_OPERATE_TIMEOUT
 * @explain This function is the abstraction layer of flash user system data program.
 * 					If you need to replace the chip, please add macro definitions
 * 					and corresponding functions according to the format
 * @example flash.flash_program.func.flash_user_system_data_program_abstract(0x1FFFC04C,1);
 */
flash_status_type_abstract flash_user_system_data_program_abstract(uint32_t address, uint8_t data)
{
	#ifdef AT32_Enable
		return(flash_status_type_abstract)flash_user_system_data_program(address,data);
	#endif
}

/*
 * @brief   flash program function The function then points to the initialization function
 * @param   none
 * @explain This function is used to initialize the flash program function pointers.
 * 					After calling this function, the flash program functions can be used through the
 * 					flash.flash_program structure.
 * @example flash_program_Init();
 */
void flash_program_Init()
{
	flash.flash_program.func.flash_byte_program                       = flash_byte_program_abstract;
	flash.flash_program.func.flash_halfword_program                   = flash_halfword_program_abstract;
	flash.flash_program.func.flash_word_program                       = flash_word_program_abstract;
	flash.flash_program.func.flash_user_system_data_program_abstract  = flash_user_system_data_program_abstract;
}
/*******************************************************************************************************************/
/************************************************flash_adddress_get_assemble****************************************/
#define flash_base_address 0x08000000 /*flash base address */
#define block_interval     0x10000    /*block interval   64kb*/
#define section_interval   0x800      /*section interval 2kb*/
#define bank_interval      0x80000    /*bank interval    512kb*/	

/*
 * @brief   flash sector address get abstract function
 * @param   section_num: the section number to get the address.
 * 					- 0~1007 (for 4032kB flash)
 * 					- 0~511  (for 1024kB flash)
 * 					- 0~111  (for 448kB flash)
 * 					- 0~127   (for 256kB flash)
 * @return  uint32_t The returned value is the sector address.
 * @explain This function is the abstraction layer of flash sector address get.
 * 					If you need to replace the chip, please add macro definitions
 * 					and corresponding functions according to the format
 * @example flash.flash_adderess_get.func.sector_address_get(511);
 */
uint32_t sector_address_get_abstract(uint16_t section_num)
{
	#ifdef AT32_Enable
		uint32_t address = flash_base_address + section_num * section_interval;
		return address;
	#endif
}

/*
 * @brief   flash block address get abstract function
 * @param   block_num: the block number to get the address.	
 * 				  - 0~63   (for 4032kB flash)
 * 				  - 0~15   (for 1024kB flash)
 * 				  - 0~6    (for 448kB flash)
 * 				  - 0~3    (for 256kB flash)
 * @return  uint32_t The returned value is the block address.
 * @explain This function is the abstraction layer of flash block address get.	
 * 					If you need to replace the chip, please add macro definitions
 * 					and corresponding functions according to the format
 * @example flash.flash_adderess_get.func.block_address_get(15);
 */
uint32_t block_address_get_abstract(uint16_t block_num)
{
	#ifdef AT32_Enable
		uint32_t address = flash_base_address + block_num * block_interval;
		return address;
	#endif 
}

/*
 * @brief   flash bank address get abstract function
 * @param   bank_num: the bank number to get the address.
 * 					- 0~1
 * @return  uint32_t The returned value is the bank address.
 * @explain This function is the abstraction layer of flash bank address get.
 * 					If you need to replace the chip, please add macro definitions
 * 					and corresponding functions according to the format
 * @example flash.flash_address_get.func.bank_address_get(1);
 */
uint32_t bank_address_get_abstract(uint16_t bank_num)
{
	#ifdef AT32_Enable	
		uint32_t address = flash_base_address + bank_num * bank_interval;
		return address;
	#endif 
}

void Flash_Address_Get_Init()
{
		flash.flash_adderess_get.func.block_address_get  = block_address_get_abstract;
		flash.flash_adderess_get.func.sector_address_get = sector_address_get_abstract;
		flash.flash_adderess_get.func.bank_address_get   = bank_address_get_abstract;
}
/*******************************************************************************************************************/
/****************************************************Flash_Address_Init*********************************************/
/*
 * @brief   FDI Flash Init function
 * @param   none
 * @explain This function is used to initialize the flash abstraction layer.
 * @example FDI_Flash_Init();
*/
void FDI_Flash_Init(void)
{
	Flash_Lock_Switch_Init();
	Flash_Mode_Config_Init();
	Flash_Erase_Init();
	flash_program_Init();
	Flash_Address_Get_Init();
	
	flash.flash_mode_config.func.flash_nzw_boost_enable(TRUE);
	flash.flash_mode_config.func.flash_continue_read_enable(TRUE);
}
/*******************************************************************************************************************/






