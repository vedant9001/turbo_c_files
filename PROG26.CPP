#include <iostream.h>
#include <graphics.h>
#include <dos.h>
#include <conio.h>
#include <math.h>

int main()
{clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
for(int i=0;i<100;i++)
{circle(250,300,i);
delay(50);
}


getch();
return 0;
}