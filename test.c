#include<conio.h> 
#include<stdio.h> 
#include<graphics.h> 
#include<dos.h> 
#include<stdlib.h> 
void car(int c1,int c2); 
void control(int &c1,int &c2); 
void road(int &r,int &d,int c1,int c2,int &tc,int &tc2,int &count); 
void traffic(int &t1,int &t2); 
void main() 
{ 
int gd=DETECT,gm; 
initgraph(&gd,&gm,"..\\bgi"); 
int c1=0,c2=0;//c1=up\down,c2=leŌ\right 
int r=0,d=0;//road 
int i=0; 
int tc=0,tc2=0;//traffic cars control 
int count=0;//count the cars 
//int t1=300,t2=100; 
do 
{ 
control(c1,c2); 
road(r,d,c1,c2,tc,tc2,count); 
//clearviewport(); 
} 
while(i!=20); 
getch(); 
closegraph(); 
} 
void road(int &r,int &d,int c1,int c2,int &tc,int &tc2,int &count) 
{ 
do 
{ 
gotoxy(45,2); 
printf("cars no:%d",count); 
line(10,10,10,600);//end of road1 
line(440,10,440,600);//end of road2 
setcolor(6); 
car(c1,c2); 
//if(kbhit()) 
//sound(tc); 
if(tc==480)//traffic car control 
{ 
//randomize(); 
tc=0; 
tc2=random(330);//traffic car posiƟon
count=count+2; 
} 
traffic(tc2+14,10+tc); 
traffic(tc2+100,tc2+tc); 
tc=tc+10; 
setcolor(15); 
line(300,100+r,300,200+r);//middle road line1 
line(150,100+r,150,200+r);//middle road 
r=r+8; 
d=d+8; 
line(300,300+d,300,400+d);//middleroad2 
line(150,300+d,150,400+d);//middle road 
if(r==400) 
r=0; 
if(d==200) 
d=-200; 
delay(30); 
clearviewport(); 
} 
while(!kbhit()); 
} 
void traffic(int &t1,int &t2) 
{ 
bar(t1,t2,t1+30,t2+40); 
bar(t1+5,t2,t1+25,t2+60); 
ellipse(t1-1,t2+7,0,360,1,6); 
ellipse(t1+32,t2+7,0,360,1,6); 
ellipse(t1-1,t2+30,0,360,1,6); 
ellipse(t1+32,t2+30,0,360,1,6); 
} 
void control(int &c1,int &c2) 
{ 
char ch; 
ch=getch(); 
if(c2==-285) 
c2=-280; 
if(c2==105) 
c2=100; 
//sound(c1+100); 
switch(ch) 
{ 
case 'w': 
{ 
c1=c1+5; 
break; 
} 
case 's': 
{ 
c1=c1-5; 
break; 
} 
case 'd': 
{ 
c2=c2+5; 
break; 
} 
case 'a': 
{ 
c2=c2-5; 
break; 
} 
case 'e': 
{ 
// nosound(); 
exit(0); 
} 
} 
} 
void car(int c1,int c2) 
{ 
bar(305+c2,350-c1,325+c2,330-c1); 
bar(300+c2,350-c1,330+c2,390-c1); 
ellipse(298+c2,357-c1,0,360,1,6); 
ellipse(332+c2,357-c1,0,360,1,6); 
ellipse(298+c2,382-c1,0,360,1,6); 
ellipse(332+c2,382-c1,0,360,1,6); 
}