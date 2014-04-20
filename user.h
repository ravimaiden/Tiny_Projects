#ifndef USER_H
#define USER_H

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<iomanip>
#include<cstring>
#include<math>
#include "user.h"
#include "train.h"
#include "admin.h"


class user1 {
	char username[40];
	char pass[40]; //to get from user
	char *password;//used for memory all0cation
	char gender;
	char a[10],b[10];
	struct address addr;
	long phno;
	char email[45];
	struct date dob;
	int n;

	public:
	void putfile(void);
	void login(void);
	void regis_getdata(void);
};

struct address {
	char country[20];
	char city[20];
	char state[20];
	char address1[100];
	char *phno;
};

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

void user::login()                   // used to login
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

