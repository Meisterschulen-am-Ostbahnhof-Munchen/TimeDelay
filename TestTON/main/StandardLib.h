/*
 * StandardLib.h
 *
 *  Created on: 24.08.2021
 *      Author: FranzHoepfinger
 */

#ifndef MAIN_STANDARDLIB_H_
#define MAIN_STANDARDLIB_H_


int32_t T_PLC_MS(void);



/**
 * Falling Edge detection.
 */
class F_TRIG
{
public:
	//VAR_OUTPUT
	bool Q;					/* Edge detected */
	//call
	bool operator()(bool CLK); /* is TRUE if falling Edge detection. */
private:
	bool M = false;			/* internal variable */
};

/**
 * Rising Edge detection.
 */
class R_TRIG
{
public:
	//VAR_OUTPUT
	bool Q;					/* Edge detected */
	//call
	bool operator()(bool CLK); /* is TRUE if rising Edge detection. */
private:
	bool M = false;			/* internal variable */
};


class TON
{
public:
	//VAR_INPUT
	int32_t PT = 0;
	//VAR_OUTPUT
	bool Q;					/* is TRUE, PT milliseconds after IN had a rising edge */
	int32_t ET = 0; 		/* elapsed time */
	//call
	bool operator()(bool IN);/* is TRUE, PT milliseconds after IN had a rising edge */
private:
	bool M = false;			/* internal variable */
	int32_t StartTime = 0;	/* internal variable */
};


#endif /* MAIN_STANDARDLIB_H_ */
