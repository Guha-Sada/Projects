#include<graphics.h>
#include<fstream.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>

struct snake
{
	int x1,y1;
}MAIN;

struct food
{
	int x,y;
}f;
int checkcollision()
{
	if(MAIN.x1+10==560)
		return 1;
	else if(MAIN.x1-10==100)
		return 1;
	else if(MAIN.y1+10==400)
		return 1;
	else if(MAIN.y1-10==40)
		return 1;
	else
		return 0;
}

void endgame(int score)
{
	cleardevice();
	char s[100];
	itoa(score,s,10);
	outtextxy(250,250,"GAME OVER");
	outtextxy(350,250,"SCORE-");
	outtextxy(350,350,s);
	delay(2000);
}


void map()
{

	rectangle(100,40,560,400);
	setcolor(2);
	outtextxy(200,450,"SNAKE");
}

int check_food(int orient)
{

	int flag=0,ax,ay;
	if(orient==1)
	{
	 for(ax=f.x-10;ax<f.x+10;ax++)
		for(ay=f.y-10;ay<f.y+10;ay++)
			if(MAIN.x1==ax&&MAIN.y1-5==ay)
				flag=1;
	}
	else
	if(orient==2)
	{
	 for(ax=f.x-10;ax<f.x+10;ax++)
		for(ay=f.y-10;ay<f.y+10;ay++)
			if(MAIN.x1==ax&&MAIN.y1+5==ay)
				flag=1;
	}
	else
	if(orient==3)
	{
	 for(ax=f.x-10;ax<f.x+10;ax++)
		for(ay=f.y-10;ay<f.y+10;ay++)
			if(MAIN.x1+5==ax&&MAIN.y1==ay)
				flag=1;
	}
	else
	if(orient==4)
	{
	 for(ax=f.x-10;ax<f.x+10;ax++)
		for(ay=f.y-10;ay<f.y+10;ay++)
			if(MAIN.x1-5==ax&&MAIN.y1==ay)
				flag=1;
	}
  return flag;
}

void drawfood(int x,int y)
{
	setfillstyle(SOLID_FILL,4);
	pieslice(x,y,0,360,10);
}

void nfood()
{
	f.x=random(440)+110;
	f.y=random(340)+50;
	drawfood(f.x,f.y);

}

void draw_snake(int o,int score)
{
	int size=score+1;
	setfillstyle(SOLID_FILL,4);
       if(o==1)
       {
       setcolor(15);
       pieslice(MAIN.x1,MAIN.y1,0,180,10);
       rectangle(MAIN.x1-10,MAIN.y1,MAIN.x1+10,MAIN.y1+(10*size));
       line(MAIN.x1-10,MAIN.y1+(10*size),MAIN.x1,MAIN.y1+(10*size)+10);
       line(MAIN.x1+10,MAIN.y1+(10*size),MAIN.x1,MAIN.y1+(10*size)+10);
       delay(10);
       }
       else if(o==2)
       {
       setcolor(15);
       pieslice(MAIN.x1,MAIN.y1,180,360,10);
       rectangle(MAIN.x1-10,MAIN.y1,MAIN.x1+10,MAIN.y1-(10*size));
       line(MAIN.x1-10,MAIN.y1-(10*size),MAIN.x1,MAIN.y1-(10*size)-10);
       line(MAIN.x1+10,MAIN.y1-(10*size),MAIN.x1,MAIN.y1-(10*size)-10);
       delay(10);

       }

       else if(o==3)
       {
       setcolor(0);
       setfillstyle(SOLID_FILL,4);
       pieslice(MAIN.x1,MAIN.y1,0,360,10);
       setfillstyle(SOLID_FILL,0);
       pieslice(MAIN.x1,MAIN.y1,90,270,10);
       setcolor(15);
       rectangle(MAIN.x1,MAIN.y1-10,MAIN.x1-(10*size),MAIN.y1+10);
       line(MAIN.x1-(10*size),MAIN.y1-10,MAIN.x1-(10*size)-10,MAIN.y1);
       line(MAIN.x1-(10*size),MAIN.y1+10,MAIN.x1-(10*size)-10,MAIN.y1);
       delay(10);
       }

       else if(o==4)
       {
	setcolor(0);
	setfillstyle(SOLID_FILL,0);
	pieslice(MAIN.x1,MAIN.y1,0,360,10);
	setcolor(15);
	setfillstyle(SOLID_FILL,4);
	pieslice(MAIN.x1,MAIN.y1,90,270,10);
	rectangle(MAIN.x1,MAIN.y1+10,MAIN.x1+(10*size),MAIN.y1-10);
	line(MAIN.x1+(10*size),MAIN.y1+10,MAIN.x1+(10*size)+10,MAIN.y1);
	line(MAIN.x1+(10*size),MAIN.y1-10,MAIN.x1+(10*size)+10,MAIN.y1);
	delay(10);
       }
}


void main()
{
       int g=DETECT,w,n=0,c,nx,ny,ch,orient,score=0;
       initgraph(&g,&w,"C:\\turboc3\\bgi");
       cleardevice();
       MAIN.x1=330;
       MAIN.y1=220;
       f.x=500;
       f.y=300;
       while(c!=1)
       {

	char m[31000],mov;
	m[n]=getch();
	mov=m[n];
	MOVE:
	cleardevice();
	if(mov=='w')
	{
	       MAIN.y1-=10;
	       orient=1;
	}
	else if(mov=='s')
	{
		MAIN.y1+=10;
		orient=2;
	}
	else if(mov=='d')
	{
		MAIN.x1+=10;
		orient=3;
	}
	else if(mov=='a')
	{
	   MAIN.x1-=10;
	   orient=4;
	}
	 else
	 {
	   mov=m[n--];
	   goto MOVE;
	 }
	n++;
	map();
	draw_snake(orient,score);
	ch=check_food(orient);
	c=checkcollision();
	if(c==1)
	     endgame(score);
	if(ch==0)
	{
		cleardevice();
		map();
		draw_snake(orient,score);
		drawfood(f.x,f.y);

	}
	else
	{
		nfood();
		score++;
	}
     }

}