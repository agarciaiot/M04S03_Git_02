/*! @file : sdk_i2c0.h
 * @author  Alvaro Luis Garcia Romero (Quote)
 * @version 1.0.0
 * @date    18/01/2021
 * @brief   Driver para I2C con ACCEL
 * @details
 *
 */
#ifndef SDK_I2C0_H_
#define SDK_I2C0_H_
/*******************************************************************************
 * Includes                                                                    *
 *******************************************************************************/
#include "fsl_common.h"

/*!
 * @addtogroup SDK_HAL
 * @{
 */
/*!
 * @addtogroup I2C
 * @{
 */
/*******************************************************************************
 * Public Definitions                                                          *
 *******************************************************************************/

/*!
 * @brief Lista de direcciones de memoria para lectura de posición ACCEL
 */
enum _i2c_addresst_list_out_data {
	kXMSB = 0x01, /* !< OUT X MSB */
	kXLSB, /* !< OUT X LSB */
	kYMSB, /* !< OUT Y MSB */
	kYLSB, /* !< OUT Y LSB */
	kZMSB, /* !< OUT Z MSB */
	kZLSB, /* !< OUT > LSB */
};

/*******************************************************************************
 * External vars                                                               *
 *******************************************************************************/

/*******************************************************************************
 * Public vars                                                                 *
 *******************************************************************************/

/*******************************************************************************
 * Public Prototypes                                                           *
 *******************************************************************************/

/*!
 * @brief Inicializa I2C0 a la velocidad en baudios (Bps) indicada
 *
 * @param baud_rate   		Configuration de velocidad en Baudios para I2C
 *
 * @return            		Resultado de la ejecución
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t I2C0_MasterInit(uint32_t baud_rate);

/*!
 * @brief Lee un byte con el Device ID del ACCEL para indicar que esta disponible
 *
 * @param device_address	Dato en Hex de dirección en bus I2C para el dispositivo a leer
 *
 * @param register_address	Dato en Hex de dirección de memoria en el dispositivo a leer
 *
 * @param device_id			Dato en Hex almacenado en la dirección de memoria en el dispositivo
 *
 * @return            		Resultado de la ejecución
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t I2C0_MasterReadStatusByte(uint8_t device_address, int8_t register_address, int8_t devide_id);



status_t I2C0_MasterReadValue(uint8_t *i2c_char, uint8_t *i2c_char_list,
		uint8_t *data, uint8_t device_address, uint32_t *memory_address);


//status_t I2C0_ReadAccelValue(uint8_t device_address, uint8_t *rxBuff);

/** @} */ // end of I2C group
/** @} */// end of SDK_HAL group
#endif /* SDK_I2C0_H_ */
