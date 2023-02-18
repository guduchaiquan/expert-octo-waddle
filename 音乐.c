#include   <reg51.h>   
  typedef   unsigned   char   uchar;   
  sbit   P0_0=P0^0;
  sbit   P0_1=P0^1; 
  sbit   P0_2=P0^2;
  sbit   P0_3=P0^3; 
  sbit   P2_0=P2^0;
  sbit   P2_1=P2^1; 
  uchar   time=0;   
  uchar   period=25;   
  uchar   high=10;
  uchar   th1=0;
  uchar   tl1=0;
  uchar   th0=0; 
  uchar   tl0=0;     
    
  void   timer0()   interrupt   1   using   1   
  {   
            TH0=0x3c;     /*????????*/   
            TL0=0xb0;
            //TH0=0xc3;/*????????*/
            //TL0=0x50;  
            time++;   
            if(time==high)   /*?????????,??*/   
            {   P2_0=tl0;
                P2_1=tl1;        
              }   
            else   if(time==period)     /*?????,??*/   
                      {   time=0;   
                          P2_0=th0;
                          P2_1=th1;
                             
                      }   
    
  }   
    
  void   main()   
  {   
        TMOD=0x01;   /*???0??1*/   
        TH0=0x3c;     /*???????,???????????1/5*/   
        TL0=0xb0; 
        //TH0=0xc3;/*???????,???????????4/5*/
        //TL0=0x50;    
        EA=1;     /*?CPU??*/   
        ET0=1;   /*????0??*/   
        TR0=1;/*?????0*/  
        
        if(P0_2==1)
         {
          th0=1;
          tl0=0;
          th1=0;
          tl1=0;
              }

          if(P0_3==1)
         {
          th0=0;
          tl0=0;
          th1=1;
          tl1=0;
              }
        while(1)     /*????*/   
        {}   
    
  }   
————————————————
????:???CSDN???????DIY?????????,??CC 4.0 BY-SA????,????????????????
????:https://blog.csdn.net/qq_17200045/article/details/127310008