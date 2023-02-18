#include <regx52.h>
#include <intrins.h>
void Delay(unsigned char i)
{
while(i--);


}



void alone()
{
   if(P3_0==0)
  {
    Delay(500);
		if(P3_0==0)
		{
		   P2_0=0;
			 while(P3_0==0){
			 P2_0=1;}
			 }
			}	 
if(P3_1==0)
  {
    Delay(500);
		if(P3_1==0)
		{
		   P2_1=0;
			 while(P3_1==0){
			 P2_1=1;
			 }
		}
	}
if(P3_3==0)
  {
    Delay(500);
		if(P3_3==0)
		{
		   P2_2=0;
			 while(P3_3==0){
			 P2_2=1;
			 }
			}	
	}
if(P3_4==0)
  {
    Delay(500);
		if(P3_4==0)
		{
		   P2_3=0;
			 while(P3_4==0){
			 P2_3=1;
			 }
		}
  }

}

void main()
{
	P2_0=0;
 while(1)
   { 
alone();
   }


}