#include "hve_core.h"
#include "hve_lut.h" // Автоматично згенерований файл з масивом синусів

int16_t fast_sin_L(int32_t phase) {
    if (phase < 0) phase = -phase;
    phase = phase % L_METRIC;

    if (phase <= L_QUARTER) {
        return sin_quarter_LUT[phase];
    } else if (phase <= L_HALF) {
        return sin_quarter_LUT[L_HALF - phase];
    } else if (phase <= L_HALF + L_QUARTER) {
        return -sin_quarter_LUT[phase - L_HALF];
    } else {
        return -sin_quarter_LUT[L_METRIC - phase];
    }
}

int32_t compute_harmonic_control(int32_t target_L, int32_t current_L, int32_t K_GAIN) {
    int32_t error = target_L - current_L;

    // Розрахунок найкоротшого шляху на кільці
    if (error > L_HALF) {
        error -= L_METRIC;
    } else if (error < -L_HALF) {
        error += L_METRIC;
    } else if (error == L_HALF || error == -L_HALF) {
        error = L_HALF - 1; // Обхід сідлової сингулярності 180 градусів
    }

    // Гармонічне зв'язування
    int16_t sin_val = fast_sin_L(error);
    
    // Ділення на 32768 (зсув >> 15) для нормалізації Q15
    return (K_GAIN * (int32_t)sin_val) >> 15; 
}