#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
void car(int x,int y){
   circle(x,y-8,8);circle(x+40,y-8,8);ellipse(x+21,y-25,0,180,28,17);
   line(x+8,y-8,x+32,y-8);line(x-8,y-8,x-18,y-8);
   line(x+58,y-8,x+48,y-8);line(x+58,y-8,x+58,y-25);
   line(x-18,y-8,x-18,y-25);line(x+58,y-25,x-18,y-25);}
void plan(int x,int y){
   line(x,y,x+30,y-10);line(x,y,x+30,y+10);line(x+30,y,x+90,y);
   line(x+100,y-10,x+30,y-10);line(x+100,y+10,x+30,y+10);
   line(x+100,y-10,x+110,y);line(x+100,y+10,x+110,y);
   line(x+50,y+10,x+70,y+50);line(x+50,y-10,x+70,y-50);
   line(x+70,y+10,x+70,y+50);line(x+70,y-10,x+70,y-50);}
main(){
   int gdrive=DETECT,gmode,errorcode;
   initgraph(&gdrive,&gmode,(char*)"");
   int x=25,X=520,n,m;;POINT pex;
   car(x,370);line(0,370,640,370);
   line(580,370,580,330);
   rectangle(540,300,620,330);
   settextstyle(10,0,1);
   outtextxy(220,450,(char*)"to stop press < m >");
   settextstyle(10,0,3);
   outtextxy(550,303,(char*)"stop");
   plan(X,150);
   bool motion=true;
   while (1){
      if(kbhit()){
      char ch=getch();
      if(ch == 'm'){
         motion = false;}}
      if (motion){
         setcolor(0);
         car(x,370);
         plan(X,150);
         x+=2,X-=5;
         setcolor(15);
         line(580,370,580,330);
         rectangle(540,300,620,330);
         car(x,370);
         plan(X,150);
         delay(30);}
      rectangle(400,400,480,430);
      rectangle(150,400,230,430);
      outtextxy(405,403,(char*)"start");
      outtextxy(155,403,(char*)"reset");
      GetCursorPos(&pex);
      n=pex.x;
      m=pex.y;
      if (n>400 && n<480 && m>425 && m<455){
         if (GetAsyncKeyState(VK_LBUTTON)) motion = true;}
      if (n>150 && n<230 && m>425 && m<455){
         if (GetAsyncKeyState(VK_LBUTTON)) {
            setcolor(0);
            car(x,370);
            plan(X,150);
            x=25,X=520;
            motion = true;}}}
   closegraph();}