//keyboard controlling LED light intensity with 4 switches

#include<LPCxx.h>

void initpwn(void);
void updatepulsewidth(unsigned int pulsewidth);
void delayms(unsigned int milliseconds);
unsigned int temp3;
int pulsewidth[] = {3000, 7500, 15000, 22500};

void initpwm(){
  LPC_PINCON->PINSEL3 |= 0X8000;//select PWM1.4 output for pin1.23 function2 
  LPC_PWM1->PCR = 0X1000; //enable PWM1.4 (by default it is single edged)
  LPC_PWM1->PR = 0; //increments every 1 pclk
  LPC_PWM1->MR0 = 30000; //period = 10ms if pclk = cclk/4
  LPC_PWM1->MCR = 2; //reset PWM tc on PWM1MR0 match
  LPC_PWM1->LER = 0XFF; //updates value in MR0
  LPC_PWM1->TCR = 0X2; //reset counter tc and pc
  LPC_PWM1->TCR = 0x9; //enale tc and pc
}

void updatepulsewidth(unsigned int pulsewidth){
  LPC_PWM1->MR4 = pulsewidth; //update MR4 width 
  LPC_PWM1->LER = 0xFF; //load MR4 new values at the start of next cycle
}

void delayms(unsigned int milliseconds){
  LPC_TIM0->CTCR = 0x0; //timer mode
  LPC_TIM0->PR = 2; //increment TC at every 3 pclk
  LPC_TIM0->TCR = 0X02; //reset timer
  LPC_TIM0->TCR = 0X01; //enable timer
  while(LPC_TIM0->TC < milliseconds); //wait until TC reahes the desired delay
  LPC_TIM0->TCR = 0X00; //disable timer
}

int main(void){
  LPC_GPIO->FIODIR = 0xF00;
  initpwm();
  while(1){
    int count = scan();
    if(count == 0x01) updatepulsewidth(pulsewidth[0]);
    else if(count == 0x02) updatepulsewidth(pulsewidth[1]);
    else if(count == 0x03) updatepulsewidth(pulsewidth[2]);
    else if(count == 0x04) updatepulsewidth(pulsewidth[3]);
    delayms(100000);
  }
}

int scan(void){
  LPC_GPIO0->FIOSET = 0x100;
  temp3 = LPC_GPIO0->FIOPIN;
  temp3 &= 0xF0;
  if(temp3 != 0)return temp3>>4;
  return 1;
}