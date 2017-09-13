#include <iostream>
using namespace std;
int main(){
	cout<<"magic-square-2"<<endl;
	int n=0;
	int sum=0;
	cout<<"input size"<<endl;
	cin>>n;
	int max=n*n;
	int **magic=new int*[n];
	for(int i=0; i<n ;i++){
		magic[i]= new int[n]();
	}
	int pos=(n-1)/2;
	for(int min=1 ,i=0; min<=max ;min++){
		magic[i%n][pos%n]=min;
		i+=n-1;
		pos+=1;
		if(magic[i%n][pos%n]!=0){
			i+=2;
			pos-=1;
		}
	}
	for(int i=0; i<n ;i++){
		for(int k=0 ; k<n ; k++){
			sum+=magic[i][k];
			cout<<magic[i][k]<<" ";
		}
		cout<<endl;
	}
	cout<<"sum is "<<sum/n<<endl;
}