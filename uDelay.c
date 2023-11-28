#include "uDelay.h"

static TIM_HandleTypeDef htim4;


void uDelay_delay_microsec(uint32_t time_us)
{
  TIM4->CNT = 0;
  while(TIM4->CNT < time_us);
}


void uDelay_delay_milisec(int time_ms)
{
  for(int i = 0; i < time_ms; i++)
    uDelay_delay_microsec(1000);
}


void uDelay_set_time(uint16_t set_time)
{
  __HAL_TIM_SetCounter(&htim4, set_time);
}


uint16_t uDelay_get_time(void)
{  
  return __HAL_TIM_GetCounter(&htim4);
}


size_t uDelay_init(void)
{
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 72-1;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 0xffff-1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    return HAL_ERROR;
  }
  return HAL_OK;
}
