//To display the number 1234 serially in the seven segment display

#include<LPC17xx.h>
#include<stdio.h>
void delay(void);
void display(void);

unsigned char dec[10] = {0x3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7D, 0X07, 0X7F, 0X6F};
unsigned int dig_value[4] = {1,2,3,4};
unsigned int dig_count = 0;
unsigned int dig_select[4] = {3<<23, 2<<23, 1<<23, 0<<23};
unsigned int i;

int main(void){
	LPC_GPIO0 -> FIODIR |= 0XFF<<4; //P0.4-P0.11 as output pin
	LPC_GPIO1 -> FIODIR |= 0XF<<23; // P1.23-P1.26 as output pin
	while(1){
		delay();
		display();
		dig_count += 1;
		if(dig_count == 4) dig_count = 0;
	}
}

void display(void){
	LPC_GPIO1 -> FIOPIN = dig_select[dig_count];
	LPC_GPIO0 -> FIOPIN = dec[dig_value[dig_count]] << 4;
}

void delay(void){
	for(i=0; i<50000; i++);//random delay
}