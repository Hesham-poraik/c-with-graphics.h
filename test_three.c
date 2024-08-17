#include <stdio.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
main()
{
  int gdrive=DETECT,gmode,errorcode;
  initgraph(&gdrive,&gmode,(char*)"");
  initwindow(1080,710);
   setbkcolor(0);
   cleardevice();
   setcolor(15);
   setfillstyle(SOLID_FILL,3);
   int x,y;
   for (x = 0; x < 1080; x++)
   {
      y=50*sin(x/0.5*3.14/180);
      y=450-y;
      putpixel(x,y,15);
      putpixel(x,y-1,15);
      putpixel(x,y+1,15);

      delay(5);
   }

   for (x = 80; x < 360; x++)
   {
      setcolor(15);
      y=20*sin(x/0.3555555556*3.14/180);
      y=650-y;
      putpixel(x,y,15);
      delay(5);
   }
   for (x = 430; x < 720; x++)
   {
      setcolor(15);
      y=20*sin(x/0.3555555556*3.14/180);
      y=600-y;
      putpixel(x,y,15);
      delay(5);
   }
   for (x = 800; x < 1020; x++)
   {
      setcolor(15);
      y=20*sin(x/0.3555555556*3.14/180);
      y=650-y;
      putpixel(x,y,15);
     delay(5);
   }
   floodfill(1000,700,15);
   for (x = 0; x < 1080; x++)
   {
      y=100*sin(x/1.2*3.14/180);
      y=300-y;
      putpixel(x,y,15);
      delay(5);
   }
   for (int i = 0; i < 361; i+=1)
   {
      x=130*sin((i)*3.14/180);
      y=130*cos(i*3.14/180);
      putpixel(x,y,14);
      delay(10);
   }
  getch();
  closegraph();
}