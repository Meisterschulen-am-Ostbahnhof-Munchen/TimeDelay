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
#include "StandardLib.h"


#define LOG_LOCAL_LEVEL ESP_LOG_INFO
#include "esp_log.h"

static const char *TAG = "impulse_switch";
static int I = 0;




#define BUTTON_IO_NUM GPIO_NUM_32		// Pin 32.
#define BUTTON_STOP GPIO_NUM_39		// Pin 39.
#define GPIO_Q1 GPIO_NUM_19
#define GPIO_Q2 GPIO_NUM_23
#define GPIO_Q3 GPIO_NUM_33
#define GPIO_Q4 GPIO_NUM_25

TON TON1;
TON TON2;
TON TON3;
TON TON4;
F_TRIG F_TRIG1;
R_TRIG R_TRIG1;


TOF TOF1;

TOF_1 TOFR1;

TP TP1;

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
    gpio_reset_pin(BUTTON_IO_NUM);
    gpio_reset_pin(BUTTON_STOP);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(GPIO_Q1, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_Q2, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_Q3, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_Q4, GPIO_MODE_OUTPUT);
    gpio_set_direction(BUTTON_IO_NUM, GPIO_MODE_INPUT);
    gpio_set_direction(BUTTON_STOP, GPIO_MODE_INPUT);
    gpio_set_level(GPIO_Q1, 0); //set to 0 at Reset.
    gpio_set_level(GPIO_Q2, 0); //set to 0 at Reset.
    gpio_set_level(GPIO_Q3, 0); //set to 0 at Reset.
    gpio_set_level(GPIO_Q4, 0); //set to 0 at Reset.



    TON1.PT =  2000;

    TOF1.PT =  2000;
    TOFR1.PT = 2000;

    TP1.PT =  2000;


    while (true) {
    	I = !gpio_get_level(BUTTON_IO_NUM);



    	// TEST TON
    	TON1(I);
        gpio_set_level(GPIO_Q4, TON1.Q);




    	// TEST TOF
    	TOF1(I);
        gpio_set_level(GPIO_Q3, TOF1.Q);



    	// TEST TOF_1
		TOFR1.RST = !gpio_get_level(BUTTON_STOP);
    	TOFR1(I);
        gpio_set_level(GPIO_Q2, TOFR1.Q);



    	// TEST TP
    	TP1(I);
        gpio_set_level(GPIO_Q1, TP1.Q);




        // Test F_TRIG
        F_TRIG1(I);
        if (F_TRIG1.Q)
        	ESP_LOGI(TAG, "Falling Edge detected on I ...");


        // Test R_TRIG
        R_TRIG1(I);
        if (R_TRIG1.Q)
        	ESP_LOGI(TAG, "Rising Edge detected on I ...");


        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

