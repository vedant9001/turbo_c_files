#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>

void dec(int&q,int a)
{
if(q<=10)
{if(a==1)
q=650;
else if(a==2)
q=370;}
else
q=q-10;
}
void inc(int&q,int a)
{if(a==1&&q>=650)
 q=10;
 else if(a==2&&q>=370)
 q=10 ;
 else
 q=q+10;
}

void gol(int x,int y)
{circle(x,y,10);
circle(x-20,y,10);}

void move(int&ypos,int&xpos,int pos)
{
if(pos==1)
dec(ypos,2);
if(pos==2)
inc(xpos,1);
if(pos==3)
inc(ypos,2);
if(pos==4)
dec(xpos,1);

}



void main()
{
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "");

char c='x';
int or=0;
int xpos=300,ypos=100;

for(int flag=1;flag==1; )
{
if(kbhit())
c=getch();

if(c==72)
or=1;
else if(c==77)
or=2;
else if(c==80)
or=3;
else if(c==75)
or=4;
else if(c==48)
flag=0;
else
or=0;

move(ypos,xpos,or);
clrscr();
gol(xpos,ypos);
delay(50);

}

}