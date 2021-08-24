/* main.c - Application main entry point */

/*
 * Copyright (c) 2017 Intel Corporation
 * Additional Copyright (c) 2018 Espressif Systems (Shanghai) PTE LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <string.h>

#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "esp_system.h"
#include "board.h"


static const char *TAG = "impulse_switch";


void app_main(void)
{



    ESP_LOGI(TAG, "Initializing...");

    board_init();
	
	


    while (true) {

        vTaskDelay(3000 / portTICK_PERIOD_MS);
    }
}

