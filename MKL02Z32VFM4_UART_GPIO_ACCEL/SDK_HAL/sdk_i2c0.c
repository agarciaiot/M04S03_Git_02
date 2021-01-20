/*! @file : sdk_i2c0.c
 * @author  Alvaro Luis Garcia Romero (Quote)
 * @version 1.0.0
 * @date    18/01/2021
 * @brief   Driver para I2C con ACCEL
 * @details
 *
 */
/*******************************************************************************
 * Includes                                                                    *
 *******************************************************************************/
#include "sdk_i2c0.h"
#include "fsl_i2c.h"

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

status_t I2C0_MasterInit(uint32_t baud_rate) {
	i2c_master_config_t masterConfig;
	uint32_t sourceClock = 0;

	/*!
	 *  Parametros por Defecto para masterConfig, estructura de configuracion
	 *  maestra I2C:
	 * @_paramcode
	 * 		baudRate_Bps = 100000U;
	 * 		enableStopHold = false;
	 * 		glitchFilterWidth = 0U;
	 * 		enableMaster = true;
	 * @end_paramcode
	 */

	I2C_MasterGetDefaultConfig(&masterConfig);
	if (baud_rate < 100000U) {
		masterConfig.baudRate_Bps = baud_rate;
	}

	/*!
	 * @brief Asignacion de la frecuencia de reloj para un nombre de reloj
	 * específico.
	 *
	 * @param I2C0_CLK_SRC Nombre de reloj para I2C en clock_name_t // kCLOCK_BusClk
	 * @return Valor de la frecuencia del reloj en Hertz
	 */

	sourceClock = CLOCK_GetFreq(I2C0_CLK_SRC);

	/*!
	 * @param I2C0 			Apuntador a direccion de instancia I2C0
	 * @param masterConfig 	Apuntador a la estructura de configuracion maestra I2C
	 * @param sourceClock 	Frecuencia de reloj del I2C en Hz
	 */

	I2C_MasterInit(I2C0, &masterConfig, sourceClock);
	return (kStatus_Success);
}

status_t I2C0_MasterReadStatusByte(uint8_t device_address, int8_t register_address, int8_t devide_id) {

	i2c_master_transfer_t masterXfer;
	uint8_t i2c_rx_buffer[1];

	masterXfer.slaveAddress = device_address;
	masterXfer.direction = kI2C_Read;
	masterXfer.subaddress = (uint32_t) register_address;
	masterXfer.subaddressSize = 1;
	masterXfer.data = i2c_rx_buffer;
	masterXfer.dataSize = 1;
	masterXfer.flags = kI2C_TransferDefaultFlag;

	I2C_MasterTransferBlocking(I2C0, &masterXfer);

	if (i2c_rx_buffer[0] == devide_id) {
		return (kStatus_Success);
	} else {
		return (kStatus_Fail);
	}
}
