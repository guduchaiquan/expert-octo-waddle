#include <regx52.h>
void Delay(unsigned int t)
{
while(t--);
while(t--);
while(t--);
}
void working()
{
P2_0=1;
Delay(60000);
P2_0=0;
Delay(60000);

}
void int0()
{
 IT0=1;
 EX0=1;
 EA=1;
}
void serve() interrupt 0
{
P2_7=0;
Delay(60000);
Delay(60000);
Delay(60000);
Delay(60000);
Delay(60000);
Delay(60000);
P2_7=1;
}
void main()
{
int0();
while(1)
 {
   working();
 }
}