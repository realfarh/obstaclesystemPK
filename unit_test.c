#include "unit_test.h"
#include <stdio.h>
#include <stdbool.h>

#define JARAK_THRESHOLD_CM 20.0f
#define LDR_THRESHOLD_ADC  3500

static bool is_buzzer_on(float jarak_cm, int ldr_adc) {
    return (jarak_cm < JARAK_THRESHOLD_CM) || (ldr_adc > LDR_THRESHOLD_ADC);
}

static bool is_led_on(int ldr_adc) {
    return ldr_adc > LDR_THRESHOLD_ADC;
}

void run_unit_test_mode(void) {
    while(1) {
        float jarak;
        int ldr;

        printf("\nMasukkan nilai jarak (cm) (-1 untuk keluar): ");
        scanf("%f", &jarak);
        
        if(jarak == -1) break;

        printf("Masukkan nilai LDR (ADC): ");
        scanf("%d", &ldr);

        bool buzzer = is_buzzer_on(jarak, ldr);
        bool led = is_led_on(ldr);

        printf("\n=== Hasil Test ===\n");
        printf("Buzzer: %s\n", buzzer ? "ON" : "OFF");
        printf("LED: %s\n", led ? "ON" : "OFF");
    }
}