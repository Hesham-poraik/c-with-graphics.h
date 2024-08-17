#include<stdio.h>
#include<graphics.h>
#include<conio.h>
int won();
int game_over();
int wall_one(int N,int M);
int wall_two(int n,int m);
int monster_one(int X_,int Y_);
int player(int X,int Y);
int jewel(int x,int y);

main()
{
   initwindow(1080,710,"jewels_game",130,20);
   setbkcolor(0);
   cleardevice();
   setcolor(15);
   int score=0,level=1,lose=3;
   int x=42,y=227,X=60,Y=145,X_=200,Y_=145;
   //                          ==>starting
   // for (int i = 0; i < count; i++)
   // {
   //    /* code */
   // }
   
   // delay(100);
   // setfillstyle(SOLID_FILL,0);
   // bar(20,100,1060,700);

   //                          ==>frame
   for (int i = 0; i < 1020; i+=40)
   {
   rectangle(10+i,10,60+i,20);
   rectangle(10+i,90,60+i,100);
   rectangle(10+i,690,60+i,700);
   setfillstyle(SOLID_FILL,10^2);
   floodfill(30+i,11,15);
   floodfill(30+i,91,15);
   floodfill(30+i,691,15);

   }
   for(int i = 0; i <680 ; i+=40)
   {
   rectangle(10,10+i,20,60+i);
   rectangle(1060,10+i,1070,60+i);
   setfillstyle(SOLID_FILL,10^2);
   floodfill(11,30+i,15);
   floodfill(1061,30+i,15);
   }
   for(int i = 0; i <580 ; i+=40)
   {
   rectangle(1010,90+i,1020,140+i);
   floodfill(1011,120+i,15);
   }
   //score_bar
   rectangle(1020,690,1060,685-(score*39));
   floodfill(1021,686-(score*39),15);

   line(70,30,550,30);
   line(70,80,550,80);
   ellipse(70,55,90,270,15,25);
   ellipse(550,55,270,90,15,25);
   setfillstyle(SOLID_FILL,15);
   settextstyle(10,0,5);
   outtextxy(85,35,(char*)"score:0");
   outtextxy(340,35,(char*)"level:1");

   line(800,30,1000,30);
   line(800,80,1000,80);
   ellipse(800,55,90,270,15,25);
   ellipse(1000,55,270,90,15,25);
   char val3[20];
   sprintf(val3,"lose:+%d",lose);
   outtextxy(810,35,val3);

   // game_map
   wall_one(100,0);
   wall_one(200,0);
   wall_one(400,0);
   wall_one(600,0);
   wall_one(700,0);
   wall_one(0,100);
   wall_one(100,100);
   wall_one(200,100);
   wall_one(700,100);
   wall_one(300,200);
   wall_one(400,200);
   wall_one(600,200);
   wall_one(800,200);
   wall_one(100,300);
   wall_one(200,300);
   wall_one(400,300);
   wall_one(700,300);
   wall_one(800,300);
   wall_one(900,300);
   wall_one(100,400);
   wall_one(200,400);
   wall_one(300,400);
   wall_one(600,400);
   wall_one(700,400);
   wall_one(800,400);

   wall_two(700,100);
   wall_two(400,200);
   wall_two(600,200);
   wall_two(900,200);
   wall_two(200,300);
   wall_two(500,300);
   wall_two(700,300);
   wall_two(900,300);
   wall_two(100,400);
   wall_two(300,400);
   wall_two(400,500);
   wall_two(600,500);
   wall_two(500,600);

   monster_one(200,145);

   player(60,145);

   jewel(42,227);


   //                      ==>>motion
   while (1)
   {
   int ch=getch();
   if(ch==77)
   {
      if (X==980) continue;
      if (Y>155){
         if (Y<235){
            if (X==80)
            continue;
            if (X==380)
            continue;
            if (X==580)
            continue;
            if (X==880)
            continue;
         }}
      if (Y>255){
         if (Y<335){
            if (X==380)
            continue;
            if (X==480)
            continue;
            if (X==580)
            continue;
            if (X==680)
            continue;
            if (X==880)
            continue;
         }}
      if (Y>355){
         if (Y<435){
            if (X==80)
            continue;
            if (X==180)
            continue;
            if (X==280)
            continue;
            if (X==580)
            continue;
            if (X==780)
            continue;
         }}
      if (Y>455){
         if (Y<535){
            if (X==80)
            continue;
            if (X==380)
            continue;
            if (X==580)
            continue;
            if (X==680)
            continue;
         }}
      if (Y>555){
         if (Y<635){
            if (X==80)
            continue;
            if (X==480)
            continue;
            if (X==580)
            continue;
         }}

      if (Y>155)
      if (X==980){
         continue;
      }
      
      if (Y>125){
         if (Y<165){
            if(X==680){
               continue;
            }
            }}

      if (Y>225){
         if (Y<265){
            if(X==380){
               continue;
            }
            if (X==580){
               continue;
            }
            if (X==880){
               continue;
            }
            }}

      if (Y>325){
         if (Y<365){
            if(X==180){
               continue;
            }
            if (X==480){
               continue;
            }
            if (X==680){
               continue;
            }
            if (X==880){
               continue;
            }
            }}

      if (Y>425){
         if (Y<465){
            if(X==80){
               continue;
            }
            if (X==280){
               continue;
            }
            }}

      if (Y>525){
         if (Y<565){
            if(X==380){
               continue;
            }
            if (X==580){
               continue;
            }
            }}

      if (Y>625){
         if (Y<665){
            if(X==480){
               continue;
            }
            }}
      
      setcolor(10);
      setfillstyle(SOLID_FILL,0);
      bar(X-25,Y-25,X+25,Y+25);
      floodfill(X,Y,0);
      X+=10;
      setcolor(15);
      arc(0+X,0+Y,30,330,25);
      line(0+X,0+Y,21+X,-12+Y);
      line(0+X,0+Y,21+X,12+Y);
      setfillstyle(SOLID_FILL,14);
      floodfill(X-1,Y-1,15);
      setcolor(0);
      circle(X+8,Y-12,3);
      circle(X+8,Y-12,2);

   }
   if(ch==75)
   {
      if (X<60)continue;
      if (Y>155){
         if (Y<235){
            if (X==950)
            continue;
            if (X==350)
            continue;
            if (X==550)
            continue;
            if (X==850)
            continue;
         }}
      if (Y>255){
         if (Y<335){
            if (X==350)
            continue;
            if (X==450)
            continue;
            if (X==550)
            continue;
            if (X==650)
            continue;
            if (X==850)
            continue;
            if (X==950)
            continue;
         }}
      if (Y>355){
         if (Y<435){
            if (X==950)
            continue;
            if (X==150)
            continue;
            if (X==250)
            continue;
            if (X==550)
            continue;
            if (X==750)
            continue;
         }}
      if (Y>455){
         if (Y<535){
            if (X==350)
            continue;
            if (X==550)
            continue;
            if (X==650)
            continue;
         }}
      if (Y>555){
         if (Y<635){
            if (X==950)
            continue;
            if (X==450)
            continue;
            if (X==550)
            continue;
         }}



      if (X==50){
         continue;
      }
      if (Y>125){
         if (Y<165){
            if(X==750){
               continue;
            }
            }}

      if (Y>225){
         if (Y<265){
            if(X==450){
               continue;
            }
            if (X==650){
               continue;
            }
            if (X==950){
               continue;
            }
            }}

      if (Y>325){
         if (Y<365){
            if(X==250){
               continue;
            }
            if (X==550){
               continue;
            }
            if (X==750){
               continue;
            }
            if (X==950){
               continue;
            }
            }}

      if (Y>425){
         if (Y<465){
            if(X==150){
               continue;
            }
            if (X==350){
               continue;
            }
            }}

      if (Y>525){
         if (Y<565){
            if(X==450){
               continue;
            }
            if (X==650){
               continue;
            }
            }}

      if (Y>625){
         if (Y<665){
            if(X==550){
               continue;
            }
            }}
      
      setcolor(10);
      setfillstyle(SOLID_FILL,0);
      bar(X-25,Y-25,X+25,Y+25);
      floodfill(X,Y,0);
      X-=10;
      setcolor(15);
      arc(0+X,0+Y,210,150,25);
      line(0+X,0+Y,-21+X,-12+Y);
      line(0+X,0+Y,-21+X,12+Y);
      setfillstyle(SOLID_FILL,14);
      floodfill(X+1,Y+1,15);
      setcolor(0);
      circle(X-8,Y-12,3);
      circle(X-8,Y-12,2);
   }
   if(ch==72)
   {
   if (Y==135) continue;
   if (Y>225){
      if (Y<245){
         if(X>80){
            if (X<350) continue;
         }
         if(X>380){
            if (X<550) continue;
         }
         if(X>580){
            if (X<850) continue;
         }
         if(X>880){
            if (X<950) continue;
         }
         }}

   if (Y>325){
      if (Y<345){
         if(X>20){
            if (X<350) continue;
         }
         if(X>380){
            if (X<450) continue;
         }
         if(X>580){
            if (X<650) continue;
         }
         if(X>680){
            if (X<850) continue;
         }
         }}

   if (Y>425){
      if (Y<445){
         if(X>180){
            if (X<250) continue;
         }
         if(X>280){
            if (X<550) continue;
         }
         if(X>580){
            if (X<750) continue;
         }
         if(X>780){
            if (X<950) continue;
         }
         }}

   if (Y>525){
      if (Y<545){
         if(X>80){
            if (X<350) continue;
         }
         if(X>380){
            if (X<550) continue;
         }
         if(X>680){
            if (X<1050) continue;
         }
         }}

   if (Y>625){
      if (Y<645){
         if(X>80){
            if (X<450) continue;
         }
         if(X>580){
            if (X<950) continue;
         }
         }}


      setcolor(10);
      setfillstyle(SOLID_FILL,0);
      bar(X-25,Y-25,X+25,Y+25);
      floodfill(X,Y,0);
      Y-=10;
      setcolor(15);
      arc(0+X,0+Y,120,60,25);
      line(0+X,0+Y,12+X,-21+Y);
      line(0+X,0+Y,-12+X,-21+Y);
      setfillstyle(SOLID_FILL,14);
      floodfill(X+1,Y+1,15);
      setcolor(0);
      circle(X+14,Y-10,3);
      circle(X+14,Y-10,2);
   }
   if(ch==80)
   {

      if (Y==655) continue;

      if (Y>145){
         if (Y<165){
            if(X>80){
               if (X<350) continue;
            }
            if(X>380){
               if (X<550) continue;
            }
            if(X>580){
               if (X<850) continue;
            }
            if(X>880){
               if (X<950) continue;
            }
            }}

      if (Y>245){
         if (Y<265){
            if(X>20){
               if (X<350) continue;
            }
            if(X>480){
               if (X<550) continue;
            }
            if(X>680){
               if (X<850) continue;
            }
            }}

      if (Y>345){
         if (Y<365){
            if(X>80){
               if (X<150) continue;
            }
            if(X>180){
               if (X<250) continue;
            }
            if(X>280){
               if (X<550) continue;
            }
            if(X>580){
               if (X<750) continue;
            }
            if(X>780){
               if (X<950) continue;
            }
            }}

      if (Y>445){
         if (Y<465){
            if(X>80){
               if (X<350) continue;
            }
            if(X>380){
               if (X<550) continue;
            }
            if(X>580){
               if (X<650) continue;
            }
            if(X>680){
               if (X<1050) continue;
            }
            }}

      if (Y>545){
         if (Y<565){
            if(X>80){
               if(X>480){
                  if (X<550) continue;
               }
               if (X<450) continue;
            }
            if(X>580){
               if (X<950) continue;
            }
            }}

      setcolor(10);
      setfillstyle(SOLID_FILL,0);
      bar(X-25,Y-25,X+25,Y+25);
      floodfill(X,Y,0);
      Y+=10;
      setcolor(15);
      arc(0+X,0+Y,300,240,25);
      line(0+X,0+Y,12+X,21+Y);
      line(0+X,0+Y,-12+X,21+Y);
      setfillstyle(SOLID_FILL,14);
      floodfill(X-1,Y-1,15);
      setcolor(0);
      circle(X-14,Y+10,3);
      circle(X-14,Y+10,2);
   }
   if (X==x+18)
   {
      if (Y==y+18){
      score +=1;
      char val1[20];
      setcolor(15);
      sprintf(val1,"%d",score);
      outtextxy(235,35,val1);
      char val2[20];
      sprintf(val2,"%d",level);
      outtextxy(490,35,val2);
      setfillstyle(SOLID_FILL,10^2);
      rectangle(1020,690,1060,685-(score*39));
      floodfill(1021,686-(score*39),15);
   }}
   if (score == 15)
   {
      level +=1;
      char val2[20];
      sprintf(val2,"%d",level);
      outtextxy(490,35,val2);
      setcolor(15);
      outtextxy(235,35,(char*)"0 ");
      delay(50);
      setfillstyle(SOLID_FILL,0);
      bar(1020,685,1060,100);
      score = 0;
   }


      //                          ==>the game
      if (level<4){
         if(score<15){
            if (X==X_){
               if(Y==Y_){
                  game_over();
      }}}}

      if (level==4){
         if(score==15){
            if (X==X_){
               if(Y==Y_){
                  won();
      }}}}
   } // end_loop

   getch();
   closegraph();
}
//                          ==>gmame over
int game_over()
   {
   delay(200);
   setfillstyle(SOLID_FILL,0);
   bar(20,100,1060,700);
   setcolor(RED);
   settextstyle(10,0,10);
   outtextxy(200,250,(char*)"game over");
   // emotion
   return(0);
   }
//                          ==>won
int won()
   {
   delay(200);
   setfillstyle(SOLID_FILL,0);
   bar(20,100,1060,700);
   setcolor(15);
   settextstyle(10,0,10);
   outtextxy(280,250,(char*)"you won");
   // emotion
   return(0);
   }
   int wall_one(int N,int M)
   {
      setfillstyle(SOLID_FILL,10^2);
      rectangle(10+N,190+M,70+N,200+M);
      floodfill(30+N,191+M,15);
      rectangle(60+N,190+M,120+N,200+M);
      floodfill(80+N,191+M,15);
      return(0);
   }
   int wall_two(int n,int m)
   {
      setfillstyle(SOLID_FILL,10^2);
      rectangle(n+10,m-10,n+20,m+50);
      floodfill(n+11,m+20,15);
      rectangle(n+10,m+40,n+20,m+100);
      floodfill(n+11,m+60,15);
      return(0);
   }
   int monster_one(int X_,int Y_)
   {
      setcolor(15);
      arc(0+X_,0+Y_,30,330,35);
      line(0+X_,0+Y_,30+X_,-17+Y_);
      line(0+X_,0+Y_,30+X_,17+Y_);
      setfillstyle(SOLID_FILL,4);
      floodfill(X_-1,Y_-1,15);
      setcolor(0);
      circle(X_+13,Y_-19,4);
      circle(X_+13,Y_-19,3);
      circle(X_+13,Y_-19,2);
      return(0);
   }
   int player(int X,int Y)
   {
      setcolor(15);
      arc(0+X,0+Y,30,330,25);
      line(0+X,0+Y,21+X,-12+Y);
      line(0+X,0+Y,21+X,12+Y);
      setfillstyle(SOLID_FILL,14);
      floodfill(X-1,Y-1,15);
      setcolor(0);
      circle(X+8,Y-12,3);
      circle(X+8,Y-12,2);
      return(0);
   }
   int jewel(int x,int y)
   {
      int points[]={6+x,y,18+x,y,30+x,y,36+x,9+y,18+x,36+y,x,9+y,6+x,y,12+x,9+y,18+x,36+y,24+x,9+y,30+x,y,24+x,9+y,18+x,y,12+x,9+y};
      setfillstyle(SOLID_FILL,9);
      setcolor(15);
      drawpoly(14,points);
      floodfill(6+x,y+1,15);
      floodfill(18+x,y+1,15);
      floodfill(30+x,y+1,15);
      setfillstyle(SOLID_FILL,8);
      floodfill(12+x,y+8,15);
      floodfill(24+x,y+8,15);
      return(0);
   }