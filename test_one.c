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
   float x,y;
   line(0,240,640,240);
   line(0,140,0,340);
   for (x = 0; x < 640; x++)
   {
      y=100*sin(x/0.3555555556*3.14/180);
      y=240-y;
      putpixel(x,y,14);
      delay(10);
   }
   outtextxy(5,150,"sine wave");
   for (x = 0; x < 640; x++)
   {
      y=100*cos(x/0.3555555556*3.14/180);
      y=240-y;
      putpixel(x,y,3);
      delay(10);
   }
   setcolor(3);
   outtextxy(30,320,"cosine wave");
   getch();
   closegraph();

}


