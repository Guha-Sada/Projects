#include<project.h>

struct location
{
	char name[26];
	int x,y;
}l,s,e;                   //s-starting location,e-ending location

struct Ride
{
	 char uname[26];
	 char stloc[26];   //Starting location
	 char endloc[26];  //Ending location
	 int traffic,fare,cab_type;
}R;

class user
{
	  int fare,traffic,cab_type,r_money;
	  char uname[26],password[26];
	  public:
	  user()
	  {
		r_money=100;
	  }
	  void ninput();		//new user input
	  void update();		//for existing user
	  void homepage();
	  void ride();
	  void add_ride();
	  void prev_rides();
	  int options();
	  void calculate_fare();
	  int checkexistence();	//for existing user
	  void einput();	//for existing user
	  void pretrips();	//to show last five trips
	  void add_money();
	  void updatemoney();
	  char *getuname()
	  {
		return uname;
	  }
	  char *getpass()
	  {
		return password;
	  }
};


void coverpage()
{
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 8);
	outtextxy(190, 160, "REIZEN");
	settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
	outtextxy(200, 240, "cabs and autos");
	delay(2500);
}

void map()
{
	clrscr();
	cleardevice();
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	rectangle(10,10,610,380);
	line(10,160,60,160);
	line(10,180,140,180);
	line(80,160,140,160);
	line(60,160,60,10);
	line(80,160,80,80);
	line(80,60,80,10);
	line(80,60,280,60);
	line(80,80,170,80);
	line(190,80,280,80);
	line(170,80,170,120);
	line(190,80,190,120);
	line(170,120,140,120);
	line(140,120,140,160);
	line(140,180,140,280);
	line(140,340,140,300);
	line(140,340,250,340);
	line(250,380,250,340);
	line(270,380,270,340);
	line(270,340,310,340);
	line(310,340,310,240);
	line(290,320,290,240);
	line(290,240,160,240);
	line(160,240,160,320);
	line(160,320,210,320);
	line(210,320,290,320);
	line(230,220,230,140);
	line(210,220,210,140);
	line(160,220,350,220);
	line(310,240,350,240);
	line(10,280,140,280);
	line(10,300,60,300);
	line(80,300,140,300);
	line(60,300,60,380);
	line(80,300,80,380);
	line(160,220,160,140);
	line(160,140,210,140);
	line(230,140,420,140);
	line(190,120,280,120);
	line(300,120,440,120);
	line(280,120,280,10);
	line(300,120,300,10);
	line(350,280,350,240);
	line(350,280,380,280);
	line(380,280,380,380);
	line(350,220,350,140);
	line(370,260,370,140);
	line(370,120,370,80);
	line(350,120,350,80);
	line(350,80,300,80);
	line(370,80,500,80);
	line(520,80,610,80);
	line(520,60,610,60);
	line(370,60,500,60);
	line(300,60,370,60);
	line(500,60,500,10);
	line(520,60,520,10);
	line(520,80,520,180);
	line(500,80,500,180);
	line(500,200,500,260);
	line(520,200,520,260);
	line(520,280,520,320);
	line(500,280,500,340);
	line(500,340,610,340);
	line(520,320,610,320);
	line(520,280,610,280);
	line(520,260,610,260);
	line(500,260,440,260);
	line(500,280,400,280);
	line(370,260,420,260);
	line(400,280,400,380);
	line(440,260,440,200);
	line(420,260,420,140);
	line(440,180,440,120);
	line(440,180,610,180);
	line(440,200,610,200);
	settextstyle(SMALL_FONT,HORIZ_DIR,5);
	setcolor(4);
	outtextxy(550,120,"KIA ==>");
	outtextxy(110,30,"Chinnaswamy Stadium");
	outtextxy(30,220,"City Station");
	outtextxy(82,100,"Cubbon Park");
	outtextxy(100,350,"Lalbagh Gardens");
	outtextxy(440,350,"Vidhana Soudha");
	outtextxy(390,90,"Phoenix Mall");
	outtextxy(165,270,"Bannerghatta Zoo");
	outtextxy(350,30,"ISKCON Temple");
	outtextxy(443,220,"NPS HSR");
	outtextxy(323,300,"Apollo");
	outtextxy(318,315,"Hospital");
	outtextxy(255,170,"Food Court");
	settextstyle(SMALL_FONT,HORIZ_DIR,4);
	outtextxy(530,140,"(Kempegowda");
	outtextxy(532,150,"International");
	outtextxy(532,160,"Airport)");
	setcolor(15);
}

location get_location(char *a) //returns location details
{
	ifstream fin("LOCATION.dat",ios::binary);
	while(fin.read((char*)&l,sizeof(location)))
	{
		if(strcmpi(a,l.name)==0)
			break;
	}
	fin.close();
	return l;
}

void user::calculate_fare()
{
	fare=sqrt(pow((abs(e.x-s.x)),2)+pow((abs(e.y-s.y)),2));
	if(strcmpi(e.name,"KIA")==0||strcmpi(s.name,"KIA")==0)
		fare+=1100;
	if(traffic==2)
		fare+=40;
	else if(traffic==3)
		fare+=80;
	if(cab_type==1)
		fare-=20;
	else if(cab_type==3)
		fare+=30;
	else if(cab_type==4)
		fare+=80;
}

int check_locations(char *a,char *b)
{
	if(strcmpi(a,b)==0)
		return 0;

	ifstream fin("LOCATION.dat",ios::binary);
	int flag=0;
	while(fin.read((char*)&l,sizeof(location)))
	{
		if(strcmpi(l.name,a)==0)
		{
			flag=1;
			s=l;
			break;
		}
	}

	if(flag==0)
		   return 0;

	fin.seekg(0,ios::beg);

	while(fin.read((char*)&l,sizeof(location)))
	{
		if(strcmpi(l.name,b)==0)
		{
			flag=2;
			e=l;
			break;
		}
	}
	if(flag==1)
		return 0;
	return 1;
}

void user::add_ride()
{
	 strcpy(R.uname,uname);
	 strcpy(R.stloc,s.name);
	 strcpy(R.endloc,e.name);
	 R.fare=fare;
	 R.traffic=traffic;
	 R.cab_type=cab_type;
	 ofstream fout("Rides.dat",ios::binary|ios::app);
	 fout.write((char*)&R,sizeof(Ride));
	 fout.close();
}

void user::updatemoney()
{
	fstream f("Users.dat",ios::binary|ios::in|ios::out);
	user ob;
	int pos;
	while(f.read((char*)&ob,sizeof(user)))
	{
		if(strcmp(ob.getuname(),uname)==0)
		{
			pos=f.tellg();
			ob.r_money=r_money;
			f.seekp(pos-sizeof(user),ios::beg);
			f.write((char*)&ob,sizeof(user));
			break;
		}

	}
}


void user::ride()
{
	 int flag=0;
	 randomize();
	 int ppl;
	 Ride ele;
	 STARTRIDE:
	 map();
	 cout<<"Enter the number of passengers(max. 6)-\t";
	 cin>>ppl;
	 if(ppl>6||ppl<1)
	 {
		clrscr();
		cleardevice();
		cout<<"\nPlease enter a valid number of people";
		getch();
		goto STARTRIDE;
	 }
	 cout<<"\nEnter Starting Location-\t";
	 gets(ele.stloc);
	 cout<<"Enter Destination-\t\t";
	 gets(ele.endloc);
	 flag=check_locations(ele.stloc,ele.endloc);
	 clrscr();
	 cleardevice();
	 if(flag==0)
	 {
		 cout<<"\tEnter the name of the places carefully-\n\tPress any key to re-enter locations";
		 getch();
		 goto STARTRIDE;
	 }
	 else if(flag==1)
	 {
		 CABTYPE:
		 clrscr();
		 cleardevice();
		 if(ppl<=2&&ppl>0)
		 {
			cout<<"\tWhat cab do you want to book?\n";
			cout<<"\t1)Reizen Auto(2 seats)\n\t2)Reizen Small(3 seats)\n\t3)Reizen Medium(4 seats)\n\t4)Reizen Large(6 seats)\n\tCHOOSE-";
			cin>>cab_type;
		 }
		 else if(ppl==3)
		 {
			cout<<"\tWhat cab do you want to book?\n";
			cout<<"\t2)Reizen Small(3 seats)\n\t3)Reizen Medium(4 seats)\n\t4)Reizen Large(6 seats)\n\tCHOOSE-";
			cin>>cab_type;
		 }
		 else if(ppl==4)
		 {
			cout<<"\tWhat cab do you want to book?\n";
			cout<<"\t3)Reizen Medium(4 seats)\n\t4)Reizen Large(6 seats)\n\tCHOOSE-";
			cin>>cab_type;
		 }
		 else if(ppl<7)
			cab_type=4;
		 else
		 {
			cout<<"\tPlease Enter Valid Number Of Passengers";
			goto CABTYPE;
		 }
		 clrscr();
		 cleardevice();
		 calculate_fare();
		 cout<<"Estimated fare for this ride-"<<fare;
		 if(r_money<fare)
		 {
			cout<<"\nYou have to pay by cash,your current balance of reizen money is lower than fare";
			getch();
		 }
		 else
		 {
			int opt;
			cout<<"\nWould you like to pay by-\n1)Cash\n2)Reizen Money\nChoose-\t";
			cin>>opt;
			if(opt==2)
			{
				r_money-=fare;
				updatemoney();
			}
		 }
		 clrscr();
		 cleardevice();
		 randomize();
		 traffic=random(3)+1;
		 cout<<"Your ride has been booked.";
		 cout<<"\nRide Details-\n";
		 cout<<"Starting location-\t";
		 puts(ele.stloc);
		 cout<<"Ending location-\t";
		 puts(ele.endloc);
		 cout<<"Cab type-\t\t";
		 if(cab_type==1)
			cout<<"Reizen Auto\n";
		 else if(cab_type==2)
			cout<<"Reizen Small\n";
		 else if(cab_type==3)
			cout<<"Reizen Medium\n";
		 else if(cab_type==4)
			cout<<"Reizen Large\n";
		 cout<<"Traffic Level-\t\t";
		 if(traffic==1)
			cout<<"Low";
		 else if(traffic==2)
			cout<<"Medium";
		 else if(traffic==3)
			cout<<"High";
		 cout<<"\nFare-\t\t\t"<<fare;
		 getch();
		 add_ride();
	 }
	 cleardevice();
}

void user::prev_rides()
{
	clrscr();
	cleardevice();
	ifstream fin("Rides.dat",ios::binary);
	Ride ob,pre[3];
	int i=0,opt,ppl;
	while(fin.read((char*)&ob,sizeof(Ride)))
	{
		if(strcmp(ob.uname,uname)==0)
		{
			pre[i++]=ob;
		}
	}
	fin.close();
	int j=i;
	for(int no=0;no<3&&j>0;)
	{
			cout<<"\nRide #"<<++no;
			cout<<"\nStart Location-\t";
			puts(pre[i-no].stloc);
			cout<<"End Location-\t";
			puts(pre[i-no].endloc);
			cout<<"Cab type-\t";
			if(pre[i-no].cab_type==1)
				cout<<"Reizen Auto\n";
			else if(pre[i-no].cab_type==2)
				cout<<"Reizen Small\n";
			else if(pre[i-no].cab_type==3)
				cout<<"Reizen Medium\n";
			else if(pre[i-no].cab_type==4)
				cout<<"Reizen Large\n";
			cout<<"Traffic Level-\t";
			if(pre[i-no].traffic==1)
				cout<<"Low";
			else if(pre[i-no].traffic==2)
				cout<<"Medium";
			else if(pre[i-no].traffic==3)
				cout<<"High";
			cout<<"\nFare-\t\t"<<pre[i-no].fare<<endl;
			j--;
	}
	cout<<"\nChoose any of the above rides by pressing the ride number(1 to 3).\nNote that the fares are subject to change based on the current traffic level.\nIf you want to pick a new ride, press 0.\n";
	cin>>opt;
	if(opt!=0&&opt<=3)
	{
		 CABTYPEA:
		 clrscr();
		 cleardevice();
		 cout<<"Enter the number of passengers(max. 6)\t-";
		 cin>>ppl;
		 if(ppl<=2&&ppl>0)
		 {
			cout<<"\tWhat cab do you want to book?\n";
			cout<<"\t1)Reizen Auto(2 seats)\n\t2)Reizen Small(3 seats)\n\t3)Reizen Medium(4 seats)\n\t4)Reizen Large(6 seats)\n\tCHOOSE-";
			cin>>cab_type;
		 }
		 else if(ppl==3)
		 {
			cout<<"\tWhat cab do you want to book?\n";
			cout<<"\t2)Reizen Small(3 seats)\n\t3)Reizen Medium(4 seats)\n\t4)Reizen Large(6 seats)\n\tCHOOSE-";
			cin>>cab_type;
		 }
		 else if(ppl==4)
		 {
			cout<<"\tWhat cab do you want to book?\n";
			cout<<"\t3)Reizen Medium(4 seats)\n\t4)Reizen Large(6 seats)\n\tCHOOSE-";
			cin>>cab_type;
		 }
		 else if(ppl<7)
			cab_type=4;
		 else
		 {
			cout<<"\tEnter valid number of passengers";
			goto CABTYPEA;
		 }
		 s=get_location(pre[i-opt].stloc);
		 e=get_location(pre[i-opt].endloc);
		 clrscr();
		 cleardevice();
		 calculate_fare();
		 cout<<"Estimated fare for this ride-"<<fare;
		 if(r_money<fare)
		 {
			cout<<"\nYou have to pay by cash,your current balance of reizen money is lower than fare";
			getch();
		 }
		 else
		 {
			int opt;
			cout<<"\nWould you like to pay by-\n1)Cash\n2)Reizen Money\nChoose-\t";
			cin>>opt;
			if(opt==2)
			{
				r_money-=fare;
				updatemoney();
			}
		 }
		 clrscr();
		 cleardevice();
		 randomize();
		 traffic=random(3)+1;
		 cout<<"Your ride has been booked.";
		 cout<<"\nRide Details-\n";
		 cout<<"Starting location-\t";
		 puts(s.name);
		 cout<<"Ending location-\t";
		 puts(e.name);
		 cout<<"Cab type-\t\t";
		 if(cab_type==1)
			cout<<"Reizen Auto\n";
		 else if(cab_type==2)
			cout<<"Reizen Small\n";
		 else if(cab_type==3)
			cout<<"Reizen Medium\n";
		 else if(cab_type==4)
			cout<<"Reizen Large\n";
		 cout<<"Traffic Level-\t\t";
		 if(traffic==1)
			cout<<"Low";
		 else if(traffic==2)
			cout<<"Medium";
		 else if(traffic==3)
			cout<<"High";
		 cout<<"\nFare-\t\t\t"<<fare;
		 opt--;
		 getch();
		 add_ride();
	}
}

void user::update()
{
	user ob,ele;
	ifstream fin("Users.dat",ios::binary);
	ofstream fout("NU.dat",ios::binary);
	cout<<"\nEnter new password-\n";
	gets(ele.password);
	strcpy(ele.uname,uname);
	while(fin.read((char*)&ob,sizeof(user)))
	{
		   if(strcmp(ob.getuname(),uname)==0)
			 fout.write((char*)&ele,sizeof(user));
		   else
			 fout.write((char*)&ob,sizeof(user));
	}
	fin.close();
	fout.close();
	remove("Users.dat");
	rename("NU.dat","Users.dat");
	cout<<"\nPassword updated\n";
}

int user::options()
{
	clrscr();
	cleardevice();
	int opt;
	cout<<"\t1)Change password\n\t2)Logout\n\tCHOOSE-";
	cin>>opt;
	switch(opt)
	{
		case 1 :update();
			return 0;
		case 2 :return 1;
		default:cout<<"INVALID CHOICE";
	}
	clrscr();
	cleardevice();
	return 0;
}


void user::add_money()
{
	   user ob;
	   int add;
	   clrscr();
	   cleardevice();
	   cout<<"\nCurrent Balance-\t"<<r_money;
	   cout<<"\nMAXIMUM MONEY THAT CAN BE STORED-\tRs.2000\n";
	   if(r_money==2000)
	   {
		cout<<"Your current Balance is the maximum balance";
		getch();
	   }
	   else
	   {
		cout<<"Enter the amount to be added-\t";
		cin>>add;
		if(r_money+add>2000)
		{
			clrscr();
			cleardevice();
			cout<<"Error!\nMAXIMUM MONEY THAT CAN BE STORED-\tRs.2000\n";
			getch();
		}
		else
		{
			clrscr();
			cleardevice();
			cout<<"Balance Updated";
			r_money+=add;
			updatemoney();
			getch();
		}

	   }
}


void user::homepage()
{
	  int flag=0,money;
	  char mon[5];
	  do
	  {
	  int opt;
	  clrscr();
	  cleardevice();
	  cout<<"\n\n\n\n\n\t";
	  settextstyle(SMALL_FONT,HORIZ_DIR,4);
	  setusercharsize(4,1,4,1);
	  outtextxy(60,35,"HOME PAGE-");
	  setusercharsize(2,1,2,1);
	  outtextxy(370,50,"CURRENT BALANCE-");
	  money=r_money;
	  itoa(money,mon,10);
	  outtextxy(570,50,mon);
	  cout<<"1)Book a Cab\n\n\t2)View previous 3 rides\n\n\t3)Add money\n\n\t4)Other Options\n\n\tChoose-\t";
	  cin>>opt;
	  switch(opt)
	  {
		case 1 :ride();
			break;
		case 2 :prev_rides();
			break;
		case 3 :add_money();
			break;
		case 4 :flag=options();
			break;
		default:cout<<"Invalid choice-";
	  }
	 }while(flag==0);

}

void addtodatabase(user ele)
{
	  ofstream fout("Users.dat",ios::binary|ios::app);
	  fout.write((char*)&ele,sizeof(user));
	  fout.close();
}


void user::ninput()
{
	user ob,ele;				//ele for inputing details to file
	int flag;
	char u[26],pv[26],p[26];		//username,Password and verifying password
	ifstream fin("Users.dat",ios::binary);
	INPUT:
	clrscr();
	cleardevice();
	flag=0;
	cout<<"\nEnter Username(26 characters or less):\t";
	gets(u);
	fin.seekg(0,ios::beg);
	while(fin.read((char*)&ob,sizeof(user)))
	{
		   if(strcmpi(u,ob.getuname())==0)
		   {
			flag=1;
			break;
		   }
	}
	if(flag==1)
	{
		 cout<<"\nUsername already exists\n Pick a new one.Press any key to continue";
		 getch();
		 goto INPUT;
	}
	else
	{
		 cout<<"Username valid\n";
		 strcpy(uname,u);
		 strcpy(ele.uname,u);
	}
	fin.close();
	cout<<"Enter Password(26 characters or less):\t";
	gets(p);
	cout<<"\nVerify Password:\t\t\t";
	gets(pv);
	if(strcmp(p,pv)==0)
	{
		 strcpy(password,p);
		 strcpy(ele.password,p);
		 addtodatabase(ele);
		 homepage();
	}
	else
	{
		 cout<<"Passwords don't match,Redo the entries.\nPressany key to continue";
		 goto INPUT;
	}
}

void forgotpassword()
{
	   char w[26];
	   int flag=0;
	   user ob;
	   clrscr();
	   cleardevice();
	   cout<<" FORGOT PASSWORD-\n";
	   ifstream fin("Users.dat",ios::binary);
	   cout<<"\n Enter username:\t";
	   gets(w);
	   while(fin.read((char*)&ob,sizeof(user)))
	   {
		 if(strcmp(ob.getuname(),w)==0)
		 {
			cout<<"\n Your Password is:\t";
			puts(ob.getpass());
			flag=1;
			getch();
			break;
		 }
	   }
	   fin.close();
	   if(flag==0)
	   {
		cout<<"\n Username doesn't exist\n";
		getch();
	   }
}

int user::checkexistence()
{
	int flag=0;
	ifstream fin("Users.dat",ios::binary);
	user ob;
	while(fin.read((char*)&ob,sizeof(user)))
	{
		if(strcmp(ob.getuname(),uname)==0&&strcmp(ob.getpass(),password)==0)
		{
			flag=1;
			r_money=ob.r_money;
			break;
		}
	}
	fin.close();
	return flag;
}

void user::einput()
{
	  EINPUT:
	  clrscr();
	  cleardevice();
	  int chk;
	  char yn,opt;
	  cout<<"\nEnter username:\t";
	  gets(uname);
	  cout<<"Press 'e' to enter password or 'f' if you forgot password.\t";
	  cin>>opt;
	  if(opt=='e')
	  {
			cout<<"Enter password:  \t";
			gets(password);
			chk=checkexistence();
			if(chk==0)
			{
				cout<<" Username or Password invalid\n Would you like to re-enter the information?(y/n)";
				cin>>yn;
				if(yn=='y'||yn=='Y')
				goto EINPUT;
			}
			else
			{
				clrscr();
				homepage();
			}
	  }
	  else if(opt=='f'||opt=='F')
	  {
			forgotpassword();
	  }
}

void newcustomer()
{
	  user g;
	  g.ninput();
	  cleardevice();

}

void existingcustomer()
{
	user g;
	g.einput();
	cleardevice();
}

void main()
{
	 int g=DETECT,m;
	 initgraph(&g,&m,"c:\\turboc3\\bgi");
	 coverpage(); 
	 int opt,redo;
	 do
	 {
		clrscr();
		cleardevice();
		cout<<"\n1)NEW CUSTOMER\n2)EXISTING CUTOMER\n3)Exit\nCHOOSE-\t";
		cin>>opt;
		switch(opt)
		{
			 case 1 :newcustomer();
				 break;
			 case 2 :existingcustomer();
				 break;
			 case 3 :exit(0);
			 default:cout<<"\nInvalid choice\n";
				 delay(1000);
		}
	 }while(opt!=0);
	 getch();
}