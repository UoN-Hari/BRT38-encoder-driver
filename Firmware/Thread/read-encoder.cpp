/*
 * read-encoder.cpp
 *
 *  Created on: May 28, 2022
 *      Author: ssyzz7
 */

/* System defines */
#include <can.h>
#include <main.h>
#include <cmsis_os2.h>

#include "../BSP/CAN/CAN-bsp.h"
#include "../Drivers/BRT38-Encoder/BRT38.h"

/* Extended thread functions*/
extern "C" void os_thread_read_encoder(void* argument);

/* Variables */
namespace Encoder {
	CAN_t *CAN = nullptr;
	BRT38_t encoder;

	uint32_t encoderVal;
}

void os_thread_read_encoder(void* argument) {
	/* Namespace */
	using namespace Encoder;

	/* Initialize */
	CAN = new CAN_t;
	CAN->initFilter();
	delete CAN;

	/* Infinite loop */
	for(;;) {
		encoder.read(&hcan1, encoderVal);
		osDelay(1);
	}
}
