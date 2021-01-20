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

/*  SDK_HAL Included Files */
#include "sdk_uart0.h"
#include "sdk_gpiob.h"
#include "sdk_i2c0.h"

/*******************************************************************************
 * Definitions                                                                 *
 *******************************************************************************/

/* UART e I2C Clock */
#define UART_BAUDRATE	115200U
#define I2C_BAUDRATE	100000U

/* MMA8451, direccion de registro para acceso por I2C. */
#define I2C_DEVICE_ADDRESS 		0x1D
/* MMA8451, ID registrado en a direccion de memoria */
#define DEVICE_ID				0x1A
/* MMA8451, direccion de resgistro del Device ID. */
#define WHO_AM_I 				0x0D

/* CharacterArray: Condicionales para Led RGB (GPIOB) y ACCEL (GPIOA e I2C) */
#define CHAR_LIST	"R" "r" "G" "g" "B" "b" "M" "m" "X" "x" "Y" "y" "Z" "z"

/*
 * @brief   Application entry point.
 */
int main(void) {

	uint8_t i = 0;
	uint8_t size_char_list = sizeof(CHAR_LIST);

	status_t status_uart0;
	status_t status_i2c0;
	uint8_t new_byte_uart0;

	/* Init board hardware. */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
	/* Init FSL debug console. */
	BOARD_InitDebugConsole();
#endif

	/* Inicializar UART0 al Baudrate indicado */
	(void) UART0_SetUp(UART_BAUDRATE); /*!< 115200 Bps */

	/* Inicializar I2C0 al Baudrate indicado */
	(void) I2C0_MasterInit(I2C_BAUDRATE); /*!< 100000 Bps */


	PRINTF("Use el teclado para:\r\n");
	PRINTF("Control de estado de los LEDs RGB\r\n");
	PRINTF("	Para el Led Rojo (Red) presione:\r\n");
	PRINTF("	(R) para Encender o (r) para Apagar\r\n");
	PRINTF("	Para el Led Green (Verde) presione:\r\n");
	PRINTF("	(G) para Encender o (g) para Apagar\r\n");
	PRINTF("	Para el Led Blue (Azul) presione:\r\n");
	PRINTF("	(B) para Encender o (b) para Apagar\r\n");
	PRINTF("Lectura del Dispositivo Acelerometro\r\n");
	PRINTF("	Para saber si esta disponible presione:\r\n");
	PRINTF("	(M)  o  (m) \r\n");
	PRINTF("	Conocer el valor en g de los ejes:\r\n");
	PRINTF("	X, presione (X)  o  (x) \r\n");
	PRINTF("	Y, presione (Y)  o  (y) \r\n");
	PRINTF("	Z, presione (Z)  o  (z) \r\n");
	PRINTF("\r\n");

	while (1) {

		if (UART0_NewDataOnBuffer() > 0) {

			status_uart0 = UART0_ReadByteCircularBuffer(&new_byte_uart0);

			status_i2c0 = I2C0_MasterReadStatusByte(I2C_DEVICE_ADDRESS,
			WHO_AM_I, DEVICE_ID);

			if (status_uart0 == kStatus_Success) {

				printf("Dato: %c\r\n", new_byte_uart0);

				for (i = 0; i < size_char_list; i++) {
					if (new_byte_uart0 == CHAR_LIST[i]) {
						if (i == 0 || i == 2 || i == 4) {
							GPIO_PinStatus(&new_byte_uart0,
									(uint8_t*) CHAR_LIST, 0);
						}
						if (i == 1 || i == 3 || i == 5) {
							GPIO_PinStatus(&new_byte_uart0,
									(uint8_t*) CHAR_LIST, 1);
						}
						if (i == 6 || i == 7) {
							if (status_i2c0 == kStatus_Success) {
								printf("MMA8451Q Encontrado!\r\n");
							} else {
								printf("MMA8451Q Error!\r\n");
							}

						}

					}

				}

			}

		}

	}

	return 0;

}
