//To display an 8 bit binary upcounter on LEDs

#include<LPC17xx.h>
unsigned int j;
unsigned long LED;

int main(void){
	
	SystemInit();
	SystemCoreClockUpdate();
	
	LPC_PINCON -> PINSEL0 &= 0xFF0000FF; //Configure port0 pins P0.4-P0.11 as GPIO function
	LPC_GPIO0 -> FIODIR |= 0x00000FF0; //Configure P0.4-P0.11 as output port
	
	while(1){
		for(LED = 0 ; LED < 256 ; LED++){
			LED_GPIO0 -> FIOPIN = LED<<4;
			for(j = 0; j < 50000 ; j++); //Random delay
		}
	}	
}
