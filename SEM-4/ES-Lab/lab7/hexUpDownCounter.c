//4 digit up/down counter on seven segment using a switch and a timer delay of 1 second between each count

#include<LPC17xx.h>
#include<stdio.h>

unsigned char dec[16] = {0x3F, 0X06, 0X5B, 0X4F, 0X66, 0X6D, 0X7D, 0X07, 0X7F, 0X6F, 0x77, 0x7C, 0X39, 0X5E, 0X79, 0X71};
long int arr[4] = {0, 0, 0, 0};
unsigned int i,j;

void delay(unsigned int milliseconds){
	LPC_TIM0->CTCR = 0x0;
	LPC_TIM0->PR = 24;
	LPC_TIM0->TCR = 0x02;
	LPC_TIM0->TCR = 0x01;
	while(LPC_TIM0->TC < milliseconds);
	LPC_TIM0->TCR = 0x00;
}

int main(void){
	LPC_GPIO0 -> FIODIR |= 0XFF0; //P0.4-P0.11 as output pin
	LPC_GPIO1 -> FIODIR |= 0XF<<23; // P1.23-P1.26 as output pin
  LPC_GPIO2 -> FIODIR &= 0xFFFFEFFF; // P2.12 as input pin for switch
	
	while(1){
    if(LPC_GPIO2 -> FIODIR & 1){
      for(arr[3]=0; arr[3]<16; arr[3]++){
        for(arr[2]=0; arr[2]<16; arr[2]++){
          for(arr[1]=0; arr[1]<16; arr[1]++){
            for(arr[0]=0; arr[0]<16 ; arr[0]++){
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
    }else{
      for(arr[3]=15; arr[3]>=0; arr[3]--){
        for(arr[2]=15; arr[2]>=0; arr[2]--){
          for(arr[1]=15; arr[1]>=0; arr[1]--){
            for(arr[0]=15; arr[0]>=0 ; arr[0]--){
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
}

void delay(void){
	for(j=0; j<50000; j++);
}

