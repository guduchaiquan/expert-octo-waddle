#include <regx52.h>
unsigned char nixietable[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00};
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
unsigned char key_num;
void ScanKeyNum()
{
P1_7=0;
P1_6=P1_5=P1_4=1;
P1_3=P1_2=P1_1=P1_0=1;
if(P1_3==0)
{
while(P1_3==0);
key_num=0;
nixie(0,1);
}
}
void main()
{
while(1)
 { 
 ScanKeyNum();



 }



}