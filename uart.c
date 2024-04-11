#include "Uart.h"


void uart_init(){
    GPIO0->PIN_CNF[5] = 1;
    GPIO0->PIN_CNF[6] = 1;
    GPIO0->PIN_CNF[7] = 0;
    GPIO0->PIN_CNF[8] = 0;
    UART->PSELTXD = 0x06; // 6   8
    UART->PSELRXD = 0x28;
    UART->BAUDRATE = 0x00275000;
    UART->PSELRTS = 0xFFFFFFFF;
    UART->PSELCTS = 0xFFFFFFFF;
    UART->ENABLE = 4;
    UART->TASKS_STARTRX = 1;
}

void uart_send(char letter){
    UART->TASKS_STARTTX = 1;
    UART->TXD = letter;
    while(1){
        if(UART->EVENTS_TXDRDY == 1){
            break;
        }
    }
    UART->EVENTS_TXDRDY = 0;
    UART->TASKS_STOPTX = 1;
    return;
}

char uart_read(){
    //  UART->TASKS_STARTRX = 1;
    if(UART->EVENTS_RXDRDY ==1){
        UART->EVENTS_RXDRDY = 0;
        return UART->RXD ;
    }
    // UART->TASKS_STOPRX = 1;
    return '\0';
}