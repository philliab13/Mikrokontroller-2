#include <stdint.h>
#include <stdbool.h>
#include "Uart.h"

void btn_init(){
	GPIO0->PIN_CNF[13]=(3<<2);
	GPIO0->PIN_CNF[14]=(3<<2);
	GPIO0->PIN_CNF[15]=(3<<2);
	GPIO0->PIN_CNF[16]=(3<<2);
}
void led_init(){
	  GPIO0->PIN_CNF[17] = 1;
	  GPIO0->PIN_CNF[18] = 1;
	  GPIO0->PIN_CNF[19] = 1;
	  GPIO0->PIN_CNF[20] = 1;
};

int isBtnPressed(int placement) {
	return (!(GPIO0->IN & (1 << placement)));
}

void led_off(int placement){
	GPIO0->OUTSET |= (1<<placement);
};

void led_on(int placement){
	GPIO0->OUTCLR &= (1<<placement);
};


int main(){
    led_init();
    btn_init();
    uart_init();
    for(int i=17; i<21;i++){
		led_off(i);
	}
    
    int sleep = 0;
    char reading = 'C';
    while(1){
		reading=uart_read();
		if (isBtnPressed(13)){
			uart_send('A');
			reading=uart_read();
			
		}
	    if (isBtnPressed(14)){
			uart_send('B');
			reading=uart_read();
		
		}

        
        if(reading == 'A'){
           led_on(17);
        }else if(reading == 'B'){
           led_on(18);
        }else if (reading=='C')
		{
			led_on(19);
		}else if (reading=='\0')
		{
			led_on(20);
		}
		
		





		sleep = 10000;
		while(--sleep);

	}
    return 0;
}