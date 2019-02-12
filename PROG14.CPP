#include<iostream.h>
#include<time.h>
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
velocity.dir=0;
xpos=ypos=0;
charge=0;
}

void define(float m,float q,vector f1,int x1,int y1){
mass=m;
charge=q;
net_force=f1;
xpos=x=x1;
ypos=y=y1;
}

void update(float dt){
float vsin;
float vcos;
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
//velocity.val+=acc.val*dt;
//velocity.dir=acc.dir;

vsin=velocity.val*(sin(velocity.dir))+acc.val*(sin(acc.dir))*dt;
vcos=velocity.val*(cos(velocity.dir))+acc.val*(cos(acc.dir))*dt;


velocity.val=sqrt(pow(vsin,2)+pow(vcos,2));
velocity.dir=atan(vsin/vcos);


xpos+=(velocity.val)*dt*cos(velocity.dir);
ypos+=(velocity.val)*dt*sin(velocity.dir);
x=xpos;
y=ypos;
}

void disp(int col=15){
setcolor(col);
circle(x,y,5);
setcolor(15);
}

};

void main()
{
clock_t start, end;
float dt;
start=clock();
char chk='a';
object p1;
vector f;
int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "");

f.val=5;
f.dir=0;//p1.velocity.dir-pi/2;
p1.define(2,0,f,320,240);
p1.velocity.val=10;
p1.velocity.dir=0;
end=clock();
dt=(end-start)/(CLK_TCK);
p1.update(dt);
while(chk!=48)
{if(kbhit())
chk=getch();
start=clock();
 delay(100);
 end=clock();
 dt=(end-start)/(CLK_TCK);
// p1.disp(0);
p1.net_force.dir=p1.velocity.dir-pi/2;
 p1.update(dt);
 p1.disp(15);
 //p1.disp(7);
// cout<<"::"<<p1.xpos<<","<<dt<<","<<p1.ypos<<"::";
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