#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdio.h>
#include<math.h>

const int r=20;
const int h=100;

void lin(int ypos,int&y,int an,int j=1){
float p=(1.57*an)/90;
y=h*cos(p);
if(j==1)
y=y+ypos;
else
y=ypos-y;                              }

void point(int x,int y){
line(x,y,x+1,y+1);
}

void harc(int xpos,int ypos, float p){
float x,y;
int x2,y2;
for(float a=0;a<=6.28;a=a+0.05){
x=r*cos(a);
y=p*r*sin(a);
x2=x;y2=y;
point(xpos+x2,ypos+y2);
}
}

void fa(int x,int y,int ch)
{float m=ch/90;
harc(x,y,m);}

void ba(int x,int y,int ch)
{float m=-ch/90;
harc(x,y,m);}

void main()
{
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "");


char ch='q';
int an=0,ypos1,ypos2;

while(ch!=48)
{
ch=getch();

if(ch==72)
{if(an==90)
an=90;
else
an++;}

if(ch==80)
{if(an==-90)
an=-90;
else
an--;}

lin(240,ypos1,an,1);
lin(240,ypos2,an,2);

clrscr();
line(320-r,240,320-r,ypos1);
line(320-r,240,320-r,ypos2);
line(320+r,240,320+r,ypos1);
line(320+r,240,320+r,ypos2);

fa(320,ypos1,an);
fa(320,ypos2,an);
ba(320,ypos1,an);
ba(320,ypos2,an);



}
}
