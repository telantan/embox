#ifndef GEN_BOARD_CONF_H_
#define GEN_BOARD_CONF_H_

#include <stdint.h>
#include <stddef.h>

struct field_int {
	const char *name;
	const char *val;
};

struct field_reg_map {
	const char *name;
	const char *baseaddr;
	const char *len;
};

struct field_pin {
	const char *name;
	const char *port;
	const char *n;
	const char *af;
};

struct device_conf {
	struct field_reg_map regs[16];
	struct field_int irqs[16];
	struct field_pin pins[64];
	struct field_int clocks[16];
};

struct uart_conf {
	const char *name;
	const char *status;
	struct device_conf dev;
	unsigned int baudrate;
};

struct spi_conf {
	const char *name;
	const char *status;
	struct device_conf dev;
	struct field_pin cs[64];
};

struct i2c_conf {
	const char *name;
	const char *status;
	struct device_conf dev;
};

struct eth_conf {
	const char *name;
	const char *status;
	struct device_conf dev;
};

#define ENABLED  "enabled"
#define DISABLED "disabled"

#define MACRO_STRING(...) __MACRO_STRING(__VA_ARGS__)
#define __MACRO_STRING(...) # __VA_ARGS__

#define VAL(_name, _n) \
	{ .name = _name, .val = MACRO_STRING(_n) }

#define REGMAP(_name, _addr, _len) \
	{ .name = _name, .baseaddr = MACRO_STRING(_addr), .len = MACRO_STRING(_len) }

#define PIN(_name, _gpio, _n, _af) \
	{ .name = _name, .port = MACRO_STRING(_gpio), .n = MACRO_STRING(_n), \
		.af = MACRO_STRING(_af) }

#endif /* GEN_BOARD_CONF_H_ */
