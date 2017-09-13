#include <iostream>
using namespace std;
int main(){
	cout<<"magic-square-1"<<endl;
	int n=0;
	cout<<"input size"<<endl;
	cin>>n;
	int **magic=new int*[n];
	for( int i=0 ; i<n ; i++ ){
		magic[i]=new int[n];			
	}
	int sum=0, sum1=0,number=0;
	cout<<"input number"<<endl;
	for(int i=0; i<n; i++){
		sum1=0;
		
		for(int k=0; k<n; k++){
			cin>>number;
			magic[i][k]=number;
			if(i==0){
				sum+=number;
			}
			sum1+=number;
		}
		if(sum!=sum1){
			//cout<<sum<<" "<<sum1<<endl;
			cout<<"No!"<<endl;
			return 0;
		}
	}
	for(int i=0; i<n; i++){
		sum1=0;
		for(int k=0; k<n; k++){
			sum1+=magic[k][i];
		}
		if(sum!=sum1){
			cout<<"No!"<<endl;
			return 0;
		}
	}
	sum1=0;
	for(int i=0; i<n; i++){
		sum1+=magic[i][i];
	}
	if(sum!=sum1){
			cout<<"No!"<<endl;
			return 0;
	}
	sum1=0;
	for(int i=0; i<n; i++){
		sum1+=magic[n-1-i][i];
	}
	if(sum!=sum1){
			cout<<"No!"<<endl;
			return 0;
	}
	cout<<"yes! sum is "<<sum<<endl;
}