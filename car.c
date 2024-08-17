#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
void car(int x,int y)
{
   // rectangle();
   circle(x,y-8,8);
   circle(x+40,y-8,8);
   line(x+8,y-8,x+32,y-8);
   line(x-8,y-8,x-18,y-8);
   line(x+58,y-8,x+48,y-8);
   line(x+58,y-8,x+58,y-25);
   line(x-18,y-8,x-18,y-25);
   line(x+58,y-25,x-18,y-25);
   ellipse(x+21,y-25,0,180,28,17);
}
void plan(int x,int y)
{
   line(x,y,x+30,y-10);
   line(x,y,x+30,y+10);
   line(x+100,y-10,x+30,y-10);
   line(x+100,y+10,x+30,y+10);
   line(x+100,y-10,x+110,y);
   line(x+100,y+10,x+110,y);
   line(x+50,y+10,x+70,y+50);
   line(x+50,y-10,x+70,y-50);
   line(x+70,y+10,x+70,y+50);
   line(x+70,y-10,x+70,y-50);
   line(x+30,y,x+90,y);
}
main()
{
   int gdrive=DETECT,gmode,errorcode;
   initgraph(&gdrive,&gmode,(char*)"");
   setlinestyle(0,0,2);
   car(20,370);
   line(0,370,640,370);
   line(580,370,580,330);
   rectangle(540,300,620,330);
   outtextxy(540,300,(char*)"c");
   plan(520,150);
   while (1)
   {
      /* code */
   }
   
   
   closegraph();
}