//Toggling of LED depending on the external interrupts
#include<LPC17xx.h>
#define PINSEL_EINT0 20
#define PINSEL_EINT1 22
#define LED1 0
#define LED2 1
#define SBIT_EINT0 0
#define SBIT_EINT1 1
#define SBIT_EXTPOLAR0 0
#define SBIT_EXTPOLAR1 1

void EINT0_IRQHandler(void){
  LPC_SC->EXINT = 1 << SBIT_EINT0; //clear interrupt flag
  LPC_GPIO2->FIOPIN ^= (1<<LED1); //toggle LED1 everytime INTR0 is generated
}
void EINT1_IRQHandler(void){
  LPC_SC->EXINT = 1 << SBIT_EINT1; //clear interrupt flag
  LPC_GPIO2->FIOPIN ^= (1<<LED2); //toggle LED2 everytime INTR1 is generated
}

int main(){
  SystemInit();
  LPC_SC->EXTINT = (1 << SBIT_EINT0) | (1 << SBIT_EINT1); //clear pending interrupts
  LPC_PINCON->PINSEL4 = (1 << PINSEL_EINT0) | (1 << PINSEL_EINT1); // configure P2.10, P2.11 as EINT0/1
  LPC_SC->EXTMODE = (1 << SBIT_EXTMODE0) | (1 << SBIT_EXTMODE1); //configure EINTx as Edge Triggered
  LPC_SC->EXTPOLAR = (1 << SBIT_EXTPOLAR0)| (1 << SBIT_EXTPOLAR0); //configure EINTx as Falling Edge
  LPC_GPIO2->FIODIR = (1 << LED1) | (1 << LED2); //configure LED pins as OUTPUT
  LPC_GPIO2->FIOPIN = 0x00;
  NVIC_EnableIRQ(EINT0_IRQn); //Enable the EINT0,EINT1 interrupts
  NVIC_EnableIRQ(EINT1_IRQn); 
  while(1){}
}
