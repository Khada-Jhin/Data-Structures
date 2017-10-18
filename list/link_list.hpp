#ifndef LINK_LIST
#define LINK_LIST

#include <iostream>
using namespace std;

struct ele
{
	char data;
	ele* next;
	ele(char a)
	{
		data=a;
		next=NULL;
	}
};
class link_list
{
	private:
		ele* head;
	public:
		link_list()
		{
			head=NULL;
		}
		~link_list()
		{
			while(head!=NULL){
				ele* temp=head;
				head=head->next;
				delete temp;
				temp=NULL;
			}
		}
		bool insert(char data,int i)
		{
			i=i-1;
			ele* temp=head;
			ele* temp1=temp;
			if(i==0)
			{
				ele* n=new ele(data);
				head=n;
				n->next=temp;
				return 1;	
			}
			int k=0;
			while(k < i && temp != NULL)
			{
				temp1=temp;
				temp=temp->next;
				k++;
			}
			if(k<i){
				cout<<"this is a wrong position!"<<endl;
				return 0;
			}
			else
			{
				ele* n=new ele(data);
				temp1->next=n;
				n->next=temp;
				return 1;
			}
		}
		bool remove(int i)
		{
			i=i-1;
			if(head==NULL){
				cout<<"It's empty!"<<endl;
				return 0;
			}
			ele* temp=head;
			ele* temp1=temp;
			int k=0;
			while(k < i && temp != NULL)
			{
				temp1=temp;
				temp=temp->next;
				k++;
				
			}
			if(k<i)
			{
				cout<<"this is a wrong position!"<<endl;
				return 0;
			}
			if(temp==temp1)
			{
				head=head->next;
				delete temp;
				temp=NULL;
				return 1;
			}
			else
			{
				temp1->next=temp->next;
				delete temp;
				temp=NULL;
				return 1;
			}
		}
		void show(){
			if(head==NULL){
				cout<<"It's empty!"<<endl;
			}
			else{
				ele* temp=head;
				while(temp!=NULL){
					cout<<temp->data<<" ";
					temp=temp->next;
				}
				cout<<endl;
			}
			
		}
};
#endif
