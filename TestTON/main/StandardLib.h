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

/**
 * \brief
	Timer on delay.
	Q is TRUE, PT milliseconds after IN had a rising edge.
 *
 * \param	IN starts timer with rising edge, resets timer with falling edge
 * \param   PT time to pass, before Q is set
 * \return	Q is TRUE, PT milliseconds after IN had a rising edge.
 *
 */
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

/**
 * \brief
	Timer of delay.
	Q is FALSE, PT milliseconds after IN had a falling edge.
 *
 * \param	IN starts timer with rising edge, resets timer with falling edge
 * \param   PT time to pass, before Q is set
 * \return	Q is FALSE, PT seconds after IN had a falling edge
 *
 */
class TOF
{
public:
	//VAR_INPUT
	int32_t PT = 0;
	//VAR_OUTPUT
	bool Q;					/* Q is FALSE, PT milliseconds after IN had a falling edge */
	int32_t ET = 0; 		/* elapsed time */
	//call
	bool operator()(bool IN);/* Q is FALSE, PT milliseconds after IN had a falling edge */
private:
	bool M = false;			/* internal variable */
	int32_t StartTime = 0;	/* internal variable */
};


/**
 * \brief
	Timer of delay.
	Q is FALSE, PT milliseconds after IN had a falling edge.


TOF_1 will extend a pulse on input in for PT seconds.
in addition the timer can be cleared asynchronously with rst.
TOF_1 is the same function as TOF from the standard LIB except the asynchronous reset input.

 *
 * \param	IN starts timer with rising edge, resets timer with falling edge
 * \param   PT time to pass, before Q is set
 * \return	Q is FALSE, PT seconds after IN had a falling edge
 *
 */
class TOF_1
{
public:
	//VAR_INPUT
	int32_t PT = 0;
	bool RST = false;
	//VAR_OUTPUT
	bool Q;					/* Q is FALSE, PT milliseconds after IN had a falling edge */
	int32_t ET = 0; 		/* elapsed time */
	//call
	bool operator()(bool IN);/* Q is FALSE, PT milliseconds after IN had a falling edge */
private:
	bool M = false;			/* internal variable */
	int32_t StartTime = 0;	/* internal variable */
};



#endif /* MAIN_STANDARDLIB_H_ */
