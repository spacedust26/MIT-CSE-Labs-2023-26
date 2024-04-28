//To stimulate a 4 digit BCD up counter on the multiplexed seven segment display

#include<LPC17xx.h>
#include<stdio.h>

unsigned char dec[10] = {0x3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7D, 0X07, 0X7F, 0X6F};
long int arr[4] = {0, 0, 0, 0};
unsigned int i,j;

void delay(unsigned int milliseconds){
	LPC_TIM0->CTCR = 0x0; // timer mode
	LPC_TIM0->PR = 2; // tc incremets after every 3 cc
	LPC_TIM0->TCR = 0x02; // reset timer
	LPC_TIM0->TCR = 0x01; // enable timer
	while(LPC_TIM0->TC < milliseconds);//wait 
	LPC_TIM0->TCR = 0x00; // disable timer
}

int main(void){
	LPC_GPIO0 -> FIODIR |= 0XFF0; //P0.4-P0.11 as output pin
	LPC_GPIO1 -> FIODIR |= 0XF<<23; // P1.23-P1.26 as output pin
	
	while(1){
		for(arr[3]=0; arr[3]<10; arr[3]++){
			for(arr[2]=0; arr[2]<10; arr[2]++){
				for(arr[1]=0; arr[1]<10; arr[1]++){
					for(arr[0]=0; arr[0]<10 ; arr[0]++){
						for(i=0 ; i<4 ;i++){
							LPC_GPIO1->FIOPIN = i<<23;
							LPC_GPIO0->FIOPIN = dec[arr[i]]<<4;
							delay(1000);
						}
						delay(1000);
						LPC_GPIO0->FIOCLR |= 0xFF0;
					}
				}
			}
		}
	}
}

void delay(void){
	for(j=0; j<50000; j++);
}