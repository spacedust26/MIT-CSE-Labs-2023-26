//sawtooth waveform
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
  unsigned int value = 0; //binary value used for digital to analog conversion
  LPC_PINCON->PINSEL1 |= (1<<21); //select Aout function for P0.26, bits[21:20] = [10]
  while(1){
    if(value > 1023) value = 0; //max value of 10 bit DAC is 1023
    LPC_DAC->DACR = value << 6;
    delayMS(9999); //for 10 millisecond delay
    value++;
  }
}