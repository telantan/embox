#include <gen_board_conf.h>
#include <stm32.h>

const struct uart_conf uarts[] = {
	{
		.status = DISABLED,
		.name = "USART2",
		.dev = {
			.irqs = {
				VAL("", 38),
			},
			.pins = {
				PIN("TX", PA, PIN_2, AF7),
				PIN("RX", PA, PIN_3, AF7),
			},
			.clocks = {
				VAL("TX",   CLK_GPIOA),
				VAL("RX",   CLK_GPIOA),
				VAL("UART", CLK_USART2),
			}
		},
		.baudrate = 115200,
	},
	{
		.status = ENABLED,
		.name = "USART6",
		.dev = {
			.irqs = {
				VAL("", 71),
			},
			.pins = {
				PIN("TX", PC, PIN_6, AF8),
				PIN("RX", PC, PIN_7, AF8),
			},
			.clocks = {
				VAL("TX",   CLK_GPIOC),
				VAL("RX",   CLK_GPIOC),
				VAL("UART", CLK_USART6),
			}
		},
		.baudrate = 115200,
	},
};
