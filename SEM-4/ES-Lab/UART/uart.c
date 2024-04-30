//uart programming
//CALCULATION: cclk = 12Mhz pclk = 3Mhz baud rate = 9600

#include<LPC17xx.h>
#define LINE_FEED 0x0A //lf for linux, mac, windows terminal
#define CARRIAGE_RETURN 0x0D //cr for windows terminals (cr+lf)

void initUART0(void){
  LPC_SC->PCONP |= 1<<3; //set bit 3 power up UART0 (3-UART0, 4-UART1, 24-UART2, 25-UART3 , UART0 and UART1 enabled by default after reset)
  LPC_UART0->LCR = 3 | 1<<7; //8 bit word length, no parity, 1 stop bit, DLAB = 1
  LPC_UART0->DLL = 0x0D; //DLL = 13, ie D in hex
  LPC_UART0->DLM = 0;
  LPC_UART0->FDR = (2<<4) | 1; //DIVADDVAL = 1, MULVAL = 2
  LPC_UART0->FCR |= 1<<0 | 1<<1 | 1<<2; //FIFO enable, Rx reset, Tx reset
  LPC_PINCON->PINSEL0 |= (1<<4) | (1<<6); //select function 1 P0.2 Tx and P0.3 rx
  LPC_UART0->LCR &= 0xFFFFFF7F; //disable DLAB bit once DLL and DLM are set
}

void U0write(char txData){
  while(!(LPC_UART0->LSR & 1<<5)); //wait until THR is empty
  LPC_UART0->THR = txData; //write into Tx FIFO
}

char U0read(void){
  while(!(LPC_UART0->LSR & 1<<0)); //wait until data arrives in Rx FIFO
  return LPC_UART0->RBR;
}

int main(){
  char msg[] = { 'H','e','l','l','o',' ','f','r','o','m',' ','L','P','C','1','7','6','8','\0' }; 
  int i = 0;
  initUART0();
  while(1){
    while(msg[i] != '\0'){
      U0write(msg[i]);
      i++;
    }
    U0write(CARRIAGE_RETURN); //comment this for linux or mac
    U0write(LINE_FEED); //windows uses cr+lf for new line
    i = 0;
  }
}