/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32g4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define button_Pin GPIO_PIN_13
#define button_GPIO_Port GPIOC
#define P1_Pin GPIO_PIN_2
#define P1_GPIO_Port GPIOC
#define P2_Pin GPIO_PIN_3
#define P2_GPIO_Port GPIOC
#define B3_Pin GPIO_PIN_5
#define B3_GPIO_Port GPIOC
#define B2_Pin GPIO_PIN_6
#define B2_GPIO_Port GPIOC
#define B1_Pin GPIO_PIN_8
#define B1_GPIO_Port GPIOC
#define LedR_Pin GPIO_PIN_3
#define LedR_GPIO_Port GPIOB
#define LedY_Pin GPIO_PIN_4
#define LedY_GPIO_Port GPIOB
#define LedG_Pin GPIO_PIN_5
#define LedG_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
