#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

int won(int point);
int game_over(int point);
int wall_one(int N, int M);
int wall_two(int n, int m);
int monster_one(int X_, int Y_);
int player(int X, int Y);
int jewel(int x, int y);
int monster_motion(int X_, int Y_, int X, int Y);
int menu_game(int menu);
int controls_game();
int about_game();
int map_game(int score, int lose, int X, int Y, int X_, int Y_, int x, int y);

main()
{
   initwindow(1080, 710, "jewels_game", 130, 20);
   setbkcolor(0);
   cleardevice();
   setcolor(15);
   int point = 1;
   int menu = 1;
   int right = 77, left = 75, down = 80, up = 72;
   while (1)
   {
      int score = 0, level = 1, lose = 3;
      int x = 42, y = 327, X = 60, Y = 645, X_ = 65, Y_ = 145;
      menu_game(menu);
      if (point == 0)
         break; // exit from game from eny way
      if (point == 1)
      {
         while (1)
         {
            int ch_menu = getch();
            if (ch_menu == 27)
            {             // exit button
               point = 0; // exit from end loop
               cleardevice();
               break;
            }
            if (ch_menu == 80)
            { // down button
               if (menu == 4)
               {
                  continue;
               }
               menu += 1;
            }

            if (ch_menu == 72)
            { // up button
               if (menu == 1)
               {
                  continue;
               }
               menu -= 1;
            }
            if (ch_menu == 13) // enter button
            {
               if (menu == 1)
               { // play game
                  point = 2;
                  break;
               }
               if (menu == 2)
               { // controls
                  point = 3;
                  break;
               }
               if (menu == 3)
               { // about
                  point = 4;
                  break;
               }
               if (menu == 4)
               { // exit
                  point = 0;
                  break;
               }
            }
            menu_game(menu);
         }
      }
      if (point == 3) // go to controls
      {
         controls_game();
         setcolor(4);
         setlinestyle(0, 0, 2);
         rectangle(145, 450, 220, 525);
         rectangle(240, 450, 315, 525);
         rectangle(335, 450, 410, 525);
         rectangle(240, 355, 315, 430);
         setcolor(15);
         settextstyle(10, 0, 3);
         outtextxy(390, 640, (char *)"To back press <ESC>");
         while (1)
         {
            int ch_menu = getch(); // esc button
            if (ch_menu == 27 || ch_menu == 13)
            {
               point = 1; // go to menu if be 0 exit from game
               cleardevice();
               break;
            }
            if (ch_menu == 77)
            {
               controls_game();
               setcolor(4);
               setlinestyle(0, 0, 3);
               rectangle(675, 450, 750, 525);
               rectangle(770, 450, 845, 525);
               rectangle(865, 450, 940, 525);
               rectangle(770, 355, 845, 430);
               right = 100, left = 97, down = 115, up = 119;
            }
            if (ch_menu == 75)
            {
               controls_game();
               setcolor(4);
               setlinestyle(0, 0, 3);
               rectangle(145, 450, 220, 525);
               rectangle(240, 450, 315, 525);
               rectangle(335, 450, 410, 525);
               rectangle(240, 355, 315, 430);
               right = 77, left = 75, down = 80, up = 72;
            }
         }
      }
      if (point == 4) // go to about
      {
         cleardevice();
         while (1)
         {
            about_game();
            setcolor(15);
            settextstyle(10, 0, 3);
            outtextxy(390, 640, (char *)"To back press <ESC>");
            setcolor(7);
            settextstyle(10, 0, 4);
            outtextxy(260, 150, (char *)"This game is about collecting");
            delay(40);
            outtextxy(470, 180, (char *)"jewels.");
            delay(40);
            outtextxy(255, 210, (char *)"but becarful from the monster.");
            delay(40);
            outtextxy(290, 240, (char *)"who will try to catch you.");
            delay(40);
            outtextxy(275, 270, (char *)"The more jewels you collect,");
            delay(40);
            outtextxy(305, 300, (char *)"the higher you level up.");
            delay(40);
            outtextxy(280, 330, (char *)"You have to collect gems by");
            delay(40);
            outtextxy(270, 360, (char *)"using the arrow keys and you");
            delay(40);
            outtextxy(280, 390, (char *)"can change how you can play");
            delay(40);
            outtextxy(410, 420, (char *)"from control.");
            delay(40);
            outtextxy(400, 450, (char *)"version:1.0.0.");
            delay(40);
            outtextxy(320, 480, (char *)"made by:a group of best");
            delay(40);
            outtextxy(450, 510, (char *)"engneers.");
            delay(40);
            settextstyle(10, 0, 6);
            outtextxy(360, 560, (char *)"_GOOD LUCK_");
            int ch_menu = getch();
            if (ch_menu == 27)
            {
               point = 1;
               cleardevice();
               break;
            }
         }
      }
      if (point == 2)
      {
         cleardevice();
         {
            setlinestyle(0, 0, 2);
            setcolor(15);
            arc(540, 270, 30, 330, 180);
            line(540, 270, 695, 180);
            line(540, 270, 695, 360);
            setfillstyle(SOLID_FILL, 4);
            floodfill(500, 200, 15);
            setcolor(0);
            setlinestyle(0, 0, 4);
            circle(590, 170, 10);
            setcolor(15);
            setlinestyle(0, 0, 1);
            rectangle(50, 550, 1031, 585);
            for (int i = 0; i < 101; i += 5)
            {
               setfillstyle(SOLID_FILL, 4);
               bar(51, 551, 51 + (i * 9.8), 585);
               settextstyle(10, 0, 1);
               char val3[20];
               sprintf(val3, "%d%%", i);
               outtextxy(500, 600, val3);
               delay(30);
            }
         }
         cleardevice();
         //                          ==>frame
         // readimagefile("map.bmp",0,0,getmaxx(),getmaxy());
         map_game(score, lose, X, Y, X_, Y_, x, y);
         //                      ==>>motion
         while (1)
         {
            //            monester_motion
            // time_t t = time(0);
            //    if (t%2==0)
            {
               int right, left, down, up;
               right = getpixel(X_ + 46, Y_);
               left = getpixel(X_ - 46, Y_);
               down = getpixel(X_, Y_ + 46);
               up = getpixel(X_, Y_ - 46);
               setfillstyle(SOLID_FILL, 0);
               bar(X_ - 35, Y_ - 35, X_ + 35, Y_ + 35);
               floodfill(X_, Y_, 0);

               if ((X_ - 65) % 100 == 0)
               {
                  if (down == 0)
                  {
                     if (up == 0)
                     {
                        if (Y > Y_)
                        {
                           Y_ += 2;
                        }
                        if (Y < Y_)
                        {
                           Y_ -= 2;
                        }
                     }
                     else
                     {
                        Y_ += 2;
                     }
                  }
                  else
                  {
                     if (up == 0)
                     {

                        Y_ -= 2;
                     }
                  }
               }

               //---------------------
               if (((Y_ - 45) % 100) == 0)
               {
                  if (right == 0)
                  {
                     if (left == 0)
                     {
                        if (X_ > X)
                        {
                           X_ -= 2;
                        }
                        if (X_ < X)
                        {
                           X_ += 2;
                        }
                     }
                     else
                     {
                        X_ += 2;
                     }
                  }
                  else
                  {
                     if (left == 0)
                     {
                        X_ -= 2;
                     }
                  }
               }
               monster_one(X_, Y_);
            }
            //         ====>> end motion monester <<====
            if (kbhit())
            {
               int ch = getch();
               if (ch == 27)
               {
                  point = 1;
                  cleardevice();
                  break;
               }
               if (ch == right)
               {
                  if (X == 980)
                     continue;
                  if (Y > 155)
                  {
                     if (Y < 235)
                     {
                        if (X == 80)
                           continue;
                        if (X == 380)
                           continue;
                        if (X == 580)
                           continue;
                        if (X == 880)
                           continue;
                     }
                  }
                  if (Y > 255)
                  {
                     if (Y < 335)
                     {
                        if (X == 380)
                           continue;
                        if (X == 480)
                           continue;
                        if (X == 580)
                           continue;
                        if (X == 680)
                           continue;
                        if (X == 880)
                           continue;
                     }
                  }
                  if (Y > 355)
                  {
                     if (Y < 435)
                     {
                        if (X == 80)
                           continue;
                        if (X == 180)
                           continue;
                        if (X == 280)
                           continue;
                        if (X == 580)
                           continue;
                        if (X == 780)
                           continue;
                     }
                  }
                  if (Y > 455)
                  {
                     if (Y < 535)
                     {
                        if (X == 80)
                           continue;
                        if (X == 380)
                           continue;
                        if (X == 580)
                           continue;
                        if (X == 680)
                           continue;
                     }
                  }
                  if (Y > 555)
                  {
                     if (Y < 635)
                     {
                        if (X == 80)
                           continue;
                        if (X == 480)
                           continue;
                        if (X == 580)
                           continue;
                     }
                  }

                  if (Y > 155)
                     if (X == 980)
                     {
                        continue;
                     }

                  if (Y > 125)
                  {
                     if (Y < 165)
                     {
                        if (X == 680)
                        {
                           continue;
                        }
                     }
                  }

                  if (Y > 225)
                  {
                     if (Y < 265)
                     {
                        if (X == 380)
                        {
                           continue;
                        }
                        if (X == 580)
                        {
                           continue;
                        }
                        if (X == 880)
                        {
                           continue;
                        }
                     }
                  }

                  if (Y > 325)
                  {
                     if (Y < 365)
                     {
                        if (X == 180)
                        {
                           continue;
                        }
                        if (X == 480)
                        {
                           continue;
                        }
                        if (X == 680)
                        {
                           continue;
                        }
                        if (X == 880)
                        {
                           continue;
                        }
                     }
                  }

                  if (Y > 425)
                  {
                     if (Y < 465)
                     {
                        if (X == 80)
                        {
                           continue;
                        }
                        if (X == 280)
                        {
                           continue;
                        }
                     }
                  }

                  if (Y > 525)
                  {
                     if (Y < 565)
                     {
                        if (X == 380)
                        {
                           continue;
                        }
                        if (X == 580)
                        {
                           continue;
                        }
                     }
                  }

                  if (Y > 625)
                  {
                     if (Y < 665)
                     {
                        if (X == 480)
                        {
                           continue;
                        }
                     }
                  }

                  setcolor(10);
                  setfillstyle(SOLID_FILL, 0);
                  bar(X - 25, Y - 25, X + 25, Y + 25);
                  floodfill(X, Y, 0);
                  X += 10;
                  setcolor(15);
                  arc(0 + X, 0 + Y, 30, 330, 25);
                  line(0 + X, 0 + Y, 21 + X, -12 + Y);
                  line(0 + X, 0 + Y, 21 + X, 12 + Y);
                  setfillstyle(SOLID_FILL, 14);
                  floodfill(X - 1, Y - 1, 15);
                  setcolor(0);
                  circle(X + 8, Y - 12, 3);
                  circle(X + 8, Y - 12, 2);
               }
               if (ch == left)
               {
                  if (X < 60)
                     continue;
                  if (Y > 155)
                  {
                     if (Y < 235)
                     {
                        if (X == 950)
                           continue;
                        if (X == 350)
                           continue;
                        if (X == 550)
                           continue;
                        if (X == 850)
                           continue;
                     }
                  }
                  if (Y > 255)
                  {
                     if (Y < 335)
                     {
                        if (X == 350)
                           continue;
                        if (X == 450)
                           continue;
                        if (X == 550)
                           continue;
                        if (X == 650)
                           continue;
                        if (X == 850)
                           continue;
                        if (X == 950)
                           continue;
                     }
                  }
                  if (Y > 355)
                  {
                     if (Y < 435)
                     {
                        if (X == 950)
                           continue;
                        if (X == 150)
                           continue;
                        if (X == 250)
                           continue;
                        if (X == 550)
                           continue;
                        if (X == 750)
                           continue;
                     }
                  }
                  if (Y > 455)
                  {
                     if (Y < 535)
                     {
                        if (X == 350)
                           continue;
                        if (X == 550)
                           continue;
                        if (X == 650)
                           continue;
                     }
                  }
                  if (Y > 555)
                  {
                     if (Y < 635)
                     {
                        if (X == 950)
                           continue;
                        if (X == 450)
                           continue;
                        if (X == 550)
                           continue;
                     }
                  }

                  if (X == 50)
                  {
                     continue;
                  }
                  if (Y > 125)
                  {
                     if (Y < 165)
                     {
                        if (X == 750)
                        {
                           continue;
                        }
                     }
                  }

                  if (Y > 225)
                  {
                     if (Y < 265)
                     {
                        if (X == 450)
                        {
                           continue;
                        }
                        if (X == 650)
                        {
                           continue;
                        }
                        if (X == 950)
                        {
                           continue;
                        }
                     }
                  }

                  if (Y > 325)
                  {
                     if (Y < 365)
                     {
                        if (X == 250)
                        {
                           continue;
                        }
                        if (X == 550)
                        {
                           continue;
                        }
                        if (X == 750)
                        {
                           continue;
                        }
                        if (X == 950)
                        {
                           continue;
                        }
                     }
                  }

                  if (Y > 425)
                  {
                     if (Y < 465)
                     {
                        if (X == 150)
                        {
                           continue;
                        }
                        if (X == 350)
                        {
                           continue;
                        }
                     }
                  }

                  if (Y > 525)
                  {
                     if (Y < 565)
                     {
                        if (X == 450)
                        {
                           continue;
                        }
                        if (X == 650)
                        {
                           continue;
                        }
                     }
                  }

                  if (Y > 625)
                  {
                     if (Y < 665)
                     {
                        if (X == 550)
                        {
                           continue;
                        }
                     }
                  }

                  setcolor(10);
                  setfillstyle(SOLID_FILL, 0);
                  bar(X - 25, Y - 25, X + 25, Y + 25);
                  floodfill(X, Y, 0);
                  X -= 10;
                  setcolor(15);
                  arc(0 + X, 0 + Y, 210, 150, 25);
                  line(0 + X, 0 + Y, -21 + X, -12 + Y);
                  line(0 + X, 0 + Y, -21 + X, 12 + Y);
                  setfillstyle(SOLID_FILL, 14);
                  floodfill(X + 1, Y + 1, 15);
                  setcolor(0);
                  circle(X - 8, Y - 12, 3);
                  circle(X - 8, Y - 12, 2);
               }
               if (ch == up)
               {
                  if (Y == 135)
                     continue;
                  if (Y > 225)
                  {
                     if (Y < 245)
                     {
                        if (X > 80)
                        {
                           if (X < 350)
                              continue;
                        }
                        if (X > 380)
                        {
                           if (X < 550)
                              continue;
                        }
                        if (X > 580)
                        {
                           if (X < 850)
                              continue;
                        }
                        if (X > 880)
                        {
                           if (X < 950)
                              continue;
                        }
                     }
                  }

                  if (Y > 325)
                  {
                     if (Y < 345)
                     {
                        if (X > 20)
                        {
                           if (X < 350)
                              continue;
                        }
                        if (X > 380)
                        {
                           if (X < 450)
                              continue;
                        }
                        if (X > 580)
                        {
                           if (X < 650)
                              continue;
                        }
                        if (X > 680)
                        {
                           if (X < 850)
                              continue;
                        }
                     }
                  }

                  if (Y > 425)
                  {
                     if (Y < 445)
                     {
                        if (X > 180)
                        {
                           if (X < 250)
                              continue;
                        }
                        if (X > 280)
                        {
                           if (X < 550)
                              continue;
                        }
                        if (X > 580)
                        {
                           if (X < 750)
                              continue;
                        }
                        if (X > 780)
                        {
                           if (X < 950)
                              continue;
                        }
                     }
                  }

                  if (Y > 525)
                  {
                     if (Y < 545)
                     {
                        if (X > 80)
                        {
                           if (X < 350)
                              continue;
                        }
                        if (X > 380)
                        {
                           if (X < 550)
                              continue;
                        }
                        if (X > 680)
                        {
                           if (X < 1050)
                              continue;
                        }
                     }
                  }

                  if (Y > 625)
                  {
                     if (Y < 645)
                     {
                        if (X > 80)
                        {
                           if (X < 450)
                              continue;
                        }
                        if (X > 580)
                        {
                           if (X < 950)
                              continue;
                        }
                     }
                  }

                  setcolor(10);
                  setfillstyle(SOLID_FILL, 0);
                  bar(X - 25, Y - 25, X + 25, Y + 25);
                  floodfill(X, Y, 0);
                  Y -= 10;
                  setcolor(15);
                  arc(0 + X, 0 + Y, 120, 60, 25);
                  line(0 + X, 0 + Y, 12 + X, -21 + Y);
                  line(0 + X, 0 + Y, -12 + X, -21 + Y);
                  setfillstyle(SOLID_FILL, 14);
                  floodfill(X + 1, Y + 1, 15);
                  setcolor(0);
                  circle(X + 14, Y - 10, 3);
                  circle(X + 14, Y - 10, 2);
               }
               if (ch == down)
               {
                  if (Y == 655)
                     continue;

                  if (Y > 145)
                  {
                     if (Y < 165)
                     {
                        if (X > 80)
                        {
                           if (X < 350)
                              continue;
                        }
                        if (X > 380)
                        {
                           if (X < 550)
                              continue;
                        }
                        if (X > 580)
                        {
                           if (X < 850)
                              continue;
                        }
                        if (X > 880)
                        {
                           if (X < 950)
                              continue;
                        }
                     }
                  }

                  if (Y > 245)
                  {
                     if (Y < 265)
                     {
                        if (X > 20)
                        {
                           if (X < 350)
                              continue;
                        }
                        if (X > 480)
                        {
                           if (X < 550)
                              continue;
                        }
                        if (X > 680)
                        {
                           if (X < 850)
                              continue;
                        }
                     }
                  }

                  if (Y > 345)
                  {
                     if (Y < 365)
                     {
                        if (X > 80)
                        {
                           if (X < 150)
                              continue;
                        }
                        if (X > 180)
                        {
                           if (X < 250)
                              continue;
                        }
                        if (X > 280)
                        {
                           if (X < 550)
                              continue;
                        }
                        if (X > 580)
                        {
                           if (X < 750)
                              continue;
                        }
                        if (X > 780)
                        {
                           if (X < 950)
                              continue;
                        }
                     }
                  }

                  if (Y > 445)
                  {
                     if (Y < 465)
                     {
                        if (X > 80)
                        {
                           if (X < 350)
                              continue;
                        }
                        if (X > 380)
                        {
                           if (X < 550)
                              continue;
                        }
                        if (X > 580)
                        {
                           if (X < 650)
                              continue;
                        }
                        if (X > 680)
                        {
                           if (X < 1050)
                              continue;
                        }
                     }
                  }

                  if (Y > 545)
                  {
                     if (Y < 565)
                     {
                        if (X > 80)
                        {
                           if (X > 480)
                           {
                              if (X < 550)
                                 continue;
                           }
                           if (X < 450)
                              continue;
                        }
                        if (X > 580)
                        {
                           if (X < 950)
                              continue;
                        }
                     }
                  }

                  setcolor(10);
                  setfillstyle(SOLID_FILL, 0);
                  bar(X - 25, Y - 25, X + 25, Y + 25);
                  floodfill(X, Y, 0);
                  Y += 10;
                  setcolor(15);
                  arc(0 + X, 0 + Y, 300, 240, 25);
                  line(0 + X, 0 + Y, 12 + X, 21 + Y);
                  line(0 + X, 0 + Y, -12 + X, 21 + Y);
                  setfillstyle(SOLID_FILL, 14);
                  floodfill(X - 1, Y - 1, 15);
                  setcolor(0);
                  circle(X - 14, Y + 10, 3);
                  circle(X - 14, Y + 10, 2);
               }
               // ch=false;
            }
            if (fabs(X - (x + 18)) <= 30)
            {
               if (fabs(Y - (y + 18)) <= 30)
               {
                  score += 1;
                  setfillstyle(SOLID_FILL, 0);
                  bar(x, y, x + 37, y + 37);
                  char val1[20];
                  setcolor(15);
                  sprintf(val1, "%d", score);
                  outtextxy(235, 35, val1);
                  char val2[20];
                  sprintf(val2, "%d", level);
                  outtextxy(490, 35, val2);
                  setfillstyle(SOLID_FILL, 10 ^ 2);
                  rectangle(1020, 690, 1060, 685 - (score * 39));
                  floodfill(1021, 686 - (score * 39), 15);
               }
            }
            if (score == 15)
            {
               if (level < 4)
               {
                  level += 1;
                  char val2[20];
                  sprintf(val2, "%d", level);
                  outtextxy(490, 35, val2);
                  setcolor(15);
                  outtextxy(235, 35, (char *)"0 ");
                  delay(50);
                  setfillstyle(SOLID_FILL, 0);
                  bar(1020, 685, 1060, 100);
                  score = 0;
               }
            }
            //                          ==>the game
            if (labs(X - X_) < 60 && labs(Y - Y_) < 60 && lose > 1)
            {
               lose -= 1;
               setfillstyle(SOLID_FILL, 0);
               bar(X - 25, Y - 25, X + 25, Y + 25);
               X = 60, Y = 645;
               setcolor(15);
               settextstyle(10, 0, 5);
               char val17[20];
               sprintf(val17, "%d", lose);
               outtextxy(960, 35, val17);
            }
            if (labs(X - X_) < 60)
            {
               if (labs(Y - Y_) < 60 && lose == 1)
               {
                  game_over(point);
                  setcolor(RED);
                  outtextxy(50, 600, (char *)"play again");
                  int game_pos = 1;
                  while (1)
                  {
                     int ch = getch();
                     if (ch == 27)
                     {
                        point = 1;
                        cleardevice();
                        break;
                     }
                     if (ch == 77)
                     {
                        if (game_pos == 3)
                           continue;
                        game_pos += 1;
                        game_over(point);
                        setcolor(RED);
                        if (game_pos == 1)
                        {
                           outtextxy(50, 600, (char *)"play again");
                        }
                        if (game_pos == 2)
                        {
                           outtextxy(500, 600, (char *)"menu list");
                        }
                        if (game_pos == 3)
                        {
                           outtextxy(900, 600, (char *)"exit");
                        }
                     }
                     if (ch == 75)
                     {
                        if (game_pos == 1)
                           continue;
                        game_pos -= 1;
                        game_over(point);
                        setcolor(RED);
                        if (game_pos == 1)
                        {
                           outtextxy(50, 600, (char *)"play again");
                        }
                        if (game_pos == 2)
                        {
                           outtextxy(500, 600, (char *)"menu list");
                        }
                        if (game_pos == 3)
                        {
                           outtextxy(900, 600, (char *)"exit");
                        }
                     }
                     if (ch == 13)
                     {
                        if (game_pos == 1)
                        {
                           point = 2;
                           cleardevice();
                           break;
                        }
                        if (game_pos == 2)
                        {
                           point = 1;
                           cleardevice();
                           break;
                        }
                        if (game_pos == 3)
                        {
                           point = 0;
                           cleardevice();
                           break;
                        }
                     }
                  }
                  break;
               }
            }
            if (level == 3)
            {
               if (score == 0)
               {
                  won(point);
                  setcolor(RED);
                  outtextxy(50, 600, (char *)"play again");
                  int game_pos = 1;
                  while (1)
                  {
                     int ch = getch();
                     if (ch == 27)
                     {
                        point = 1;
                        cleardevice();
                        break;
                     }
                     if (ch == 77)
                     {
                        if (game_pos == 3)
                           continue;
                        game_pos += 1;
                        won(point);
                        setcolor(RED);
                        if (game_pos == 1)
                        {
                           outtextxy(50, 600, (char *)"play again");
                        }
                        if (game_pos == 2)
                        {
                           outtextxy(500, 600, (char *)"menu list");
                        }
                        if (game_pos == 3)
                        {
                           outtextxy(900, 600, (char *)"exit");
                        }
                     }
                     if (ch == 75)
                     {
                        if (game_pos == 1)
                           continue;
                        game_pos -= 1;
                        won(point);
                        setcolor(RED);
                        if (game_pos == 1)
                        {
                           outtextxy(50, 600, (char *)"play again");
                        }
                        if (game_pos == 2)
                        {
                           outtextxy(500, 600, (char *)"menu list");
                        }
                        if (game_pos == 3)
                        {
                           outtextxy(900, 600, (char *)"exit");
                        }
                     }
                     if (ch == 13)
                     {
                        if (game_pos == 1)
                        {
                           point = 2;
                           cleardevice();
                           break;
                        }
                        if (game_pos == 2)
                        {
                           point = 1;
                           cleardevice();
                           break;
                        }
                        if (game_pos == 3)
                        {
                           point = 0;
                           cleardevice();
                           break;
                        }
                     }
                  }
                  break;
               }
            }
            {
               if (score == 0)
               {
                  x = 42, y = 327;
                  jewel(x, y);
               }
               if (score == 1)
               {
                  x = 542, y = 627;
                  jewel(x, y);
               }
               if (score == 2)
               {
                  x = 742, y = 127;
                  jewel(x, y);
               }
               if (score == 3)
               {
                  x = 342, y = 627;
                  jewel(x, y);
               }
               if (score == 4)
               {
                  x = 142, y = 127;
                  jewel(x, y);
               }
               if (score == 5)
               {
                  x = 742, y = 327;
                  jewel(x, y);
               }
               if (score == 6)
               {
                  x = 942, y = 627;
                  jewel(x, y);
               }
               if (score == 7)
               {
                  x = 242, y = 427;
                  jewel(x, y);
               }
               if (score == 8)
               {
                  x = 942, y = 227;
                  jewel(x, y);
               }
               if (score == 9)
               {
                  x = 42, y = 627;
                  jewel(x, y);
               }
               if (score == 10)
               {
                  x = 442, y = 227;
                  jewel(x, y);
               }
               if (score == 11)
               {
                  x = 642, y = 127;
                  jewel(x, y);
               }
               if (score == 12)
               {
                  x = 42, y = 627;
                  jewel(x, y);
               }
               if (score == 13)
               {
                  x = 542, y = 327;
                  jewel(x, y);
               }
               if (score == 14)
               {
                  x = 942, y = 427;
                  jewel(x, y);
               }
               delay(10);
            }
         }
      }
   }
   // end_loop
   closegraph();
}
//                          ==>gmame over
int game_over(int point)
{
   setfillstyle(SOLID_FILL, 0);
   bar(20, 100, 1060, 690);
   setcolor(RED);
   settextstyle(10, 0, 10);
   outtextxy(200, 120, (char *)"game over");
   // emotion
   setlinestyle(0, 0, 5);
   arc(540, 540, 30, 140, 100);
   ellipse(540, 420, 0, 360, 220, 140);
   circle(430, 385, 30);
   circle(650, 385, 30);
   setcolor(15);
   settextstyle(10, 0, 6);
   outtextxy(50, 600, (char *)"play again");
   outtextxy(500, 600, (char *)"menu list");
   outtextxy(900, 600, (char *)"exit");
   return (0);
}
//                          ==>won
int won(int point)
{
   while (1)
   {
      setfillstyle(SOLID_FILL, 0);
      bar(20, 100, 1060, 690);
      setcolor(RED);
      settextstyle(10, 0, 10);
      outtextxy(280, 120, (char *)"you won");
      // emotion
      setlinestyle(0, 0, 5);
      arc(540, 410, 220, 320, 100);
      ellipse(540, 420, 0, 360, 220, 140);
      circle(430, 385, 30);
      circle(650, 385, 30);
      setcolor(15);
      settextstyle(10, 0, 6);
      outtextxy(50, 600, (char *)"play again");
      outtextxy(500, 600, (char *)"menu list");
      outtextxy(900, 600, (char *)"exit");
      return (0);
   }
   return (0);
}
int wall_one(int N, int M)
{
   setfillstyle(SOLID_FILL, 10 ^ 2);
   rectangle(10 + N, 190 + M, 70 + N, 200 + M);
   floodfill(30 + N, 191 + M, 15);
   rectangle(60 + N, 190 + M, 120 + N, 200 + M);
   floodfill(80 + N, 191 + M, 15);
   return (0);
}
int wall_two(int n, int m)
{
   setfillstyle(SOLID_FILL, 10 ^ 2);
   rectangle(n + 10, m - 10, n + 20, m + 50);
   floodfill(n + 11, m + 20, 15);
   rectangle(n + 10, m + 40, n + 20, m + 100);
   floodfill(n + 11, m + 60, 15);
   return (0);
}
int monster_one(int X_, int Y_)
{

   setcolor(15);
   arc(0 + X_, 0 + Y_, 30, 330, 35);
   line(0 + X_, 0 + Y_, 30 + X_, -17 + Y_);
   line(0 + X_, 0 + Y_, 30 + X_, 17 + Y_);
   setfillstyle(SOLID_FILL, 4);
   floodfill(X_ - 1, Y_ - 1, 15);
   setcolor(0);
   circle(X_ + 13, Y_ - 19, 4);
   circle(X_ + 13, Y_ - 19, 3);
   circle(X_ + 13, Y_ - 19, 2);
   return (0);
}
int player(int X, int Y)
{
   setcolor(15);
   arc(0 + X, 0 + Y, 30, 330, 25);
   line(0 + X, 0 + Y, 21 + X, -12 + Y);
   line(0 + X, 0 + Y, 21 + X, 12 + Y);
   setfillstyle(SOLID_FILL, 14);
   floodfill(X - 1, Y - 1, 15);
   setcolor(0);
   circle(X + 8, Y - 12, 3);
   circle(X + 8, Y - 12, 2);
   return (0);
}
int jewel(int x, int y)
{
   int points[] = {6 + x, y, 18 + x, y, 30 + x, y, 36 + x, 9 + y, 18 + x, 36 + y, x, 9 + y, 6 + x, y, 12 + x, 9 + y, 18 + x, 36 + y, 24 + x, 9 + y, 30 + x, y, 24 + x, 9 + y, 18 + x, y, 12 + x, 9 + y};
   setfillstyle(SOLID_FILL, 9);
   setcolor(15);
   drawpoly(14, points);
   floodfill(6 + x, y + 1, 15);
   floodfill(18 + x, y + 1, 15);
   floodfill(30 + x, y + 1, 15);
   setfillstyle(SOLID_FILL, 8);
   floodfill(12 + x, y + 8, 15);
   floodfill(24 + x, y + 8, 15);
   return (0);
}
int monster_motion(int X_, int Y_, int X, int Y)
{
   int right, left, down, up;
   right = getpixel(X_ + 46, Y_);
   left = getpixel(X_ - 46, Y_);
   down = getpixel(X_, Y_ + 46);
   up = getpixel(X_, Y_ - 46);
   setfillstyle(SOLID_FILL, 0);
   bar(X_ - 35, Y_ - 35, X_ + 35, Y_ + 35);
   floodfill(X_, Y_, 0);

   if ((Y - 45) % 100 == 0)
   {
      if (down == 0)
      {
         if (up == 0)
         {
            if (Y > Y_)
            {
               Y_ += 10;
            }
            if (Y < Y_)
            {
               Y_ -= 10;
            }
         }
         else
         {
            Y_ += 10;
         }
      }
      else
      {
         if (up == 0)
         {
            Y_ -= 10;
         }
      }
   }

   //---------------------
   if ((X_ - 65) % 100 == 0)
   {
      if (right == 0)
      {
         if (left == 0)
         {
            if (X_ > X)
            {
               X_ -= 10;
            }
            if (X_ < X)
            {
               X_ += 10;
            }
         }
         else
         {
            X_ += 10;
         }
      }
      else
      {
         if (left == 0)
         {
            X_ -= 10;
         }
      }
   }
   monster_one(X_, Y_);

   return (X_, Y_);
}
int menu_game(int menu)
{
   if (menu == 1)
   {
      setcolor(0);
      outtextxy(265, 250, (char *)"<        >");
      outtextxy(345, 350, (char *)"<     >");
      outtextxy(375, 450, (char *)"<    >");
      setcolor(4);
      settextstyle(10, 0, 9);
      outtextxy(370, 150, (char *)"<    >");
      outtextxy(430, 150, (char *)"play");
      setcolor(15);
      settextstyle(10, 0, 9);
      outtextxy(320, 250, (char *)"controls");
      outtextxy(400, 350, (char *)"about");
      outtextxy(430, 450, (char *)"exit");
   }
   if (menu == 2)
   {
      setcolor(0);
      outtextxy(370, 150, (char *)"<    >");
      outtextxy(345, 350, (char *)"<     >");
      outtextxy(375, 450, (char *)"<    >");
      setcolor(4);
      settextstyle(10, 0, 9);
      outtextxy(265, 250, (char *)"<        >");
      outtextxy(320, 250, (char *)"controls");
      setcolor(15);
      settextstyle(10, 0, 9);
      outtextxy(430, 150, (char *)"play");
      outtextxy(400, 350, (char *)"about");
      outtextxy(430, 450, (char *)"exit");
   }
   if (menu == 3)
   {
      setcolor(0);
      outtextxy(370, 150, (char *)"<    >");
      outtextxy(265, 250, (char *)"<        >");
      outtextxy(375, 450, (char *)"<    >");
      setcolor(4);
      settextstyle(10, 0, 9);
      outtextxy(345, 350, (char *)"<     >");
      outtextxy(400, 350, (char *)"about");
      setcolor(15);
      settextstyle(10, 0, 9);
      outtextxy(430, 150, (char *)"play");
      outtextxy(320, 250, (char *)"controls");
      outtextxy(430, 450, (char *)"exit");
   }
   if (menu == 4)
   {
      setcolor(0);
      outtextxy(370, 150, (char *)"<    >");
      outtextxy(265, 250, (char *)"<        >");
      outtextxy(345, 350, (char *)"<     >");
      setcolor(4);
      settextstyle(10, 0, 9);
      outtextxy(375, 450, (char *)"<    >");
      outtextxy(430, 450, (char *)"exit");
      setcolor(15);
      settextstyle(10, 0, 9);
      outtextxy(430, 150, (char *)"play");
      outtextxy(320, 250, (char *)"controls");
      outtextxy(400, 350, (char *)"about");
   }
   return (0);
}
int controls_game()
{
   cleardevice();
   setcolor(15);
   settextstyle(10, 0, 3);
   outtextxy(390, 640, (char *)"To back press <ESC>");
   settextstyle(10, 0, 10);
   outtextxy(240, 150, (char *)"controls");
   setlinestyle(0, 0, 3);
   rectangle(145, 450, 220, 525);
   rectangle(240, 450, 315, 525);
   rectangle(335, 450, 410, 525);
   rectangle(240, 355, 315, 430);
   line(165, 487, 200, 487);
   line(165, 487, 180, 494);
   line(165, 487, 180, 480);
   line(355, 487, 390, 487);
   line(375, 494, 390, 487);
   line(375, 480, 390, 487);
   line(277, 470, 277, 505);
   line(284, 490, 277, 505);
   line(270, 490, 277, 505);
   line(277, 375, 277, 410);
   line(277, 375, 284, 390);
   line(277, 375, 270, 390);
   settextstyle(10, 0, 8);
   outtextxy(690, 449, (char *)"A");
   rectangle(675, 450, 750, 525);
   outtextxy(785, 449, (char *)"S");
   rectangle(770, 450, 845, 525);
   outtextxy(880, 449, (char *)"D");
   rectangle(865, 450, 940, 525);
   outtextxy(785, 354, (char *)"W");
   rectangle(770, 355, 845, 430);
   return (0);
}
int about_game()
{
   setcolor(15);
   settextstyle(10, 0, 8);
   setlinestyle(0, 0, 7);
   outtextxy(410, 50, (char *)"about");
   rectangle(245, 20, 835, 690);
   return (0);
}
int map_game(int score, int lose, int X, int Y, int X_, int Y_, int x, int y)
{
   for (int i = 0; i < 1020; i += 40)
   {
      rectangle(10 + i, 10, 60 + i, 20);
      rectangle(10 + i, 90, 60 + i, 100);
      rectangle(10 + i, 690, 60 + i, 700);
      setfillstyle(SOLID_FILL, 10 ^ 2);
      floodfill(30 + i, 11, 15);
      floodfill(30 + i, 91, 15);
      floodfill(30 + i, 691, 15);
   }
   for (int i = 0; i < 680; i += 40)
   {
      rectangle(10, 10 + i, 20, 60 + i);
      rectangle(1060, 10 + i, 1070, 60 + i);
      setfillstyle(SOLID_FILL, 10 ^ 2);
      floodfill(11, 30 + i, 15);
      floodfill(1061, 30 + i, 15);
   }
   for (int i = 0; i < 580; i += 40)
   {
      rectangle(1010, 90 + i, 1020, 140 + i);
      floodfill(1011, 120 + i, 15);
   }
   // score_bar
   rectangle(1020, 690, 1060, 685 - (score * 39));
   floodfill(1021, 686 - (score * 39), 15);

   line(70, 30, 550, 30);
   line(70, 80, 550, 80);
   ellipse(70, 55, 90, 270, 15, 25);
   ellipse(550, 55, 270, 90, 15, 25);
   setfillstyle(SOLID_FILL, 15);
   settextstyle(10, 0, 5);
   outtextxy(85, 35, (char *)"score:0");
   outtextxy(340, 35, (char *)"level:1");

   line(800, 30, 1000, 30);
   line(800, 80, 1000, 80);
   ellipse(800, 55, 90, 270, 15, 25);
   ellipse(1000, 55, 270, 90, 15, 25);
   char val3[20];
   sprintf(val3, "lose:+%d", lose);
   outtextxy(810, 35, val3);

   // game_map
   wall_one(100, 0);
   wall_one(200, 0);
   wall_one(400, 0);
   wall_one(600, 0);
   wall_one(700, 0);
   wall_one(0, 100);
   wall_one(100, 100);
   wall_one(200, 100);
   wall_one(700, 100);
   wall_one(300, 200);
   wall_one(400, 200);
   wall_one(600, 200);
   wall_one(800, 200);
   wall_one(100, 300);
   wall_one(200, 300);
   wall_one(400, 300);
   wall_one(700, 300);
   wall_one(800, 300);
   wall_one(900, 300);
   wall_one(100, 400);
   wall_one(200, 400);
   wall_one(300, 400);
   wall_one(600, 400);
   wall_one(700, 400);
   wall_one(800, 400);
   wall_two(700, 100);
   wall_two(400, 200);
   wall_two(600, 200);
   wall_two(900, 200);
   wall_two(200, 300);
   wall_two(500, 300);
   wall_two(700, 300);
   wall_two(900, 300);
   wall_two(100, 400);
   wall_two(300, 400);
   wall_two(400, 500);
   wall_two(600, 500);
   wall_two(500, 600);
   monster_one(X_, Y_);
   player(X, Y);
   jewel(x, y);
   return (0);
}