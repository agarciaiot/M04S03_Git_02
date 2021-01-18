/*
 * Copyright 2016-2021 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file    MKL02Z32VFM4_UART_GPIO_ACCEL.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL02Z4.h"
#include "fsl_debug_console.h"

/* TODO: insert other include files here. */
#include "sdk_uart0.h"
#include "sdk_gpiob.h"

/* TODO: insert other definitions and declarations here. */

/*
 * @brief   Application entry point.
 */
int main(void) {

	/* Init board hardware. */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
	/* Init FSL debug console. */
	BOARD_InitDebugConsole();
#endif

	/* Init UART0 to Set Baudrate. */
	(void) UART0_SetUp(115200); /*!< 115200 Bps */

	PRINTF("Use el teclado para controlar el Estado de los LEDs RGB\r\n");
	PRINTF("Para el Led Rojo (Red) presione:\r\n");
	PRINTF("(R) para Encender o (r) para Apagar\r\n");
	PRINTF("Para el Led Green (Verde) presione:\r\n");
	PRINTF("(G) para Encender o (g) para Apagar\r\n");
	PRINTF("Para el Led Blue (Azul) presione:\r\n");
	PRINTF("(B) para Encender o (b) para Apagar\r\n");
	PRINTF("\r\n");

	while (1) {
		status_t status;
		uint8_t new_byte_uart0;
		if (UART0_NewDataOnBuffer() > 0) {
			status = UART0_ReadByteCircularBuffer(&new_byte_uart0);
			if (status == kStatus_Success) {
				printf("Dato: %c\r\n", new_byte_uart0);
				/* PUBLIC FUCNTION Led Status*/
				GPIO_PinStatus(&new_byte_uart0);
			}
		}
	}
	return 0;
}
