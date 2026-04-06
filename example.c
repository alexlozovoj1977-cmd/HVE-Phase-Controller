#include <stdio.h>
#include "hve_core.h"

// Простий приклад роботи контролера HVE
int main() {
    int32_t target_position = 6930; // Ціль: 90 градусів (чверть кола)
    int32_t current_position = 0;   // Початкова позиція: 0 градусів
    
    // Коефіцієнт підсилення K = 0.5 у форматі Q15 (32767 * 0.5 = 16384)
    int32_t K_GAIN_Q15 = 16384; 

    printf("HVE Controller Simulation Starts...\n");
    printf("Target L-units: %d\n\n", target_position);

    // Симуляція 10 кроків наближення до цілі
    for (int step = 1; step <= 10; step++) {
        // 1. Розрахунок керуючого зусилля
        int32_t control_effort = compute_harmonic_control(target_position, current_position, K_GAIN_Q15);
        
        // 2. Симуляція реакції системи (додаємо зусилля до поточної позиції)
        // У реальній системі тут буде PWM сигнал на мотор або магнітну котушку
        current_position += control_effort;

        printf("Step %02d | Current Pos: %6d | Control Effort: %6d\n", step, current_position, control_effort);
        
        // Зупинка, якщо досягли ідеальної рівноваги
        if (control_effort == 0) {
            printf("\nEquilibrium reached!\n");
            break;
        }
    }

    return 0;
}