//alternative code to toggle LED using interrupt EINT2

#include<LPC17xx.h>
unsigned int i;

void EINT2_IRQHandler(void){
  LPC_GPIO0->FIOPIN = -LPC_GPIO0->FIOPIN; //toggle LED everytime interrupt is generated
  for(i = 0 ; i < 5000 ; i++); //random delay
  LPC_SC->EXTINT = 4; //clear interrupt flag
}

int main(void){
  LPC_PINCON->PINSEL4 = (1<<24); //P2.12 as EINT2 with function1 
  LPC_GPIO0->FIODIR = 0xFF0; //P0.4 - P0.11 as LED outputs
  LPC_SC->EXTMODE = 0; //EINT2 level triggered
  LPC_SC->EXTPOLAR = 4; //EINT2 active high
  NVIC_EnableIRQ(EINT2_IRQn); //call EINT2 interrupt
  while(1);
}