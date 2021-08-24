/*
 * StandardLib.h
 *
 *  Created on: 24.08.2021
 *      Author: FranzHoepfinger
 */

#ifndef MAIN_STANDARDLIB_H_
#define MAIN_STANDARDLIB_H_


int32_t T_PLC_MS(void);


class TON
{
private:
	bool M = false;			/* internal variable */
	int32_t StartTime = 0;	/* internal variable */
public:
	int32_t PT = 0;
	int32_t ET = 0; 		/* elapsed time */
	bool operator()(bool IN);/* is TRUE, PT milliseconds after IN had a rising edge */
};


#endif /* MAIN_STANDARDLIB_H_ */
