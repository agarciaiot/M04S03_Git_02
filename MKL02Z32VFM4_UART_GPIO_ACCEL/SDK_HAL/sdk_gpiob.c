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
	uint8_t i = 0;
	uint8_t j_s = sizeof(RGB_CHAR_LIST) - 1;
	uint8_t status_pin;
	uint16_t gpio_pin;
	uint16_t gpio_port;

	/* @ConditionalLoop Codificacion GPIO Pin y Status */
	for (i = 0; i <= j_s; i++) {

		/* @ConditionalPin  Codificacion de GPIO Pin */
		if (*new_char == RGB_CHAR_LIST[i]) {

			/* @ConditionalPinStatusR GPIO Pin PTB6 (Led Red) */
			if (i == 0 || i == 1) {
				gpio_pin = kPTB6; /*!< KL02 pin-1 in QFN pinout diagram */
				if (i == 0)
					status_pin = 0;
				if (i == 1)
					status_pin = 1;
			} /* @EndConditionalPinStatusR */

			/* @ConditionalPinStatusG GPIO Pin PTB6 (Led Red) */
			if (i == 2 || i == 3) {
				gpio_pin = kPTB7; /*!< KL02 pin-2 in QFN pinout diagram */
				if (i == 2)
					status_pin = 0;
				if (i == 3)
					status_pin = 1;
			} /* @EndConditionalPinStatusG */

			/* @ConditionalPinStatusB GPIO Pin PTB6 (Led Red) */
			if (i == 4 || i == 5) {
				gpio_pin = kPTB10; /*!< KL02 pin-13 in QFN pinout diagram */
				if (i == 4)
					status_pin = 0;
				if (i == 5)
					status_pin = 1;
			} /* @EndConditionalPinStatusB */

		} /* @EndConditionalPin */

	} /* @EndConditionalLoop */

	/* Tomar los 8 bits MS del gpio_pin para asignar el codigo GPIO Port */
	gpio_port = gpio_pin & 0xFF00;
	gpio_port >>= 8; /*!< GPIO(Port) <- 0x0000 (Port A) o <- 0x0001 (Port B) */

	/* Solo disponible para rango de pines de (0 a 31) por Puerto */
	if ((gpio_pin & 0x00FF) > 0x001F)
		return (kStatus_Fail);

	/* Mascara para la funcion de estado Set o Clear */
	uint32_t gpio_mask = (uint32_t) (1 << ((uint8_t) gpio_pin));

	switch (gpio_port) {

	/* @CaseA Asignacion de Puerto A y Mascara al Pin seleccionado */
	case kGPIOA:
		/* @CaseA_Exe Ejecucion segun Pin Status, Clear (0) o Set (1)*/
		switch (status_pin) {
		case 0:
			GPIO_PortClear(GPIOA, gpio_mask);
			break;
		case 1:
			GPIO_PortSet(GPIOA, gpio_mask);
			break;
		default:
			return (kStatus_Fail);
			break;
		} /* @EndCaseA_Exe */
		break; /* @EndCaseA */

		/* @CaseB Asignacion de Puerto A y Mascara al Pin seleccionado */
	case kGPIOB:
		/* @CaseB_Exe Ejecucion segun Pin Status, Clear (0) o Set (1)*/
		switch (status_pin) {
		case 0:
			GPIO_PortClear(GPIOB, gpio_mask);
			break;
		case 1:
			GPIO_PortSet(GPIOB, gpio_mask);
			break;
		default:
			return (kStatus_Fail);
			break;
		} /* @EndCaseB_Exe */
		break; /* @EndCaseB */

	default:
		return (kStatus_Fail);
		break;

	}
	return (kStatus_Success);
}
