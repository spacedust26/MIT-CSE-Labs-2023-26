//To read a key and display an 8 bit up/down counter on the LEDs

#include<LPC17xx.h>
unsigned int j;
unsigned long LED;

int main(void){	
	SystemInit();
	SystemCoreClockUpdate();	
	LPC_PINCON -> PINSEL0 &= 0xFF0000FF; //P0.4-P0.11 as GPIO function
	LPC_GPIO0 -> FIODIR |= 0x00000FF0; //P0.4-P0.11 as output port
	LPC_PINCON -> PINSEL4 &= 0xFCFFFFFF; //P2.12 pin as GPIO function
	LPC_GPIO2 -> FIODIR &= 0xFFFFEFFF; //Configure P2.12 as input port	
	while(1){		
		if(LPC_GPIO2 -> FIODIR & 1<<12){ //switch not pressed = 1
			for(LED = 255 ; LED >= 0 ; LED--){
				LED_GPIO0 -> FIOPIN = LED<<4;
				for(int j = 0 ; j < 50000 ; j++); //Random delay
			}
		}else{ //switch pressed = 0
			for(LED = 0 ; LED < 256 ; LED++){
				LED_GPIO0 -> FIOPIN = LED<<4;
				for(j = 0; j < 50000 ; j++); //Random delay
			}
		}		
	}	
}
