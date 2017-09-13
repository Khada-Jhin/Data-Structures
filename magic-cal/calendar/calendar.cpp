#include <iostream>
#include "calendar.hpp"
using namespace std;
int main(){
	cout<<"1. Any year 2.Any day 3.Tow days' difference"<<endl;
	int key=0;
	cin>>key;
	if(key==1){
		int i=0;
		cout<<"input year"<<endl;
		cin>>i;
		calendar year(i);
		year.print();
		
	}
	else if(key==2){
		cout<<"input date"<<endl;
		int y=0,m=0,d=0;
		cin>>y>>m>>d;
		calendar year(y,m,d);
		year.print1();
	}
	else if(key==3){
		cout<<"input first date"<<endl;
		int y1=0,m1=0,d1=0;
		cin>>y1>>m1>>d1;
		calendar first(y1,m1,d1);
		cout<<"input second date"<<endl;
		int y2=0,m2=0,d2=0;
		cin>>y2>>m2>>d2;
		calendar second(y2,m2,d2);
		int dif=first.dif+second.dif;
		cout<<dif<<endl;
	}
	return 0;
}