#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<time.h>
#include<stdio.h>

//float p,q,r;

const int max=270;
const float pi=3.14159;
const float deg=pi/180;
float temp1,temp2;

class point{
public:
//int x,y,z;
float fx,fy,fz;

void initialize(int a,int b,int c)
{fx=a;fy=b;fz=c; }

void rotate(float m,float n,float o) // rotation about x,y,z axes by m,n,o angle respectively!!!
{
if(m)
{temp1=fx*cos(m)+fy*sin(m);
 temp2=-fx*sin(m)+fy*cos(m);
 fx=temp1;
 fy=temp2;  }

 if(n)
{ temp1=fx*cos(n)+fz*sin(n);
 temp2=-fx*sin(n)+fz*cos(n);
 fx=temp1;
 fz=temp2; }

  if(o)
{ temp1=fy*cos(o)+fz*sin(o);
 temp2=-fy*sin(o)+fz*cos(o);
 fy=temp1;
 fz=temp2;    }

//  x=fx;
 // y=fy;
 // z=fz;

}

};

/*void join(point p1,point p2,int color=15){
setcolor(color);
line(p1.fx+320,240-p1.fy,p2.fx+320,240-p2.fy);
setcolor(15);}
*/

/*
int k=200;

point p1(100+k,100,100)
,p2(-100+k,100,100)
,p3(-100+k,-100,100)
,p4(100+k,-100,100)
,p5(100+k,100,-100)
,p6(-100+k,100,-100)
,p7(-100+k,-100,-100)
,p8(100+k,-100,-100); */

point sp[max];
/*
point q1(50,50,50)
,q2(-50,50,50)
,q3(-50,-50,50)
,q4(50,-50,50)
,q5(50,50,-50)
,q6(-50,50,-50)
,q7(-50,-50,-50)
,q8(50,-50,-50);    */
/*
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
}  */

void trnsq(float e1,float e2,float e3){
/*q1.rotate(e1,e2,e3);
q2.rotate(e1,e2,e3);
q3.rotate(e1,e2,e3);
q4.rotate(e1,e2,e3);
q5.rotate(e1,e2,e3);
q6.rotate(e1,e2,e3);
q7.rotate(e1,e2,e3);
q8.rotate(e1,e2,e3);
*/

for(int i=0;i<max;i++)
{
 sp[i].rotate(e1,e2,e3);
}

}
void joinlq(int co){
/*join(q1,q2,co);
join(q2,q3,co);
join(q3,q4,co);
join(q4,q1,co);
join(q1,q5,co);
join(q2,q6,co);
join(q3,q7,co);
join(q4,q8,co);
join(q5,q6,co);
join(q6,q7,co);
join(q7,q8,co);
join(q5,q8,co);
join(q1,q7,co);
*/

for(int i=0;i<max;i++)
{
 putpixel(sp[i].fx+320,240-sp[i].fy,co);
}

}


void main()
{
int gdriver = DETECT, gmode, errorcode;
int i;
float ran;
char ch='a';
initgraph(&gdriver, &gmode, "");


/*randomize();
for(i=0;i<100;i++)
{ ran=(rand()%600);
 sp[i].initialize(100*sin(ran),100*cos(ran),100);
} */

for(i=0;i<90;i++)
{ sp[i].initialize(100*cos(deg*4*i),100*sin(deg*4*i),0); }   //xy

for(i=90;i<180;i++)
{ sp[i].initialize(100*cos(deg*4*i),0,100*sin(deg*4*i)); }

for(i=180;i<270;i++)
{ sp[i].initialize(0,100*cos(deg*4*i),100*sin(deg*4*i)); }
/*
for(i=24;i<48;i++)
{ sp[i].initialize(100*cos(deg*15*i),100*sin(deg*15*i),0);
sp[i].rotate(0,pi/6,0); }


for(i=48;i<72;i++)
{ sp[i].initialize(100*cos(deg*15*i),100*sin(deg*15*i),0);
sp[i].rotate(0,2*pi/6,0); }


for(i=72;i<96;i++)
{ sp[i].initialize(100*cos(deg*15*i),100*sin(deg*15*i),0);
sp[i].rotate(0,3*pi/6,0); }


for(i=96;i<120;i++)
{ sp[i].initialize(100*cos(deg*15*i),100*sin(deg*15*i),0);
sp[i].rotate(0,4*pi/6,0); }

for(i=120;i<144;i++)
{ sp[i].initialize(100*cos(deg*15*i),100*sin(deg*15*i),0);
sp[i].rotate(0,5*pi/6,0); }

for(i=144;i<168;i++)
{ sp[i].initialize(100*cos(deg*15*i),100*sin(deg*15*i),0);
sp[i].rotate(0,6*pi/6,0); }

for(i=168;i<192;i++)
{ sp[i].initialize(100*cos(deg*15*i),100*sin(deg*15*i),0);
sp[i].rotate(0,7*pi/6,0); }


for(i=192;i<216;i++)
{ sp[i].initialize(100*cos(deg*15*i),0,100*sin(deg*15*i));
sp[i].rotate(pi/6,0,0); }

for(i=216;i<240;i++)
{ sp[i].initialize(100*cos(deg*15*i),0,100*sin(deg*15*i));
sp[i].rotate(2*pi/6,0,0); }

for(i=240;i<264;i++)
{ sp[i].initialize(100*cos(deg*15*i),0,100*sin(deg*15*i));
sp[i].rotate(3*pi/6,0,0); }//trnsq(45*deg,45*deg,0);

for(i=264;i<288;i++)
{ sp[i].initialize(100*cos(deg*15*i),0,100*sin(deg*15*i));
sp[i].rotate(4*pi/6,0,0); }
//joinl(15);


for(i=288;i<312;i++)
{ sp[i].initialize(100*cos(deg*15*i),0,100*sin(deg*15*i));
sp[i].rotate(5*pi/6,0,0); }

for(i=312;i<336;i++)
{ sp[i].initialize(100*cos(deg*15*i),0,100*sin(deg*15*i));
sp[i].rotate(6*pi/6,0,0); }

for(i=336;i<360;i++)
{ sp[i].initialize(100*cos(deg*15*i),0,100*sin(deg*15*i));
sp[i].rotate(7*pi/6,0,0); }   */

joinlq(15);


while(ch!=48)
{
ch=getch();
//joinl(0);
joinlq(0);

if(ch==75) //left
{trnsq(0,deg,0);
//trns(0,deg,0);}
		 }
else if(ch==77)//right
{//trns(0,-1*deg,0);
trnsq(0,-1*deg,0);}

else if(ch=='k')
{//trns(deg,0,0);
trnsq(deg,0,0);}

else if(ch=='m'){
//trns(-1*deg,0,0);
trnsq(-1*deg,0,0);}

else if(ch==80)//down arrow
{//trns(0,0,deg);
trnsq(0,0,deg); }

else if(ch==72)//up arrow
{//trns(0,0,-1*deg);
trnsq(0,0,-1*deg);}

//joinl(15);
joinlq(15);
}


}
