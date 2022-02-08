/* FOUR_POSITION_3TOF/main.cpp - Application main entry point */

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
#include "TimerSettings3.h"
#include "Automation_FOUR_POSITION.h"
#include "AutomationTimer_FOUR_POSITION_3TOFObserved.h"

#include "settingsNVS.h"
#include "SettingsAdapter.h"

#define LOG_LOCAL_LEVEL ESP_LOG_INFO
#include "esp_log.h"


static const char * const TAG = "FOUR_POSITION_3TOF";
static int I1 = 0;
static int I2 = 0;
static int I3 = 0;

#define BUTTON_I1 GPIO_NUM_26        // Pin 26.
#define BUTTON_I2 GPIO_NUM_32        // Pin 32.
#define BUTTON_I3 GPIO_NUM_39        // Pin 39.
#define GPIO_Q1 GPIO_NUM_19
#define GPIO_Q2 GPIO_NUM_23
#define GPIO_Q3 GPIO_NUM_33
#define GPIO_Q4 GPIO_NUM_25



SettingsAdapter*   	settingsAdapter    = new SettingsAdapter;
TimerSettings3*   	timerSettings      = TimerSettings3::getInstance(settingsAdapter);



FOUR_POSITION_SWITCH SWITCH;
FOUR_POSITION_3TOF_O    TIMER(timerSettings, "TOF1_up", "TOF1_down", "TOF1_float");
VALVE_WITH_FLOAT     VALVE;


/* Inside .cpp file, app_main function must be declared with C linkage */
extern "C" void app_main(void)
{



    ESP_LOGI(TAG, "Initializing...");



	/* Initialize application */
    initSettings();

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
    gpio_reset_pin(BUTTON_I3);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(GPIO_Q1, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_Q2, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_Q3, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_Q4, GPIO_MODE_OUTPUT);
    gpio_set_direction(BUTTON_I1, GPIO_MODE_INPUT);
    gpio_set_direction(BUTTON_I2, GPIO_MODE_INPUT);
    gpio_set_direction(BUTTON_I3, GPIO_MODE_INPUT);
    gpio_set_level(GPIO_Q1, 0); //set to 0 at Reset.
    gpio_set_level(GPIO_Q2, 0); //set to 0 at Reset.
    gpio_set_level(GPIO_Q3, 0); //set to 0 at Reset.
    gpio_set_level(GPIO_Q4, 0); //set to 0 at Reset.








    while (true) {
        I1 = not gpio_get_level(BUTTON_I1);
        I2 = not gpio_get_level(BUTTON_I2);
        I3 = not gpio_get_level(BUTTON_I3);



        SWITCH.I1 = I1;
        SWITCH.I2 = I2;
        SWITCH.I3 = I3;
        SWITCH();
        TIMER.IN = SWITCH.State;
        TIMER();
        VALVE.State = TIMER.OUT;
        VALVE();




        gpio_set_level(GPIO_Q1, VALVE.Q1);
        gpio_set_level(GPIO_Q2, VALVE.Q2);
        gpio_set_level(GPIO_Q3, VALVE.Q3);
        gpio_set_level(GPIO_Q4, VALVE.Q4);


        vTaskDelay(100 / portTICK_PERIOD_MS); // 100ms cycle for Test.

    }
}

