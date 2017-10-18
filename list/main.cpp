#include <iostream>
#include <windows.h>
#include "array_list.hpp"
#include "link_list.hpp"
using namespace std;
int main(){
	while(1)
	{
		system("cls");
		cout<<"please select list:"<<endl;
		cout<<"1. array list"<<endl;
		cout<<"2. link list"<<endl;
		cout<<"0. quit"<<endl;
		char a;
		cin>>a;
		if(a=='0')
		{
			break;
		}
		else if(a=='1')
		{
			array_list list1; 
			while(1)
			{
				system("cls");
				cout<<"array list:"<<endl;
				cout<<"1. insert"<<endl;
				cout<<"2. remove"<<endl;
				cout<<"3. show"<<endl;
				cout<<"0. quit"<<endl;
				char m;
				cin>>m;
				if(m=='0'){
					break;
				}
				else if(m=='1'){
					char ele;
					int pos;
					cout<<"please input element:"<<endl;
					cin>>ele;
					cout<<"please input position:"<<endl;
					cin>>pos;
					if(list1.insert(ele,pos)){
						cout<<"insert success!"<<endl;
					}
					else{
						cout<<"insert fail!"<<endl;
					}
					system("pause");
				}
				else if(m=='2'){
					int pos1;
					cout<<"please input position:"<<endl;
					cin>>pos1;
					if(list1.remove(pos1)){
						cout<<"remove success!"<<endl;
					}
					else{
						cout<<"remove fail!"<<endl;
					}
					system("pause");
				}
				else if(m=='3'){
					list1.show();
					system("pause");
				}
				else{
					cout<<"wrong command!"<<endl;
					system("pause");
				}
			}
		}
		else if(a=='2')
		{
			link_list list2;
			while(1)
			{
				system("cls");
				cout<<"link list:"<<endl;
				cout<<"1. insert"<<endl;
				cout<<"2. remove"<<endl;
				cout<<"3. show"<<endl;
				cout<<"0. quit"<<endl;
				char m;
				cin>>m;
				if(m=='0'){
					break;
				}
				else if(m=='1'){
					char ele;
					int pos;
					cout<<"please input element:"<<endl;
					cin>>ele;
					cout<<"please input position:"<<endl;
					cin>>pos;
					if(list2.insert(ele,pos)){
						cout<<"insert success!"<<endl;
					}
					else{
						cout<<"insert fail!"<<endl;
					}
					system("pause");
				}
				else if(m=='2'){
					int pos1;
					cout<<"please input position:"<<endl;
					cin>>pos1;
					if(list2.remove(pos1)){
						cout<<"remove success!"<<endl;
					}
					else{
						cout<<"remove fail!"<<endl;
					}
					system("pause");
				}
				else if(m=='3'){
					list2.show();
					system("pause");
				}
				else{
					cout<<"wrong command!"<<endl;
					system("pause");
				}
			}
		}
		else{
			cout<<"wrong command!"<<endl;
			system("pause");
		}
	}
	system("pause");
	return 0;
}
