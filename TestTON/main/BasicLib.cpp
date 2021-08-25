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
	return (Q1);
}

bool CLK_DIV::operator ()(bool CLK) {
	if(RST)
	{
		CNT = 0;
		Q0  = 0;
		Q1  = 0;
		Q2  = 0;
		Q3  = 0;
		Q4  = 0;
		Q5  = 0;
		Q6  = 0;
		Q7  = 0;
	}
	else if(CLK)
	{
		CNT = CNT    +1;
		Q0  = CNT &   1;
		Q1  = CNT &   2;
		Q2  = CNT &   4;
		Q3  = CNT &   8;
		Q4  = CNT &  16;
		Q5  = CNT &  32;
		Q6  = CNT &  64;
		Q7  = CNT & 128;
	}
	return (Q0);
}

bool CLK_N::operator ()(void) {
	STIME = T_PLC_MS() >> N;
	CLK = STIME & 1;
	Q = CLK ^ EDGE;
	EDGE = CLK;
	return (Q);
}






