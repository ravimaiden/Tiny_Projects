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

class user u[50];
class train t;

struct date dob;
struct address addr;


int main()
{
	clrscr();
	int r, n;
	class train tha, t;
	
	cout<<setw(45)<<"USSR  RAILWAY RESERVATION\n";
	do
	{
		r = menu();
		switch(r) {
		case 1:
			clrscr();
			u[0].regis_getdata();
			date();
			u[0].login();


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
			u[0].login();
			do {
				n=menu();
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
		u[i].putfile();
	}
return 0;
}

