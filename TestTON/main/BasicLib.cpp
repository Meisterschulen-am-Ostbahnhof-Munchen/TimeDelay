/*
 * BasicLib.cpp
 *
 *  Created on: 25.08.2021
 *      Author: FranzHoepfinger
 */



#include <stdbool.h>
#include <stdint.h>
#include "TimeLib.h"
#include "StandardLib.h"
#include "BasicLib.h"

bool CLICK_DEC::operator ()(bool IN)
{
	/* Q shall only be active for one cycle only */
	if (IN == false)
	{
		Q0 = false;
		Q1 = false;
		Q2 = false;
		Q3 = false;
	}

	if (IN && !EDGE && !TX.Q)
	{
		/* a rising edge on in sets the counter to 0 */
		CNT = 0;
	}
	else if (TX.Q && !IN && EDGE)
	{
		/* count falling edges when tp.q is true */
		CNT++;
	}
	else if (!TX.Q)
	{
		switch (CNT) {
		case 0 : Q0 = true; break;
		case 1 : Q1 = true; break;
		case 2 : Q2 = true; break;
		case 3 : Q3 = true; break;
		default:			break;
		}
		CNT = -1;
	};

	/* remember the status of IN */
	EDGE = IN;
	TX.PT = TC;
	TX(IN); //Call TX
	return (Q0);


}
