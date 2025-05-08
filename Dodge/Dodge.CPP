#include<iostream.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<fstream.h>

struct prot
{
 int x1,y1,x2,y2;
};

struct box
{
 int x1,y1,x2,y2;
};

struct enemy
{
 int x1,y1,x2,y2;
};

struct tether
{
 int x1,y1,x2,y2;
};

struct person
{
 char name[20];
 int score;
}p;

void write(person a)
{
   ofstream of("hscores.txt",ios::app);

   of.write((char *)&a,sizeof(a));

   of.close();
}


void read()         //to read high scores
{
  ifstream f("hscores.txt");
  person ob[1000],temp;
  int i=0,b=1,k;
  char ch,rank[2],score[10][100];

  cleardevice();
  settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
  setusercharsize(3,1,3,1);
  setcolor(3);
  outtextxy(10,150,"HIGH SCORES");
  delay(1000);
  cleardevice();
  setusercharsize(1,1,1,1);
   
  person a; 

  while(!f.eof())
   {
	f.read((char *)&a,sizeof(a));
	if(f.eof())
	   break;
	ob[i]=a;
	i++;
   }

  for(int j=0;j<i;j++)
  {
   for(k=0;k<(i-j-1);k++)
   {
	 if(ob[k].score<=ob[k+1].score)
	{
	 temp=ob[k];
	 ob[k]=ob[k+1];
	 ob[k+1]=temp;

	}
    }
  }

  int x_sno,x_name,x_score,y_all;
  y_all=10;
  x_sno=30;
  x_name=200;
  x_score=400;

  line(10,10,10,260);     //verticalline
  line(150,10,150,260);  //verticalline
  line(375,10,375,260);  //verticalline
  line(530,10,530,260);   //verticalline

  line(10,260,530,260);  //horizontalline
  line(10,50,530,50);    //horizontalline
  line(10,10,530,10);    //horizontalline

  setcolor(15);
  outtextxy(x_sno,y_all,"RANK");
  outtextxy(x_name,y_all,"NAME");
  outtextxy(x_score,y_all,"SCORE");

  for(k=0;k<=4;k++,b++)
  {
	y_all+=40;
	itoa(b,rank,10);
	itoa(ob[k].score,score[k],10);

	if(strcmp(ob[k].name,'\0')==0)
		strcpy(ob[k].name,"-------");

	outtextxy(x_sno,y_all,rank);
	outtextxy(x_name,y_all,ob[k].name);
	outtextxy(x_score,y_all,score[k]);
  }

  f.close();
  exitscoreboard:
  setcolor(3);
  outtextxy(1,370,"Press 'b' or 'B' to go back to the home");
  outtextxy(1,400,"screen");
  ch=getch();
  if(ch=='b'||ch=='B')
	cleardevice();
  else
	goto exitscoreboard;

}



void rulespage()
{
   char back;
   int x,y,x1,y1;
   setcolor(3);
   x=20;
   y=20;

   cleardevice();
   settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
   setusercharsize(3,1,3,1);
   x1=(getmaxx()/2)-140;
   y1=(getmaxy()/2)-100;
   outtextxy(x1,y1,"RULES");
   delay(1000);

   cleardevice();

   setcolor(15);
   setusercharsize(1,1,1,1);

   setfillstyle(1,getcolor());
   pieslice(15,(y+20),0,360,2);         //Bullet points
   pieslice(15,(y+70),0,360,2);
   pieslice(15,(y+120),0,360,2);
   pieslice(15,(y+200),0,360,2);
   pieslice(15,(y+280),0,360,2);

   outtextxy(x,y,"You control the green box.");
   y+=50;

   outtextxy(x,y,"Controls are 'w','a','s','d'.");
   y+=50;

   rectangle(480,70,630,100);
   rectangle(530,40,580,100);

   outtextxy(535,35,"w^");
   outtextxy(538,62,"s");

   line(560,90,565,95);
   line(570,90,565,95);

   outtextxy(490,62,"<a");
   outtextxy(585,62,"d>");

   outtextxy(x,y,"Last as long as possible while");
   y+=30;
   outtextxy((x+25),y,"dodging the red boxes.");
   y+=50;

   outtextxy(x,y,"You will lose if the green box touches");
   y+=30;
   outtextxy((x+30),y,"the edges of the white box.");
   y+=50;
   outtextxy(x,y,"The game will also end if the green");
   y+=30;
   outtextxy((x+30),y,"box touches a red box.");

   exitrulespage:

   setcolor(3);
   y+=75;
   outtextxy(x,y,"Press 'b' or 'B' to go back to the home");
   y+=30;
   outtextxy(x,y,"screen.");
   back=getch();

   if(back=='b'||back=='B')
	cleardevice();
   else
	goto exitrulespage;

}


int startpage()
{
   Mainscreen:
   setcolor(12);
   int x,y;
   char a,ch[20];
   settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
   setusercharsize(3,1,3,1);
   cleardevice();
   x=(getmaxx()/2)-280;
   y=(getmaxy()/2)-200;

   outtextxy((x+150),y,"DODGE");

   setusercharsize(1,1,1,1);

   setcolor(14);
   y+=120;
   outtextxy(x,y,"Press 'R' or 'r' for Rules and controls");

   y+=50;
   outtextxy(x,y,"Press 'P' or 'p' to play the game");

   y+=50;
   outtextxy(x,y,"Press 'V' or 'v' to view high scores");

   y+=50;
   outtextxy(x,y,"Press 'E' or 'e' to exit the program");

   setcolor(15);
   y+=80;
   outtextxy(x,y,"CREATED BY - JATHIN AND GUHA");

   a=getch();

   if(a=='r' || a=='R')
   {
	rulespage();
	goto Mainscreen;
   }
   else if(a=='e'||a=='E')
	return(0);
   else if(a=='P'||a=='p')
   {
	cleardevice();
	setusercharsize(1,1,1,1);
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t";
	outtextxy(5,195,"ENTER YOUR NAME-");
	outtextxy(5,240,"Press enter to continue.");
	gets(p.name);
	cleardevice();
	setcolor(14);
	outtextxy(5,140,"The game starts when you move for the");
	outtextxy(5,170,"first time.");
	outtextxy(5,215,"So does the timer/score.");
	outtextxy(210,275,"GOOD LUCK!");
	delay(5000);
	cleardevice();
	return(1);
   }
   else if(a=='V'||a=='v')
   {
	read();
	goto Mainscreen;
   }
   else
	goto Mainscreen;
}

void endgame(int moves)		//function to display end screen
{
   int a,b;
   setcolor(4);
   int x,y;
   char score[1000];
   settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
   setusercharsize(3,1,3,1);
   cleardevice();
   x=(getmaxx()/2)-280;
   y=(getmaxy()/2)-100;
   outtextxy(x,y,"GAME OVER");

   itoa(moves,score,10);


   setusercharsize(1,1,1,1);
   setcolor(15);
   outtextxy(x+100,y+150,"SCORE-");
   outtextxy(x+250,y+150,score);
   delay(2000);

   p.score=moves;
   write(p);
}

//The next funtion is to check whether the box

int checkcollision(int hx1,int hy1,int hx2,int hy2,int e1x1,int e1y1,int e1x2,int e1y2,int e2x1,int e2y1,int e2x2,int e2y2)
{
   for(int i=e1y1;i<e1y2;i++)
   {
	   for(int j=e1x1;j<e1x2;j++)
	   {
		if(i==hy1&&j==hx1)
			return(1);
		else if(i==hy2&&j==hx1)
			return(1);
		else if(i==hy1&&j==hx2)
			return(1);
		else if(i==hy2&&j==hx2)
			return(1);
	   }
	}

   for(i=e2y1;i<e2y2;i++)
   {
	   for(int j=e2x1;j<e2x2;j++)
	   {
		if(i==hy1&&j==hx1)
			return(1);
		else if(i==hy2&&j==hx1)
			return(1);
		else if(i==hy1&&j==hx2)
			return(1);
		else if(i==hy2&&j==hx2)
			return(1);

	  }
	}
   return(0);
}



void main()
{
clrscr();

Maincode:
int g=DETECT,m,a,b,c,d=0,j=0,st,finx,finy,finx2,finy2,coll,inc1,inc2;
char ch;
initgraph(&g,&m,"c:\\turboc3\\bgi");
box mb={10,10,625,470};
prot hero={250,210,350,290};
tether lteth,rteth;
enemy en1={108,108,188,188},en2={508,108,588,188};


//MAIN CODE STARTS HERE-

st=startpage();
if(st==0)
   exit(0);
else if(st==1)    //The Game starts if this condition is true
{
  randomize();
   for(int i=0;i!=1; )
   {
	inc1=10;
	inc2=10;
	Decide:
	a=random(12);	  //to decide whether it moves upwards randomly or sideways randomly
	if(a==d||a==d+4||a==d+8||a==d-4||a==d-8)
	goto Decide;
	else if(d!=a)
	{
	if(a==0)
	{
	 randomize();
	 finx=mb.x2-10;
	 finy=random(365)+100;
	 if(finy>(en1.y1+en1.y2)/2)
		b=5;
	 else if(finy<(en1.y1+en1.y2)/2)
		b=-5;

	 finx2=mb.x1+10;
	 finy2=random(8000)+1000;
	 if(finy2>(en2.y1+en2.y2)/2)
		c=5;
	 else if(finy2<(en2.y1+en2.y2)/2)
		c=-5;


	for( ;en1.x2<=finx||en2.x1>=finx2;en1.x2+=inc1,en1.x1+=inc1,en1.y1+=b,en1.y2+=b,en2.x2-=inc2,en2.x1-=inc2,en2.y1+=c,en2.y2+=c)
	{
	 setcolor(15);
	 rectangle(mb.x1,mb.y1,mb.x2,mb.y2);   //Boundaries,main box

	 line(20,200,20,300);		      //left restrictor
	 line(615,200,615,300);		      //right resctrictor


	 setcolor(12);
	 setfillstyle(1,getcolor());
	 bar(en1.x1,en1.y1,en1.x2,en1.y2);    //enemy 1(obstacle 1-left)
	 bar(en2.x1,en2.y1,en2.x2,en2.y2);    //enemy 2(obs 2-right)

	 if(en1.y1<=mb.y1+10)
		b=5;
	 else if(en1.y2>=mb.y2)
		b=-5;

	 if(en2.y1<=mb.y1+10)
		c=5;
	 else if(en2.y2>=mb.y2)
		c=-5;

	 setcolor(15);
	 line(20,200,20,300);				//left restrictor
	 line(615,200,615,300);				//right resctrictor

	 rteth.x1=615;rteth.y1=250;rteth.x2=hero.x2;rteth.y2=(hero.y1+hero.y2)/2;
	 lteth.x1=20;lteth.y1=250;lteth.x2=hero.x1;lteth.y2=(hero.y1+hero.y2)/2;


	 line(lteth.x1,lteth.y1,lteth.x2,lteth.y2); //Left tether
	 line(rteth.x1,rteth.y1,rteth.x2,rteth.y2); //Right tether

	 setcolor(2);

	 setfillstyle(6,getcolor());
	 bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0); //Protagonist

	 coll=checkcollision(hero.x1,hero.y1,hero.x2,hero.y2,en1.x1,en1.y1,en1.x2,en1.y2,en2.x1,en2.y1,en2.x2,en2.y2);
	 if(coll==1)
	 {
		i=1;
		break;
	 }


	 ch=getch();
	 if(ch=='w')
	{
	   hero.y1-=5;
	   hero.y2-=5;
	   j++;
	}
	else if(ch=='s')
	{
		hero.y1+=5;
		hero.y2+=5;
		j++;
	}
	else if(ch=='a')
	{
		hero.x1-=5;
		hero.x2-=5;
		j++;
	}
	else if(ch=='d')
	{
		hero.x1+=5;
		hero.x2+=5;
		j++;
	}

	delay(10);

	bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0);

	if(en1.x2>=finx)
	{
		b=0;
		inc1=0;
	}

	if(en2.x1<=finx2)
	{
		c=0;
		inc2=0;
	}

	if(hero.x1<=mb.x1||hero.x2>=mb.x2||hero.y1<=mb.y1||hero.y2>=mb.y2)
	{
		i=1;
		break;
	}
	  cleardevice();
	}
   }


	else if(a==1)
	 {
	randomize();
	finx=mb.x1+10;
	finy=random(8000)+1000;
	if(finy>(en1.y1+en1.y2)/2)
		b=5;
	else if(finy<(en1.y1+en1.y2)/2)
		b=-5;

	finx2=mb.x2-10;
	finy2=random(370)+100;
	if(finy2>(en2.y1+en2.y2)/2)
		c=5;
	else if(finy2<(en2.y1+en2.y2)/2)
		c=-5;


	for(;en1.x1>=finx||en2.x2<=finx2;en1.x1-=inc1,en1.x2-=inc1,en1.y1+=b,en1.y2+=b,en2.x2+=inc2,en2.x1+=inc2,en2.y1+=c,en2.y2+=c )
	{
	 setcolor(15);
	 rectangle(mb.x1,mb.y1,mb.x2,mb.y2);   //Boundaries,main box

	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor


	 setcolor(12);
	 setfillstyle(1,getcolor());
	 bar(en1.x1,en1.y1,en1.x2,en1.y2); //enemy 1(obstacle 1-left)
	 bar(en2.x1,en2.y1,en2.x2,en2.y2); //enemy 2(obs 2-right)

	 if(en1.y1<=mb.y1+10)
		b=5;
	 else if(en1.y2>=mb.y2)
		b=-5;

	 if(en2.y1<=mb.y1+10)
		c=5;
	 else if(en2.y2>=mb.y2)
		c=-5;

	 setcolor(15);
	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor

	 rteth.x1=615;rteth.y1=250;rteth.x2=hero.x2;rteth.y2=(hero.y1+hero.y2)/2;
	 lteth.x1=20;lteth.y1=250;lteth.x2=hero.x1;lteth.y2=(hero.y1+hero.y2)/2;


	 line(lteth.x1,lteth.y1,lteth.x2,lteth.y2);//Left tether
	 line(rteth.x1,rteth.y1,rteth.x2,rteth.y2); //Right tether

	 setcolor(2);
	 setfillstyle(6,getcolor());
	 bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0); //Protagonist

	 coll=checkcollision(hero.x1,hero.y1,hero.x2,hero.y2,en1.x1,en1.y1,en1.x2,en1.y2,en2.x1,en2.y1,en2.x2,en2.y2);
	  if(coll==1)
	 {
		i=1;
		break;
	 }


	 ch=getch();
	 if(ch=='w')
	 {
		hero.y1-=5;
		hero.y2-=5;
		j++;
	 }
	 else if(ch=='s')
	 {
		hero.y1+=5;
		hero.y2+=5;
		j++;
	 }
	else if(ch=='a')
	 {
		hero.x1-=5;
		hero.x2-=5;
		j++;
	 }
	else if(ch=='d')
	 {
		hero.x1+=5;
		hero.x2+=5;
		j++;
	 }

	delay(10);
	bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0);

	if(en1.x1<=finx)
	{
		b=0;
		inc1=0;
	}

	if(en2.x2>=finx2)
	{
		c=0;
		inc2=0;
	}

	if(hero.x1<=mb.x1||hero.x2>=mb.x2||hero.y1<=mb.y1||hero.y2>=mb.y2)
	 {
		i=1;
		break;
	 }

	cleardevice();
	}
	 }


	else if(a==2)
	{
	 randomize();
	 finy=mb.y2-10;
	 finx=random(620)+10;
	 if(finx>(en1.x1+en1.x2)/2)
		  b=5;
	 else
		  b=-5;

	 finx2=mb.x1+10;
	 finy2=random(8000)+1000;
	 if(finy2>(en2.y1+en2.y2)/2)
		c=5;
	 else if(finy2<(en2.y1+en2.y2)/2)
		c=-5;


	 for( ;en1.y2<=finy||en2.x1>=finx2;en1.y2+=inc1,en1.y1+=inc1,en1.x1+=b,en1.x2+=b,en2.x2-=inc2,en2.x1-=inc2,en2.y1+=c,en2.y2+=c)
	{
	 setcolor(15);
	 rectangle(mb.x1,mb.y1,mb.x2,mb.y2);   //Boundaries,main box

	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor


	 setcolor(12);
	 setfillstyle(1,getcolor());
	 bar(en1.x1,en1.y1,en1.x2,en1.y2); //enemy 1(obstacle 1-left)
	 bar(en2.x1,en2.y1,en2.x2,en2.y2); //enemy 2(obs 2-right)

	 if(en1.x1<=mb.x1+10)
		b=5;
	 else if(en1.x2>=mb.x2-10)
		b=-5;

	 if(en2.y1<=mb.y1+10)
		c=5;
	 else if(en2.y2>=mb.y2)
		c=-5;

	 setcolor(15);
	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor

	 rteth.x1=615;rteth.y1=250;rteth.x2=hero.x2;rteth.y2=(hero.y1+hero.y2)/2;
	 lteth.x1=20;lteth.y1=250;lteth.x2=hero.x1;lteth.y2=(hero.y1+hero.y2)/2;


	 line(lteth.x1,lteth.y1,lteth.x2,lteth.y2);//Left tether
	 line(rteth.x1,rteth.y1,rteth.x2,rteth.y2); //Right tether

	 setcolor(2);
	 setfillstyle(6,getcolor());
	 bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0); //Protagonist

	 coll=checkcollision(hero.x1,hero.y1,hero.x2,hero.y2,en1.x1,en1.y1,en1.x2,en1.y2,en2.x1,en2.y1,en2.x2,en2.y2);
	 if(coll==1)
	 {
		i=1;
		break;
	 }


	 ch=getch();
	 if(ch=='w')
	 {
		hero.y1-=5;
		hero.y2-=5;
		j++;
	 }
	 else if(ch=='s')
	 {
		hero.y1+=5;
		hero.y2+=5;
		j++;
	 }
	 else if(ch=='a')
	 {
		hero.x1-=5;
		hero.x2-=5;
		j++;
	 }
	 else if(ch=='d')
	 {
		hero.x1+=5;
		hero.x2+=5;
		j++;
	 }

	 delay(10);
	 bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0);

	if(en1.y2>=finy)
	{
		b=0;
		inc1=0;
	}

	if(en2.x1<=finx2)
	{
		c=0;
		inc2=0;
	}

	 if(hero.x1<=mb.x1||hero.x2>=mb.x2||hero.y1<=mb.y1||hero.y2>=mb.y2)
	 {
		i=1;
		break;
	 }

	 cleardevice();
	}
	 }

	 else if(a==3)
	{
	 randomize();
	 finy=mb.y1+10;
	 finx=random(620)+15;
	 if(finx>(en1.x1+en1.x2)/2)
		b=5;
	 else if(finx<=(en1.x1+en1.x2)/2)
		b=-5;

	 finx2=mb.x1+10;
	 finy2=random(8000)+1000;
	 if(finy2>(en2.y1+en2.y2)/2)
		c=5;
	 else if(finy2<(en2.y1+en2.y2)/2)
		c=-5;


	 for( ;en1.y1>=finy||en2.x1>=finx2;en1.y1-=inc1,en1.y2-=inc1,en1.x1+=b,en1.x2+=b,en2.x2-=inc2,en2.x1-=inc2,en2.y1+=c,en2.y2+=c)
	 {
	 setcolor(15);
	 rectangle(mb.x1,mb.y1,mb.x2,mb.y2);   //Boundaries,main box

	 line(20,200,20,300);   //left restrictor
	 line(615,200,615,300);	//right resctrictor


	 setcolor(12);
	 setfillstyle(1,getcolor());
	 bar(en1.x1,en1.y1,en1.x2,en1.y2); //enemy 1(obstacle 1-left)
	 bar(en2.x1,en2.y1,en2.x2,en2.y2); //enemy 2(obs 2-right)

	 if(en1.x1<=mb.x1+10)
		b=5;
	 else if(en1.x2>=mb.x2-10)
		b=-5;

	 if(en2.y1<=mb.y1+10)
		c=5;
	 else if(en2.y2>=mb.y2)
		c=-5;

	 setcolor(15);
	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor

	 rteth.x1=615;rteth.y1=250;rteth.x2=hero.x2;rteth.y2=(hero.y1+hero.y2)/2;
	 lteth.x1=20;lteth.y1=250;lteth.x2=hero.x1;lteth.y2=(hero.y1+hero.y2)/2;


	 line(lteth.x1,lteth.y1,lteth.x2,lteth.y2);//Left tether
	 line(rteth.x1,rteth.y1,rteth.x2,rteth.y2); //Right tether

	 setcolor(2);

	 setfillstyle(6,getcolor());
	 bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0); //Protagonist

	 coll=checkcollision(hero.x1,hero.y1,hero.x2,hero.y2,en1.x1,en1.y1,en1.x2,en1.y2,en2.x1,en2.y1,en2.x2,en2.y2);
	 if(coll==1)
	 {
		i=1;
		break;
	 }


	 ch=getch();

	 if(ch=='w')
	 {
		 hero.y1-=5;
		 hero.y2-=5;
		 j++;
	 }
	 else if(ch=='s')
	 {
		 hero.y1+=5;
		 hero.y2+=5;
		 j++;
	 }
	 else if(ch=='a')
	 {
		 hero.x1-=5;
		 hero.x2-=5;
		 j++;
	 }
	 else if(ch=='d')
	 {
		 hero.x1+=5;
		 hero.x2+=5;
		 j++;
	 }

	 delay(10);
	 bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0);

	if(en1.y1<=finy)
	{
		b=0;
		inc1=0;
	}

	if(en2.x1<=finx2)
	{
		c=0;
		inc2=0;
	}

	 if(hero.x1<=mb.x1||hero.x2>=mb.x2||hero.y1<=mb.y1||hero.y2>=mb.y2)
	 {
		i=1;
		break;
	 }

	 cleardevice();
	}
	   }


	else if(a==4)
	{
	 randomize();
	 finx=mb.x2-10;
	 finy=random(365)+100;
	 if(finy>(en1.y1+en1.y2)/2)
		b=5;
	 else if(finy<(en1.y1+en1.y2)/2)
		b=-5;

	 finy2=mb.y2-10;
	 finx2=random(620)+10;
	 if(finx2>(en2.x1+en2.x2)/2)
		c=5;
	 else if(finy2<(en2.x1+en2.x2)/2)
		c=-5;


	for( ;en1.x2<=finx||en2.y2<=finy2;en1.x2+=inc1,en1.x1+=inc1,en1.y1+=b,en1.y2+=b,en2.y2+=inc2,en2.y1+=inc2,en2.x1+=c,en2.x2+=c)
	{
	 setcolor(15);
	 rectangle(mb.x1,mb.y1,mb.x2,mb.y2);   //Boundaries,main box

	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor


	 setcolor(12);
	 setfillstyle(1,getcolor());
	 bar(en1.x1,en1.y1,en1.x2,en1.y2); //enemy 1(obstacle 1-left)
	 bar(en2.x1,en2.y1,en2.x2,en2.y2); //enemy 2(obs 2-right)

	 if(en1.y1<=mb.y1+10)
		b=5;
	 else if(en1.y2>=mb.y2)
		b=-5;

	 if(en2.x1<=mb.x1+10)
		c=5;
	 else if(en2.x2>=mb.x2-10)
		c=-5;

	 setcolor(15);
	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor

	 rteth.x1=615;rteth.y1=250;rteth.x2=hero.x2;rteth.y2=(hero.y1+hero.y2)/2;
	 lteth.x1=20;lteth.y1=250;lteth.x2=hero.x1;lteth.y2=(hero.y1+hero.y2)/2;


	 line(lteth.x1,lteth.y1,lteth.x2,lteth.y2);//Left tether
	 line(rteth.x1,rteth.y1,rteth.x2,rteth.y2); //Right tether

	 setcolor(2);

	 setfillstyle(6,getcolor());
	 bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0); //Protagonist

	 coll=checkcollision(hero.x1,hero.y1,hero.x2,hero.y2,en1.x1,en1.y1,en1.x2,en1.y2,en2.x1,en2.y1,en2.x2,en2.y2);
	 if(coll==1)
	 {
		i=1;
		break;
	 }


	 ch=getch();
	 if(ch=='w')
	{
	   hero.y1-=5;
	   hero.y2-=5;
	   j++;
	}
	else if(ch=='s')
	{
		hero.y1+=5;
		hero.y2+=5;
		j++;
	}
	else if(ch=='a')
	{
		hero.x1-=5;
		hero.x2-=5;
		j++;
	}
	else if(ch=='d')
	{
		hero.x1+=5;
		hero.x2+=5;
		j++;
	}

	delay(10);

	bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0);

	if(en1.x2>=finx)
	{
		b=0;
		inc1=0;
	}

	if(en2.y2>=finy2)
	{
		c=0;
		inc2=0;
	}

	if(hero.x1<=mb.x1||hero.x2>=mb.x2||hero.y1<=mb.y1||hero.y2>=mb.y2)
	{
		i=1;
		break;
	}
	  cleardevice();
	}
   }


	else if(a==5)
	{
	randomize();
	finx=mb.x1+10;
	finy=random(8000)+1000;
	if(finy>(en1.y1+en1.y2)/2)
		b=5;
	else if(finy<(en1.y1+en1.y2)/2)
		b=-5;

	finy2=mb.y1+10;
	finx2=random(620)+10;
	if(finx2>(en2.x1+en2.x2)/2)
		c=5;
	else if(finx2<(en2.x1+en2.x2)/2)
		c=-5;

	for(;en1.x1>=finx||en2.y1>=finy2;en1.x1-=inc1,en1.x2-=inc1,en1.y1+=b,en1.y2+=b,en2.y2-=inc2,en2.y1-=inc2,en2.x1+=c,en2.x2+=c )
	{
	 setcolor(15);
	 rectangle(mb.x1,mb.y1,mb.x2,mb.y2);   //Boundaries,main box

	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor


	 setcolor(12);
	 setfillstyle(1,getcolor());
	 bar(en1.x1,en1.y1,en1.x2,en1.y2); //enemy 1(obstacle 1-left)
	 bar(en2.x1,en2.y1,en2.x2,en2.y2); //enemy 2(obs 2-right)

	 if(en1.y1<=mb.y1+10)
		b=5;
	 else if(en1.y2>=mb.y2)
		b=-5;

	 if(en2.x1<=mb.x1+10)
		c=5;
	 else if(en2.x2>=mb.x2-10)
		c=-5;

	 setcolor(15);
	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor

	 rteth.x1=615;rteth.y1=250;rteth.x2=hero.x2;rteth.y2=(hero.y1+hero.y2)/2;
	 lteth.x1=20;lteth.y1=250;lteth.x2=hero.x1;lteth.y2=(hero.y1+hero.y2)/2;


	 line(lteth.x1,lteth.y1,lteth.x2,lteth.y2);//Left tether
	 line(rteth.x1,rteth.y1,rteth.x2,rteth.y2); //Right tether

	 setcolor(2);
	 setfillstyle(6,getcolor());
	 bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0); //Protagonist

	 coll=checkcollision(hero.x1,hero.y1,hero.x2,hero.y2,en1.x1,en1.y1,en1.x2,en1.y2,en2.x1,en2.y1,en2.x2,en2.y2);
	  if(coll==1)
	 {
		i=1;
		break;
	 }


	 ch=getch();
	 if(ch=='w')
	 {
		hero.y1-=5;
		hero.y2-=5;
		j++;
	 }
	 else if(ch=='s')
	 {
		hero.y1+=5;
		hero.y2+=5;
		j++;
	 }
	else if(ch=='a')
	 {
		hero.x1-=5;
		hero.x2-=5;
		j++;
	 }
	else if(ch=='d')
	 {
		hero.x1+=5;
		hero.x2+=5;
		j++;
	 }

	delay(10);
	bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0);

	if(en1.x1<=finx)
	{
		b=0;
		inc1=0;
	}

	if(en2.y1<=finy2)
	{
		c=0;
		inc2=0;
	}

	if(hero.x1<=mb.x1||hero.x2>=mb.x2||hero.y1<=mb.y1||hero.y2>=mb.y2)
	 {
		i=1;
		break;
	 }

	cleardevice();
	}
	  }


	else if(a==6)
	{
	 randomize();
	 finy=mb.y2-10;
	 finx=random(620)+10;
	 if(finx>(en1.x1+en1.x2)/2)
		  b=5;
	 else
		  b=-5;

	 finy2=mb.y1+10;
	 finx2=random(620)+10;
	 if(finx2>(en2.x1+en2.x2)/2)
		c=5;
	 else if(finx2<(en2.x1+en2.x2)/2)
		c=-5;


	 for( ;en1.y2<=finy||en2.y1>=finy2;en1.y2+=inc1,en1.y1+=inc1,en1.x1+=b,en1.x2+=b,en2.y2-=inc2,en2.y1-=inc2,en2.x1+=c,en2.x2+=c)
	{
	 setcolor(15);
	 rectangle(mb.x1,mb.y1,mb.x2,mb.y2);   //Boundaries,main box

	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor


	 setcolor(12);
	 setfillstyle(1,getcolor());
	 bar(en1.x1,en1.y1,en1.x2,en1.y2); //enemy 1(obstacle 1-left)
	 bar(en2.x1,en2.y1,en2.x2,en2.y2); //enemy 2(obs 2-right)

	 if(en1.x1<=mb.x1+10)
		b=5;
	 else if(en1.x2>=mb.x2-10)
		b=-5;

	 if(en2.x1<=mb.x1+10)
		c=5;
	 else if(en2.x2>=mb.x2-10)
		c=-5;

	 setcolor(15);
	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor

	 rteth.x1=615;rteth.y1=250;rteth.x2=hero.x2;rteth.y2=(hero.y1+hero.y2)/2;
	 lteth.x1=20;lteth.y1=250;lteth.x2=hero.x1;lteth.y2=(hero.y1+hero.y2)/2;


	 line(lteth.x1,lteth.y1,lteth.x2,lteth.y2);//Left tether
	 line(rteth.x1,rteth.y1,rteth.x2,rteth.y2); //Right tether

	 setcolor(2);
	 setfillstyle(6,getcolor());
	 bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0); //Protagonist

	 coll=checkcollision(hero.x1,hero.y1,hero.x2,hero.y2,en1.x1,en1.y1,en1.x2,en1.y2,en2.x1,en2.y1,en2.x2,en2.y2);
	 if(coll==1)
	 {
		i=1;
		break;
	 }


	 ch=getch();
	 if(ch=='w')
	 {
		hero.y1-=5;
		hero.y2-=5;
		j++;
	 }
	 else if(ch=='s')
	 {
		hero.y1+=5;
		hero.y2+=5;
		j++;
	 }
	 else if(ch=='a')
	 {
		hero.x1-=5;
		hero.x2-=5;
		j++;
	 }
	 else if(ch=='d')
	 {
		hero.x1+=5;
		hero.x2+=5;
		j++;
	 }

	 delay(10);
	 bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0);

	if(en1.y2>=finy)
	{
		b=0;
		inc1=0;
	}

	if(en2.y1<=finy2)
	{
		c=0;
		inc2=0;
	}

	 if(hero.x1<=mb.x1||hero.x2>=mb.x2||hero.y1<=mb.y1||hero.y2>=mb.y2)
	 {
		i=1;
		break;
	 }

	 cleardevice();
	}
	 }

	 else if(a==7)
	{
	 randomize();
	 finy=mb.y1+10;
	 finx=random(620)+15;
	 if(finx>(en1.x1+en1.x2)/2)
		b=5;
	 else if(finx<=(en1.x1+en1.x2)/2)
		b=-5;

	 finx2=mb.x2-10;
	 finy2=random(370)+100;
	 if(finy2>(en2.y1+en2.y2)/2)
		c=5;
	 else if(finy2<(en2.y1+en2.y2)/2)
		c=-5;


	 for( ;en1.y1>=finy||en2.x2<=finx2;en1.y1-=inc1,en1.y2-=inc1,en1.x1+=b,en1.x2+=b,en2.x1+=inc2,en2.x2+=inc2,en2.y1+=c,en2.y2+=c)
	 {
	 setcolor(15);
	 rectangle(mb.x1,mb.y1,mb.x2,mb.y2);   //Boundaries,main box

	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor


	 setcolor(12);
	 setfillstyle(1,getcolor());
	 bar(en1.x1,en1.y1,en1.x2,en1.y2); //enemy 1(obstacle 1-left)
	 bar(en2.x1,en2.y1,en2.x2,en2.y2); //enemy 2(obs 2-right)

	 if(en1.x1<=mb.x1+10)
		b=5;
	 else if(en1.x2>=mb.x2-10)
		b=-5;

	 if(en2.y1<=mb.y1+10)
		c=5;
	 else if(en2.y2>=mb.y2)
		c=-5;

	 setcolor(15);
	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor

	 rteth.x1=615;rteth.y1=250;rteth.x2=hero.x2;rteth.y2=(hero.y1+hero.y2)/2;
	 lteth.x1=20;lteth.y1=250;lteth.x2=hero.x1;lteth.y2=(hero.y1+hero.y2)/2;


	 line(lteth.x1,lteth.y1,lteth.x2,lteth.y2);//Left tether
	 line(rteth.x1,rteth.y1,rteth.x2,rteth.y2); //Right tether

	 setcolor(2);

	 setfillstyle(6,getcolor());
	 bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0); //Protagonist

	 coll=checkcollision(hero.x1,hero.y1,hero.x2,hero.y2,en1.x1,en1.y1,en1.x2,en1.y2,en2.x1,en2.y1,en2.x2,en2.y2);
	 if(coll==1)
	 {
		i=1;
		break;
	 }


	 ch=getch();

	 if(ch=='w')
	 {
		 hero.y1-=5;
		 hero.y2-=5;
		 j++;
	 }
	 else if(ch=='s')
	 {
		 hero.y1+=5;
		 hero.y2+=5;
		 j++;
	 }
	 else if(ch=='a')
	 {
		 hero.x1-=5;
		 hero.x2-=5;
		 j++;
	 }
	 else if(ch=='d')
	 {
		 hero.x1+=5;
		 hero.x2+=5;
		 j++;
	 }

	 delay(10);
	 bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0);

	if(en1.y1<=finy)
	{
		b=0;
		inc1=0;
	}

	if(en2.x2>=finx2)
	{
		c=0;
		inc2=0;
	}

	 if(hero.x1<=mb.x1||hero.x2>=mb.x2||hero.y1<=mb.y1||hero.y2>=mb.y2)
	 {
		i=1;
		break;
	 }

	 cleardevice();
	}
	  }

	  else if(a==8)
	{
	 randomize();
	 finx=mb.x2-10;
	 finy=random(365)+100;
	 if(finy>(en1.y1+en1.y2)/2)
		b=5;
	 else if(finy<(en1.y1+en1.y2)/2)
		b=-5;

	 finy2=mb.y2-10;
	 finx2=random(620)+10;
	 if(finx2>(en2.x1+en2.x2)/2)
		c=5;
	 else if(finx2<(en2.x1+en2.x2)/2)
		c=-5;


	for( ;en1.x2<=finx||en2.y2<=finy2;en1.x2+=inc1,en1.x1+=inc1,en1.y1+=b,en1.y2+=b,en2.y2+=inc2,en2.y1+=inc2,en2.x1+=c,en2.x2+=c)
	{
	 setcolor(15);
	 rectangle(mb.x1,mb.y1,mb.x2,mb.y2);   //Boundaries,main box

	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor


	 setcolor(12);
	 setfillstyle(1,getcolor());
	 bar(en1.x1,en1.y1,en1.x2,en1.y2); //enemy 1(obstacle 1-left)
	 bar(en2.x1,en2.y1,en2.x2,en2.y2); //enemy 2(obs 2-right)

	 if(en1.y1<=mb.y1+10)
		b=5;
	 else if(en1.y2>=mb.y2)
		b=-5;

	 if(en2.x1<=mb.x1+10)
		c=5;
	 else if(en2.x2>=mb.x2-10)
		c=-5;

	 setcolor(15);
	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor

	 rteth.x1=615;rteth.y1=250;rteth.x2=hero.x2;rteth.y2=(hero.y1+hero.y2)/2;
	 lteth.x1=20;lteth.y1=250;lteth.x2=hero.x1;lteth.y2=(hero.y1+hero.y2)/2;


	 line(lteth.x1,lteth.y1,lteth.x2,lteth.y2);//Left tether
	 line(rteth.x1,rteth.y1,rteth.x2,rteth.y2); //Right tether

	 setcolor(2);

	 setfillstyle(6,getcolor());
	 bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0); //Protagonist

	 coll=checkcollision(hero.x1,hero.y1,hero.x2,hero.y2,en1.x1,en1.y1,en1.x2,en1.y2,en2.x1,en2.y1,en2.x2,en2.y2);
	 if(coll==1)
	 {
		i=1;
		break;
	 }


	 ch=getch();
	 if(ch=='w')
	{
	   hero.y1-=5;
	   hero.y2-=5;
	   j++;
	}
	else if(ch=='s')
	{
		hero.y1+=5;
		hero.y2+=5;
		j++;
	}
	else if(ch=='a')
	{
		hero.x1-=5;
		hero.x2-=5;
	}
	else if(ch=='d')
	{
		hero.x1+=5;
		hero.x2+=5;
	}

	delay(10);

	bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0);

	if(en1.x2>=finx)
	{
		b=0;
		inc1=0;
	}

	if(en2.y2>=finy2)
	{
		c=0;
		inc2=0;
	}

	if(hero.x1<=mb.x1||hero.x2>=mb.x2||hero.y1<=mb.y1||hero.y2>=mb.y2)
	{
		i=1;
		break;
	}
	  cleardevice();
	}
   }


	else if(a==9)
	{
	randomize();
	finx=mb.x1+10;
	finy=random(8000)+1000;
	if(finy>(en1.y1+en1.y2)/2)
		b=5;
	else if(finy<(en1.y1+en1.y2)/2)
		b=-5;

	finy2=mb.y2-10;
	finx2=random(620)+10;
	if(finx2>(en2.x1+en2.x2)/2)
		c=5;
	else if(finx2<(en2.x1+en2.x2)/2)
		c=-5;


	for(;en1.x1>=finx||en2.y2<=finy2;en1.x1-=inc1,en1.x2-=inc1,en1.y1+=b,en1.y2+=b,en2.y2+=inc2,en2.y1+=inc2,en2.x1+=c,en2.x2+=c )
	{
	 setcolor(15);
	 rectangle(mb.x1,mb.y1,mb.x2,mb.y2);   //Boundaries,main box

	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor


	 setcolor(12);
	 setfillstyle(1,getcolor());
	 bar(en1.x1,en1.y1,en1.x2,en1.y2); //enemy 1(obstacle 1-left)
	 bar(en2.x1,en2.y1,en2.x2,en2.y2); //enemy 2(obs 2-right)

	 if(en1.y1<=mb.y1+10)
		b=5;
	 else if(en1.y2>=mb.y2)
		b=-5;

	 if(en2.x1<=mb.x1+10)
		c=5;
	 else if(en2.x2>=mb.x2-10)
		c=-5;

	 setcolor(15);
	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor

	 rteth.x1=615;rteth.y1=250;rteth.x2=hero.x2;rteth.y2=(hero.y1+hero.y2)/2;
	 lteth.x1=20;lteth.y1=250;lteth.x2=hero.x1;lteth.y2=(hero.y1+hero.y2)/2;


	 line(lteth.x1,lteth.y1,lteth.x2,lteth.y2);//Left tether
	 line(rteth.x1,rteth.y1,rteth.x2,rteth.y2); //Right tether

	 setcolor(2);
	 setfillstyle(6,getcolor());
	 bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0); //Protagonist

	 coll=checkcollision(hero.x1,hero.y1,hero.x2,hero.y2,en1.x1,en1.y1,en1.x2,en1.y2,en2.x1,en2.y1,en2.x2,en2.y2);
	  if(coll==1)
	 {
		i=1;
		break;
	 }


	 ch=getch();
	 if(ch=='w')
	 {
		hero.y1-=5;
		hero.y2-=5;
		j++;
	 }
	 else if(ch=='s')
	 {
		hero.y1+=5;
		hero.y2+=5;
		j++;
	 }
	else if(ch=='a')
	 {
		hero.x1-=5;
		hero.x2-=5;
		j++;
	 }
	else if(ch=='d')
	 {
		hero.x1+=5;
		hero.x2+=5;
		j++;
	 }

	delay(10);
	bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0);

	if(en1.x1<=finx)
	{
		b=0;
		inc1=0;
	}

	if(en2.y2>=finy2)
	{
		c=0;
		inc2=0;
	}

	if(hero.x1<=mb.x1||hero.x2>=mb.x2||hero.y1<=mb.y1||hero.y2>=mb.y2)
	 {
		i=1;
		break;
	 }

	cleardevice();
	}
	 }


	else if(a==10)
	{
	 randomize();
	 finy=mb.y2-10;
	 finx=random(620)+10;
	 if(finx>(en1.x1+en1.x2)/2)
		  b=5;
	 else
		  b=-5;

	 finx2=mb.x2-10;
	 finy2=random(370)+100;
	 if(finy2>(en2.y1+en2.y2)/2)
		c=5;
	 else if(finy2<(en2.y1+en2.y2)/2)
		c=-5;


	 for( ;en1.y2<=finy||en2.x2<=finx2;en1.y2+=inc1,en1.y1+=inc1,en1.x1+=b,en1.x2+=b,en2.x2+=inc2,en2.x1+=inc2,en2.y1+=c,en2.y2+=c)
	{
	 setcolor(15);
	 rectangle(mb.x1,mb.y1,mb.x2,mb.y2);   //Boundaries,main box

	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor


	 setcolor(12);
	 setfillstyle(1,getcolor());
	 bar(en1.x1,en1.y1,en1.x2,en1.y2); //enemy 1(obstacle 1-left)
	 bar(en2.x1,en2.y1,en2.x2,en2.y2); //enemy 2(obs 2-right)

	 if(en1.x1<=mb.x1+10)
		b=5;
	 else if(en1.x2>=mb.x2-10)
		b=-5;

	 if(en2.y1<=mb.y1+10)
		c=5;
	 else if(en2.y2>=mb.y2)
		c=-5;

	 setcolor(15);
	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor

	 rteth.x1=615;rteth.y1=250;rteth.x2=hero.x2;rteth.y2=(hero.y1+hero.y2)/2;
	 lteth.x1=20;lteth.y1=250;lteth.x2=hero.x1;lteth.y2=(hero.y1+hero.y2)/2;


	 line(lteth.x1,lteth.y1,lteth.x2,lteth.y2);//Left tether
	 line(rteth.x1,rteth.y1,rteth.x2,rteth.y2); //Right tether

	 setcolor(2);
	 setfillstyle(6,getcolor());
	 bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0); //Protagonist

	 coll=checkcollision(hero.x1,hero.y1,hero.x2,hero.y2,en1.x1,en1.y1,en1.x2,en1.y2,en2.x1,en2.y1,en2.x2,en2.y2);
	 if(coll==1)
	 {
		i=1;
		break;
	 }


	 ch=getch();
	 if(ch=='w')
	 {
		hero.y1-=5;
		hero.y2-=5;
		j++;
	 }
	 else if(ch=='s')
	 {
		hero.y1+=5;
		hero.y2+=5;
		j++;
	 }
	 else if(ch=='a')
	 {
		hero.x1-=5;
		hero.x2-=5;
		j++;
	 }
	 else if(ch=='d')
	 {
		hero.x1+=5;
		hero.x2+=5;
		j++;
	 }

	 delay(10);
	 bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0);

	if(en1.y2>=finy)
	{
		b=0;
		inc1=0;
	}

	if(en2.x2>=finx2)
	{
		c=0;
		inc2=0;
	}

	 if(hero.x1<=mb.x1||hero.x2>=mb.x2||hero.y1<=mb.y1||hero.y2>=mb.y2)
	 {
		i=1;
		break;
	 }

	 cleardevice();
	}
	 }

	 else if(a==11)
	{
	 randomize();
	 finy=mb.y1+10;
	 finx=random(620)+15;
	 if(finx>(en1.x1+en1.x2)/2)
		b=5;
	 else if(finx<=(en1.x1+en1.x2)/2)
		b=-5;

	 finy2=mb.y2-10;
	 finx2=random(620)+10;
	 if(finx2>(en2.x1+en2.x2)/2)
		c=5;
	 else if(finx2<(en2.x1+en2.x2)/2)
		c=-5;


	 for( ;en1.y1>=finy||en2.y2<=finy2;en1.y1-=inc1,en1.y2-=inc1,en1.x1+=b,en1.x2+=b,en2.y2+=inc2,en2.y1+=inc2,en2.x1+=c,en2.x2+=c)
	 {
	 setcolor(15);
	 rectangle(mb.x1,mb.y1,mb.x2,mb.y2);   //Boundaries,main box

	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor


	 setcolor(12);
	 setfillstyle(1,getcolor());
	 bar(en1.x1,en1.y1,en1.x2,en1.y2); //enemy 1(obstacle 1-left)
	 bar(en2.x1,en2.y1,en2.x2,en2.y2); //enemy 2(obs 2-right)

	 if(en1.x1<=mb.x1+10)
		b=5;
	 else if(en1.x2>=mb.x2-10)
		b=-5;

	 if(en2.x1<=mb.x1+10)
		c=5;
	 else if(en2.x2>=mb.x2-10)
		c=-5;

	 setcolor(15);
	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor

	 rteth.x1=615;rteth.y1=250;rteth.x2=hero.x2;rteth.y2=(hero.y1+hero.y2)/2;
	 lteth.x1=20;lteth.y1=250;lteth.x2=hero.x1;lteth.y2=(hero.y1+hero.y2)/2;


	 line(lteth.x1,lteth.y1,lteth.x2,lteth.y2);//Left tether
	 line(rteth.x1,rteth.y1,rteth.x2,rteth.y2); //Right tether

	 setcolor(2);

	 setfillstyle(6,getcolor());
	 bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0); //Protagonist

	 coll=checkcollision(hero.x1,hero.y1,hero.x2,hero.y2,en1.x1,en1.y1,en1.x2,en1.y2,en2.x1,en2.y1,en2.x2,en2.y2);
	 if(coll==1)
	 {
		i=1;
		break;
	 }


	 ch=getch();

	 if(ch=='w')
	 {
		 hero.y1-=5;
		 hero.y2-=5;
		 j++;
	 }
	 else if(ch=='s')
	 {
		 hero.y1+=5;
		 hero.y2+=5;
		 j++;
	 }
	 else if(ch=='a')
	 {
		 hero.x1-=5;
		 hero.x2-=5;
		 j++;
	 }
	 else if(ch=='d')
	 {
		 hero.x1+=5;
		 hero.x2+=5;
		 j++;
	 }

	 delay(10);
	 bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0);

	if(en1.y1<=finy)
	{
		b=0;
		inc1=0;
	}

	if(en2.y2>=finy2)
	{
		c=0;
		inc2=0;
	}

	 if(hero.x1<=mb.x1||hero.x2>=mb.x2||hero.y1<=mb.y1||hero.y2>=mb.y2)
	 {
		i=1;
		break;
	 }

	 cleardevice();
	}
   }


}

	 setcolor(15);
	 rectangle(mb.x1,mb.y1,mb.x2,mb.y2);   //Boundaries,main box

	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor


	 setcolor(12);
	 setfillstyle(1,getcolor());
	 bar(en1.x1,en1.y1,en1.x2,en1.y2); //enemy 1(obstacle 1-left)
	 bar(en2.x1,en2.y1,en2.x2,en2.y2); //enemy 2(obs 2-right)

	 setcolor(15);
	 line(20,200,20,300);//left restrictor
	 line(615,200,615,300);//right resctrictor

	 rteth.x1=615;rteth.y1=250;rteth.x2=hero.x2;rteth.y2=(hero.y1+hero.y2)/2;
	 lteth.x1=20;lteth.y1=250;lteth.x2=hero.x1;lteth.y2=(hero.y1+hero.y2)/2;


	 line(lteth.x1,lteth.y1,lteth.x2,lteth.y2);//Left tether
	 line(rteth.x1,rteth.y1,rteth.x2,rteth.y2); //Right tether


	 setcolor(2);
	 setfillstyle(6,getcolor());
	 bar3d(hero.x1,hero.y1,hero.x2,hero.y2,0,0); //Protagonist

	 d=a;

}
endgame(j);        //function call to display final screen
goto Maincode;
}
getch();
}
