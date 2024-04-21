//square waveform
#include<LPC17xx.h>

void delayms(unsigned int milliseconds){
  LPC_TIM0->CTCR = 0x0; //Timer mode
  LPC_TIM0->PR = 2; //increment after every 3pclk
  LPC_TIM0->TCR = 0x02; //reset timer
  LPC_TIM0->TCR = 0x01; //enable timer
  while(LPC_TIM0->TC < count); //wait until timer reaches the desired delay
  LPC_TIM0->TCR = 0x00; //disable timer
}

int main(void){
  LPC_PINCON->PINSEL1 |= (1<<21); //select Aout function for P0.26, bits[21:20] = [10]
  while(1){
    LPC_DAC->DACR = 1023 << 6;
    delayMS(9999); //for 10 millisecond delay
    LPC_DAC->DACR = 0 << 6;
    delayMS(9999); //for 10 millisecond delay
  }
}