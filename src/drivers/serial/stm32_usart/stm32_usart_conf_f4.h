/**
 * @file
 *
 * @data 30.11.2015
 * @author: Anton Bondarev
 */

#ifndef SRC_DRIVERS_SERIAL_STM32_USART_STM32_USART_CONF_F4_H_
#define SRC_DRIVERS_SERIAL_STM32_USART_STM32_USART_CONF_F4_H_

#include "stm32f4xx_hal.h"
#include "stm32f4xx_hal_usart.h"
#include "stm32f4xx_hal_uart.h"

#if defined(STM32F407xx)
#include "stm32f4_discovery.h"
#elif defined (STM32F429xx)
#include "stm32f4xx_nucleo_144.h"
#else
#error Unsupported platform
#endif

#include <assert.h>
#include <framework/mod/options.h>
#include <module/embox/driver/serial/stm_usart_f4.h>

#define MODOPS_USARTX OPTION_GET(NUMBER, usartx)

#define USART6_IRQ    \
	OPTION_MODULE_GET(embox__driver__serial__stm_usart_f4, NUMBER, usart6_irq)
static_assert(USART6_IRQ == USART6_IRQn);

#define USART3_IRQ    \
	OPTION_MODULE_GET(embox__driver__serial__stm_usart_f4, NUMBER, usart3_irq)
static_assert(USART3_IRQ == USART3_IRQn);

#define USART2_IRQ    \
	OPTION_MODULE_GET(embox__driver__serial__stm_usart_f4, NUMBER, usart2_irq)
static_assert(USART2_IRQ == USART2_IRQn);

#if MODOPS_USARTX == 6

#define USARTx                           USART6

/* Definition for USARTx's NVIC */
#define USARTx_IRQn                      USART6_IRQ

#elif MODOPS_USARTX == 2
#define USARTx                           USART2

/* Definition for USARTx's NVIC */
#define USARTx_IRQn                      USART2_IRQ

#elif MODOPS_USARTX == 3
#define USARTx                           USART3

/* Definition for USARTx's NVIC */
#define USARTx_IRQn                      USART3_IRQ

#else
#error Unsupported USARTx
#endif


#define STM32_USART2_ENABLED             1
#define USART2_RX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()
#define USART2_TX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()
#define USART2_TX_PIN                    GPIO_PIN_2
#define USART2_TX_GPIO_PORT              GPIOA
#define USART2_TX_AF                     GPIO_AF7_USART2
#define USART2_RX_PIN                    GPIO_PIN_3
#define USART2_RX_GPIO_PORT              GPIOA
#define USART2_RX_AF                     GPIO_AF7_USART2

#define STM32_USART3_ENABLED             1
#define USART3_RX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOD_CLK_ENABLE()
#define USART3_TX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOD_CLK_ENABLE()
#define USART3_TX_PIN                    GPIO_PIN_8
#define USART3_TX_GPIO_PORT              GPIOD
#define USART3_TX_AF                     GPIO_AF7_USART3
#define USART3_RX_PIN                    GPIO_PIN_9
#define USART3_RX_GPIO_PORT              GPIOD
#define USART3_RX_AF                     GPIO_AF7_USART3

#define STM32_USART6_ENABLED             1
#define USART6_RX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOC_CLK_ENABLE()
#define USART6_TX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOC_CLK_ENABLE()
#define USART6_TX_PIN                    GPIO_PIN_6
#define USART6_TX_GPIO_PORT              GPIOC
#define USART6_TX_AF                     GPIO_AF8_USART6
#define USART6_RX_PIN                    GPIO_PIN_7
#define USART6_RX_GPIO_PORT              GPIOC
#define USART6_RX_AF                     GPIO_AF8_USART6


#define STM32_USART_FLAGS(uart)   uart->SR
#define STM32_USART_RXDATA(uart)  uart->DR
#define STM32_USART_TXDATA(uart)  uart->DR

/* Look at stm32f4xx_hal_uart.h and find ORE */
#define STM32_USART_CLEAR_ORE(uart) \
	do { \
		uint32_t __tmpreg; \
		if (STM32_USART_FLAGS(uart) & USART_SR_ORE) \
			/* Just read RX */ \
			__tmpreg = STM32_USART_RXDATA(uart); \
		(void) __tmpreg; \
	} while (0)

#endif /* SRC_DRIVERS_SERIAL_STM32_USART_STM32_USART_CONF_F4_H_ */
