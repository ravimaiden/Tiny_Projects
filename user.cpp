#include<stdio.h>
#include<iomanip>
#include<cstring>
#include<math.h>

#include "user.h"
#include "train.h"
#include "ui.h"

user u[50];

void user::putfile()
{
	ofstream reg;
	reg.open("project.txt",ios::app);
	reg<<username<<password;
	reg.close();
}


void user::regis_getdata()
{
	int i;
	char pwd[12], repwd[12];
	clr();
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
a:	printf("PASSWORD : ");
	gets(pwd);
#if 0
	for(i = 0;i < 8; i++)
	{
		b[i]=getch();
		printf("*");
	}
#endif
	cout<<endl;
	printf("REENTER PASSWORD : ");
	gets(repwd);
#if 0	
	for(i = 0;i < 8; i++)
	{
		a[i]=getch();
	}
	cout<<endl;
#endif
	if(strcmp(pwd,repwd) == 0) {
		strcpy(password, pwd);
		do {
			printf("GENDER : ");
			cin>>gender;
			if((gender!='f') && (gender!='m'))
			{
				printf("enter an valid gender \n");
			}
		} while(gender=='f'|| gender=='m');
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
		textcolor(RESET);
		clr();
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

int user::login()                   // used to login
{
	return 1;
#if 0
	int i;
	char uname[10];
	char pass[12];
	char c[10];
	heading();
	cout<<endl;
	fflush(stdin);
	textcolor(GREEN);
	printf("LOGIN :");
	gets(uname);
	cout<<endl;
	printf("ENTER THE PASSWORD:");
	gets(password);
	return verify(uname, pass);
#endif	
/*
	for(i=0;i<8;i++) {
		//c[i]=getch();
		//printf("*");
	}
*/
	cout<<endl;
}

