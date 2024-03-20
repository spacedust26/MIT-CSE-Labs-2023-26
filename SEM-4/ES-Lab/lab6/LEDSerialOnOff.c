//Program to turn on/off the LEDs serially

#include<LPC17xx.h>
unsigned int i,j;
unsigned long LED;

int main(void){
  SystemInit();
  SystemCoreClockUpdate();
	LPC_PINCON->PINSEL0 &= 0xFF0000FF; //P0.4-P0.11 as GPIO function
  LPC_GPIO->FIODIR |= 0X00000FF0; //P0.4-P0.11 as output port
		while(1){
		LED = 0x00000010; //Initial value on LED
		for(i = 1; i < 9; i++){
			LPC_GPIO0->FIOSET = LED; //Turn ON LED at LSB(P0.4)
			for(j = 0; j < 10000; j++); //Random delay
			LED <<= 1; //Shift the LED to the left by one unit
		}//loop for 8 times
		LED = 0x00000010;
		for(i = 1; i < 9; i++){
			LPC_GPIO0->FIOCLR = LED; //Turn OFF LED at LSB(P0.4)
			for(j = 0; j < 10000; j++);
			LED <<= 1;
		}
	}
}
