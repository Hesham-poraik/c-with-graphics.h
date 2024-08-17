#include <stdio.h>
#include <graphics.h>
#include <conio.h>
main(){
    initwindow(1080,710,"jewels_game",130,20);
    setfillstyle(SOLID_FILL,0);
    bar(20,100,1060,700);
    setcolor(RED);
    settextstyle(10,0,10);
    outtextxy(200,150,(char*)"game over");
    setlinestyle(0,0,5);
    arc(540,570,30,140,100);
    ellipse(540,450,0,360,220,140);
    circle(430,400,30);
    circle(650,400,30);
    getch();
    closegraph();
}