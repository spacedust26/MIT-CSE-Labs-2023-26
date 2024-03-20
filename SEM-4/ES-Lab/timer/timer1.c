//Program to get 1ms delay using timer0

#include<LPC17xx.h>
#include<stdio.h>

void initTimer0(void){
  LPC_TIM0->CTCR = 0x0; //timer mode
  LPC_TIM0->TCR = 0x02; //reset timer
  LPC_TIM0->PR = 2; //increment TC at every 2+1 clock cycle Tres = 1 us
  LPC_TIM0->MR0 = 999; // for 1 ms delay TC counts 0 to 999
  LPC_TIM0->MCR = 2; //reset TC after 1 ms delay
  LPC_TIM0->EMR = 0x20; //when match occurs bit 0 of EMR will set
  LPC_TIM0->TCR = 0x01; //enable timer0
}

void delay(void){
  initTimer0();
  while(!(LPC_TIM0->EMR & 1));
}

int main(){
  delay();
}