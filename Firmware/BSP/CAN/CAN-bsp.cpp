/*
 * CAN-bsp.cpp
 *
 *  Created on: May 28, 2022
 *      Author: ssyzz7
 */

/* System includes */
#include <cstring>

/* User includes */
#include "./CAN-bsp.h"

/* Local variable define*/
static CAN_RxHeaderTypeDef canRxHeader;
static CAN_HandleTypeDef canRxHandle;
static uint8_t rxData[8];

/* Default constructor and destroctor */
CAN_t::CAN_t() {}
CAN_t::~CAN_t() {}

/* Function implementation */
void CAN_t::send(CAN_HandleTypeDef *hcan, uint32_t STD_ID, uint8_t* data, uint8_t len) {
	CAN_TxHeaderTypeDef canTxHeader;
	uint32_t txMailbox;

	canTxHeader.StdId = STD_ID;
	canTxHeader.DLC = len;
	canTxHeader.IDE = CAN_ID_STD;
	canTxHeader.RTR = CAN_RTR_DATA;

	HAL_CAN_AddTxMessage(hcan, &canTxHeader, data, &txMailbox);
}

void CAN_t::getRxData(CAN_HandleTypeDef *hcan, uint32_t &STD_ID, uint8_t* data, uint8_t &len) {
	hcan = &canRxHandle;
	STD_ID = canRxHeader.StdId;
	len = canRxHeader.DLC;

	memcpy(data, rxData, sizeof(uint8_t)*len);
}

void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan) {
	HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &canRxHeader, rxData);
	canRxHandle = *hcan;
}

void CAN_t::initFilter() {
    CAN_FilterTypeDef can_filter_st;
    can_filter_st.FilterActivation = ENABLE;
    can_filter_st.FilterMode = CAN_FILTERMODE_IDMASK;
    can_filter_st.FilterScale = CAN_FILTERSCALE_32BIT;
    can_filter_st.FilterIdHigh = 0x0000;
    can_filter_st.FilterIdLow = 0x0000;
    can_filter_st.FilterMaskIdHigh = 0x0000;
    can_filter_st.FilterMaskIdLow = 0x0000;
    can_filter_st.FilterBank = 0;
    can_filter_st.FilterFIFOAssignment = CAN_RX_FIFO0;
    HAL_CAN_ConfigFilter(&hcan1, &can_filter_st);
    HAL_CAN_Start(&hcan1);
    HAL_CAN_ActivateNotification(&hcan1, CAN_IT_RX_FIFO0_MSG_PENDING);


    can_filter_st.SlaveStartFilterBank = 14;
    can_filter_st.FilterBank = 14;
//    HAL_CAN_ConfigFilter(&hcan2, &can_filter_st);
//    HAL_CAN_Start(&hcan2);
//    HAL_CAN_ActivateNotification(&hcan2, CAN_IT_RX_FIFO0_MSG_PENDING);
}

