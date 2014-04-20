#include<iostream>
//#include<fstream>
#include<stdio.h>
#include<stdlib.h>
#include<iomanip>
#include<cstring>
#include<math.h>


#include "ui.h" 
#include "train.h"
#include "user.h"
#define TRUE 1
#define FALSE 0

#if 0
#include "admin.h"
#endif

train t;

user u[50];

struct date dob;
struct address addr;

using namespace std;

int main()
{
	int n;
	if(!splash_screen()) return 0;
	clr();
	int r, n;
	train my_trains, t;
	
	debugfl();
	//init_users();
	cout<<setw(45)<<"USER  RAILWAY RESERVATION\n"<<endl;
	
	#if 1

	while(1) {
		clr();
		r = menu();
		switch(r) {
		case 1: //LOGIN
			clr();
			debug("Case 2 Selected\n");
			/*Display Login Screen*/

			#if 1
			if(u[0].login() == TRUE) {
				while(1) {
					n = user_menu();
					switch(n) {
					case 1:
						clr();
						//train tha;
						my_trains.master();
						my_trains.display();
						my_trains.gett();
						my_trains.modify();
						my_trains.details();
						my_trains.ticket();
						break;
					case 2:
						clr();
						//train t;
						t.cancellation();
						t.confirm();
						t.modification();
						break;
					case 3:
						cout<<"Thank You\n";
						break;
					default:
						break;
					}
				}
			}
			#endif	
			debug("Case 2 End\n");
			break;
			//end case 2

		
		case 2: //NEW USER REGISTRATION
			clr();
			u[0].regis_getdata();
			//verify_date();
			u[0].login();
			debug("Case 1 Selected\n");
			#if 0
			while(1) {
				n = user_menu();
				switch(n) {
				case 1:
					clr();
					#if 0
					tha.display();
					tha.gett();
					tha.modify();
					tha.details();
					tha.ticket();
					#endif
					debugfl();
					break;
				case 2:
					clr();
					#if 0
					t.cancellation();
					t.confirm();
					t.modification();
					#endif
					debugfl();
					break;
				case 3:
					return 0;
					break;
				case 4:
					break;
				default:
					break;
				}
				if(n == 4) break;
			}
			debug("Case 1 End\n");
			#endif
			break;
		case 3:
			clr();
			debug("Case 3 Selected\n");
			#if 0
			administration ad;
			ad.admin();
			#endif
			debug("Case 3 End\n");
			break;
		case 4:
			return 0;
			break;
		default:
			cout<<"Please Enter Correct Option\n";
				
		}//end of switch
	}
	/*
	for(int i=0;i<50;i++) {
		u[i].putfile();
	}
	*/
	debugfl();
#endif
return 0;
}

