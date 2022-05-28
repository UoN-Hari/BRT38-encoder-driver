/*
 * BRT38.cpp
 *
 *  Created on: May 28, 2022
 *      Author: ssyzz7
 */
#include <cstring>
#include "./BRT38.h"

BRT38_t::BRT38_t() {}
BRT38_t::~BRT38_t() {}

void BRT38_t::read(CAN_HandleTypeDef *hcan, uint32_t &value) {
	memset(txData, 0x00, sizeof(uint8_t)*8);

	txData[0] = 0x04; //Data length
	txData[1] = ECD_ADDR; //Encoder address
	txData[2] = ECD_READ; //CMD
	CAN.send(hcan, ECD_ID, txData, txData[0]);

	CAN.getRxData(hcan, rxID, rxData, rxLen);
	value = (uint32_t)rxData[3] + ((uint32_t)rxData[4] << 8) +
			((uint32_t)rxData[5] << 16) + ((uint32_t)rxData[6] << 24);
}
