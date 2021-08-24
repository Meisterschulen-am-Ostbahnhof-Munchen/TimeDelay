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
static int Q = 0;




static const gpio_num_t BUTTON_IO_NUM 	= gpio_num_t::GPIO_NUM_32;		// Pin 32.
static const gpio_num_t Q_GPIO 			= gpio_num_t::GPIO_NUM_19;



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
    gpio_reset_pin(Q_GPIO);
    gpio_reset_pin(BUTTON_IO_NUM);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(Q_GPIO, GPIO_MODE_OUTPUT);
    gpio_set_direction(BUTTON_IO_NUM, GPIO_MODE_INPUT);
    gpio_set_level(Q_GPIO, Q); //set to 0 at Reset.


    while (true) {
    	I = !gpio_get_level(BUTTON_IO_NUM);

    	Q = TON(I, 500);

        gpio_set_level(Q_GPIO, Q);
        vTaskDelay(100 / portTICK_PERIOD_MS);
    }
}

