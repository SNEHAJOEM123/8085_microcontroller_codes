#include<reg51.h>
#include<stdio.h>
sbit sw=P1^0;
// delay subroutine starts here
void delay()
{
int i,j;
for(j=0;j<40;j++)
for(i=0;i<15000;i++);
}
// main function starts here
void main()
{
sw=1; // initialize P1^0 as an i/p pin
if(sw==0) // if switch is pressed then send the SMS
{
 TMOD=0X20; // Timer 1 in mode2
 TH1=0XFD; // TH1 is loaded for 9600bps baud rate generation
 SCON=0X50; // Serial communication in mode 1 with receive enable
 TR1=1; // Start Timer 
 TI=1; // Since printf( ) is used so TI flag has to be raised
 printf("at"); // initiate the GSM modem
 printf("\n");
 printf("\r");
 delay();
 printf("at+cmgf=1"); // initiate GSM modem in text mode
 printf("\n");
 printf("\r");
 delay();
 printf("at+cmgs=\"+918921109079\""); // send sms to the specified mobile number
 printf("\n");
 printf("\r");
 delay();
 printf("DANGER!!!!!!!!!!!"); // body of the SMS
 delay();
 SBUF=0x1A; // ASCII code for ctrl+z
 while(TI==0); // wait for the transmission to complete
 TI=0; // clear the transmit interrupt flag
 delay();
}
}