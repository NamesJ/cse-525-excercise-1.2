#ifndef _P_UART_H
#define _P_UART_H

#include "peripherals/base.h"
#define PL011_UART_BASE	0x7E201000
#define	UART_DR			(PL011_UART_BASE+0x0)	/* Data register */
#define UART_FR			(PL011_UART_BASE+0x18)	/* Flag register */
#define UART_IBRD		(PL011_UART_BASE+0x24)	/* Integer Baud rate divisor */
#define UART_FBRD		(PL011_UART_BASE+0x28)	/* Fractional Baud rate divisor */
#define UART_LCRH		(PL011_UART_BASE+0x2C)	/* Line Control register */
#define UART_CR			(PL011_UART_BASE+0x30)	/* Control register */
#define UART_IFLS		(PL011_UART_BASE+0x34)	/* Interupt FIFO Level Select register */
#define UART_IMSC		(PL011_UART_BASE+0x38)	/* Interupt Mask Set Clear register */
#define UART_RIS		(PL011_UART_BASE+0x3C)	/* Raw Interupt Status Register */
#define UART_ICR		(PL011_UART_BASE+0x44)	/* Interupt Clear Register */

#endif /* _P_UART_H */