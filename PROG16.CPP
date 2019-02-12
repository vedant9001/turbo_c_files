#include<fstream.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

const int wid=140;
const int high=15;
const int gap=5;
const int phyq=40;
const int chmq=40;
const int matq=45;
const int engq=15;
const int logq=10;


void disp_opt(int cx,int cy,int wd,int l,int n=1){
rectangle(cx-wd,cy-l,cx+n*wd,cy+l);
}

class ques{    public:
int no;
char ans;
char key;
};

class item{ public:
char ch1;
char item_name[20];
float quantity;
float item_code;
float price;

item(int q){
strcpy(item_name,"");
quantity=q;
item_code=0;
price=0;
}

void getdata(int,int);
void putdata(int);
void putframe(); };

void item :: getdata(int x=310,int y=150){
settextstyle(SMALL_FONT,HORIZ_DIR,5);

outtextxy(x-310,y-10,"ENTER NAME OF THE PRODUCT ");
disp_opt(x,y,50,10,2);
outtextxy(x-310,y-10+32,"ENTER ITEM CODE (PRODUCT ID) ");
disp_opt(x,y+32,50,10,2);
outtextxy(x-310,y-10+64,"ENTER PRICE PER UNIT ");
disp_opt(x,y+64,50,10,2);
outtextxy(x-310,y-10+96,"ENTER QUANTITY ADDED ");
disp_opt(x,y+96,50,10,2);

gotoxy(34,10);cin.get(ch1);
gotoxy(34,10);cin.getline(item_name,20);
gotoxy(34,12);cin>>item_code;
gotoxy(34,14);cin>>price;
gotoxy(34,16);cin>>quantity;
outtextxy(x-310+100,y-10-32,"!! ITEM ADDED TO WAREHOUSE !!");
}

void item :: putframe(){
settextstyle(SMALL_FONT,HORIZ_DIR,5);
outtextxy(15,5,"PRODUCT");
outtextxy(260,5,"PRODUCT ID");
outtextxy(410,5,"PRICE");
outtextxy(530,5,"QUANTITY");
line(250,0,250,470);
line(400,0,400,470);
line(520,0,520,470);
line(635,0,635,470);
line(5,0,5,470);
line(5,22,635,22);
line(5,470,635,470);
}

void item :: putdata(int n){
gotoxy(4,n+3);cout<<ch1;
gotoxy(5,n+3);cout.write(item_name,10);
gotoxy(5,n+3);cout<<"";
gotoxy(34,n+3);cout<<item_code;
gotoxy(54,n+3);cout<<price;
gotoxy(69,n+3);cout<<quantity;

}

void selection(int cx,int cy,int wd,int l,int color=15){
setcolor(color);
rectangle(cx-wd,cy-l,cx+wd,cy+l);
setcolor(0);
line(cx-0.1*wd,cy-l,cx+0.1*wd,cy-l);
line(cx-0.1*wd,cy+l,cx+0.1*wd,cy+l);
line(cx-wd,cy-0.2*l,cx-wd,cy+0.2*l);
line(cx+wd,cy-0.2*l,cx+wd,cy+0.2*l);
setcolor(15);
}

class costumer{  public:
char ch1;
char name[20];
float quantity;
float c_item;
float amount;

costumer(int q)
{
strcpy(name,"");
c_item=0;
amount=0;
quantity=q;
}

void getdata(int,int);
void putframe();
void putdata(int);
void generate_inv(item);
};

void costumer :: getdata(int x=310,int y=150){
settextstyle(SMALL_FONT,HORIZ_DIR,5);
outtextxy(x-310,y-10,"ENTER NAME OF THE CUSTOMER ");
disp_opt(x,y,50,10,2);
outtextxy(x-310,y-10+32,"ENTER ITEM PURCHASED (CODE) ");
disp_opt(x,y+32,50,10,2);
outtextxy(x-310,y-10+64,"ENTER QUANTITY PURCHASED ");
disp_opt(x,y+64,50,10,2);
gotoxy(34,10);cin.get(ch1);
gotoxy(34,10);cin.getline(name,20);
gotoxy(34,12);cin>>c_item;
gotoxy(34,14);cin>>quantity;



}

void costumer :: putframe(){
settextstyle(SMALL_FONT,HORIZ_DIR,5);
outtextxy(15,5,"COSTUMER");
outtextxy(260,5,"PRODUCT ID");
outtextxy(410,5,"QUANTITY");
outtextxy(530,5,"AMOUNT");
line(250,0,250,470);
line(400,0,400,470);
line(520,0,520,470);
line(635,0,635,470);
line(5,0,5,470);
line(5,22,635,22);
line(5,470,635,470);
}

void costumer :: putdata(int n){

settextstyle(SMALL_FONT,HORIZ_DIR,5);
gotoxy(4,n+3);cout<<ch1;
gotoxy(5,n+3);cout.write(name,12);cout<<"     ";
gotoxy(5,n+3);cout<<"";
gotoxy(34,n+3);cout<<c_item;
gotoxy(54,n+3);cout<<quantity;
gotoxy(69,n+3);cout<<amount;

}


void costumer :: generate_inv(item i0){
amount = i0.price*quantity;
rectangle(150,50,510,100);
rectangle(150,100,510,300);
rectangle(150,300,510,350);
rectangle(450,100,510,300);
line(350,100,350,350);
outtextxy(290,55,"INVOICE");
gotoxy(24,10);
cout<<i0.ch1;
gotoxy(25,10);
cout.write(i0.item_name,10);
gotoxy(25,10);
cout<<" ";
gotoxy(48,10);
cout<<i0.price;
gotoxy(58,10);
cout<<quantity;
gotoxy(50,21);
cout<<amount;

outtextxy(200,320,"AMOUNT");
outtextxy(230,400,"!!THANKS FOR SHOPPING!!");


}





void disp_menu(){
settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
outtext("           :::QUESTION:::");

for(int i=0;i<=7;i++)
disp_opt(310,120+i*(2*high+gap),wid,high);

settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
outtextxy(180,106,"A");
outtextxy(180,141,"B");
outtextxy(180,176,"C");
outtextxy(180,211,"D");
outtextxy(180,246,"DONT KNOW AT ALL");
outtextxy(180,281,"NOT GETTING ANSWER");
outtextxy(180,316,"TIME CONSUMING SO LEFT");
outtextxy(180,316,"        EXIT");

}

int check_arr(char ch,int&n,int up,int lo){
if(ch==72){
if(n>up)
n--;
else
n=lo;
return 1;  }
else if(ch==80)
{if(n<lo)
n++;
else
n=up;
return 2;    }
else if(ch==75)
return 3;
else if(ch==74)
return 4;
else if(ch=='\0')
return 5;
return 0;
}

void main(){
int n=0;
int up=0;
int lo=6;
char ch='a';
costumer c1(0),c2(0),c3(0);
item i1(0),i2(0),i3(0),i4(0);
int flag=1;
int count;

ofstream i1_list("file1.txt",ios::out|ios::binary);
ofstream c1_list("file2.txt",ios::out|ios::binary);


i1_list.close();
c1_list.close();



fstream i_list;
i_list.open("file1.txt",ios::in|ios::out|ios::app|ios::binary);
fstream c_list;
c_list.open("file2.txt",ios::in|ios::out|ios::app|ios::binary);

ques pcm[phyq+chmq+matq+engq+logq];

int count;//     first maths then phy then chem then log then english

int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "");

heaven:
ch='a';
closegraph();
clrscr();
initgraph(&gdriver, &gmode, "");


disp_menu();
selection(310,120+n*(2*high+gap),wid+3,high+3);


while(ch!=48){
ch=getch();
selection(310,120+n*(2*high+gap),wid+3,high+3,0);
check_arr(ch,n,up,lo);
selection(310,120+n*(2*high+gap),wid+3,high+3);
}
if(n==6)
{
pcm[count].ans='G';
}

else if(n==0)
{
pcm[count].ans='A';
}

else if(n==1)
{
pcm[count].ans='B';
}
else if(n==2)
{
pcm[count].ans='C';
}
else if(n==3)
{
pcm[count].ans='D';
}
else if(n==4)
{
pcm[count].ans='E';
}
else if(n==5)
{
pcm[count].ans='F';
}



hell:
;
}


