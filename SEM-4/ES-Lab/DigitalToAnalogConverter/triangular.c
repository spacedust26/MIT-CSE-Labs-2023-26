//triangular waveform
#include<LPC17xx.h>

int main(void){
  unsigned int temp, i; //binary value used for digital to analog conversion
  LPC_PINCON->PINSEL1 |= (1<<21); //select Aout function for P0.26, bits[21:20] = [10]
  while(1){
    for(i = 0 ; i < 1024 ; i++){
      temp = i;
      LPC_DAC->DACR = temp << 6;
    }
    for(i = 1023 ; i >= 0 ; i--){
      temp = i;
      LPC_DAC->DACR = temp << 6;
    }
  }
}