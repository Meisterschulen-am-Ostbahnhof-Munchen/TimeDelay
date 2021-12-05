/* EXAMPLE_TRIG/main.cpp - Application main entry point */

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

static const char * const TAG = "EXAMPLE_TRIG";


#define BUTTON_I1 GPIO_NUM_26        // Pin 26.
#define GPIO_Q1 GPIO_NUM_19            // Pin 19.
#define GPIO_Q2 GPIO_NUM_23



/* Inside .cpp file, app_main function must be declared with C linkage */
extern "C" void app_main(void)
{


    ESP_LOGI(TAG, "Initializing EXAMPLE_TRIG ...");

    /* Configure the IOMUX register for pad BLINK_GPIO (some pads are
       muxed to GPIO on reset already, but some default to other
       functions and need to be switched to GPIO. Consult the
       Technical Reference for a list of pads and their default
       functions.)
    */
    gpio_reset_pin(GPIO_Q1);
    gpio_reset_pin(GPIO_Q2);
    gpio_reset_pin(BUTTON_I1);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(GPIO_Q1, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_Q2, GPIO_MODE_OUTPUT);
    gpio_set_direction(BUTTON_I1, GPIO_MODE_INPUT);
    gpio_set_level(GPIO_Q1, 0); //set to 0 at Reset.
    gpio_set_level(GPIO_Q2, 0); //set to 0 at Reset.



    F_TRIG F_TRIG1;
    R_TRIG R_TRIG1;

    TOF TOF1;
    TOF1.PT = 1000;
    TOF TOF2;
    TOF2.PT = 1000;


    while (true) // Endlos-Schleife
    {
        // Eingang lesen, das not wird gebraucht weil die Eingaenge bei losgelassenem Taster auf 3.3V sind, und der Taster auf GND schaltet.
        bool I1 = not gpio_get_level(BUTTON_I1);

        // den I1 an F_TRIG1 uebergeben, und F_TRIG1 aufrufen
        F_TRIG1(I1);

        //Nachricht ausgeben (optional)
        if (F_TRIG1.Q) {
        	ESP_LOGI(TAG, "Falling Edge detected on I1 ...");
        }

        // den I1 an R_TRIG1 uebergeben, und R_TRIG1 aufrufen
        R_TRIG1(I1);

        //Nachricht ausgeben (optional)
        if (R_TRIG1.Q) {
        	ESP_LOGI(TAG, "Raising Edge detected on I1 ...");
        }

        // den F_TRIG1 an TOF1 uebergeben, und TOF1 aufrufen
        TOF1(F_TRIG1.Q);

        // den R_TRIG1 an TOF2 uebergeben, und TOF2 aufrufen
        TOF2(R_TRIG1.Q);

        // Ausgaenge setzen
        gpio_set_level(GPIO_Q1, TOF1.Q);
        gpio_set_level(GPIO_Q2, TOF2.Q);

        // 100ms warten  = Intervallzeit des Tasks
        vTaskDelay(100 / portTICK_PERIOD_MS); // 100ms cycle for Test.
    }
}

