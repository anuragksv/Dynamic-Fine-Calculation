#include<iostream>
#include<iomanip>
#include<stdlib.h>8
using namespace std;
void quit();
class driver{
	public :
		char name[30],lc_id[30];
		int v[7],t[7],age,n,flag;
		void accept(){
			cout<<"\t>>>>>>>>>>TRAFFIC RULES VIOLATION CHECK<<<<<<<<<<\n\n";
			cout<<"Enter Lisence Number :\t";
			gets(lc_id);
			cout<<"Enter Name of Driver :\t";
			gets(name);
			cout<<"Enter age of Driver  :\t";
			cin>>age;
			if(age<18){
				quit();
				exit(1);
			}
			cout<<"\n\n\t**********VIOLATION HISTORY**********\n\n";
			cout<<"1.Violated Safety Rules (Helmet/Seat Belt)      : \t";
			cin>>v[0];
			cout<<"2.Travelled Without License                     : \t";
			cin>>v[1];
			cout<<"3.Violated Road Rules (Signal Jump/Wrong Route) : \t";
			cin>>v[2];
			cout<<"4.Unsafe Driving (Speeding/Rash Driving)        : \t";
			cin>>v[3];
			cout<<"5.Drink and Drive                               : \t";
			cin>>v[4];
			cout<<"6.Travelled Without/Expired Insurance           : \t";
			cin>>v[5];
			if(v[5]>=0){
				t[5]=5;
			}
			cout<<"7.Pollution Check Violation                     : \t";
			cin>>v[6];
			if(v[6]>=0){
				t[6]=6;
			}
			cout<<"\n\n\t**********VIOLATIONS INDEX**********\n\n1.No Safety (Helmet/Seat Belt)\n2.No License\n";
			cout<<"3.Road Rules (Signal Skip/Wrong Route)\n4.Speeding/Rash Driving\n5.Drunk and Drive\n";
			cout<<"\nEnter number of violations committed :\t";
			cin>>n;
			cout<<"\nEnter the indexes of the violations as mentioned above :\n";
			for(int i=0;i<n;i++)
			cin>>t[i];
		}	
};
class vehicle : public driver{
	public :
		char rc_no[20],ins;
		int lpc;
		void get(){
			cout<<"\n\n\t**********VEHICLE DETAILS**********\n\n";
			cout<<"Enter Registation Number of the vehicle    : \t";
			cin>>rc_no;
			cout<<"Vehicle under active Insurace Policy (Y/N) : \t";
			cin>>ins;
			cout<<"Months since last pollution check          : \t";
			cin>>lpc;
		}
};
class compute : public vehicle{
	public :
		double fine[7],tfine;
	compute(){
		fine[0]=1000;
		fine[1]=5000;
		fine[2]=1000;
		fine[3]=3000;
		fine[4]=10000;
		fine[5]=4000;
		fine[6]=2000;
		tfine = 0;
		flag = 0;
	}
	void violation(int x){
	if(x>0&&x<=5){	
	x--;
	if(v[x]!=0)	
	v[x]++;
	double p = (double) v[x]/100;
	if(v[x]>0&&v[x]<=3){
	p = (p*4)*fine[x];
	fine
	[x]+=p;
	}
	else if(v[x]>3&&v[x]<=6){
	p = (p*8)*fine[x];
	fine[x]+=p;
	}
	else if (v[x]>6&&v[x]<=10){
	p = (p*12)*fine[x];
	fine[x]+=p;
	}
	else if(v[x]>10){
	flag=1;
	}
	tfine+=fine[x];
}
	if((ins=='n'||ins=='N')&&(v[5]>=0&&v[5]<=10)&&x==6){
		double p = (double) v[5]/100;
		p *= fine[5];
		fine[5]+=p;
		tfine+=fine[5];
	}
	else if((ins=='n'||ins=='N')&&v[5]>10&&x==7){
		flag=1;
	}
	if((lpc>6)&&(v[6]>=0&&v[6]<=10)&&x==6){
		double p = (double) v[6]/100;
		p *= fine[6];
		fine[6]+=p;
		tfine+=fine[6];
	}
	else if((lpc>6)&&v[6]>10&&x==6){
		flag=1;
	}
	}
};
void quit(){
	compute q;
	cout<<"\n\t>>>>>>>>>>VIOLATION TICKET<<<<<<<<<<\n\n";
	cout<<"**********WARNING : UNDERAGE DRIVER**********\n";
	cout<<"NOTICE :\n   1.SIEZE VEHICLE\n   2.CONTACT PARENTS/GUARDIANS";
}
main(){
	compute tf;
	tf.accept();
	tf.get();
	for(int i=0;i<tf.n;i++){
		int a=tf.t[i];
		tf.violation(a);
	}
	if(tf.lpc>6){
		tf.violation(6);
	}
	if(tf.ins=='n'||tf.ins=='N'){
		tf.violation(7);
	}
	system("CLS");
	if(tf.flag==0){
		cout<<"\n\n\t>>>>>>>>>>VIOLATION TICKET<<<<<<<<<<\n\n";
		cout<<"NAME OF THE DRIVER          :\t"<<tf.name;
		cout<<"\nLICENSE NUMBER              :\t"<<tf.lc_id;
		cout<<"\nVEHICLE REGISTRATION NUMBER :\t"<<tf.rc_no;
		cout<<"\n\n---------------------------------------------------------------\n";
		cout<<" VIOLATION"<<setw(50)<<"FINE";
		cout<<"\n---------------------------------------------------------------\n";
		for(int i=0;i<tf.n;i++){
			switch(tf.t[i]){
				case 1 : cout<<" Safety (Helmet/Seat Belt)          "<<setw(25)<<tf.fine[0]<<"/-\n";		
				break;
				case 2 : cout<<" No License                         "<<setw(25)<<tf.fine[1]<<"/-\n";		
				break;
				case 3 : cout<<" Road Rules(Signal Skip/Wrong Route)"<<setw(25)<<tf.fine[2]<<"/-\n";	
				break;
				case 4 : cout<<" Speeding/Rash Driving              "<<setw(25)<<tf.fine[3]<<"/-\n";
				break;
				case 5 : cout<<" Drunk and Drive                    "<<setw(25)<<tf.fine[4]<<"/-\n";
				break;
			}
		}
		if(tf.lpc>6){
		cout<<" Polluion Check Violation           "<<setw(25)<<tf.fine[6]<<"/-\n";
		}
		if(tf.ins=='n'||tf.ins=='N'){
		cout<<" Uninsured Vehicle                  "<<setw(25)<<tf.fine[5]<<"/-\n";
		}
		cout<<"---------------------------------------------------------------\n";
		cout<<" TOTAL AMOUNT                       "<<setw(25)<<tf.tfine<<"/-\n";
		cout<<"---------------------------------------------------------------\n\n\n\n\n";			
	}
	else{
		cout<<"\n\t>>>>>>>>>>VIOLATION TICKET<<<<<<<<<<\n\n";
		cout<<"NAME OF THE DRIVER          :\t"<<tf.name;
		cout<<"\nLICENSE NUMBER              :\t"<<tf.lc_id;
		cout<<"\nVEHICLE REGISTRATION NUMBER :\t"<<tf.rc_no;
		cout<<"\n\n**********WARNING : PENALITY LIMIT EXCEEDED**********\n\n";
		cout<<"NOTICE :\n   1.CONFISCATE LISENCE\n   2.SIEZE VEHICLE";
	}
}
