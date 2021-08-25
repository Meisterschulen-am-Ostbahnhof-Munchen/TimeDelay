/* main.c - Application main entry point */

/*
 * Copyright (c) 2017 Intel Corporation
 * Additional Copyright (c) 2018 Espressif Systems (Shanghai) PTE LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <string.h>


#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "hal/gpio_types.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_system.h"
#include "TimeLib.h"
#include "StandardLib.h"
#include "UtilLib.h"
#include "ExtraLib.h"
#include "BasicLib.h"

#define LOG_LOCAL_LEVEL ESP_LOG_INFO
#include "esp_log.h"

static const char *TAG = "impulse_switch";
static int I1 = 0;
static int I2 = 0;



#define BUTTON_I1 GPIO_NUM_32		// Pin 32.
#define BUTTON_I2 GPIO_NUM_39		// Pin 39.
#define GPIO_Q1 GPIO_NUM_19
#define GPIO_Q2 GPIO_NUM_23
#define GPIO_Q3 GPIO_NUM_33
#define GPIO_Q4 GPIO_NUM_25



CLICK_DEC CLICK_DEC1;
TP TP0;
TP TP1;
TP TP2;
TP TP3;


/* Inside .cpp file, app_main function must be declared with C linkage */
extern "C" void app_main(void)
{



    ESP_LOGI(TAG, "Initializing...");

    /* Configure the IOMUX register for pad BLINK_GPIO (some pads are
       muxed to GPIO on reset already, but some default to other
       functions and need to be switched to GPIO. Consult the
       Technical Reference for a list of pads and their default
       functions.)
    */
    gpio_reset_pin(GPIO_Q1);
    gpio_reset_pin(GPIO_Q2);
    gpio_reset_pin(GPIO_Q3);
    gpio_reset_pin(GPIO_Q4);
    gpio_reset_pin(BUTTON_I1);
    gpio_reset_pin(BUTTON_I2);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(GPIO_Q1, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_Q2, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_Q3, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_Q4, GPIO_MODE_OUTPUT);
    gpio_set_direction(BUTTON_I1, GPIO_MODE_INPUT);
    gpio_set_direction(BUTTON_I2, GPIO_MODE_INPUT);
    gpio_set_level(GPIO_Q1, 0); //set to 0 at Reset.
    gpio_set_level(GPIO_Q2, 0); //set to 0 at Reset.
    gpio_set_level(GPIO_Q3, 0); //set to 0 at Reset.
    gpio_set_level(GPIO_Q4, 0); //set to 0 at Reset.

    CLICK_DEC1.TC = 1000;
    TP1.PT = 200;
    TP2.PT = 200;
    TP3.PT = 200;
    TP0.PT = 200;



    while (true) {
    	I1 = !gpio_get_level(BUTTON_I1);
    	I2 = !gpio_get_level(BUTTON_I2);




    	CLICK_DEC1(I1);

        gpio_set_level(GPIO_Q1, TP1(CLICK_DEC1.Q1));
        gpio_set_level(GPIO_Q2, TP2(CLICK_DEC1.Q2));
        gpio_set_level(GPIO_Q3, TP3(CLICK_DEC1.Q3));
        gpio_set_level(GPIO_Q4, TP0(CLICK_DEC1.Q0));




        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

