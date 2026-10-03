#include "esc.h"

HAL_StatusTypeDef ESC_Init(ESC_Handle *esc, TIM_HandleTypeDef *htim, uint32_t channel)
{
  esc->htim = htim;
  esc->channel = channel;
  esc->armed = 0;

  __HAL_TIM_SET_COMPARE(htim, channel, ESC_PULSE_MIN_US);
  return HAL_TIM_PWM_Start(htim, channel);
}

void ESC_Arm(ESC_Handle *esc)
{
  ESC_SetPulseUs(esc, ESC_PULSE_MIN_US);
  HAL_Delay(ESC_ARM_TIME_MS);
  esc->armed = 1;
}

void ESC_SetPulseUs(ESC_Handle *esc, uint16_t pulse_us)
{
  if (pulse_us < ESC_PULSE_MIN_US)
  {
    pulse_us = ESC_PULSE_MIN_US;
  }
  else if (pulse_us > ESC_PULSE_MAX_US)
  {
    pulse_us = ESC_PULSE_MAX_US;
  }
  __HAL_TIM_SET_COMPARE(esc->htim, esc->channel, pulse_us);
}

void ESC_SetThrottle(ESC_Handle *esc, uint8_t percent)
{
  if (!esc->armed)
  {
    return;
  }
  if (percent > 100U)
  {
    percent = 100U;
  }
  ESC_SetPulseUs(esc, ESC_PULSE_MIN_US
                      + (uint32_t)percent * (ESC_PULSE_MAX_US - ESC_PULSE_MIN_US) / 100U);
}

void ESC_Stop(ESC_Handle *esc)
{
  ESC_SetPulseUs(esc, ESC_PULSE_MIN_US);
}
