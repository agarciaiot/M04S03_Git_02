/*! @file : sdk_gpiob.c
 * @author  Alvaro Luis Garcia Romero (Quote)
 * @version 1.0.0
 * @date    17/01/2021
 * @brief   Driver para GPIOB
 * @details
 *
 */
/*******************************************************************************
 * Includes                                                                    *
 *******************************************************************************/
#include "sdk_gpiob.h"
#include "fsl_gpio.h"

/*******************************************************************************
 * Definitions                                                                 *
 *******************************************************************************/

/*******************************************************************************
 * Private Prototypes                                                          *
 *******************************************************************************/

/*******************************************************************************
 * External vars                                                               *
 *******************************************************************************/

/*******************************************************************************
 * Private vars                                                                  *
 *******************************************************************************/

/*******************************************************************************
 * Private Source Code                                                         *
 *******************************************************************************/

/*******************************************************************************
 * Public Source Code                                                          *
 *******************************************************************************/

status_t GPIO_PinStatus(uint8_t *new_char) {
	uint8_t i = 0, j = 0;
	uint8_t status_led;
	uint16_t gpio_pin;
	uint16_t gpio_port;

	for (i = 0; i <= 2; i++) {

		for (j = 0; j <= 1; j++) {

			if (*new_char == RGB_CHAR_LIST[i][j]) {

				if (i == 0) {
					gpio_pin = kPTB6;
					if (j == 0)
						status_led = 0;
					if (j == 1)
						status_led = 1;
				}

				if (i == 1) {
					gpio_pin = kPTB7;
					if (j == 0)
						status_led = 0;
					if (j == 1)
						status_led = 1;
				}

				if (i == 2) {
					gpio_pin = kPTB10;
					if (j == 0)
						status_led = 0;
					if (j == 1)
						status_led = 1;
				}

			}

		}

	}

	gpio_port = gpio_pin & 0xFF00;
	gpio_port >>= 8;

	if ((gpio_pin & 0x00FF) > 0x000F)
		return (kStatus_Fail);

	uint32_t gpio_mask = (uint32_t) (1 << ((uint8_t) gpio_pin));

	switch (gpio_port) {

	case kGPIOA:
		switch (status_led) {
		case 0:
			GPIO_PortClear(GPIOA, gpio_mask);
			break;
		case 1:
			GPIO_PortSet(GPIOA, gpio_mask);
			break;
		default:
			return (kStatus_Fail);
			break;
		}
		break;

	case kGPIOB:
		switch (status_led) {
		case 0:
			GPIO_PortClear(GPIOB, gpio_mask);
			break;
		case 1:
			GPIO_PortSet(GPIOB, gpio_mask);
			break;
		default:
			return (kStatus_Fail);
			break;
		}
		break;

	default:
		return (kStatus_Fail);
		break;

	}
	return (kStatus_Success);
}
