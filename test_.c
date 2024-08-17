#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
main()
{
   int gdrive=DETECT,gmode,errorcode;
  initgraph(&gdrive,&gmode,(char*)"");
  initwindow(1080,720);
  int i;

for(i=5;i<400;i++)
{
   setcolor(3);
   circle(540,360,i);
   delay(10);

}
for(i=5;i<350;i++)
{
   setcolor(12);
   circle(540,360,i);
   delay(10);
   
}

for(i=5;i<300;i++)
{
   setcolor(7);
   circle(540,360,i);
   delay(10);
}
for(i=5;i<250;i++)
{
   setcolor(13);
   circle(540,360,i);
   delay(10);
}
for(i=5;i<200;i++)
{
   setcolor(9);
   circle(540,360,i);
   delay(10);

}
for(i=5;i<150;i++)
{
   setcolor(14);
   circle(540,360,i);
   delay(10);
   
}
for(i=5;i<100;i++)
{
   setcolor(11);
   circle(540,360,i);
   delay(10);
}
for(i=5;i<50;i++)
{
   setcolor(9);
   circle(540,360,i);
   delay(10);

}
cleardevice();
setcolor(15);
circle(540,360,100);
setfillstyle(1,14);
floodfill(540,360,15);
cleardevice();
float x,y ;
for (x = 0; x < 640; x++)
   {
      y=100*sin(x/0.444455*3.14/180);
      y=240-y;
      putpixel(x,y,14);
      delay(10);
      setcolor(RED);
      outtextxy(350,600,"EVERY THING WILL BE GOOD JUST WAIT");

setcolor(BLUE);
       outtextxy(400,650,"I KNOW YOU ARE EXCITED (<^O_O^>)");
      
   }
   cleardevice();
   rectangle(200,50,400,550);
    settextstyle(1,0,15);
       outtextxy(300,70,"about");

   getch();
   closegraph();
}