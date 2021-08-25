/*
 * BasicLib.h
 *
 *  Created on: 25.08.2021
 *      Author: FranzHoepfinger
 */

#ifndef MAIN_BASICLIB_H_
#define MAIN_BASICLIB_H_


/**
 * \brief

	this Module detects a rising edge on In and decodes the amount of falling edges (Pulses) within a specified time TC.
	the outputs Q0..Q3 will go true for one cycle and the amount of clicks within a specified time TC.
	if only a rising egde is detected within TC Q0 will respond, Q1 for 1 pulse and so on..
 *

 *
 */
class CLICK_DEC
{
public:
	//VAR_INPUT
	int32_t TC = 0;			/* TIME */
	//VAR_OUTPUT
	bool Q0 = false;		/* output signal rising edge without falling edge */
	bool Q1 = false;		/* output signal of a pulse within TC */
	bool Q2 = false;		/* output signal of a pulse within TC */
	bool Q3 = false;		/* output signal of a pulse within TC */
	//call
	bool operator()(bool IN);/* Q is FALSE, PT milliseconds after IN had a falling edge */
private:
	TP TX;					/* internal variable */
	bool EDGE = false;			/* internal variable */
	int32_t CNT = -1;			/* TIME */
};



#endif /* MAIN_BASICLIB_H_ */
