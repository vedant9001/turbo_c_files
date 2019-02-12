#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdio.h>
#include<math.h>


int r=50;
int h=40;

void lin(int ypos,int&y,int an,int j)
{
float p=(1.57*an)/90;
y=h*cos(p);
if(j==1)
y=y+ypos;
else
y=ypos-y;                              }

void point(int x,int y){
line(x,y,x+1,y+1);
}

void harc(int xpos,int ypos, float u,int n){
float x,y,p;
int x2,y2;

if(n==1)
p=u/90;
else
p=-1*u/90;

for(float a=0;a<=3.14;a=a+0.05)
{
x=r*cos(a);
y=p*r*sin(a);
x2=x;y2=y;
point(xpos+x2,ypos+y2);
}
}

void fa(int x,int y,int ch)
{
harc(x,y,ch,1);}

void ba(int x,int y,int ch)
{
harc(x,y,ch,2);}

void main()
{
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "");

setcolor(0);

char ch='q';
int an=30,ypos1,ypos2;
int m=320,b=240;

while(ch!=48)
{
ch=getch();

if(ch=='m')
m++;
else if(ch=='n')
m--;
else if(ch=='b')
b++;
else if(ch=='v')
b--;

else if(ch==72)
{if(an==90)
an=-90;
else
an++;}

if(ch==80)
{if(an==-90)
an=90;
else
an=an-1;}

if(ch=='r')
r++;
else if(ch=='t')
if(r>5)
r--;

if(ch=='h')
h++;
else if(ch=='j')
if(h>5)
h--;




lin(b,ypos1,an,1);
lin(b,ypos2,an,2);

clrscr();



line(m-r,b,m-r,ypos1);
line(m-r,b,m-r,ypos2);
line(m+r,b,m+r,ypos1);
line(m+r,b,m+r,ypos2);

if(an>=0)
fa(m,ypos1,an);
if(an<=0)
fa(m,ypos2,an);

ba(m,ypos1,an);
ba(m,ypos2,an);



}
}
