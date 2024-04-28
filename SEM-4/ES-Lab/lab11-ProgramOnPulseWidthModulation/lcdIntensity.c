//Program to vary the intensity of an LED using PWM
#include<LPC17xx.h>

void initpwn(void);
void updatepulsewidth(unsigned int pulsewidth);
void delayms(unsigned int milliseconds);

void initpwm(){
  LPC_PINCON->PINSEL3 |= 0X8000;//select PWM1.4 output for P1.23 function 2
  LPC_PWM1->PCR = 0X1000; //enable PWM1.4 (by default it is single edged)
  LPC_PWM1->PR = 0; //TC increments every 1 pclk
  LPC_PWM1->MR0 = 30000; //period = 10ms which is 10^2 Hz , ie 3 * 10^6 / 10^2
  LPC_PWM1->MCR = 2; //reset PWM tc on PWM1MR0 match
  LPC_PWM1->LER = 0XFF; //updates value in MR0
  LPC_PWM1->TCR = 0X2; //reset counter tc and pc
  LPC_PWM1->TCR = 0x9; //enable tc and pc and PWM
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
  int pulsewidth[] = {0, 3000, 6000, 9000, 12000, 15000, 18000, 21000, 24000, 27000};
  int numpulsewidth = 10;
  int count = 1;
  int dir = 0; //0->increasing 1->decreasing
  initpwm();
  while(1){
    updatepulsewidth(pulsewidth[count]);
    delayms(10000);
    if(count == (numpulsewidth - 1) || count == 0) dir = !dir;
    if(dir) count--;
    else count++;
  }
}