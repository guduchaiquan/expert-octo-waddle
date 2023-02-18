#include <regx52.h>
sfr AUXR=0x8e;
unsigned char urdate;
void send(unsigned char dat)
void init()
{
 TMOD=0x20;
 TH1=0xfd;
 TL1=0xfd;
 TR1=1;
 AUXR=0x00;
 SCON=0x50;
 ES=1;
 EA=1;
}

void serve() interrupt 4
{
 if(RI==1)
 {
 RI=0;
   urdate=SBUF;
	 send(urdat+1);
 }
}
void send(unsigned char dat)
{
SBUF=dat;
while(TI==0);
TI=0;
}
void main()
{
 init();
 send(0x5a);
 send(0xa5);
 while(1)
 {
 
 }
}