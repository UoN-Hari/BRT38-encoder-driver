/*
 * BRT38.h
 *
 *  Created on: May 28, 2022
 *      Author: ssyzz7
 */

#ifndef DRIVERS_BRT38_ENCODER_BRT38_H_
#define DRIVERS_BRT38_ENCODER_BRT38_H_

/* System includes */
#include <main.h>

/* User includes */
#include "../../BSP/CAN/CAN-bsp.h"

#define ECD_ID 0x01
#define ECD_ADDR 0x01

#define ECD_READ 0x01

class BRT38_t {
private:
	/* Variables */
	CAN_t CAN;
	uint8_t txData[8];
	uint8_t rxData[8];
	uint32_t rxID;
	uint8_t rxLen;

public:
	BRT38_t();
	~BRT38_t();

	void read(CAN_HandleTypeDef *hcan, uint32_t &value);
};


#endif /* DRIVERS_BRT38_ENCODER_BRT38_H_ */
