#ifndef UI_H
#define UI_H

#define GCC 1

#ifdef GCC
#include <curses.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

#endif

#ifdef GCC
#define printcolor(COLOR, fmt, ...) do {			\
	if(GCC) {						\
		printf(RED "-------------------------------");	\
		printf(fmt, ##__VA_ARGS__);			\
		printf("-------------------------------" RESET);\
	} else {						\
								\
	}							\
} while(0);


#define clrscr() do {				\					
			if(GCC) {		\
				system("clear");\
			} else {		\
				clrscr();	\
			}			\
		} while(0);

#define textcolor(color) do {			\
			if(GCC) {		\
				printf(color)	\
			}			\
			}while(0);

#endif

struct date {
	int dd,mm,y;
};

struct address {
	char country[20];
	char city[20];
	char state[20];
	char address1[100];
	char *phno;
};



/*function prototypes*/

int menu1(void);
int menu(void);
void heading(void);
void date(void);


#endif
