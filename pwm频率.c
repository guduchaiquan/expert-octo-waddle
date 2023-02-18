#include <regx52.h>
void Delay(unsigned char t)
{
while(t--);
}
unsigned char count=0;
unsigned char duty=0;
void intime0()
{
TMOD=0x01;
TH0=(65535-100)/256;
TL0=(65535-100)%156;
ET0=1;
EA=1;
}
void sever0() interrupt 1
{
TH0=(65535-100)/256;
TL0=(65535-100)%256;
count++;
if(count==duty)
{
 P2_0=1;
}else if(count==100)
 {
  P2_0=0;
	count=0;
 }
}
unsigned char stat=0;
void scan()
{
if(P1_6==0)
 {
 Delay(1000);
 if(P1_6==0)
  {
   switch(stat)
	 {
	 case 0:P2_0=0;
	 TR0=1;
	 duty=10;
	 stat=1;
	 break;
	 
	 case 1:
	 duty=50;
	 stat=2;
	 break;
	 
	 case 2:
	 duty=90;
	 stat=2;
	 break;
	 
	 case 3:
	 P2_0=1;
	 TR0=0;
	 stat=0;
	 break;
	 }
	 while(P1_6==0);
  }
 }

}
void main()
{
intime0();
P2_0=1;
while(1)
 {
 scan();
 }
}