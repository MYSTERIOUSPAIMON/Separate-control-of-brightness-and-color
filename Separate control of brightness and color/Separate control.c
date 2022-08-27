#include <__STC8H_H__.H>
#include "intrins.h"

int i=0;	   //定义灯的周期
int a=0;	   //定义key1
int b=0;	   //定义key2
int TH=0;		 //定义灯的初值
int flag=0; 
int c=0;

void main()
{
    P0M0 = 0xff;
    P0M1 = 0x00;
	IT0=1;
    EX0=1;
	IT1=1;
	EX1=1;
    EA=1;

    while(1){
	if(b==0){	 //红灯
		if(a==0)
    	{
   	      TH=600;
		  }

	    if(a==1)
		{
	      TH=300;
		  }

	    if(a==2)
		{
	       TH=0;}

		for(i=0;i<600;i++)
		{
		   if(i<TH)
		   P01=1;
		   if(i>=TH)
		   P01=0;	   
		  }
		}

	if(b==1){		//蓝灯
		if(a==0)
    	{
   	      TH=600;
		  }

	    if(a==1)
		{
	      TH=300;
		  }

	    if(a==2)
		{
	       TH=0;}

		for(i=0;i<600;i++)
		{
		   if(i<TH)
		   P00=1;
		   if(i>=TH)
		   P00=0;	   
		  }
	  }
	if(b==2){	   //绿灯
		if(a==0)
    	{
   	      TH=600;
		  }

	    if(a==1)
		{
	      TH=300;
		  }

	    if(a==2)
		{
	       TH=0;}

		for(i=0;i<600;i++)
		{
		   if(i<TH)
		   P02=1;
		   if(i>=TH)
		   P02=0;	   
		  }
		  }
		}
}

void int1_isr(void) interrupt 2	 //key2
{
  if(P33==0)
{
	if(c==0)
	{c=1;}
   if(c==1)
   {
    b++;
    if(b>2)
    {
      b=0;
    }	 
     c=0;
   }  
	} 
}

void int0_isr(void) interrupt 0	 //key1
{
  if(P32==0)
{
	if(flag==0)
	{flag=1;}
   if(flag==1)
   {
    a++;
    if(a>2)
    {
      a=0;
    }	 
     flag=0;
   }  
	} 
}
