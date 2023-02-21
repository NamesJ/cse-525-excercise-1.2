#include "utils.h"
#include "peripherals/uart.h"
#include "peripherals/gpio.h"

void uart_send ( char c )
{
	while(get32(UART_FR)&(1<<5)); // Transmit FIFO is full
	put32(UART_DR,c);
}

char uart_recv ( void )
{
	while(get32(UART_FR)&(1<<4)); // Receive FIFO is empty
	return get32(UART_DR)&0xFF;
}

void uart_send_string(char* str)
{
	for (int i = 0; str[i] != '\0'; i ++) {
		uart_send((char)str[i]);
	}
}

void uart_init ( void )
{
	unsigned int selector;
	
	selector = get32(GPFSEL1);
	selector &= ~(7<<12);				// clean gpio14
	selector |= (4<<12);				// set alt1 for gpio14 
	selector &= ~(7<<15);				// clean gpio15
	selector |= (4<<15);				// set alt1 for gpio15
	put32(GPFSEL1,selector);

	put32(GPPUD,0);
	delay(150);
	put32(GPPUDCLK0,(1<<14)|(1<<15));
	delay(150);
	put32(GPPUDCLK0,0);
	
	put32(UART_CR,0);						// Disable the UART
	put32(UART_IBRD,26);					// Set integer baud rate divisor for 115200
	put32(UART_FBRD,3);						// Set fractional baud rate divisor for 115200
	put32(UART_LCRH,(1<<4)|(3<<5));			// Enable FIFO (8 bits)
	put32(UART_CR, (1 | (3<<8)));   		// Enable UART for RX and TX
}