#ifndef HVE_CORE_H
#define HVE_CORE_H

#include <stdint.h>

// Основна метрика Лозового (LCM 1..12)
#define L_METRIC 27720
#define L_HALF 13860
#define L_QUARTER 6930

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Обчислює синус на основі метрики L=27720 з використанням чвертьхвильової симетрії
 * @param phase Фаза в L-одиницях
 * @return Значення синуса у форматі Q15 (-32767 .. 32767)
 */
int16_t fast_sin_L(int32_t phase);

/**
 * @brief Обчислює гармонічне керуюче зусилля на кільцевому многовиді
 * @param target_L Цільова позиція (0 .. 27720)
 * @param current_L Поточна позиція (0 .. 27720)
 * @param K_GAIN Базовий коефіцієнт підсилення
 * @return Керуюче зусилля (наприклад, PWM)
 */
int32_t compute_harmonic_control(int32_t target_L, int32_t current_L, int32_t K_GAIN);

#ifdef __cplusplus
}
#endif

#endif // HVE_CORE_H