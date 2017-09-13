#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main(){
	int n,m;
	cin>>n;
	int *train = new int[n * sizeof(int)];
	for(int i=0;i<n;i++){
		cin>>m;
		train[i]=m;
	}
	vector< stack<int> > v;
	int count=1,k=0;
	bool suc=false;
	while(count<=n){
		if(k<n && train[k] == count){
			cout<<train[k]<<' ';
			count++;
			k++;
		}
		else{
			if(k<n){
				for(auto &i:v){
					if( i.empty()||train[k]<i.top()){
						i.push(train[k]);
						suc=true;
						k++;
						break;
					}
				}

				if(!suc){
					stack<int> st;
					st.push(train[k]);
					v.push_back(st);
					k++;
				}
				suc=false;
			}
			for (int i = 0; i < v.size(); ++i){
				while(!v[i].empty() && v[i].top()==count){
					cout<<v[i].top()<<' ';
					v[i].pop();
					count++;
				}
			}
		}
	}
	delete []train;
	return 0;
}