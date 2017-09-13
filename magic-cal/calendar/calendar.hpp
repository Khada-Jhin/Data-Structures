#ifndef CALENDAR_HPP
#define CALENDAR_HPP

#include <iostream>
#include <vector>
using namespace std;

vector<string> v={"January","February","March","April","May","June",
				"July","August","September","October","November","December"};
int days[12]={31,0,31,30,31,30,31,31,30,31,30,31};
std::vector<string> week={"Sun","Mon","Tue","Wed","Thur","Fri","Sat"};

class calendar
{
public:
	int dif;
	calendar(){
		year=2017;
		month=1;
		day=1;
		weekday=0;
		dif=0;
	}
	calendar(int y){
		year=y;
		month=1;
		day=1;
		dif=0;
		int n=0;
		if(y>2017){
			for(int i=2017;i<y;i++){
				if(isleap(i)){
					n+=366;
				}
				else{
					n+=365;
				}
			}
		}
		else if(y<2017){
			for(int i=2016;i>=y;i--){
				if(isleap(i)){
					n+=366;
				}
				else{
					n+=365;
				}
			}
		}
		if(n>7)
			if(n%7==0){
				weekday=0;
			}
			else
				weekday=7-(n%7);
		else
			weekday=n%7;
	}
	calendar(int y,int m,int d){
		int n=0;
		if(y>=2017){
			for(int i=2017;i<y;i++){
				if(isleap(i)){
					n+=366;
				}
				else{
					n+=365;
				}
			}
			if(isleap(y)){
				for(int i=1;i<m;i++){
					if(m>2&&i==2){
						n+=29;
					}
					n+=days[i-1];
				}
				n+=d-1;
			}
			else{
				for(int i=1;i<m;i++){
					if(m>2&&i==2){
						n+=28;
					}
					n+=days[i-1];
				}
				n+=d-1;
			}
		}
		else if(y<2017){
			for(int i=2016;i>=y;i--){
				if(isleap(i)){
					n+=366;
				}
				else{
					n+=365;
				}
			}
			if(isleap(y)){
				for(int i=1;i<m;i++){
					if(m>2&&i==2){
						n-=29;
					}
					n-=days[i-1];
				}
				n-=(d-1);
			}
			else{
				for(int i=1;i<m;i++){
					if(m>2&&i==2){
						n-=28;
					}
					n-=days[i-1];
				}
				n-=(d-1);
			}
		}
		dif=n;
		if(n>7){
			if(n%7==0){
				weekday=0;
			}
			else
				weekday=7-(n%7);
		}
		else
			weekday=n%7;
		//cout<<week[weekday]<<endl;
	}
	void print1(){
		cout<<week[weekday]<<endl;
	}
	bool isleap(int y){
		if((y%4==0&&y%100!=0)||y%400==0){
			return true;
		}
		return false;
	}
	void print(){
		cout<<"Year: "<<year<<endl;
		for(;month<=12;month++){
			day=1;
			cout<<v[month-1]<<":"<<endl;
			if(month==2){
				cout<<"Sun    Mon    Tue    Wed    Thur    Fri    Sat"<<endl;
				if(isleap(year)){
					for(;day<=29;day++){
						weekday=weekday%7;
						if(day==1){
							switch(weekday){
								case 0:
									cout<<" "<<day;
									break;
								case 1:
									cout<<"        "<<day;
									break;
								case 2:
									cout<<"               "<<day;
									break;
								case 3:
									cout<<"                      "<<day;
									break;
								case 4:
									cout<<"                             "<<day;
									break;
								case 5:
									cout<<"                                     "<<day;
									break;
								case 6:
									cout<<"                                           "<<day<<endl;
									break;
							}
						}
						else{
							switch(weekday){
								case 0:
									cout<<" "<<day;
									break;
								case 1:
									cout<<"      "<<day;
									break;
								case 2:
									cout<<"      "<<day;
									break;
								case 3:
									cout<<"      "<<day;
									break;
								case 4:
									cout<<"      "<<day;
									break;
								case 5:
									cout<<"      "<<day;
									break;
								case 6:
									cout<<"      "<<day<<endl;
									break;
							}
						}
						weekday++;
					}
				}
				else{
					for(;day<=28;day++){
						weekday=weekday%7;
						if(day==1){
							switch(weekday){
								case 0:
									cout<<" "<<day;
									break;
								case 1:
									cout<<"        "<<day;
									break;
								case 2:
									cout<<"               "<<day;
									break;
								case 3:
									cout<<"                      "<<day;
									break;
								case 4:
									cout<<"                             "<<day;
									break;
								case 5:
									cout<<"                                     "<<day;
									break;
								case 6:
									cout<<"                                           "<<day<<endl;
									break;
							}
						}
						else{
							switch(weekday){
								case 0:
									cout<<" "<<day;
									break;
								case 1:
									cout<<"      "<<day;
									break;
								case 2:
									cout<<"      "<<day;
									break;
								case 3:
									cout<<"      "<<day;
									break;
								case 4:
									cout<<"      "<<day;
									break;
								case 5:
									cout<<"      "<<day;
									break;
								case 6:
									cout<<"      "<<day<<endl;
									break;
							}
						}
						weekday++;
					}
				}
			}
			else{
				cout<<"Sun    Mon    Tue    Wed    Thur    Fri    Sat"<<endl;
				for(;day<=days[month-1];day++){
					weekday=weekday%7;
						if(day==1){
							switch(weekday){
								case 0:
									cout<<" "<<day;
									break;
								case 1:
									cout<<"        "<<day;
									break;
								case 2:
									cout<<"               "<<day;
									break;
								case 3:
									cout<<"                      "<<day;
									break;
								case 4:
									cout<<"                             "<<day;
									break;
								case 5:
									cout<<"                                     "<<day;
									break;
								case 6:
									cout<<"                                           "<<day<<endl;
									break;
							}
						}
						else{
							switch(weekday){
								case 0:
									cout<<" "<<day;
									break;
								case 1:
									cout<<"      "<<day;
									break;
								case 2:
									cout<<"      "<<day;
									break;
								case 3:
									cout<<"      "<<day;
									break;
								case 4:
									cout<<"      "<<day;
									break;
								case 5:
									cout<<"      "<<day;
									break;
								case 6:
									cout<<"      "<<day<<endl;
									break;
							}
						}
						weekday++;
				}
			}
			cout<<endl;
		}
	}
private:
	int year,month,day;
	int weekday;
};

#endif