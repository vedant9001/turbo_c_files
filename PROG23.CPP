#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<dos.h>

int d=100;
int box[3][3];


int winnercheck()
{
for(int a=0;a<3;a++){
if((box[0][a]==1)&&(box[1][a]==1)&&(box[2][a]==1))
return 1;
if((box[0][a]==2)&&(box[1][a]==2)&&(box[2][a]==2))
return 2; }

for(a=0;a<3;a++)
{
if((box[a][0]==1)&&(box[a][1]==1)&&(box[a][2]==1))
return 1;
if((box[a][0]==2)&&(box[a][1]==2)&&(box[a][2]==2))
return 2; }

if((box[0][0]==1)&&(box[1][1]==1)&&(box[2][2]==1))
return 1;

if((box[0][0]==2)&&(box[1][1]==2)&&(box[2][2]==2))
return 2;

return 0;
}


void dec(int&pos,int a)
{int n;
int p;

if(a==1)
p=320;
else if(a==2)
p=240;

n=((pos-p+d)/d);

if(n==0)
pos=p+d;
else
pos=pos-d;

}

void inc(int&pos,int a)
{
int n;
int p;

if(a==1)
p=320;
else if(a==2)
p=240;

n=((pos-p+d)/d);

if(n==2)
pos=p-d;
else
pos=pos+d;
}


void selection(int x,int y)
{
d=d-14;

int space=(d*9)/20;
int hd=d/2;

line(x-hd,y-hd,x-hd+space,y-hd);
line(x+hd,y-hd,x+hd-space,y-hd);
line(x-hd,y-hd,x-hd,y-hd+space);
line(x+hd,y-hd,x+hd,y-hd+space);
line(x-hd,y+hd,x-hd+space,y+hd);
line(x+hd,y+hd,x+hd-space,y+hd);
line(x+hd,y+hd,x+hd,y+hd-space);
line(x-hd,y+hd,x-hd,y+hd-space);

d=d+14;
}
void circla(int x,int y)
{d=d-50;
 circle(x,y,d/2);
 d=d+50;}

void cross(int x,int y)
{
d=d-50;
line(x+d/2,y-d/2,x-d/2,y+d/2);
line(x-d/2,y-d/2,x+d/2,y+d/2);
d=d+50;
}



void frame()
{
line(320+d/2,240+d+d/2,320+d/2,240-d-d/2);
line(320-d/2,240+d+d/2,320-d/2,240-d-d/2);
line(320+d+d/2,240+d/2,320-d-d/2,240+d/2);
line(320+d+d/2,240-d/2,320-d-d/2,240-d/2);
}


void main()
{
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "");

int flag=0;
char ch;
int xpos=320-d,ypos=240-d;
int or=0;
int winner=0;

for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
box[i][j]=0;
int tr=1;

frame();
selection(xpos,ypos);


while(tr)
{
for(or=0;or!=5;)
{ch=getch();

if(ch==72)
or=1;
else if(ch==77)
or=2;
else if(ch==80)
or=3;
else if(ch==75)
or=4;
else if(ch==13)
or=5;
else if(ch==48)
exit(0);
else
or=0;

if(or==5)
{if(box[((xpos-320+d)/d)][((ypos-240+d)/d)]==0)
box[((xpos-320+d)/d)][((ypos-240+d)/d)]=1;
else
or=0;
}
else if(or==1)
dec(ypos,2);
else if(or==2)
inc(xpos,1);
else if(or==3)
inc(ypos,2);
else if(or==4)
dec(xpos,1);

clrscr();
frame();
selection(xpos,ypos);

for(i=0;i<3;i++)
for(j=0;j<3;j++)
if(box[i][j]==2)
circla((320-d+(d*i)),(240-d+(d*j)));

for(i=0;i<3;i++)
for(j=0;j<3;j++)
if(box[i][j]==1)
cross((320-d+(d*i)),(240-d+(d*j)));

}
winner=winnercheck();
if(winner==1)
{
gotoxy(34,4);
cout<<"cross wins!!!!";
getch();
exit(0);
}
else if(winner==2)
{
gotoxy(34,4);
cout<<"circle wins!!!!";
getch();
exit(0);
}


for(int u=0;u<3;u++)
for(int r=0;r<3;r++)
if(box[u][r]==0)
flag=4;

if(flag==0)
{
gotoxy(34,4);
cout<<"aww!!  draw!!";
getch();
exit(0);

}




for(or=0;or!=5;)
{
ch=getch();

if(ch==72)
or=1;
else if(ch==77)
or=2;
else if(ch==80)
or=3;
else if(ch==75)
or=4;
else if(ch==13)
or=5;
else if(ch==48)
exit(0);
else
or=0;


if(or==5)
{if(box[((xpos-320+d)/d)][((ypos-240+d)/d)]==0)
box[((xpos-320+d)/d)][((ypos-240+d)/d)]=2;
else
or=0;
}
else if(or==1)
dec(ypos,2);
else if(or==2)
inc(xpos,1);
else if(or==3)
inc(ypos,2);
else if(or==4)
dec(xpos,1);

clrscr();

frame();
selection(xpos,ypos);

for(i=0;i<3;i++)
for(j=0;j<3;j++)
if(box[i][j]==1)
cross((320-d+(d*i)),(240-d+(d*j)));


for(i=0;i<3;i++)
for(j=0;j<3;j++)
if(box[i][j]==2)
circla((320-d+(d*i)),(240-d+(d*j)));

}//for 2 end
winner=winnercheck();
if(winner==1)
{
gotoxy(30,4);
cout<<"cross wins!!!!";
getch();
exit(0);
}
else if(winner==2)
{
gotoxy(30,4);
cout<<"circle wins!!!!";
getch();
exit(0);}


for(u=0;u<3;u++)
for(r=0;r<3;r++)
if(box[u][r]==0)
flag=4;

if(flag==0)
{
gotoxy(34,4);
cout<<"aww!!  draw!!";
getch();
exit(0);

}





} //while 3 end



//main end
}