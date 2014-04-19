#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<iomanip.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<process.h>
#include<time.h>

//using namespace std;

void display(void);
void train(void);
void details(void);
void cancellation(void);
void confirm(void);
void gett(void);
void modification(void);
void heading(void);

class user1 {
	char username[40];
	char pass[40]; //to get from user
	char *password;//used for memory all0cation
	char gender;
	char a[10],b[10];
	//address addr;
	long phno;
	char email[45];
	//date1 dob;
	int n;

	public:
	void putfile(void);
	void login(void);
	void regis_getdata(void);
}u1[50];

class train {
	float trainno[12];
	char trainname[12][25];
	char boardpt[12][25];
	char destpt[12][25];
	long time;
	long n;
	char username[25];
	int userid;
	int ns;
	char coach[2];
	float acfare[12],scfare[12];
	int sac[12],ssc[12];
	char timing[12][25];
	char n1[20][25];
	int age[20];
	float amt;
	char g[20];
	float trainfare;
	// under variables have been used for cancellation module
	char u_name[25];
	int u_id;

	public :
	void display(void);
	train();
	void modify(void);
	void details(void);
	void cancellation(void);
	void confirm(void);
	void gett(void);
	void modification(void);
	void ticket(void);

}t;

// structures

struct date1 {
	int dd,mm,y;
}dob;

struct address {
	char country[20];
	char city[20];
	char state[20];
	char address1[100];
	char *phno;
}addr;


//functions

int menu1()
{
	int choice;
	heading();
	cout<<endl;
	cout<<"\t1 CHECKING AVAILABILITY CUM RESERVATION\n";
	cout<<"\t2.CANCELLATION                   \n";
	cout<<"ENTER YOUR CHOICE\n";
	cin>>choice;
	return choice;
}


int  menu()
{
	int num;
	heading();
	cout<<endl;
	cout<<"1:REGISTRATION\n";
	cout<<"2:LOGIN\n";
	cout<<"3:ADMINISTRATOR\n";
	cout<<"enter your choice\n";
	cin>>num;
	return num;
}


void heading()
{
	textcolor(RED);
	printf("------------------------------------------------------------------\n");
	cout<<setw(45);
	printf("USRR RAILWAY RESERVATION \n");
	printf("------------------------------------------------------------------ \n");
}


/*code to check validity of the date entered*/
void date()
{
	int dd,mm,y;
	cout<<"Enter the date(ddm1myyyy)\n";
	//cin>>dd>>mm>>y;
z:	scanf("%d%d%d",&dd,&mm,&y);
	textcolor(RED);
	if((y<=2013)&&(y>=1000))
	{
		if(mm==2)
		{
			if(y%4==0)
			{
				if((dd<=29)&&(dd>0))
				{
				textcolor(YELLOW);
				printf("the entered date is valid\n");
				}
				else
				      cout<<"the entered date is not valid\n";
			 }
			if((y%4)!=0)
			{
				if((dd<=28)&&(dd>0))
				     { textcolor(YELLOW);
				      printf("the entered date is valid\n");
				     }
				else
				      cout<<"the entered data is not valid\n";
			}

		}
		else if((mm<=7)&&(mm>0)&&(mm!=2))
		{
			if(mm%2==0)
			{
				if((dd<=30)&&(dd>0))
				{ textcolor(YELLOW);
				      printf("the entered date is valid\n");
				}
				else
					cout<<"the entered date is  not valid\n";
			}
			else
			{
				if((dd<=31)&&(dd>0))
				 {    textcolor(YELLOW);
				      printf("the entered date is valid\n");
				 }
				else
				      cout<<"the entered date is not valid\n";
			}
		}
		else if((mm>7)&&(mm<=12))
		{
			if(mm%2==0)
			{
				if((dd<=31)&&(dd>0))
				{     textcolor(YELLOW);
				      printf("the entered date is valid\n");
				}
				else
					cout<<"the entered date is  not valid\n";
			}
		}
		else
		{
			if((dd<=30)&&(dd>0))
			{ textcolor(YELLOW);
			  printf("the entered date is valid\n");
			}
			else
			cout<<"the entered date is not valid\n";
		}
	}
	else
	{
		cout<<"the entered date is not valid\n";
		cout<<"REENTER\n";
		goto z;
	}
	getch();

}
		      //class functions

void user1::putfile()
{
	ofstream reg;
	reg.open("project.txt",ios::app);
	reg<<username<<password;
}


void user1::regis_getdata()
{
	clrscr();
	heading();
	textcolor(BLUE);
	printf("___________________________________________\n");
	printf("            REGISTRATION                   \n");
	printf("___________________________________________\n");
	cout<<endl;
	textcolor(RED);
	printf("USER NAME : ");
	gets(username);
	cout<<"\n";
	a:printf("PASSWORD : ");
	for(int i=0;i<8;i++)
	{
	b[i]=getch();
	printf("*");
	}
	cout<<endl;
	printf("REENTER PASSWORD : ");
	for(i=0;i<8;i++)
	{
	a[i]=getch();
	}
	cout<<endl;

	if(strcmp(a,b)==0)
	{
		do {
			printf("GENDER : ");
			cin>>gender;
			if((gender!='f')&&(gender!='m'))
			{
				printf("enter an valid gender \n");
			}
		} while(gender=='f'||gender=='m');
			cout<<endl;
		printf("COUNTRY : ");
		gets(addr.country);
		cout<<endl;
		printf("STATE : ");
		gets(addr.state);
		cout<<endl;
		printf("CITY : ");
		gets(addr.city);
		cout<<endl;
		printf("ADDRESS : ");
		gets(addr.address1);
		cout<<endl;
		printf("PHONE NUMBER : ");
		gets(addr.phno);
		cout<<endl;
		printf("EMAIL : ");
		gets(email);
		cout<<endl;
		//end of password checking
	} else {
		textcolor(RED);
		printf("PASSWORD MISSMATCH\n");
		clrscr();
		heading();
		goto a;
	}

		ofstream us;
		us.open("userdata.dat",ios::binary|ios::app);
		while(!us) {
		      us.write((char *)&u1,sizeof(u1));
		}
		us.close();
}//end of regis

void user1::login()                   // used to login
{
	int i;
	char c[10];
	heading();
	cout<<endl;
	fflush(stdin);
	textcolor(RED);
	printf("LOGIN :");
	gets(username);
	cout<<endl;
	printf("ENTER THE PASSWORD:");
	for(i=0;i<8;i++) {
		c[i]=getch();
		//printf("*");
	}
	cout<<endl;
}


class administration : public train
{
	char p[20];
	char *username1;
	char username[30];
	char pass[13];
	public:
	administration()
	{
		strcpy(username, "srikrishnan");
		strcpy(pass, "benedict");
	}
	void admin(void);
}ad;

void administration::admin()
{
	int i;
	char password[13];
	textcolor(BLUE);
d:	printf("USER NAME: \t");
	gets(username1);
	printf("PASSWORD: \t");
	for(i=0;i<8;i++) {
		p[i]=getch();
		printf("*");
	}

	if(strcmp(username,p)==0) {
		if(strcmp(pass,password)==0)
			train();
		else {
			printf("REENTER PASSWORD CORRECTLY\n");
			goto d;
		}
	} else {
		textcolor(RED);
		printf("ENTER A VALID USERNAME:");
	}
}              


void train::train()
{
	trainno[0]=1001;
	strcpy(trainname[0],"RAJDHANI EXPRESS");
	strcpy(boardpt[0],"DELHI");
	strcpy(destpt[0],"CHENNAI");
	strcpy(timing[0],"6:30 am");
	sac[0]=50;
	ssc[0]=100;
	acfare[0]=150;
	scfare[0]=250;


	trainno[1]=1002;
	strcpy(trainname[1],"DURONTO EXPRESS");
	strcpy(boardpt[1],"DELHI");
	strcpy(destpt[1],"CHENNAI");
	strcpy(timing[1],"5:30 pm");
	sac[1]=50;
	ssc[1]=100;
	acfare[1]=150;
	scfare[1]=250;

	trainno[2]=1003;
	strcpy(trainname[2],"NEW JAIPAIGURI EXPRESS");
	strcpy(boardpt[2],"DELHI");
	strcpy(destpt[2],"KOLKATA");
	strcpy(timing[2],"5:45 am");
	sac[2]=50;
	ssc[2]=100;
	acfare[2]=150;
	scfare[2]=250;



	trainno[3]=1004;
	strcpy(trainname[3],"AMARAVATHI EXPRESS");
	strcpy(boardpt[3],"DELHI");
	strcpy(destpt[3],"KOLKATA");
	strcpy(timing[3],"7:00 pm");
	sac[3]=50;
	ssc[3]=100;
	acfare[3]=150;
	scfare[3]=250;



	trainno[4]=1005;
	strcpy(trainname[4],"DADAR EXPRESS");
	strcpy(boardpt[4],"CHENNAI");
	strcpy(destpt[4],"MUMBAI");
	strcpy(timing[4],"7:00 am");
	sac[4]=50;
	ssc[4]=100;
	acfare[4]=150;
	scfare[4]=250;


	trainno[5]=1006;
	strcpy(trainname[5],"CHENNAI EXPRESS");
	strcpy(boardpt[5],"CHENNAI");
	strcpy(destpt[5],"MUMBAI");
	strcpy(timing[5],"6:00 pm");
	sac[5]=50;
	ssc[5]=100;
	acfare[5]=150;
	scfare[5]=250;

	trainno[6]=1007;
	strcpy(trainname[6],"COROMANDEL EXPRESS");
	strcpy(boardpt[6],"CHENNAI");
	strcpy(destpt[6],"KOLKATA");
	strcpy(timing[6],"5:45 am");
	sac[6]=50;
	ssc[6]=100;
	acfare[6]=150;
	scfare[6]=250;


	trainno[7]=1008;
	strcpy(trainname[7],"HOWRAH EXPRESS");
	strcpy(boardpt[7],"CHENNAI");
	strcpy(destpt[7],"KOLKATA");
	strcpy(timing[7],"6:30 pm");
	sac[7]=50;
	ssc[7]=100;
	acfare[7]=150;
	scfare[7]=250;


	trainno[8]=1009;
	strcpy(trainname[8],"GEETHANJALI EXPRESS");
	strcpy(boardpt[8],"KOLKATA");
	strcpy(destpt[8],"MUMBAI");
	strcpy(timing[8],"6:10 am");
	sac[8]=50;
	ssc[8]=100;
	acfare[8]=150;
	scfare[8]=250;


	trainno[9]=10010;
	strcpy(trainname[9],"REDFORT EXPRESS");
	strcpy(boardpt[9],"KOLKATA");
	strcpy(destpt[9],"MUMBAI");
	strcpy(timing[9],"6:45 pm");
	sac[9]=50;
	ssc[9]=100;
	acfare[9]=150;
	scfare[9]=250;


	trainno[10]=10011;
	strcpy(trainname[10],"YESHWATHPUR EXPRESS");
	strcpy(boardpt[10],"KOLKATA");
	strcpy(destpt[10],"DELHI");
	strcpy(timing[10],"7:00 am");
	sac[10]=50;
	ssc[10]=100;
	acfare[10]=150;
	scfare[10]=250;


	trainno[11]=10012;
	strcpy(trainname[11],"SELDAH EXPRESS");
	strcpy(boardpt[11],"KOLKATA");
	strcpy(destpt[11],"DELHI");
	strcpy(timing[11],"6:30 am");
	sac[11]=50;
	ssc[11]=100;
	acfare[11]=150;
	scfare[11]=250;

}
     
void train::display()
{
	clrscr();
	cout<<setw(45)<<"USRR RAILWAY RESERVATION \n\n";
	cout<<"CHECKING FOR TRAIN TO BOOK \n\n";
	cout<<"Train no    Train name\t    boarding point       Destination point    Timing \n\n";
	ifstream df;
	int i;
	df.open("master.dat",ios::binary|ios::in);
	df.read((char *)&t,sizeof(t));
	for(i=0;i<12;i++)
	{
		cout<<trainno[i]<<"   "<<trainname[i]<<"\t   "<<boardpt[i]<<"\t"<<destpt[i]<<"\t"<<timing[i]<<"\n";
	}
	getch();
	df.close();
} //end of display

void train::gett()
{
	clrscr();
	cout<<setw(45)<<"USRR RAILWAY RESERVATION \n\n";
	cout<<setw(30)<<"TICKET RESERVATION\n";
	cout<<"\n";

m:	cout<<"enter train no for reservation";
	cin>>n;
	if((n==1001)||(n==1002)||(n==1003)||(n==1004)||(n==1005)||(n==1006)||(n==1007)||(n==1008)||(n==1009)||(n==10010)||(n==10011)||(n==10012))
	{
		cout<<"enter user's name\n";
		gets(username);
		cout<<"enter the user id\n";
		cin>>userid;
	d:	cout<<"enter the coach(ac/sc)\n";
		gets(coach);
		ifstream df;   int i;
		df.open("master.dat",ios::binary|ios::in);
		df.read((char *)&t,sizeof(t));
		if((strcmp(coach,"ac")==0)) {
			for(i=0;i<12;i++)
			{
				if(n==trainno[i]) {
					cout<<"the no of available seats in ac coach : \n"<<sac[i];
				a:	cout<<"\nenter the no of seats you want to book.\n";
					cin>>ns;
					if((ns<0)||(ns>sac[i]))	{
						cout<<"invalid entry \n";
						cout<<"please enter a valid entry\n";
						goto a;
					}
					break;
				}

			}
		} else if((strcmp(coach,"sc")==0)) {
			for(i=0;i<12;i++)
			{
				if(n==trainno[i])
				{
					cout<<"the no of available seats in sc coach : \n"<<ssc[i];
					b: cout<<"\n enter the no of seats you want to book.\n";
					cin>>ns;
					if((ns<0)||(ns>ssc[i]))
					{
						cout<<"invalid entry \n";
						cout<<"please enter a valid entry\n";
						goto b;
					}
					break;
				 }

			}
		}
		else
		{
			cout<<"invalid entry \n";
			cout<<"please enter a valid entry\n";
			goto d;
		}
		df.close();
		ofstream ress;
		ress.open("cone.dat",ios::binary|ios::app);
		ress<<username<<"\t\t"<<userid<<"\t"<<ns<<"\t"<<coach<<"\t"<<n<<"\n";
		getch();
		}
		else
		{
			cout<<"invalid entry \n";
			cout<<"please enter a valid entry\n";
			goto m;
		}
} //end of gett fun

void train::modify()
{
	ofstream tf;int i;
	tf.open("temp1.dat",ios::binary|ios::app);
	ifstream df;
	df.open("master.dat",ios::binary|ios::in);
	df.read((char *)&t,sizeof(t));
	for(i=0;i<12;i++) {
		if(n!=trainno[i]) {
			tf<<trainno[i]
			<<"   "
			<<trainname[i]
			<<"\t   " 
			<<boardpt[i]
			<<"\t"
			<<destpt[i]
			<<"\t"
			<<timing[i]
			<<"\t  "
			<<sac[i]
			<<"  "
			<<ssc[i]
			<<"\n";
		} else  if(n==trainno[i]) {
				if(strcmp(coach,"ac")==0)
				{
					sac[i]-=ns;
				}
				else if(strcmp(coach,"sc")==0)
				{
					ssc[i]-=ns;
				}
				tf<<trainno[i]
				<<"   "
				<<trainname[i]
				<<"\t   "
				<<boardpt[i]
				<<"\t"
				<<destpt[i]
				<<"\t"
				<<timing[i]
				<<"\t  "
				<<sac[i]
				<<"  "
				<<ssc[i]
				<<"\n";
		}
	} //end of for
	tf.close();
	df.close();
	remove("master.d	at");
	rename("temp1.dat","master.dat");
}//end of modify

void train::details()
{
	amt=0; trainfare=0;
	clrscr();
	cout<<setw(45)<<"USSR RAILWAY RESERVATION \n\n";
	cout<<setw(30)<<"getting details for reservation\n";
	cout<<" \n";
	ifstream df;int i,p;
	df.open("master.dat",ios::binary|ios::in);
	df.read((char *)&t,sizeof(t));
	for(i=0;i<12;i++) {
		if(n==trainno[i]) {
			p=i;
			break;
		}

	}
	if(strcmp(coach,"ac")==0) {
		trainfare=acfare[p];
	} else if(strcmp(coach,"sc")==0) {
		trainfare=scfare[p];
	}
	ofstream out;
	out.open("passenger.dat",ios::binary|ios::app);

	for(i=0;i<ns;i++) {
		cout<<"\n\n enter "<<i+1<<" passenger's name\n";
		gets(n1[i]);
		cout<<"\n enter the age of"<<i+1<<" passenger\n";
		cin>>age[i];
		if(age[i]<=5) {
			  amt+=0;
		} else if(age[i]>=60) {
			amt+=(1/2)*trainfare;
		} else {
			amt+=trainfare;
		}
	y:	cout<<"\n enter the gender of"<<i+1<<" passenger[m/f]\n";
		cin>>g[i];
		if((g[i]=='m')||(g[i]=='f')) {
			continue;
		} else {
			cout<<"invalid entry \n";
			cout<<"please enter a valid entry\n";
			goto y;
		}
			/*out<<username<<n<<"\t"<<n1[i]<<"\t\t"<<age[i]<<"\t"<<g[i]<<"\n";*/
	}
	getch();
}//end of detail fun

        
void train::ticket()
{
	clrscr();
	ifstream df;int i;
	df.open("master.dat",ios::binary|ios::in);
	df.read((char *)&t,sizeof(t));
	getch();
	df.close();
	heading();
	cout<<endl<<endl;
	cout<<setw(40);textcolor(RED);
	printf("JOURNEY CUM RESERVATION TICKET\n\n");
	for(i=0;i<12;i++) {
		if(n==trainno[i]) {
			cout<<"pnr no\ttrain no    train name\t   boarding point    destination point  timing \n\n";
			cout<<trainno[i]+500<<"\t";
			cout<<trainno[i]<<"   "<<trainname[i]<<"\t   "<<boardpt[i]<<"\t"<<destpt[i]<<"\t "<<timing[i]<<"\n";
			break;
		}
	}
	cout<<"seat nos are :";
	for(int j=1;j<=ns;j++) {
		  cout<<j<<" ";
	}
	cout<<"\n";
	/* e:	q=j;
	for(int j=q;j<ns;j++)
		cout<<j<<" " ;
		 goto e;        */
		 cout<<"passenger's details\n";
		 for(i=0;i<ns;i++)
		 {
		cout<<n1[i]<<"\t"<<age[i]<<"\t"<<g[i]<<"\n";
		 }
		 cout<<"total fare:"<<amt<<"\n";
		 cout<<"date of journey : 22/4/2014\n";
}//end of ticket fun

		  
void train::cancellation()
{
	clrscr();
	heading();
	cout<<setw(40)<<" TICKET CANCELLATION :\n";
	cout<<endl;
se:	cout<<"Username : ";
	cin>>u_name;
	cout<<"\nUserId : ";
	cin>>u_id;
	ifstream c,tr,pas;
	tr.open("master.dat",ios::binary|ios::in);
	c.open("cone.dat",ios::binary|ios::in);
	pas.open("passenger.dat",ios::binary|ios::in);
	while((c.read((char *)&t,sizeof(t)))&& ( tr.read((char *)&t,sizeof(t)))) {
		if(((strcmp(username,u_name))==0)&&(userid==u_id)) {
			for(int v=0;v<12;v++) {
				if(n==trainno[v]) {
					clrscr();
					cout<<"---------------------------------------------------\n";
					cout<<setw(45)<<"USSR RAILWAY RESERVATION \n";
					cout<<"----------------------------------------------------\n";
					cout<<endl;
					cout<<setw(40)<<"TICKET CANCELLATION \n";
					cout<<endl;
					cout<<"Welcome "<<u_name<<endl;
					cout<<"Booked Train Details : \n\n";
					cout<<"Train no      Train name     Boarding point     Destination point    Timing \n";
					cout<<trainno[v]<<"  "<<trainname[v]<<"  "<<boardpt[v]<<"  "<<destpt[v]<<"  "<<timing[v]<<endl;
					cout<<"Date of Journey : 22/04/2014"<<endl;
					cout<<"The coach of the train :"<<coach<<endl;
					cout<<"The no of seats you have booked :"<<ns<<endl;
					getch();
					c.close();
					tr.close();
					pas.close();
				} //end of checking train no
			} //end of v loop
		} else { //end of checking userid and useranme
			cout<<"enter an valid username and userid\n";
			goto se;
		}
	}//end of while
}//end of cancellation function
	

void train::confirm()
{
	clrscr();
	heading();
	cout<<endl<<endl;
	cout<<setw(40)<<"TICKET CANCELLATION \n";
	cout<<endl;
	cout<<"Confirmation :\n";
	cout<<endl;
	char ch;
	cout<<"Do you really want to cancel the ticket ? (y/n)\n";
	cin>>ch;
	switch(ch) {
	case 'y':
		ifstream ae,ef;int i,p;  amt=0;
		ae.open("cone.dat",ios::binary|ios::in);
		ef.open("master.dat",ios::binary|ios::in);
		ae.read((char *)&t,sizeof(t));
		ef.read((char *)&t,sizeof(t));
		for(i=0;i<12;i++) {
			if(n==trainno[i]) {
				p=i;
				break;
			}
		}
		if(strcmp(coach,"ac")==0) {
			trainfare=acfare[p];
		} else if(strcmp(coach,"sc")==0) {
			trainfare=scfare[p];
		} 
		
		for(i=0;i<ns;i++) {
			cout<<"\n enter the age of"<<i+1<<" passenger\n";
			cin>>age[i];
			if(age[i]<=5) {
				amt+=0;
			} else if(age[i]>=60) {
				amt+=(1/2)*trainfare;
			} else {
				amt+=trainfare;
			}
		}//end of for
		ae.close();
		ef.close();
		cout<<"The ticket is cancelled.\n";
		cout<<"The amount refunded is : "<<amt<<"\n";
		cout<<"Thank you..\n";
		cout<<"Book next time :) \n";

		ifstream af;
		ofstream fd;
		fd.open("temp.dat",ios::binary|ios::app);

		af.open("cone.dat",ios::binary|ios::in);
		af.read((char *)&t,sizeof(t));
		if((strcmp(u_name,username)>0)&&(strcmp(u_name,username)<0)) {
			fd<<username<<"\t\t"<<userid<<"\t"<<ns<<"\t"<<coach<<"\t"<<n<<"\n";
		}
		remove("cone.dat");
		rename("temp.dat","cone.dat");
		break;
		//end of case 'y'

		case 'n':
		cout<<"Proceed on your journey\n";
		break;

		default:
		cout<<"enter an valid choice\n";
		
	} //end of switch
	getch();
	clrscr();
}//end of confirm function

			
void train::modification()
{
	ofstream ta;int i;
	ta.open("temper.dat",ios::binary|ios::app);
	ifstream da;
	da.open("master.dat",ios::binary|ios::in);
	da.read((char *)&t,sizeof(t));
	for(i=0;i<12;i++) {
		if(n!=trainno[i]) {
			ta<<trainno[i]<<"   "<<trainname[i]<<"\t   "<<boardpt[i]<<"\t"<<destpt[i]<<"\t"<<timing[i]<<"\t  "<<sac[i]<<"  "<<ssc[i]<<"\n";
		} else if(n==trainno[i]) {
			if(strcmp(coach,"ac")==0) {
				sac[i]+=ns;
			} else if(strcmp(coach,"sc")==0) {
				ssc[i]+=ns;
			}
			ta<<trainno[i]<<"   "<<trainname[i]<<"\t   "<<boardpt[i]<<"\t"<<destpt[i]<<"\t"<<timing[i]<<"\t  "<<sac[i]<<"  "<<ssc[i]<<"\n";
		}
	} //end of for
	ta.close();
	da.close();
	remove("master.dat");
	rename("temper.dat","master.dat");
}//end of modi

int main()
{
	clrscr();
	int r, n;
	class train tha, t;
	cout<<setw(45)<<"USSR  RAILWAY RESERVATION\n";
	do
	{
		r=menu();
		switch(r) {
		case 1:
			clrscr();
			u1[0].regis_getdata();
			date();
			u1[0].login();


			do {
				n=menu1();
				switch(n) {
				case 1:
					clrscr();
					//train tha;
					 //  tha.master();
					tha.display();
					tha.gett();
					tha.modify();
					tha.details();
					tha.ticket();
					break;
				case 2:
					clrscr();
					//train t;
					t.cancellation();
					t.confirm();
					t.modification();
					break;
				}
			} while((n>=0)&&(n<=2));
			break;
		  //end case 1
		case 2:
			clrscr();
			u1[0].login();
			do {
				n=menu1();
				switch(n) {
				case 1:
					clrscr();
					//train tha;
					//  tha.master();
					tha.display();
					tha.gett();
					tha.modify();
					tha.details();
					tha.ticket();
					break;
				case 2:
					clrscr();
					//train t;
					t.cancellation();
					t.confirm();
					t.modification();
					break;
				}
			} while((n>=0)&&(n<=2));
				break;
			  //end case 2
		case 3:

			clrscr();
			administration ad;
			ad.admin();
			break;	
		}//end of switch
	} while((r>=1)&&(r<=2));
	for(int i=0;i<50;i++) {
		u1[i].putfile();
	}
return 0;
}

