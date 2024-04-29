//Toggling of LED depending on the external interrupts EINT0 and EINT1
#include<LPC17xx.h>

void EINT0_IRQHandler(void){
  LPC_SC->EXTINT = (1<<0); //clear interrupts flag in EINT0
  LPC_GPIO2->FIOPIN ^= (1 << 0); //toggle
}
void EINT1_IRQHandler(void){
  LPC_SC->EXTINT = (1<<1); //clear interrupts flag in EINT1
  LPC_GPIO2->FIOPIN ^= (1 << 1); //toggle
}

int main(){
  LPC_SC->EXTINT = (1<<0) | (1<<1); //clear pending interrupts in EINT0 and EINT1
  LPC_PINCON->PINSEL4 = (1<<20) | (1<<22); //Configure 2.10 and 2.11 as EINT0 and EINT1 as function 1
  LPC_SC->EXTMODE = (1<<0) | (1<<1); //set bits 0 and 1 for edge triggered
  LPC_SC->EXTPOLAR = (1<<0) | (1<<1); // set bits 0 and 1 for rising edge
  LPC_GPIO2->FIODIR = (1<<0) | (1<<1); //configure P2.0 and P2.1 for LED output
  LPC_GPIO->FIOPIN = 0x00;
  NVIC_EnableIRQ(EINT0_IRQn); //enable EINT0 interrupt
  NVIC_EnableIRQ(EINT1_IRQn); //enable EINT1 interrupt
  while(1);
}