//write a program to configure and read analog data from ADC channel no 5, and display the digital data on the LCD

#include<LPC17xx.h>
#include<stdio.h>
#include "lcd_header.h"

int main(void){
  unsigned long adc_temp;
  unsigned int i;
  float in_vtg;
  unsigned char vtg[7], dval[7];
  unsigned char msg1[11] = {"Analog IP:"};
  unsigned char msg2[12] = {"ADC output:"};
  SystemInit();
  SystemCoreClockUpdate();
  LPC_SC->PCONP |= 1 << 15; //power for GPIO block
  lcd_init();
  LPC_PINCON->PINSEL3 |= 3 << 30; // 3rd function P1.31 as AD0.5
  LPC_SC->PCONP |= 1 << 12;  //enable peripheral ADC
  lcd_comdata(0x80,0);
  delay_lcd(800);
  lcd_puts(&msg1[0]);
  lcd_comdata(0xC0,0);
  delay_lcd(800);
  lcd_puts(&msg2[0]);
  while(1){
    LPC_ADC->ADCR = (1 << 5) | (1 << 21) | (1 << 24); //select AD0.5, PDN bit set, Start set to 001 for software mode
    while(!(LPC_ADC->ADDR5 & 0x80000000)); //wait till done bit[31] is set to 1
    adc_temp = (LPC_ADC->ADDR5 >> 4) & 0xFFF; //12 bit result of adc conversion
    in_vtg = ((float)(adc_temp * 3.3)) / 4096; // calculating input analog volatge
    sprintf(vtg,"%3.2fV", in_vtg); //convert reading to string to display on LCD, minimum width of 3 for the entire field, 2 decimal points
    sprintf(dval,"%x",adc_temp); //x is hexadecimal
    for(int i = 0 ; i < 2000 ; i++); //random delay
    lcd_comdata(0x89,0); //first line 9th character
    delay_lcd(800);
    lcd_puts(&vtg[0]);
    lcd_comdata(0xC8,0); //first line 8th character
    delay_lcd(800);
    lcd_puts(&dval[0]);
    for(int i = 0 ; i < 200000 ; i++); //random delay
    for(i = 0; i < 7 ; i++){
      vtg[i] = dval[i] = 0x00;
    }
    adc_temp = 0;
    in_vtg = 0;
  }
}