/* EXAMPLE_TOF/main.cpp - Application main entry point */

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
#include "StandardLibObserved.h"

#define LOG_LOCAL_LEVEL ESP_LOG_INFO
#include "esp_log.h"

static const char * const TAG = "EXAMPLE_TON";


#define BUTTON_I1 GPIO_NUM_26        // Pin 26.
#define GPIO_Q1 GPIO_NUM_19            // Pin 19.



/* Inside .cpp file, app_main function must be declared with C linkage */
extern "C" void app_main(void)
{


    ESP_LOGI(TAG, "Initializing EXAMPLE_TOF ...");

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




    TimerSettings*   timerSettings        = new TimerSettings;
    TOF_R_TRIG_O TOF1(timerSettings);
    TOF_R_TRIG_O TOF2(timerSettings);

    while (true) {
    	I1 = !gpio_get_level(BUTTON_I1);
    	I2 = !gpio_get_level(BUTTON_I2);
    	I3 = !gpio_get_level(BUTTON_I3);


    	if (I3)
    		timerSettings->setPT(5000);



    	// TEST TOF
    	TOF1(I1);
    	TOF2(I2);
        gpio_set_level(GPIO_Q1, TOF1.Q);
        gpio_set_level(GPIO_Q2, TOF2.Q);
        vTaskDelay(100 / portTICK_PERIOD_MS);




    }
}

