/* add user code begin Header */
/**
  **************************************************************************
  * @file     main.c
  * @brief    main program
  **************************************************************************
  *                       Copyright notice & Disclaimer
  *
  * The software Board Support Package (BSP) that is made available to
  * download from Artery official website is the copyrighted work of Artery.
  * Artery authorizes customers to use, copy, and distribute the BSP
  * software and its related documentation for the purpose of design and
  * development in conjunction with Artery microcontrollers. Use of the
  * software is governed by this copyright notice and the following disclaimer.
  *
  * THIS SOFTWARE IS PROVIDED ON "AS IS" BASIS WITHOUT WARRANTIES,
  * GUARANTEES OR REPRESENTATIONS OF ANY KIND. ARTERY EXPRESSLY DISCLAIMS,
  * TO THE FULLEST EXTENT PERMITTED BY LAW, ALL EXPRESS, IMPLIED OR
  * STATUTORY OR OTHER WARRANTIES, GUARANTEES OR REPRESENTATIONS,
  * INCLUDING BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE, OR NON-INFRINGEMENT.
  *
  **************************************************************************
  */
/* add user code end Header */

/* Includes ------------------------------------------------------------------*/
#include "at32f435_437_wk_config.h"
#include "wk_system.h"

/* private includes ----------------------------------------------------------*/
/* add user code begin private includes */
#include "rtthread.h"
/* add user code end private includes */

/* private typedef -----------------------------------------------------------*/
/* add user code begin private typedef */

/* add user code end private typedef */

/* private define ------------------------------------------------------------*/
/* add user code begin private define */

/* add user code end private define */

/* private macro -------------------------------------------------------------*/
/* add user code begin private macro */

/* add user code end private macro */

/* private variables ---------------------------------------------------------*/
/* add user code begin private variables */

/* add user code end private variables */

/* private function prototypes --------------------------------------------*/
/* add user code begin function prototypes */

/* add user code end function prototypes */

/* private user code ---------------------------------------------------------*/
/* add user code begin 0 */

int i = 0;
static struct rt_thread thread_1;
static void thread_1_f(void* parameter)
{
		while(1)
		{
			i++;
			rt_thread_delay(10);
		}
}
ALIGN(8)
uint8_t thread_1_stack[2048];

int j = 0;
static struct rt_thread thread_2;
static void thread_2_f(void* parameter)
{
		while(1)
		{
			j++;
			rt_thread_delay(10);
		}
}
ALIGN(8)
uint8_t thread_2_stack[2048];

void thread_init()
{
	__disable_irq();
	rt_thread_init(&thread_1,"thread_1",thread_1_f,NULL,&thread_1_stack[0],sizeof(thread_1_stack),5,10);
	rt_thread_startup(&thread_1);
	
	rt_thread_init(&thread_2,"thread_2",thread_2_f,NULL,&thread_2_stack[0],sizeof(thread_2_stack),6,10);
	rt_thread_startup(&thread_2);
	__enable_irq();
}

void SystemCoreClockUpdate()
{

}
/* add user code end 0 */

/**
  * @brief main function.
  * @param  none
  * @retval none
  */
int main(void)
{
  /* add user code begin 1 */

  /* add user code end 1 */

  /* system clock config. */
  wk_system_clock_config();

  /* config periph clock. */
  wk_periph_clock_config();

  /**
   * users need add interrupt handler code into the below function in the at32f435_437_int.c file.
   *  --void SystTick_IRQHandler(void)
   */
  systick_interrupt_config(1000);

  /* nvic config. */
  wk_nvic_config();

  /* add user code begin 2 */
	thread_init();
  /* add user code end 2 */

  while(1)
  {
    /* add user code begin 3 */

//    /* add user code end 3 */
  }
}

  /* add user code begin 4 */

  /* add user code end 4 */
