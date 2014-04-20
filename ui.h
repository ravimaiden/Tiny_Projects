#ifndef UI_H
#define UI_H
#include <stdio.h>
#include <stdlib.h>

#define GCC 1
#define DEBUG 1
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

using namespace std;

#ifdef GCC
#define printcolor(COLOR, fmt, ...) do {			\
	if(GCC) {						\
		printf(RED "-------------------------------\n");\
		printf(fmt, ##__VA_ARGS__);			\
		printf("-------------------------------\n" RESET);\
	} else {						\
								\
	}							\
} while(0);


#define clr() do {				\
			if(GCC) {		\
				system("clear");\
			} 			\
		} while(0);

#define textcolor(color) do {			\
			if(GCC) {		\
				printf(color);	\
			}			\
			}while(0);

#endif

#define debug(fmt, ...) do {				\
				if(DEBUG) {		\
					printf(GREEN fmt RESET, ##__VA_ARGS__); \
				}			\
			}while(0);
#define debugfl()	do {				\
				if(DEBUG) {		\
					printf(RED "%s, Line: %d\n" RESET, __func__, __LINE__); \
				}			\
			} while(0);
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

int splash_screen();
int user_menu(void);
int menu(void);
void heading(void);
/*
void date(void);
*/

#endif
