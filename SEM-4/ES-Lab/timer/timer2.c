//timer program using timer 0

#include<LPC17xx.h>
#include<stdio.h>

void delayms(unsigned int milliseconds){
  LPC_TIM0->CTCR = 0x0; //timer mode
  LPC_TIM0->PR = 2; //increment TC at every 3 pclk
  LPC_TIM0->TCR = 0X02; //reset timer
  LPC_TIM0->TCR = 0X01; //enable timer
  while(LPC_TIM0->TC < milliseconds); //wait until TC reahes the desired delay
  LPC_TIM0->TCR = 0X00; //disable timer
}

int main(){
  delayms(1000);
}