#pragma once

#include <stdint.h>
#include <stdbool.h>


#define UART ((NRF_UART_REG*)0x40002000)

typedef struct{
    volatile uint32_t TASKS_STARTRX;
	volatile uint32_t TASKS_STOPRX;
	volatile uint32_t TASKS_STARTTX;
	volatile uint32_t TASKS_STOPTX;
    volatile uint32_t RESERVED0[3];

	volatile uint32_t TASKS_SUSPEND;
    volatile uint32_t RESERVED1[56];

	volatile uint32_t EVENTS_CTS;
	volatile uint32_t EVENTS_NCTS;
	volatile uint32_t EVENTS_RXDRDY;
    volatile uint32_t RESERVED2[4];

	volatile uint32_t EVENTS_TXDRDY;
    volatile uint32_t RESERVED3[1];

	volatile uint32_t EVENTS_ERROR;
    volatile uint32_t RESERVED4[7];

	volatile uint32_t EVENTS_RXTO;
    volatile uint32_t RESERVED5[46];

    volatile uint32_t SHORTS;
    volatile uint32_t RESERVED6[64];

	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
    volatile uint32_t RESERVED7[93];

	volatile uint32_t ERRORSRC;
    volatile uint32_t RESERVED8[31];

	volatile uint32_t ENABLE;
    volatile uint32_t RESERVED9[1];

	volatile uint32_t PSELRTS;
	volatile uint32_t PSELTXD;
	volatile uint32_t PSELCTS;
	volatile uint32_t PSELRXD;
	volatile uint32_t RXD;
	volatile uint32_t TXD;
    volatile uint32_t RESERVED10[1];

    volatile uint32_t BAUDRATE;
    volatile uint32_t RESERVED11[17];

	volatile uint32_t CONFIG;
} NRF_UART_REG;






#define GPIO0 ((NRF_GPIO_REGS0*)0x50000000)


typedef struct {
	volatile uint32_t RESERVED0[321];
	volatile uint32_t OUT;
	volatile uint32_t OUTSET;
	volatile uint32_t OUTCLR;
	volatile uint32_t IN;
	volatile uint32_t DIR;
	volatile uint32_t DIRSET;
	volatile uint32_t DIRCLR;
	volatile uint32_t LATCH;
	volatile uint32_t DETECTMODE;
	volatile uint32_t RESERVED1[118];
	volatile uint32_t PIN_CNF[32];
} NRF_GPIO_REGS0;



void uart_init();
void uart_send(char letter);
char uart_read();