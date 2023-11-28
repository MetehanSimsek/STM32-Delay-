#ifndef __UDELAY_H
#define __UDELAY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stm32f1xx_hal.h>
#include <stddef.h>

  
/** @brief uDelay_init initialize the uDelay
 *  @return void
**/  
size_t uDelay_init(void);


/** @brief uDelay_delay_microsec use for microsecond delay
 *  @param time_us is value of time
    @return void
**/
void uDelay_delay_microsec(uint32_t time_us);


/** @brief uDelay_delay_milisec use for milisecond delay
 *  @param time_ms is value of time
    @return void
**/
void uDelay_delay_milisec(int time_ms);


/** @brief uDelay_set_time sets start time
 *  @param set_time is value of start time
    @return void
**/
void uDelay_set_time(uint16_t set_time);



/** @brief uDelay_get_time is measuring current time of a timer
 *  @param void
    @return The current time count of the specified timer.
**/
uint16_t uDelay_get_time(void);



#ifdef __cplusplus
}
#endif

#endif 