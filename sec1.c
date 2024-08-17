#include <stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
int pen(int x,int y);
int putmypixel(int x,int y,int n);
main()
{
   initwindow(1080,710);
   setfillstyle(1,3);
   int x,y;
   for (x = 0; x < 1080; x++){
      setcolor(15);
      y=50*sin(x/0.5*3.14/180);
      y=450-y;
      putmypixel(x,y,15);
      pen(x,y);}
   delay(40);
   for (x = 410; x < 670; x++){
      setcolor(15);
      y=20*sin(x/0.3555555556*3.14/180);
      y+=600;
      putpixel(x,y,15);
      pen(x,y);}
   for (x = 755; x < 1015; x++){
      setcolor(15);
      y=20*sin(x/0.3555555556*3.14/180+24);
      y+=600;
      putpixel(x,y,15);
      pen(x,y);
      }
   delay(30);
   floodfill(1000,700,15);
   for (x = 300; x < 710; x++){
      y=150*sin(((x+180)*0.6*3.14/180));
      y=422-y;
      int color=getpixel(x,y);
      if(color == 0){
      putmypixel(x,y,15);
      pen(x,y);}}
   for (x = 500; x < 1080; x++){
      y=220*sin((x*0.4*3.14/180)-61.3);
      y=420-y;
      int color=getpixel(x,y);
      if(color == 0){
      putmypixel(x,y,15);
      pen(x+2,y);}}
      setfillstyle(1,6);
      floodfill(820,265,15);
      floodfill(600,300,15);


      
   delay(50);
   for (int i = 0; i < 91; i+=1){
      x=130*sin(i*3.14/180);
      y=130*cos(i*3.14/180);
      setcolor(14);
      putmypixel(x,y,14);
      pen(x,y);}
      setfillstyle(1,14);
      floodfill (1,1,14);
   int n=0;
   while (1){
      for (x = 65; x < 325; x++){
         y=20*sin((x-n)/0.3555555556*3.14/180+20);
         y+=600;
         putpixel(x,y,3);}
      for (x = 410; x < 670; x++){
         y=20*sin((x-n)/0.3555555556*3.14/180);
         y+=600;
         putpixel(x,y,3);}
      for (x = 755; x < 1015; x++){
         y=20*sin((x-n)/0.3555555556*3.14/180+24);
         y+=600;
         putpixel(x,y,3);}
      n+=5;
      for (x = 65; x < 325; x++){
         y=20*sin((x-n)/0.3555555556*3.14/180+20);
         y+=600;
         putpixel(x,y,15);}
      for (x = 410; x < 670; x++){
         y=20*sin((x-n)/0.3555555556*3.14/180);
         y+=600;
         putpixel(x,y,15);}
      for (x = 755; x < 1015; x++){
         y=20*sin((x-n)/0.3555555556*3.14/180+24);
         y+=600;
         putpixel(x,y,15);}
      delay(600);}
   getch();
   closegraph();
}
int pen(int x,int y){
   int points[]={x+3,y-3,x+20,y-10,x+60,y-60,x+50,y-70,x+10,y-20,x+3,y-3,x+20,y-10,x+10,y-20,x+56,y-77,x+66,y-67,x+58,y-58,x+48,y-68};
   setcolor(15);
   setlinestyle(0,0,2);
   drawpoly(12,points);
   delay(10);
   setcolor(0);
   drawpoly(12,points);
   return(0);
}
int putmypixel(int x,int y,int n)
{
   putpixel(x,y,n);
   putpixel(x+1,y,n);
   putpixel(x-1,y,n);
   putpixel(x,y+1,n);
   putpixel(x,y-1,n);
   putpixel(x+1,y+1,n);
   putpixel(x+1,y-1,n);
   putpixel(x-1,y+1,n);
   putpixel(x-1,y-1,n);
   return(0);
}