/*
 * ExtraLib.h
 *
 *  Created on: 25.08.2021
 *      Author: FranzHoepfinger
 */

#ifndef MAIN_EXTRALIB_H_
#define MAIN_EXTRALIB_H_


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
class DBP
{
public:
	//VAR_INPUT
	int32_t PT = 0;
	//VAR_OUTPUT
	bool Q = false;					/* Q is FALSE, PT milliseconds after IN had a falling edge */
	int32_t ET = 0; 		/* elapsed time */
	//call
	bool operator()(bool IN);/* Q is FALSE, PT milliseconds after IN had a falling edge */
private:
	bool M = false;			/* internal variable */
	int32_t StartTime = 0;	/* internal variable */
};


#endif /* MAIN_EXTRALIB_H_ */
