//ramp waveform
#include<LPC17xx.h>

int main(void){
  unsigned int value = 0; //binary value used for digital to analog conversion
  LPC_PINCON->PINSEL1 |= (1<<21); //select Aout function for P0.26, bits[21:20] = [10]
  while(1){
    if(value > 1023) value = 0; //max value of 10 bit DAC is 1023
    LPC_DAC->DACR = value << 6;
    value++;
  }
}