//displays the key value of the key pressed
#include<LPCxx.h>
#include "lcd_display.h"

void scan();
unsigned char msg1[13] = "Key pressed";
unsigned char row, flag, key;
unsigned long int i, var1, temp3;
unsigned char SCAN_CODE[16] = {0x11, 0x21, 0x41, 0x81, 0x12, 0x22, 0x42, 0x82, 0x14, 0x24, 0x44, 0x84, 0x18, 0x28, 0x48, 0x88};
unsigned char ASCII_CODE[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int main(){
  LPC_GPIO2->FIODIR |= 0x00003c00; //port pins P2.10-2.13 as output 
  LPC_GPIO1->FIODIR |= 0xF87FFFFF; //port pins P2.10-2.13 as output 
  lcd_init();
  lcd_comdata(0x80,0); //1st line 1st char
}