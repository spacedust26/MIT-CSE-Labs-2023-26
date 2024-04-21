//sine waveform
#include<LPC17xx.h>
#include<math.h>
#define pi 3.14

int main(void){
  unsigned int i, temp;
  float rad, value;
  LPC_PINCON->PINSEL1 |= (1<<21); //select Aout function for P0.26, bits[21:20] = [10]
  while(1){
   for(i = 0 ; i <= 360 ; i = i + 9){
    rad = sin(i * (pi / 180));
    value = 1.65 + 1.65 * rad;
    temp = (value * 1023) / 3.3;
    LPC_DAC->DACR = temp << 6;
   }
  }
}