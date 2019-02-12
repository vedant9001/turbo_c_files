#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>
//float p,q,r;
const float pi=3.14159;
const float deg=pi/180;
class point{
public:
int x,y,z;
float fx,fy,fz;
float temp1,temp2;

point(int a,int b,int c)
{x=fx=a;y=fy=b;z=fz=c; }

void rotate(float m,float n,float o)
{
if(m)
{temp1=fx*cos(m)-fy*sin(m);
 temp2=fx*sin(m)+fy*cos(m);
 fx=temp1;
 fy=temp2;  }

 if(n)
{ temp1=fx*cos(n)-fz*sin(n);
 temp2=fx*sin(n)+fz*cos(n);
 fx=temp1;
 fz=temp2; }

  if(o)
{ temp1=fy*cos(o)-fz*sin(o);
 temp2=fy*sin(o)+fz*cos(o);
 fy=temp1;
 fz=temp2;    }

  x=fx;
  y=fy;
  z=fz;

}


};


void join(point p1,point p2,int color=15){
setcolor(color);
line(p1.x+320,240-p1.y,p2.x+320,240-p2.y);
setcolor(15);}



point p1(100,100,50)
,p2(-100,100,50)
,p3(-100,-100,50)
,p4(100,-100,50)
,p5(100,100,-50)
,p6(-100,100,-50)
,p7(-100,-100,-50)
,p8(100,-100,-50);

void trns(float e1,float e2,float e3){
p1.rotate(e1,e2,e3);
p2.rotate(e1,e2,e3);
p3.rotate(e1,e2,e3);
p4.rotate(e1,e2,e3);
p5.rotate(e1,e2,e3);
p6.rotate(e1,e2,e3);
p7.rotate(e1,e2,e3);
p8.rotate(e1,e2,e3);
}
void joinl(int co){
join(p1,p2,co);
join(p2,p3,co);
join(p3,p4,co);
join(p4,p1,co);
join(p1,p5,co);
join(p2,p6,co);
join(p3,p7,co);
join(p4,p8,co);
join(p5,p6,co);
join(p6,p7,co);
join(p7,p8,co);
join(p5,p8,co);
}


void main()
{
 int gdriver = DETECT, gmode, errorcode;



char ch='a';
initgraph(&gdriver, &gmode, "");
while(ch!=48)
{
ch=getch();
joinl(0);
if(ch=='g')
trns(0,deg,0);
else if(ch=='h')
trns(0,-1*deg,0);
else if(ch=='k')
trns(deg,0,0);
else if(ch=='m')
trns(-1*deg,0,0);
else if(ch=='s')
trns(0,0,deg);
else if(ch=='d')
trns(0,0,-1*deg);
joinl(15);
}





}
