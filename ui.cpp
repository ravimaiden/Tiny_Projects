#include<iostream>
#include<fstream>
#include<stdio.h>
#include<iomanip>
#include<cstring>
#include<math>

#include "ui.h"
#include "user.h"
#include "train.h"
#include "admin.h"

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
