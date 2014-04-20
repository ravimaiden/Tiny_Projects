#ifndef USER_H
#define USER_H

#include<iostream>
#include<fstream>
#include<stdio.h>
#include<iomanip>
#include<cstring>
#include<math.h>
#include "user.h"
#include "train.h"
#include "ui.h"
//#include "admin.h"

class user {
	char username[40];
	char password[40]; //to get from user
	char gender;
	struct address addr;
	long phno;
	char email[45];
	struct date dob;

	public:
	user(char *u, char *p, char g, long pn, char *em)
	{
		strcpy(username, u);
		strcpy(password, p);
		gender = g;
		phno = pn;
		strcpy(email, em);
	}

	void putfile(void);
	int login(void);
	void regis_getdata(void);
};

#endif
