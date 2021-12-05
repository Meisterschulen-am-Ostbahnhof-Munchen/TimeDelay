/* main.c - Application main entry point */

/*
 * Copyright (c) 2017 Intel Corporation
 * Additional Copyright (c) 2018 Espressif Systems (Shanghai) PTE LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "StandardLib.h"

#define LOG_LOCAL_LEVEL ESP_LOG_INFO
#include "esp_log.h"

static const char * const TAG = "EXAMPLE_TON";


#define BUTTON_I1 GPIO_NUM_26        // Pin 26.
#define GPIO_Q1 GPIO_NUM_19            // Pin 19.



/* Inside .cpp file, app_main function must be declared with C linkage */
extern "C" void app_main(void)
{


    ESP_LOGI(TAG, "Initializing EXAMPLE_TON ...");

    /* Configure the IOMUX register for pad BLINK_GPIO (some pads are
       muxed to GPIO on reset already, but some default to other
       functions and need to be switched to GPIO. Consult the
       Technical Reference for a list of pads and their default
       functions.)
    */
    gpio_reset_pin(GPIO_Q1);
    gpio_reset_pin(BUTTON_I1);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(GPIO_Q1, GPIO_MODE_OUTPUT);
    gpio_set_direction(BUTTON_I1, GPIO_MODE_INPUT);
    gpio_set_level(GPIO_Q1, 0); //set to 0 at Reset.


    TOF TOF1;
    TOF1.PT = 1000;

    while (true) // Endlos-Schleife
    {
        // Eingang lesen, das "!" bedeutet "NOT" weil die Eingaenge bei losgelassenem Taster auf 3.3V sind, und der Taster auf GND schaltet.
        bool I1 = !gpio_get_level(BUTTON_I1);

        // den I1 an TON1 uebergeben, und TON1 aufrufen
        TOF1(I1);

        // Ausgaenge setzen
        gpio_set_level(GPIO_Q1, TOF1.Q);

        // 100ms warten
        vTaskDelay(100 / portTICK_PERIOD_MS); // 100ms cycle for Test.
    }
}

