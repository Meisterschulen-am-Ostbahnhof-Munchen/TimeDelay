/*
 * StandardLib.c
 *
 *  Created on: 24.08.2021
 *      Author: FranzHoepfinger
 */


#include <stdbool.h>
#include <stdint.h>
#include "StandardLib.h"




#define LOG_LOCAL_LEVEL ESP_LOG_DEBUG
#include "esp_log.h"

static const char *TAG = "StandardLib";

int32_t T_PLC_MS(void) // @suppress("Name convention for function")
{
	return (esp_log_timestamp());
}



/**
 * \brief
 * Timer on delay.
 *
 * \param	IN starts timer with rising edge, resets timer with falling edge
 * \param   PT time to pass, before Q is set
 * \return	Q is TRUE, PT milliseconds after IN had a rising edge.
 *
 */
bool TON::operator ()(bool IN)
{
	int32_t tx;					/* internal variable */

	/* read system timer */
	tx = T_PLC_MS();

	// raising Edge
	if (IN && !M)
	{
		ESP_LOGD(TAG, "TON: raising Edge detected");
		//Start the Timer
		StartTime = tx;
	}

	// falling Edge
	if (!IN && M)
	{
		ESP_LOGD(TAG, "TON: falling Edge detected");
		//reset the Timer
		StartTime = 0;
	}


	if (IN)
	{
		ET = tx - StartTime;
	}
	else
	{
		ET = 0;
	}

	M = IN; //remember old State.

	ESP_LOGV(TAG, "ET %i    PT %i", ET, PT);
	Q = ET >= PT ? true : false;
	return (Q);
}

bool F_TRIG::operator ()(bool CLK) {

	// falling Edge
	if (!CLK && M)
	{
		ESP_LOGD(TAG, "F_TRIG: falling Edge detected");
		Q = 1;
	}
	else
	{
		Q = 0;
	}
	M = CLK; //remember old State.
	return (Q);
}
