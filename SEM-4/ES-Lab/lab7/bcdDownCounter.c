//To stimulate a 4 digit BCD down counter on the multiplexed seven segment display

#include<LPC17xx.h>
#include<stdio.h>

unsigned char dec[10] = {0x3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7D, 0X07, 0X7F, 0X6F};
long int arr[4] = {9, 9, 9, 9};
unsigned int i,j;

int main(void){
	LPC_GPIO0 -> FIODIR |= 0XFF0; //P0.4-P0.11 as output pin
	LPC_GPIO1 -> FIODIR |= 0XF<<23; // P1.23-P1.26 as output pin
		while(1){
		for(arr[3]=9; arr[3]>=0; arr[3]--){
			for(arr[2]=9; arr[2]>=0; arr[2]--){
				for(arr[1]=9; arr[1]>=0; arr[1]--){
					for(arr[0]=9; arr[0]>=0 ; arr[0]--){
						for(i=0 ; i<4 ;i++){
							LPC_GPIO1->FIOPIN = i<<23;
							LPC_GPIO0->FIOPIN = dec[arr[i]]<<4;
							delay();
						}
						delay();
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