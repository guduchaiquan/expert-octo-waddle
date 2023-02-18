#include <regx52.h>
unsigned char nixietable[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00};
unsigned char fen=0;
unsigned char miao=0;
unsigned char haomiao=0;
void nixie(unsigned char location,number)
{
    switch(location)
		{
	   	case 1:P2_4=1;P2_3=1,P2_2=1;break;
			case 2:P2_4=1;P2_3=1,P2_2=0;break;
		  case 3:P2_4=1;P2_3=0,P2_2=1;break;
			case 4:P2_4=1;P2_3=0,P2_2=0;break;
			case 5:P2_4=0;P2_3=1,P2_2=1;break;
			case 6:P2_4=0;P2_3=1,P2_2=0;break;
			case 7:P2_4=0;P2_3=0,P2_2=1;break;
			case 8:P2_4=0;P2_3=0,P2_2=0;break;
		}
P0=nixietable[number];
}
void Delay(unsigned char t)
{
while(t--);
}
void play()
{
nixie(7,haomiao%10);
Delay(500);
nixie(6,haomiao/10);
Delay(500);
nixie(5,16);
Delay(500);
nixie(4,miao%10);
Delay(500);
nixie(3,miao/10);
Delay(500);
nixie(2,16);
Delay(500);
nixie(1,fen%10);
Delay(500);
nixie(0,fen/10);
Delay(500);
}
//*******************************
void intime0()
{
TMOD=0x01;
TH0=(65535-50000)/256;
TL0=(65535-50000)%256;
ET0=1;
EA=1;
TR0=1;
}
void serve0() interrupt 1
{
TH0=(65535-50000)/256;
TL0=(65535-50000)%256;
haomiao++;
if(haomiao==20)
 {
   miao++;
	 haomiao=0;
	 if(miao==60)
	 {
	 fen++;
	 miao=0;
	 }
	 if(fen==99)
	 {
	 fen=0;
	 }
 }
}

void scan()
{
if(P3_1==0)
 {
  Delay(100);
	if(P3_1==0)
	{
	 TR0=~TR0;
	}
 }
 if(P3_0==0)
 {
  Delay(100);
	if(P3_0==0)
	{
	miao=0;
	haomiao=0;
	fen=0;
	}
 }
}
void main()
{
intime0();
 while(1)
 {
 play();
 scan();
 }
}