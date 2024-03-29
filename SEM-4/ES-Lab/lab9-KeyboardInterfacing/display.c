//displays the key value of the key pressed
#include<LPCxx.h>
#include "lcd_header.h"

void scan();
unsigned char msg1[13] = "Key pressed";
unsigned char row, flag, key;
unsigned long int i, var1, temp3;
unsigned char scan_code[16] = {0x11, 0x21, 0x41, 0x81, 0x12, 0x22, 0x42, 0x82, 0x14, 0x24, 0x44, 0x84, 0x18, 0x28, 0x48, 0x88};
unsigned char ascii_code[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int main(){
  LPC_GPIO2->FIODIR |= 0x00003C00; //port pins P2.10-2.13 as output rows
  LPC_GPIO1->FIODIR &= 0xF87FFFFF; //port pins P1.23-1.26 as input columns
  lcd_init();
  lcd_comdata(0x80,0); //1st line 1st char
  delay_lcd(800);
  lcd_puts(&msg1[0]);
  while(1){
    while(1){
      for(row = 1 ; row < 5 ; row++){
        if(row == 1) var1 = 0x00000400;
        else if(row == 2) var1 = 0x00000800;
        else if(row == 3) var1 = 0x00001000;
        else if(row == 4) var1 = 0x00002000;
        LPC_GPIO2->FIOCLR = 0x00003C00; //clear the ports to send appropriate values
        LPC_GPIO2->FIOSET = var1; //enable row
        flag = 0;
        scan(); //scan if any key is pressed in the enabled row
        if(flag == 1) break;
      }// end for
      if(flag == 1) break;
    }// end of while 2
    for(i = 0 ; i < 16 ; i++){
      if(key == scan_code[i]){
        key = ascii_code[i];
        break;
      }
    }// end for
    lcd_comdata(0xC0,0);
    delay_lcd(800);
    lcd_puts(&key);
  }//end of while 1
}

void scan(void){
  temp3 = LPC_GPIO1->FIOPIN;
  temp3 &= 0x07800000; //check if any key is pressed in the enabled row 
  if(temp3 != 0x00000000){
    flag = 1;
    temp3 >>= 19; //shift to come at HN of byte
    var1 >>= 10; //shift to come at LN of byte
    key = temp3 | var1; //get scan_code
  }
}

