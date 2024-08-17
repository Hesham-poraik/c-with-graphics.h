#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
main()
{
   int gdrive=DETECT,gmode,errorcode;
   initgraph(&gdrive,&gmode,(char*)"");
   setbkcolor(0);
   cleardevice();
   setcolor(14);
   setfillstyle(SOLID_FILL,14);
   for (int i = 0; i < 6; i++)                          //large shapes
   {
      rectangle(30-i,40-i,150+i,320+i);                 //case
      rectangle(170-i,40-i,580+i,270+i);                //screen
      circle(125,200,(10+i)/2);
      rectangle(325-i,270+i,425+i,310+i);
      rectangle(275-i,310+i,475+i,335+i);
      floodfill(276,320,14);
      rectangle(160-i,360+i,430+i,440+i);               //keyboard
      rectangle(450-i,350+i,550+i,450+i);                       //mouse
   }
   //case
   rectangle(40,50,140,90);
   rectangle(45,60,135,70);
   rectangle(120,75,130,80);
   rectangle(40,50,140,130);
   rectangle(40,50,140,170);
   rectangle(45,290,60,295);
   rectangle(65,290,80,295);
   rectangle(85,290,100,295);
   circle(110,293,2);
   circle(116,293,2);
   circle(122,293,2);

   //keyboard
   for (int y = 373; y < 430; y+=13)
   {
   for (int x = 165; x < 420; x+=12)
   {
   if (y>422){
      if (224<x){
         if (x<297){
            continue;
   }}}
   if (x>368){
      if (380>x){
         continue;
   }}
      rectangle(x,y,x+9,y+10);
   }}
   rectangle(225,425,294,435);
   
   //mouse
   rectangle(470,390,500,435);
   rectangle(472,409,498,433);
   floodfill(473,410,14);
   rectangle(470,390,500,407);
   rectangle(487,392,498,405);
   floodfill(488,393,14);
   rectangle(470,390,485,407);
   rectangle(472,392,483,405);
   floodfill(473,393,14);

   // motion
   setfillstyle(SOLID_FILL,0);
   setcolor(15);
   for (int i = 0; i < 310; i+=3)
   {
      circle(220+i,150,40);
      line(190,190,560,190);
      int X,Y,X_,Y_;
      X=30*sin((-i)*3.14/180);
      Y=30*cos(-i*3.14/180);
      X_=30*sin((-i*3.14/180)+1.5707963);
      Y_=30*cos((-i*3.14/180)+1.5707963);
      line(i+220-X,150-Y,i+220+X,150+Y);
      line(i+220-X_,150-Y_,i+220+X_,150+Y_);
      delay(50);
      bar(171,41,580,270);     //=> screen bar
      floodfill(175,45,0);
   }

   //screen name
   setcolor(15);
   settextstyle(10,0,9);
   outtextxy(200,45,"sherif");
   settextstyle(10,0,5);
   outtextxy(340,150,"(^_^)");

   // lood
   rectangle(190,210,560,230);
   for (int i = 0; i < 371; i++)
   {
      setcolor(15);
      rectangle(190,210,190+i,230);
      delay(20);
   }
   bar(171,41,580,270);     //=> screen bar
   floodfill(175,45,0);

   // sine and cosine wave
   float x,y;
   setcolor(15);
   line(180,155,570,155);
   line(565,151,570,155);
   line(565,159,570,155);
   line(180,50,180,260);
   line(180,50,184,55);
   line(180,50,176,55);
   line(184,255,180,260);
   line(176,255,180,260);
   for (x = 180; x < 565; x++)
   {
      y=90*sin((x-180)/0.3555555556*3.14/180);
      y=155-y;
      putpixel(x,y,4);
      delay(20);
   }
   setcolor(4);
   settextstyle(10,0,1);
   outtextxy(200,70,"sine wave");
   for (x = 180; x < 565; x++)
   {
      y=90*cos((x-180)/0.3555555556*3.14/180);
      y=155-y;
      putpixel(x,y,1);
      delay(20);
   }
   setcolor(1);
   outtextxy(190,220,"cosine wave");

   getch();
   closegraph();
}
/* -------------------------------------------------------
 coded By mohamed sherif
 Created on 10.3.2022
 
 -------------------------------------------------------*/


