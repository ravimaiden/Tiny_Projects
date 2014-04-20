#include<iostream>
#include<fstream>
#include<stdio.h>
#include<iomanip>
#include<cstring>
#include<math.h>

#include <curses.h>

#include "ui.h"
//#include "user.h"
//#include "train.h"
//#include "admin.h"
using namespace std;

int splash_screen(void)
{
	char option;
	initscr();
	clr();
	cout<<"***********************************************************\n";
	cout<<"*                                                         *\n";
	cout<<"*                                                         *\n";
	cout<<"*                                                         *\n";
	cout<<"*                                                         *\n";
	cout<<"*                                                         *\n";
	cout<<"*     -------   -------   -------   -------   -------     *\n";
	cout<<"*        *      *     *   *            *      *           *\n";
	cout<<"*        *      *_____/   *            *      *           *\n";
	cout<<"*        *      *    \\   *            *      *           *\n";
	cout<<"*        *      *     *   *            *      *           *\n";
	cout<<"*     -------   *     *   *------      *      *------     *\n";
	cout<<"*                                                         *\n";
	cout<<"*                                                         *\n";
	cout<<"*                                                         *\n";
	cout<<"*                                                         *\n";
	cout<<"*                                                         *\n";
	cout<<"*                                                         *\n";
	cout<<"***********************************************************\n";
	cout<<"Press Enter to continue or Esc to Exit: ";
	option = getch();
	endwin();
	if(option == '\n')
		return 1;
	else
		return 0;
}

void heading()
{
	textcolor(RED);
	printf("------------------------------------------------------------------\n");
	printf("USER RAILWAY RESERVATION \n");
	printf("------------------------------------------------------------------ \n");
	textcolor(RESET);
}


int user_menu()
{
	int choice;
	heading();
	cout<<endl;
	cout<<"1. CHECKING AVAILABILITY CUM RESERVATION\n"<<endl;
	cout<<"2. CANCELLATION\n"<<endl;
	cout<<"3. LOGOUT\n"<<endl;
	cout<<"ENTER YOUR CHOICE\n"<<endl;
	cin>>choice;
	return choice;
}


int  menu()
{
	int num;
	cout<<"1. LOGIN\n";
	cout<<"2. NEW USER\n";
	cout<<"3. ADMINISTRATOR\n";
	cout<<"4. EXIT\n";
	cout<<"enter your choice\n";
	cin>>num;
	return num;
}



/*code to check validity of the date entered*/
/*
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
*/
