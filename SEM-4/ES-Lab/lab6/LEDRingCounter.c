//To stimulate an 8 bit ring counter with key press

#include<LPC17xx.h>
unsigned int i,j, c = 1;
unsigned long LED;

int main(void){
	SystemInit();
	SystemCoreClockUpdate();
	LPC_PINCON -> PINSEL0 &= 0xFF0000FF; //Configure port0 pins P0.4-P0.11 as GPIO function
	LPC_GPIO0 -> FIODIR |= 0x00000FF0; //Configure P0.4-P0.11 as output port
	LPC_PINCON -> PINSEL4 &= 0xFCFFFFFF; //Configure port2 P2.12 pin as GPIO function
	LPC_GPIO2 -> FIODIR &= 0xFFFFEFFF; //Configure P2.12 as input port
	while(1){
		if(!(LPC_GPIO2 -> FIODIR & 1<<12)){ //switch not pressed
			for(i = 0 ; i < 8 ; i++){
				LPC_GPIO0 -> FIOPIN = c<<4;
				for(j = 0 ; j < 80000 ; j++); //random delay
				c = c << 1;
			}
			c = 1;
		}
	}	
}
