#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<stdio.h>
#include<math.h>

const int prtcl=10;
const float pi=3.1495;

struct vector{
float val;
float dir;
};

class object{
public:
vector force[prtcl];
vector net_force;
vector acc;
float mass;
float charge;
vector velocity;
float xpos,ypos;
int x,y;

object(){
mass=1;
velocity.val=0;
xpos=ypos=0;
charge=0;
}

void define(float m,float q,vector f1,int x1,int y1){
mass=m
charge=q;
netforce=f1;
xpos=x=x1;
ypos=y=y1;
}

void update(clock_t dt){
float fsin;
float fcos;
/*
for(int i=0;i<prtcl;i++)
{fsin+=force[i].val*(sin(force[i].dir));
fcos+=force[i].val*(cos(force[i].dir));
}

net_force.val=sqrt(pow(fsin,2)+pow(fcos,2));
net_force.dir=atan(fsin/fcos);
*/
acc.val=net_force.val/mass;
acc.dir=net_force.dir;
velocity.val+=acc.val*dt;
velocity.dir=acc.dir
xpos+=(velocity.val)*dt*cos(velocity.dir);
ypos+=(velocity.val)*dt*sin(velocity.dir);
x=xpos;
y=ypos;
}

void disp(int col=15){
putpixel(x,y,col);
}

};

void main()
{ clock_t start, end, dt;
start=clock();
int r=0;
object p1;
vector f;
f.val=10;
f.dir=pi/4;
p1.define(2,0,f,320,240);
end=clock();
dt=end-start;
p1.update(dt);
while(r<30)
{start=clock();
 delay(100);
 p1.disp(0);
 end=clock();
 dt=start-end;
 p1.update(dt);
 p1.disp();
r++
}
getch();
}


/*
int main(void)
{
   clock_t start, end;
   start = clock();

   delay(2000);

   end = clock();
   printf("The time was: %f\n", (end - start) / CLK_TCK);

   return 0;
}
  */