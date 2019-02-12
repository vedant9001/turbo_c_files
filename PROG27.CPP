#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>

const int r=2;
const int pw=5;
const int str=30;
const int no=1000;
const float pi= 3.14159;
const float l=5;
const float sc= 2.5;

class pob{
public:
float x;
float y;

void init(int x1,int y1){
x = x1;y = y1;    };

void prn()
{ circle(x,y,r);   } ;

};

void main()
{


int gdriver = DETECT, gmode, errorcode;
pob bob[no];
int j=0; //int t=0;        char ch='h';
initgraph(&gdriver, &gmode, "");


//while(ch!=48){ if(kbhit()){ch=getch();};

//t+=speed;
 setcolor(7);
for(j=0;j<no;j++)
{
 bob[j].init(str + pw*j  ,100);
 bob[j].prn();
 line (str + pw*j,0,str + pw*j,480  );  }

 setcolor(13);


for(j=0;j<no;j++)
{
 bob[j].init(str + pw*j + pw*sin(2*pi*pw*j/l) ,200);
 bob[j].prn(); } ;

for(j=0;j<no;j++){
line (str+ pw*j -(pw/2),300+ sc*(bob[j].x - str- (pw*j)), str + pw*j +(pw/2),300+sc*(bob[j].x-str- pw*j)); }
line(0,300,640,300);

//delay(100);


getch();

}
