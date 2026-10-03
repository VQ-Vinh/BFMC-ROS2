/**
 * @file  esc.h
 * @brief Dieu khien ESC brushless bang xung RC (50 Hz, 1000-2000 us).
 *
 * Yeu cau timer co tick 1 us va chu ky 20 ms (PSC/ARR cau hinh trong CubeMX).
 */
#ifndef ESC_H
#define ESC_H

#include "main.h"

#define ESC_PULSE_MIN_US   1000U   /* ga 0% */
#define ESC_PULSE_MAX_US   2000U   /* ga 100% */
#define ESC_ARM_TIME_MS    3000U   /* thoi gian giu ga 0 de ESC arm */

typedef struct
{
  TIM_HandleTypeDef *htim;
  uint32_t channel;
  uint8_t armed;
} ESC_Handle;

/* Bat PWM o muc ga 0. Goi sau MX_TIMx_Init(). */
HAL_StatusTypeDef ESC_Init(ESC_Handle *esc, TIM_HandleTypeDef *htim, uint32_t channel);

/* Giu ga 0 trong ESC_ARM_TIME_MS de ESC arm (blocking). */
void ESC_Arm(ESC_Handle *esc);

/* Dat do rong xung truc tiep, tu dong gioi han trong [MIN, MAX]. */
void ESC_SetPulseUs(ESC_Handle *esc, uint16_t pulse_us);

/* Dat ga theo phan tram 0-100. Bo qua neu chua arm. */
void ESC_SetThrottle(ESC_Handle *esc, uint8_t percent);

/* Ve ga 0, van giu xung de ESC khong mat tin hieu. */
void ESC_Stop(ESC_Handle *esc);

#endif /* ESC_H */
