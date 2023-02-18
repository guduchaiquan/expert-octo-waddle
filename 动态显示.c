#include <REGX52.H>
void Delay(unsigned int t)
{
while(t--);
while(t--);
 }
unsigned char nixietable[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00};
void suo(unsigned char location,number)
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
void main()
{
suo(2,0);
Delay(500);
suo(0,1);
Delay(500);
suo(1,2);
Delay(500);
suo(8,3);
Delay(500);
   while(1)
   {


   }


}