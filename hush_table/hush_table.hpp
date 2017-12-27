#ifndef HUSH_TABLE_HPP
#define HUSH_TABLE_HPP

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

struct student{
	string name;
	string id;
	string sex;
	string phone;
	student *next;
	student (string n,string i,string s,string p){
		name=n;
		id=i;
		sex=s;
		phone=p;
		next=NULL;
	}
};

class hush_table
{
public:
	hush_table(){
		table=new student*[max];
		for(int i=0;i<max;i++){
			table[i]=NULL;
		}
		person=0;
	}
	int hush(int key){
		return key%num;
	}
	bool search(string name){
		int n=1;
		int key=get_key(name);
		int pos=hush(key);
		if(table[pos]!=NULL){
			student *temp=table[pos];
			while(temp!=NULL){
				if(temp->name==name){
					cout<<"_____________________"<<endl<<endl;
					cout<<"name: "<<temp->name<<endl;
					cout<<"id: "<<temp->id<<endl;
					cout<<"sex: "<<temp->sex<<endl;
					cout<<"phone: "<<temp->phone<<endl;
					cout<<"_____________________"<<endl;
					cout<<"Search times: "<<n<<endl;
					return true;
				}
				temp=temp->next;
				n++;
			}
		}
		return false;
	}
	bool insert(student* stu){
		if(person==max){
			cout<<"table is full!"<<endl;
			return false;
		}
		if(search(stu->name)){
			cout<<"this student is exited!"<<endl;
			return false;
		}
		int key=get_key(stu->name);
		int pos=hush(key);
		//cout<<pos;
		if(table[pos]){
			student *temp=table[pos];
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=stu;
		}
		else{
			table[pos]=stu;
			//cout<<table[pos]->name<<endl;
		}
		person++;
		return true;
	}
	bool erase(string name){
		if(!search(name)){
			return false;
		}
		int key=get_key(name);
		int pos=hush(key);
		student *head=table[pos];
		student *temp;
		if(head->name==name){
			table[pos]=head->next;
			delete head;
			person--;
			return true;
		}
		while(head!=NULL){
			temp=head;
			head=head->next;
			if(head->name==name){
				break;
			}
		}
		temp->next=head->next;
		delete head;
		person--;
		return true;
	}
	int get_key(string name){
		int k=0,key=0;
		for(int i=0;i<name.length();i++){
			k=name[i]-'a';
			if(k>=10){
				key=key*100+k;
			}
			else{
				key=key*10+k;
			}
		}
		if(key<0){
			key=-key;
		}
		return key;
	}
	void show(){
		for(int i=0;i<max;i++){
			if(table[i]){
				cout<<i<<": "<<endl;
				student *temp=table[i];
				while(temp!=NULL){
					cout<<"_____________________"<<endl<<endl;
					cout<<"name: "<<temp->name<<endl;
					cout<<"id: "<<temp->id<<endl;
					cout<<"sex: "<<temp->sex<<endl;
					cout<<"phone: "<<temp->phone<<endl;
					cout<<"_____________________"<<endl;
					temp=temp->next;
				}
			}
		}
	}
	void file_in(){
		ifstream in("student.txt");
		string stu,name,id,sex,phone;
		stringstream ss;
		while(getline(in,stu)){
			ss.clear();
			ss<<stu;
			ss>>name>>id>>sex>>phone;
			ss.str("");
			student *temp=new student(name,id,sex,phone);
			insert(temp);
		}
		in.close();
	}
	void save(){
		ofstream out("student.txt");
		for(int i=0;i<max;i++){
			if(table[i]){
				student *temp=table[i];
				while(temp!=NULL){
					out<<temp->name<<" "<<temp->id<<" "<<temp->sex<<" "<<temp->phone<<endl;
					temp=temp->next;
				}
			}
		}
		out.close();		
	}
	~hush_table(){
		for(int i=0;i<max;i++){
			if(table[i]!=NULL){
				student *head=table[i];
				student *temp;
				while(head!=NULL){
					temp=head;
					head=head->next;
					delete temp;
				}
			}
		}
		delete []table;
	}
private:
	static const int max=99;
	static const int num=97;
	student **table;
	int person;	
};

#endif
