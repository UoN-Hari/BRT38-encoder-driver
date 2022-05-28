/*
 * CAN-bsp.h
 *
 *  Created on: May 28, 2022
 *      Author: ssyzz7
 */

#ifndef BSP_CAN_CAN_BSP_H_
#define BSP_CAN_CAN_BSP_H_

/* System defines */
#include <can.h>
#include <main.h>

/* User defines */
#include "../../typedefs/struct_typedef.h"

class CAN_t {
private:
	/* Variables */
public:
	/* Default constructor and destroctor */
	CAN_t();
	~CAN_t();

	/* Function declaration */
	void send(CAN_HandleTypeDef *hcan, uint32_t STD_ID, uint8_t* data, uint8_t len);
	void getRxData(CAN_HandleTypeDef *hcan, uint32_t &STD_ID, uint8_t* data, uint8_t &len);
	void initFilter();
};

extern "C" void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan);

#endif /* BSP_CAN_CAN_BSP_H_ */
