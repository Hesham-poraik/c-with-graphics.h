#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
main()
{
   int gdrive=DETECT,gmode,errorcode;
   initgraph(&gdrive,&gmode,(char*)"");
   setfillstyle(SOLID_FILL,0);
   setcolor(14);
   for (int i = 0; i < 3100; i+=3)
   {
      int X,Y,X_,Y_,x,x_,y_;
      X=200*sin((-i)*3.14/180);
      x=200*sin((i)*3.14/180);
      Y=200*cos(-i*3.14/180);
      X_=200*sin((-i*3.14/180)+1.5707963);
      x_=200*sin((i*3.14/180)+1.5707963);
      Y_=200*cos((-i*3.14/180)+1.5707963);
      y_=200*cos((i*3.14/180)+1.5707963);
      line(320-X,240-Y,320+X_,240+Y_);
      line(320-X,240-Y,320-X_,240-Y_);
      line(320+X,240+Y,320+X_,240+Y_);
      line(320+X,240+Y,320-X_,240-Y_);

      line(320-x,240-Y,320+x_,240+y_);
      line(320-x,240-Y,320-x_,240-y_);
      line(320+x,240+Y,320+x_,240+y_);
      line(320+x,240+Y,320-x_,240-y_);
      circle(320,240,200);
      delay(50);
      cleardevice();
   }
   getch();
   closegraph();
}