//Program to display the digital value representing the difference in analog voltages at ADC channel 4 and channel 5 on LCD using burst mode

#include<LPC17xx.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include "lcd_header.h"
unsigned long x;
float t1=0, t2=0;
unsigned char vtg1[7], vtg2[7];

int main(){
  lcd_init();
  LPC_PINCON->PINSEL3 = 0xF << 28; //set P1.28, P1.29, P1.30. P1.31 as 
  LPC_SC->PCONP = 1 << 12; 
  LPC_ADC->ADCR = (1<<4) | (1<<5) | (1<<16) | (1<<21); // set 4th and 5th channel,burst bit set, PDN bit set
  LPC_ADC->ADINTEN = (1<<4) | (1<<5); //interrupt enabled
  NVIC_EnableIRQ(ADC_IRQn);
  while(1);
}

void ADC_IRQHandler(void){
  x = LPC_ADC->ADSTAT & (3 << 4); //check done bits of 4th and 5th channel
  if(x & (1<<4)){
    t1 = (LPC_ADC->ADDR4 >> 4) & 0xFFF; // fetch result from channel 4
    t1 = ((float)(t1 * 3.3)) / 4096; //get initial analog volatge
    sprintf(vtg1, "%3.2fV", t1);
    lcd_comdata(0x80,0);
    delay_lcd(800);
    lcd_puts(&vtg1[0]);
  }
  if(x & (1<<5)){
    t2 = (LPC_ADC->ADDR5 >> 4) & 0xFFF; // fetch result from channel 5
    t2 = ((float)(t1 * 3.3)) / 4096; //get initial analog volatge
    sprintf(vtg2, "%3.2fV", t2);
    lcd_comdata(0xC0,0);
    delay_lcd(800);
    lcd_puts(&vtg2[0]);
  }
}