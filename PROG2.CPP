#include<fstream.h>
#include<graphics.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

const int wid=140;
const int high=15;
const int gap=5;
const int phyq=40;
const int chmq=40;
const int matq=45;
const int engq=15;
const int logq=10;




class ques{    public:
int no;
char ans;
char key;
};

void disp_opt(int cx,int cy,int wd,int l,int n=1){
rectangle(cx-wd,cy-l,cx+n*wd,cy+l);
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

void disp_menu(){
//cout<<" ques :: "<<num<<" : "<<subj;
settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);
outtext("             :::QUESTION:::");


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
outtextxy(180,351,"EXIT");

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
int lo=7;
char ch='a';
int i=0;

//ofstream report1("file1.txt",ios::out|ios::binary);

//report1.close();



ofstream report;
report.open("file1.txt",ios::out|ios::app);

ques pcm[phyq+chmq+matq+engq+logq];

for(i=0;i<phyq+chmq+matq+engq+logq;i++){
pcm[i].ans='O';
}


int unap=0;
int donknow=0;
int unab=0;
int timles=0;
int unsee=0;
int ap=0;
int correct=0;
int incorrect=0;


int punap[5];
int pdonknow[5];
int punab[5];
int ptimles[5];
int punsee[5];
int pap[5];
int pcorrect[5];
int pincorrect[5];


float count=1;
int sub_count=1;
char sub_c='M';//     first maths then phy then chem then log then english

int gdriver = DETECT, gmode, errorcode;
initgraph(&gdriver, &gmode, "");

ch='a';


for(count=1;count<151;count++){

if(count<=matq)
{sub_count=count;
sub_c='M';}
else if(count<=phyq+matq)
{sub_count=count-matq;
sub_c='P';}
else if(count<=phyq+matq+chmq)
{sub_count=count-matq-phyq;
sub_c='C';}
else if(count<=phyq+matq+chmq+engq)
{sub_count=count-matq-phyq-chmq;
sub_c='E';}
else if(count<=phyq+matq+chmq+engq+logq)
{sub_count=count-matq-phyq-chmq-engq;
sub_c='L';}

closegraph();
clrscr();
initgraph(&gdriver, &gmode, "");

disp_menu();
selection(310,120+n*(2*high+gap),wid+3,high+3,10);
gotoxy(0,0);
cout<<" QUES :: "<<sub_count<<":"<<count<<":"<<sub_c;

ch='a';

while(ch!=48) {
ch=getch();
selection(310,120+n*(2*high+gap),wid+3,high+3,0);
check_arr(ch,n,up,lo);
selection(310,120+n*(2*high+gap),wid+3,high+3,10); }


if(n==6)
{pcm[count-1].ans='G';}

else if(n==0)
{pcm[count-1].ans='A';}

else if(n==1)
{pcm[count-1].ans='B';}

else if(n==2)
{pcm[count-1].ans='C';}

else if(n==3)
{pcm[count-1].ans='D';}

else if(n==4)
{pcm[count-1].ans='E';}

else if(n==5)
{pcm[count-1].ans='F'; }

else if(n==7){break;}

}
count=1;


cout<<endl<<endl<<endl<<"                    now provide answer key in order";
getch();
//clrscr();
//cout<<endl<<endl<<endl<<"                    hello 1 order";
//getch()

for(count=1;count<151;count++){


if(count<=matq)
{sub_count=count;  sub_c='M';}

else if(count<=phyq+matq)
{sub_count=count-matq;   sub_c='P';}

else if(count<=phyq+matq+chmq)
{sub_count=count-matq-phyq; sub_c='C';}

else if(count<=phyq+matq+chmq+engq)
{sub_count=count-matq-phyq-chmq;  sub_c='E';}

else if(count<=phyq+matq+chmq+engq+logq)
{sub_count=count-matq-phyq-chmq-engq;  sub_c='L';}

closegraph();
clrscr();
initgraph(&gdriver, &gmode, " ");

errorcode = graphresult();

if (errorcode != grOk)
{
   printf("Graphics error: %s\n", grapherrormsg(errorcode));
   printf("Press any key to halt:");
   getch();
   exit(1);
}





disp_menu();
selection(310,120+n*(2*high+gap),wid+3,high+3,10);
gotoxy(0,0);
cout<<" ANS :: "<<sub_count<<" : "<<count<<" : "<<sub_c;


ch='A';

while(ch!=48){
ch=getch();
selection(310,120+n*(2*high+gap),wid+3,high+3,0);
check_arr(ch,n,up,lo);
selection(310,120+n*(2*high+gap),wid+3,high+3,10);
}


if(n==6)
{pcm[count-1].key='X';}

else if(n==0)
{pcm[count-1].key='A';}

else if(n==1)
{pcm[count-1].key='B';}

else if(n==2)
{pcm[count-1].key='C';}

else if(n==3)
{pcm[count-1].key='D';}

else if(n==4)
{pcm[count-1].key='X';}

else if(n==5)
{pcm[count-1].key='X';}

else if(n==7)
{break;}

}

closegraph();
clrscr();
initgraph(&gdriver, &gmode, " ");

errorcode = graphresult();

if (errorcode != grOk)
{
   printf("Graphics error: %s\n", grapherrormsg(errorcode));
   printf("Press any key to halt:");
   getch();
   exit(1);
}


for(i=0;i<150;i++)
{

if(i<=matq)
{count=0;}

else if(i<=phyq+matq)
{count=1;}

else if(i<=phyq+matq+chmq)
{count=2;}

else if(i<=phyq+matq+chmq+engq)
{count=3;}

else if(i<=phyq+matq+chmq+engq+logq)
{count=4;}


if(pcm[i].ans=='E'){unap++;donknow++;punap[count]++;pdonknow[count]++;}
else if(pcm[i].ans=='F'){unap++;unab++;punap[count]++;punab[count]++;}
else if(pcm[i].ans=='G'){unap++;timles++;punap[count]++;ptimles[count]++;}
else if(pcm[i].ans=='O'){unap++;unsee++;punap[count]++;punsee[count]++;}
else if(pcm[i].ans==pcm[i].key){ap++;correct++;pap[count]++;pcorrect[count]++;}
else if(pcm[i].ans!=pcm[i].key){ap++;incorrect++;pap[count]++;pincorrect[count]++;}
report<<"ques :"<<i+1<<": "<<pcm[i].ans<<"   key: "<<pcm[i].key<<endl;
}

cout<<endl<<"                             REPORT CARD  ";
cout<<endl<<endl<<endl<<"                             ATTEMPTED :: "<<ap;
cout<<endl<<endl<<"                             UNATTEMPTED :: "<<unap;
cout<<endl<<endl<<"                             CORRECT :: "<<correct;
cout<<endl<<endl<<"                             INCORRECT :: "<<incorrect;
cout<<endl<<endl<<"                             MARKS :: "<<(3*correct-incorrect);
cout<<endl<<endl<<"                             UNSEE :: "<<unsee;
cout<<endl<<endl<<"                             DONT KNOW :: "<<donknow;
cout<<endl<<endl<<"                             UNABLE :: "<<unab;
cout<<endl<<endl<<"                             TIMELESS :: "<<timles;


report<<endl<<"                     REPORT CARD  ";
report<<endl<<endl<<endl<<"                     ATTEMPTED :: "<<ap<<"  math:: "<<pap[0]<<"  phys:: "<<pap[1]<<"  chem:: "<<pap[2]<<"  eng:: "<<pap[3]<<"  logic:: "<<pap[4];
report<<endl<<endl<<"                     UNATTEMPTED :: "<<unap<<"  math:: "<<punap[0]<<"  phys:: "<<punap[1]<<"  chem:: "<<punap[2]<<"  eng:: "<<punap[3]<<"  logic:: "<<punap[4];
report<<endl<<endl<<"   		  CORRECT :: "<<correct<<"  math:: "<<pcorrect[0]<<"  phys:: "<<pcorrect[1]<<"  chem:: "<<pcorrect[2]<<"  eng:: "<<pcorrect[3]<<"  logic:: "<<pcorrect[4];
report<<endl<<endl<<"                     INCORRECT :: "<<incorrect<<"  math:: "<<pincorrect[0]<<"  phys:: "<<pincorrect[1]<<"  chem:: "<<pincorrect[2]<<"  eng:: "<<pincorrect[3]<<"  logic:: "<<pincorrect[4];
report<<endl<<endl<<"                     MARKS :: "<<(3*correct-incorrect)<<"  math:: "<<(3*(pcorrect[0])-pincorrect[0])<<"  phys:: "<<(3*(pcorrect[1])-pincorrect[1])<<"  chem:: "<<(3*(pcorrect[2])-pincorrect[2])<<"  eng:: "<<(3*(pcorrect[3])-pincorrect[3])<<"  logic:: "<<(3*(pcorrect[4])-pincorrect[4]);
report<<endl<<endl<<"                     UNSEE :: "<<unsee<<"  math:: "<<punsee[0]<<"  phys:: "<<punsee[1]<<"  chem:: "<<punsee[2]<<"  eng:: "<<punsee[3]<<"  logic:: "<<punsee[4];
report<<endl<<endl<<"                     DONT KNOW :: "<<donknow<<"  math:: "<<pdonknow[0]<<"  phys:: "<<pdonknow[1]<<"  chem:: "<<pdonknow[2]<<"  eng:: "<<pdonknow[3]<<"  logic:: "<<pdonknow[4];
report<<endl<<endl<<"                     UNABLE :: "<<unab<<"  math:: "<<punab[0]<<"  phys:: "<<punab[1]<<"  chem:: "<<punab[2]<<"  eng:: "<<punab[3]<<"  logic:: "<<punab[4];
report<<endl<<endl<<"                     TIMELESS :: "<<timles<<"  math:: "<<ptimles[0]<<"  phys:: "<<ptimles[1]<<"  chem:: "<<ptimles[2]<<"  eng:: "<<ptimles[3]<<"  logic:: "<<ptimles[4];


report.close();
getch();


}


