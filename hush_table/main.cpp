#include <iostream>
#include <windows.h>
#include "hush_table.hpp"
using namespace std;
int main(){
	hush_table table;
	while(1){
		system("cls");
		cout<<"_____________________"<<endl<<endl;
		cout<<"please input command:"<<endl<<endl;
		cout<<"1: insert;"<<endl;
		cout<<"2: delete;"<<endl;
		cout<<"3: search;"<<endl;
		cout<<"4: insert exited table;"<<endl;
		cout<<"5: show table;"<<endl;
		cout<<"6: save;"<<endl;
		cout<<"0: quit;"<<endl;
		cout<<"_____________________"<<endl<<endl;;
		string com;
		cout<<"~~~~$ : ";
		cin>>com;
		if(com=="0"){
			break;
		}
		else{
			if(com=="1"){
				string name,id,sex,phone;
				cout<<"insert:"<<endl;
				cout<<"_____________________"<<endl<<endl;
				cout<<"name:";cin>>name;
				cout<<"id:";cin>>id;
				cout<<"sex:";cin>>sex;
				cout<<"phone:";cin>>phone;
				cout<<"_____________________"<<endl<<endl;
				student* stu=new student(name,id,sex,phone);
				if(table.insert(stu)){
					cout<<"insert success!"<<endl;
					system("pause");
				}
				else{
					cout<<"insert fail!"<<endl;
					system("pause");
				}
			}
			if(com=="2"){
				string name;
				cout<<"delete:"<<endl;
				cout<<"_____________________"<<endl<<endl;
				cout<<"name:";cin>>name;
				cout<<"_____________________"<<endl<<endl;
				if(table.erase(name)){
					cout<<"delete success!"<<endl;
					system("pause");
				}
				else{
					cout<<"this student is not exited!"<<endl;
					cout<<"delete fail!"<<endl;
					system("pause");
				}
			}
			if(com=="3"){
				string name;
				cout<<"search:"<<endl;
				cout<<"_____________________"<<endl<<endl;
				cout<<"name:";cin>>name;
				cout<<"_____________________"<<endl<<endl;
				if(table.search(name)){
					cout<<"search sucess!"<<endl;
					system("pause");
				}
				else{
					cout<<"this student is not exited!"<<endl;
					system("pause");
				}
			}
			if(com=="4"){
				table.file_in();
				cout<<"insert success!"<<endl;
				system("pause");
			}
			if(com=="5"){
				table.show();
				system("pause");
			}
			if(com=="6"){
				table.save();
				cout<<"save success!"<<endl;
				system("pause");
			}
		}
	}
	return 0;
}
