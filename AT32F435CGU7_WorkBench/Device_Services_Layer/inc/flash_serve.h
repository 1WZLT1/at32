#ifndef __flash_serve_h
#define __flash_serve_h

#include "fdi_parame.h"
#include "flash.h"

/**************************************************flash_external_interface*****************************************/
typedef struct
{
	uint32_t flash_last_address;
}flash_serve_box_t;
void fdi_parame_init(void);

/*******************************************************************************************************************/

#endif

