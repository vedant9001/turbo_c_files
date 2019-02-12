#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<time.h>
#include<stdio.h>

//float p,q,r;

//const int max=192;
const float pi=3.14159;
const float deg=pi/180;
float temp1,temp2,temp3;

class point{
public:
//int x,y,z;
float fx,fy,fz;

point(int a,int b,int c)
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
 fz=temp2;    }  }

void lintr(int x1,int x2,int x3,int y1,int y2,int y3,int z1,int z2,int z3){
temp1= x1*fx + y1*fy + z1*fz ;
temp2= x2*fx + y2*fy + z2*fz ;
temp3= x3*fx + y3*fy + z3*fz ;
fx=temp1;
fy=temp2;
fz=temp3;
}

//  x=fx;
 // y=fy;
 // z=fz;



};
float st=100;
float ena=-100;
float scl=0.7;
float zbuf[6];
float z2buf[6];


float scale(float fw) {
return ( ((fw-st)*(1-scl)/(st-ena))+1  );
}

void join(point p1,point p2,int color=1){
setcolor(0);
line(p1.fx*scale(p1.fz) +320, 240-(p1.fy*scale(p1.fz)),p2.fx*scale(p2.fz)+320,240-( p2.fy*scale(p2.fz)));
setfillstyle(1,15);}



int k=200;

/*point p1(100+k,100,100)
,p2(-100+k,100,100)
,p3(-100+k,-100,100)
,p4(100+k,-100,100)
,p5(100+k,100,-100)
,p6(-100+k,100,-100)
,p7(-100+k,-100,-100)
,p8(100+k,-100,-100);*/

point q1(100,100,100)
,q2(-100,100,100)
,q3(-100,-100,100)
,q4(100,-100,100)
,q5(100,100,-100)
,q6(-100,100,-100)
,q7(-100,-100,-100)
,q8(100,-100,-100);

/*void trns(float e1,float e2,float e3){
/*p1.rotate(e1,e2,e3);
p2.rotate(e1,e2,e3);
p3.rotate(e1,e2,e3);
p4.rotate(e1,e2,e3);
p5.rotate(e1,e2,e3);
p6.rotate(e1,e2,e3);
p7.rotate(e1,e2,e3);
p8.rotate(e1,e2,e3);
}
void joinl(int co){
/*join(p1,p2,co);
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
} */

void trnsq(float e1,float e2,float e3){
q1.rotate(e1,e2,e3);
q2.rotate(e1,e2,e3);
q3.rotate(e1,e2,e3);
q4.rotate(e1,e2,e3);
q5.rotate(e1,e2,e3);
q6.rotate(e1,e2,e3);
q7.rotate(e1,e2,e3);
q8.rotate(e1,e2,e3);


}


void skew(int x1,int x2,int x3,int y1,int y2,int y3,int z1,int z2,int z3){

q1.lintr(x1,x2,x3,y1,y2,y3,z1,z2,z3);
q2.lintr(x1,x2,x3,y1,y2,y3,z1,z2,z3);
q3.lintr(x1,x2,x3,y1,y2,y3,z1,z2,z3);
q4.lintr(x1,x2,x3,y1,y2,y3,z1,z2,z3);
q5.lintr(x1,x2,x3,y1,y2,y3,z1,z2,z3);
q6.lintr(x1,x2,x3,y1,y2,y3,z1,z2,z3);
q7.lintr(x1,x2,x3,y1,y2,y3,z1,z2,z3);
q8.lintr(x1,x2,x3,y1,y2,y3,z1,z2,z3);

}

void joinlq(int co){
join(q1,q2,co);
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


}



int poly1[6][8];

int least(){
int tn=0;
for(int u=1;u<6;u++)
{ if(z2buf[u]>z2buf[tn])
tn=u;
} z2buf[tn]=-500;
return tn;
}

float valx(point p1)
{return (p1.fx*scale(p1.fz) +320);}

float valy(point p2)
{return (240-(p2.fy*scale(p2.fz)));}

float quad(int n,point p1,point p2,point p3,point p4)
{
poly1[n][0]=valx(p1);
poly1[n][1]=valy(p1);

poly1[n][2]=valx(p2);
poly1[n][3]=valy(p2);

poly1[n][4]=valx(p3);
poly1[n][5]=valy(p3);

poly1[n][6]=valx(p4);
poly1[n][7]=valy(p4);

return ((p1.fz+p2.fz+p3.fz+p4.fz)/4);   }

void update(){
z2buf[0]=quad(0,q1,q2,q3,q4);   //ok
z2buf[1]=quad(1,q1,q2,q6,q5);   //ok
z2buf[2]=quad(2,q5,q6,q7,q8);   //ok
z2buf[3]=quad(3,q7,q8,q4,q3);   //ok
z2buf[4]=quad(4,q4,q1,q5,q8);   //ok
z2buf[5]=quad(5,q3,q2,q6,q7);   //ok

for(int i=0;i<6;i++)
{
zbuf[i]=least();
}

}
int colbuf[6]={1,2,3,4,5,6};
//ylop[8]={0,0,640,0,640,480,0,480};

void colorpoly(int inf=1)
{if(inf)
for(int i=1;i<=6;i++){
   setfillstyle(7,colbuf[zbuf[6-i]]);
   fillpoly(4, poly1[zbuf[6-i]]);
		       }
  else
for(int i=1;i<=6;i++){
   setfillstyle(1,0);
   fillpoly(4, poly1[zbuf[6-i]]);
		       }

}

void main()
{
int gdriver = DETECT, gmode, errorcode;
int i;
float ran;
char ch='a';
initgraph(&gdriver, &gmode, "");

///trnsq(45*deg,45*deg,0);
//skew(1,0,0,0,1,0,0,0,1);
//joinl(15);

update();
colorpoly();
//joinlq(1);



while(ch!=48)
{
ch=getch();
//joinl(0);

colorpoly(0);
joinlq(0);

if(ch==75) //left
{trnsq(0,deg,0);
//trns(0,deg,0);
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
{///trns(0,0,-1*deg);
trnsq(0,0,-1*deg);}
else if(ch=='i')
{st++;ena++;  }
else if(ch=='o')
{st--;ena--;}


update();
//joinl(15);
colorpoly();
//joinlq(0);
}


}
