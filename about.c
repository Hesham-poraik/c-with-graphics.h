#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
main()
{
int gdrive=DETECT,gmode,errorcode;
     initgraph(&gdrive,&gmode,(char*)"");
        initwindow(1080,710);
              settextstyle(1,0,5);
                  outtextxy(420,50,"about");
                       rectangle(260,100,760,650);
                           settextstyle(10,0,2);
                              setcolor(15);
                                               outtextxy(280,120," < This game is about collecting     >");
                                               outtextxy(280,150," < jewels but becarful from the      >");
                                               outtextxy(280,180," < monster who will try to catch you >");
                                               outtextxy(280,210," < You have to collect gems          >");
                                               outtextxy(280,240," < by using the arrow keys           >"); 
                                               outtextxy(280,270," < you can change how you            >");
                                               outtextxy(280,300," < can play from CONTROLS BUTTON     >");
                                               outtextxy(280,330," < the more jewels  you collect      >"); 
                                               outtextxy(280,360," < the higherleve up                 >");
                                               outtextxy(280,390," < version:1.0.0                     >");
                                               outtextxy(280,420," < made by :a group of best engneers >");
                                               setcolor(WHITE);
                                               circle(470,500,6);
                                               setcolor(WHITE);
                                               circle(510,500,6);
                                               setcolor(YELLOW);
                                               circle(490,520,50);
                                               arc(490,540,180,0,15);
                                               outtextxy(440,590,"GOOD LUCK");
                                               setcolor(RED);
                                               outtextxy(380,620,"to back press < Esc >");
                                               int ch=getch();
                                               if (ch==27)
                                              {
                                               cleardevice(); 
                                              }
                                                                                             getch();
                                                                                            closegraph();

}