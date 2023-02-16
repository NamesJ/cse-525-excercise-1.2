#include "utils.h"
#include "peripherals/uart.h"
#include "peripherals/gpio.h"

void uart_send ( char c )
{
	while(1) {
		//if(get32(AUX_MU_LSR_REG)&0x20) 
		if(get32(UART_FR&0x80))
			break;
	}
	//put32(AUX_MU_IO_REG,c);
	put32(UART_DR&0x000F,c);
}

char uart_recv ( void )
{
	while(1) {
		//if(get32(AUX_MU_LSR_REG)&0x01) 
		if(get32(UART_FR&0x20))
			break;
	}
	//return(get32(AUX_MU_IO_REG)&0xFF);
	get32(UART_DR&0x000F);
}

void uart_send_string(char* str)
{
	for (int i = 0; str[i] != '\0'; i ++) {
		uart_send((char)str[i]);
	}
}

void uart_init ( void )
{
	/*
	unsigned int selector;
	selector = get32(GPFSEL1);
	selector &= ~(7<<12);                   // clean gpio14
	selector |= 2<<12;                      // set alt5 for gpio14
	selector &= ~(7<<15);                   // clean gpio15
	selector |= 2<<15;                      // set alt5 for gpio15
	put32(GPFSEL1,selector);
	*/
	put32(GPPUD,0);
	delay(150);
	put32(GPPUDCLK0,(1<<14)|(1<<15));
	delay(150);
	put32(GPPUDCLK0,0);
	/*
	put32(AUX_ENABLES,1);                   //Enable mini uart (this also enables access to its registers)
	put32(AUX_MU_CNTL_REG,0);               //Disable auto flow control and disable receiver and transmitter (for now)
	put32(AUX_MU_IER_REG,0);                //Disable receive and transmit interrupts
	put32(AUX_MU_LCR_REG,3);                //Enable 8 bit mode
	put32(AUX_MU_MCR_REG,0);                //Set RTS line to be always high
	put32(AUX_MU_BAUD_REG,3254);             //Set baud rate to 9600

	put32(AUX_MU_CNTL_REG,3);               //Finally, enable transmitter and receiver
	*/
	// Disable the UART
	put32(UART_CR,0);
	// Wait for the end of transmission or reception of the current character
	//?
	// Flush the transmit FIFO by setting the FEN bit to 0 in Line Control Register, UART_LCRH
	put32(UART_LCRH,0x60);
	// Reprogram the Control Register, UART_CR
	put32(UART_CR,0x4300);
	// Enable the UART
	put32(UART_CR,0x4301);
	
	// Set the baud rate
	put32(UART_IBRD, 30&0xFFFF);
	put32(UART_FBRD, 0&0x3F);
}