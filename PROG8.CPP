#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>

const int rad=5;

void dec(int&q,int a)
{
if(q<=10)
{if(a==1)
q=650;
else if(a==2)
q=370;}
else
q=q-(2*rad);
}
void inc(int&q,int a)
{if(a==1&&q>=650)
 q=10;
 else if(a==2&&q>=370)
 q=10 ;
 else
 q=q+(2*rad);
}

void gol(int x,int y)
{circle(x,y,rad);}
void golh(int x,int y)
{circle(x,y,rad);
circle(x,y,(rad/2));
}
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

void fixg(int&x,int&y,int or)
{if(or==1)
inc(y,2);
if(or==2)
dec(x,1);
if(or==3)
dec(y,2);
if(or==4)
inc(x,1);
}

void main()
{
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "");

setcolor(0);

char c='x',ca='q';
int or=1,or1=1;
int xpos=300,ypos=100;
int hx[10],hy[10];
int count=3;

for(int flag=1;flag==1; )
{
if(kbhit())
{ca=getch();
if(ca==72||ca==77||ca==80||ca==48||ca==75)
c=ca;
}
if(c==72)
or1=1;
else if(c==77)
or1=2;
else if(c==80)
or1=3;
else if(c==75)
or1=4;
else if(c==48)
flag=0;

if(((or==1)&&(or1!=3))||((or==2)&&(or1!=4))||((or==3)&&(or1!=1))||((or==4)&&(or1!=2)))
or=or1;

for(int i=0;i<9;i++)
{hx[i]=hx[i+1];
hy[i]=hy[i+1];}

hx[9]=xpos;
hy[9]=ypos;

if((xpos==220)&&(ypos==210))
count++;

move(ypos,xpos,or);


if(count>9)
count=9;

clrscr();
golh(xpos,ypos);
for(int a=9;a>=(9-count);a--)
gol(hx[a],hy[a]);

circle(220,210,10);

delay(100);

}

}