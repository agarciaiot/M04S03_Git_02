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
 * @param baud_rate   Configuration de velocidad en Baudios para I2C
 * @return            Resultado de la ejecución
 * @code
 * 		kStatus_Success
 * 		kStatus_Fail
 * @endcode
 */
status_t I2C0_MasterInit(uint32_t baud_rate);


/** @} */ // end of I2C group

/** @} */ // end of SDK_HAL group

#endif /* SDK_I2C0_H_ */
