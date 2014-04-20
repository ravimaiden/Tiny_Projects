#ifndef TRAIN_H
#define TRAIN_H

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
	train();
	void display(void);
	void modify(void);
	void details(void);
	void cancellation(void);
	void confirm(void);
	void gett(void);
	void modification(void);
	void ticket(void);

};

        
#endif
