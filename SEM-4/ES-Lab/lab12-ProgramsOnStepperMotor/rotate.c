//To rotate the stepper motor in clockwise and anticlockwise direction at a particular speed continuously

#include<LPC17xx.h>
void clockwise(void);
void anticlockwise(void);
unsigned int var1, var2;
unsigned int i = 0, j = 0, k = 0;

int main(void){
  LPC_GPIO0->FIODIR = 0x000000F0;//P0.4 - P0.7 output
  while(1){
    for(j = 0 ; j < 50 ; j++) clockwise();
    for(k = 0 ; k < 65000 ; k++); //delay
    for(j = 0 ; j < 50 ; j++) anticlockwise();
    for(k = 0 ; k < 65000 ; k++); //delay
  }
}

void clockwise(){
  var1 = 0x00000008; //clockwise A B C D stepping
  for(i = 0 ; i <= 3 ; i++){
    var1 = var1 << 1;
    LPC_GPIO0->FIOPIN = var1;
    for(k = 0 ; k < 3000 ; k++); //for step speed variation
  }
}

void anticlockwise(){
  var1 = 0x00000100; //anticlockwise A B C D stepping
  for(i = 0 ; i <= 3 ; i++){
    var1 = var1 >> 1;
    LPC_GPIO0->FIOPIN = var1;
    for(k = 0 ; k < 3000 ; k++); //for step speed variation
  }
}