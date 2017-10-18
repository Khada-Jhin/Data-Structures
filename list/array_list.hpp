#ifndef ARRAY_LIST
#define ARRSY_LIST

#include <iostream>
using namespace std;
#define max 100

class array_list
{
	private:
		char *str;
		int size;
	public:
		array_list()
		{
			str=new char[max];
			size=0;
		}
		~array_list(){
			delete []str;
		}
		bool insert(char ele,int i)
		{
			i=i-1;
			if(size==max)
			{
				cout<<"It's full"<<endl;
				return 0;	
			}			
			if(i<0||i>size)
			{
				cout<<"this is a wrong position!"<<endl;
				return 0;
			}
			if(size==0)
			{
				str[0]=ele;
			}
			else
			{
				for(int k=size-1; k>=i; k--)
				{
					str[k+1]=str[k];	
				}
				str[i]=ele;
			}
			size++;
			return 1;
		}
		bool remove (int i)
		{
			i=i-1;
			if(size == 0)
			{
				cout<<"It's empty!"<<endl;
				return 0;
			}
			if(i<0 || i>=max)
			{
				cout<<"this is a wrong position!"<<endl;
				return 0;
			}
			if(i==max-1)
			{
				size--;
				return 1;				
			}
			for(int k=i; k<size; k++)
			{
				str[k]=str[k+1];
			}
			size--;
			return 1;
		}
		void show()
		{
			if(size==0){
				cout<<"It's empty!"<<endl;
			}
			else{
				for(int i=0;i<size;i++){
					cout<<str[i]<<" ";
				}
				cout<<endl;
			}
		}
};
#endif
