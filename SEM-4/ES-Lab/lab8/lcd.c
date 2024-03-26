//To display message on LCD
#include<LPC17xx.h>
#define rs_ctrl 0x08000000 //P0.27
#define en_ctrl 0x10000000 //P0.28
#define dt_ctrl 0x78000000 //P0.23 - P0.26

void lcd_init(void);
void write(int, int);
void delay_lcd(unsigned int);
void lcd_comdata(int, int);
void clear_ports(void);
void lcd_puts(unsigned char *);

//Main function
int main(void){
  unsigned char msg1[4] = {"MIT"};
  unsigned char msg2[19] = {"Department of CSE"};
  SystemInit();
  SystemCoreClockUpdate();
  lcd_init();
  lcd_comdata(0x80,0); //1st line 1st char
  delay_lcd(800);
  lcd_puts(&msg1[0]);
  lcd_comdata(0xC0,0); //2nd line 1st char
  delay_lcd(800);
  lcd_puts(&msg2[0]);
}

//lcd initialisation
void lcd_init(){
  LPC_GPIO0->FIODIR |= dt_ctrl;
  LPC_GPIO0->FIODIR |= rs_ctrl;
  LPC_GPIO0->FIODIR |= en_ctrl;
  clear_ports();
  delay_lcd(3200);
  //4 bit mode
  lcd_comdata(0x33,0);
  delay_lcd(30000);
  lcd_comdata(0x32,0);
  delay_lcd(30000);
  lcd_comdata(0x28,0); //function set - 4 bit mode and 2 lines
  delay_lcd(30000);
  lcd_comdata(0x0C,0); // display on cursor off
  delay_lcd(800);
  lcd_comdata(0x06,0); // entry mode set increment cursor right
  delay_lcd(800);
  lcd_comdata(0x01,0); //display clear
  delay_lcd(10000);
}

void lcd_comdata(int temp1, int type){
  int temp2 = temp1 & 0xF0; //gets msb nibble
  temp2 = temp2 << 19;
  write(temp2, type);
  temp2 = temp1 & 0x0F; // gets lsb nibble
  temp2 = temp2 << 23;
  write(temp2, type);
  delay_lcd(1000);
}

void write(int temp2, int type){
  clear_ports();
  LPC_GPIO0->FIOPIN = temp2; //assign values to data lines
  if(type == 0) LPC_GPIO0->FIOCLR = rs_ctrl; //clear rs for command
  else LPC_GPIO0->FIOSET = rs_ctrl; //set rs for data
  LPC_GPIO0->FIOSET = en_ctrl; //en=1
  delay_lcd(25);
   LPC_GPIO0->FIOCLR = en_ctrl; //en=0
}

void delay_lcd(unsigned int r1){
  unsigned int r;
  for(r = 0 ; r < r1 ; r++);
}

void clear_ports(void){
  LPC_GPIO0->FIOCLR = dt_ctrl;
  LPC_GPIO0->FIOCLR = rs_ctrl;
  LPC_GPIO0->FIOCLR = en_ctrl;
}

void lcd_puts(unsigned char *buf1){
  unsigned int i = 0;
  unsigned int temp3;
  while(buf1[i]!='\0'){
    temp3 = buf1[i];
    lcd_comdata(temp3, 1);
    i++;
    if(i == 16){
      lcd_comdata(0xC0,0);
    }
  }
}