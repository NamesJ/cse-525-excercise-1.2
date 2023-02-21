#ifndef _P_UART_H
#define _P_UART_H

#include "peripherals/base.h"

#define	UART_DR			(PBASE+0x201000)	// Data register
#define UART_FR			(PBASE+0x201018)	// Flag register
#define UART_IBRD		(PBASE+0x201024)	// Integer Baud rate divisor
#define UART_FBRD		(PBASE+0x201028)	// Fractional Baud rate divisor
#define UART_LCRH		(PBASE+0x20102C)	// Line Control register
#define UART_CR			(PBASE+0x201030)	// Control register

#endif /* _P_UART_H */