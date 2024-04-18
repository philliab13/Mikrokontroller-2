#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>
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

ssize_t _write(int fd, const void *buf, size_t count){
	char * letter = (char *)(buf);
	for(int i = 0; i < count; i++){
		uart_send(*letter);
		letter++;
	}
return count;
}


int main(){
    led_init();
    btn_init();
    uart_init();
	int lightAON=1;
	int lightBON=1;
    for(int i=17; i<21;i++){
		led_off(i);
		lightAON=0;
	}
    
    int sleep = 0;
    char reading = 'C';
    while(1){

		
		
		if (isBtnPressed(13)){
			uart_send('A');
			
		}
	    if (isBtnPressed(14)){
			uart_send('B');
			
		
		}
		reading=uart_read();

		
        
        if(reading == 'A'){
           if(lightAON==0){
			led_on(17);
			lightAON=1;
		   }else{led_off(17); 
		   lightAON=0;}
			
        }else if(reading == 'B'){
            if(lightBON==0){
			led_on(18);
			lightBON=1;
		   }else{led_off(18); 
		   lightBON=0;}
		}

		sleep = 10000;
		while(--sleep);
		iprintf("The average grade in TTK%d was in %d was: %c\n\r",4235,2022,'B');

	}
    return 0;
}