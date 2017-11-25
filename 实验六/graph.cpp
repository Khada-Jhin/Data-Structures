#include <iostream>
#include <queue>
#include <windows.h>
using namespace std;

bool s[100];   
int path[100]; 
int d[100];  
int yes=0;

class GraphArr 
{
public:
    GraphArr() {
    	for (int i = 0; i < 100; i++) {
    	    for (int j = 0; j < 100; j++)
    	        arcs[i][j] = 0;                     
    	}
    	for (int i = 0; i < 100; i++) {
    	    for (int j = 0; j < 100; j++)
    	        weight[i][j] = 0;                     
    	}
    	for (int i = 0; i < 100; i++){
    	    is_trav[i] = 0;
    	}
	}
    void CreateGraph() {
    	cout << "Please input the number of vertexes: " << endl;
    	cin >> vex_num;
    	char s;
    	cout<<"Please input the content of each vertexes: "<<endl;
		for (int i=0;i<vex_num;i++) {
			cin>>s;
			vex[i]=s;
		} 
    	cout << "Please input the size of adjacent matrix: " << endl;
    	cin >> arc;
    	cout << "Please input the adjacent matrix: " << endl;
    	for (int i = 0; i < arc; i++){
    	    for (int j = 0; j < arc; j++){
    	        cin >> arcs[i][j];
    	    }
    	}
    	for (int i = 0; i < arc; i++){
    	    for (int j = 0; j < arc; j++){
		        if (arcs[i][j]==1) {
		        	cout<<"Please input the weight of side"<<i+1<<"->"<<j+1<<": "<<endl;
					int w=0;
					cin>>w;
					weight[i][j]=w; 
				}
				else {
					weight[i][j]=10000;
				}
    	    }
    	}
	}                        
private:
    int vex_num;
    char vex[100];
    int arc=0; 
    int arcs[100][100];
    int weight [100][100];
    bool is_trav[100];                        
    void BFSFunction(int);                      
    void DFSFunction(int);                      
};

struct edge{//边的结构
	int dest;
	int weight;
	edge* next;
	edge(){
		dest=-1;
		weight=0;
		next=NULL;
	}
	edge(int v,int w){
		dest=v;
		weight=w;
		next=NULL;
	}
};
struct vertex{//节点的结构
	int ver;
	string name;
	edge* head;
	vertex(){
		ver=-1;
		head=NULL;
	}
};
class list_graph{
	private:
		vertex* node;
		int size;
	public:
		list_graph(int n){
			size=n;
			node=new vertex[size];
		}
		~list_graph(){
			delete []node;
		}
		bool insert_vertex(int n, string value){//点插入
			if(n>=size){
				cout<<"the index is wrong"<<endl;
				return false;
			}
			if(node[n].ver==-1){
				node[n].ver=n;
				node[n].name=value;
				return true;
			}
			else{
				return false;
			}
		}
		bool insert_edge(int v1, int v2,int w){//边插入
			if(node[v1].ver==-1){
				cout<<"vertex "<<v1<<" is not exsisted."<<endl;
				return false;
			}
			if(node[v2].ver==-1){
				cout<<"vertex "<<v2<<" is not exsisted."<<endl;
				return false;
			}
			edge* temp=node[v1].head;
			edge* temp1=node[v2].head;
			if(temp==NULL){
				temp= new edge(v2,w);
				node[v1].head=temp;
			}
			else{
				while(temp->next!=NULL){
					if(temp->dest==v2){
						cout<<"this edge has been exsisted"<<endl;
						return false;
					}
					temp=temp->next;
				}
				temp->next=new edge(v2,w);				
			}
			if(temp1==NULL){
				temp1= new edge(v1,w);
				node[v2].head=temp1;
			}						
			else{
				while(temp1->next!=NULL){
					if(temp1->dest==v1){
						cout<<"this edge has been exsisted"<<endl;
						return false;
					}
					temp1=temp1->next;
				}		
				temp1->next=new edge(v1,w);				
			}
			return true;
		}
		void dfs(int v,bool visit[]){
			cout<<v+1<<"("<<node[v].name<<")  ->";
			visit[v]=true;
			edge* temp=node[v].head;
			while(temp!=NULL){
				if(visit[temp->dest]==false){
					dfs(temp->dest,visit);
				}
				temp=temp->next;
			}
		}
		void DFS(int v){
			cout<<"DFS:     "<<endl;
			bool* visit=new bool[size];
			for(int i=0;i<size;i++){
				visit[i]=false;
			}
			dfs(v,visit);
			cout<<endl;
			delete []visit;
		}
		void BFS(int v){
			cout<<"BFS:     "<<endl;
			bool* visit=new bool[size];
            for(int i=0;i<size;i++){
				visit[i]=false;
			}
			cout<<v+1<<"("<<node[v].name<<") ->";
			visit[v]=true;	
			queue<vertex> que;
			que.push(node[v]);
			while(!que.empty()){
				edge* temp=que.front().head;
				que.pop();
				while(temp!=NULL){
                    if(visit[temp->dest]==false){
						cout<<temp->dest+1<<"("<<node[temp->dest].name<<") ->";
			        	visit[temp->dest]=true;
			        	que.push(node[temp->dest]);                    	
                    }
                    temp=temp->next;					
				}
			}
			cout<<endl;		
			delete []visit;			
		}
		void Dij(int n){
			cout<<"Dijstra:     "<<endl;
			bool* visit=new bool[size];
			for(int i=0;i<size;i++){
				visit[i]=false;
			}
			visit[n-1]=true;
			int min=0;
			int t=1;
			int *len=new int[size];
			for(int i=0;i<size;i++){
				len[i]=-1;
			}
			dij(n-1,visit,min,len,t);
			delete []visit;
			delete []len;
		}
		void dij(int n,bool visit[],int min,int len[],int t){
			if(t==size){
				return;
			}
			edge* temp=node[n].head;
			while(temp != NULL){
				if(len[temp->dest]== -1 && visit[temp->dest]!=true){
					len[temp->dest]=temp->weight;
					//cout<<temp->dest<<" "<<len[temp->dest]<<endl;
				}
				else{
					if(temp->weight < len[temp->dest] && visit[temp->dest]!=true){
						len[temp->dest]=temp->weight;
						//cout<<temp->dest<<" "<<len[temp->dest]<<endl;
					}
				}
				temp=temp->next;
			}
			int m=-1;
			int min_x=0;
			for(int i=0;i<size;i++){
				if(len[i] != -1){
					if(m == -1){
						m=len[i];
						min_x=i;
					}
					else if(len[i]<m){
						m=len[i];
						min_x=i;
					}
				}
				//cout<<len[i]<<endl;
			}
			edge* temp1=node[min_x].head;
			int d;
			while(temp1!=NULL){
				if(temp1->weight==m){
					d=temp1->dest;
				}
				temp1=temp1->next;
			}
			cout<<t<<":  "<<d+1<<"("<<node[d].name<<")"<<"->"<<min_x+1<<"("<<node[min_x].name<<")"<<"   weight:  "<<m<<endl;
			t++;
			min+=m;
			visit[min_x]=true;
			len[min_x]=-1;
			dij(min_x,visit,min,len,t);
		}
};
int main(){
	int n;
	cout<<"Construct graph:   "<<endl<<endl;
	cout<<"Please input the number of vertex:  "<<endl;
	cin>>n;
	list_graph g(n);
	string name;
	int index;
	cout<<"Please input the name of vertex(order[1~n]):"<<endl;
	for(int i=0;i<n;i++){
		cin>>name;
		g.insert_vertex(i,name);
	}
	int v1,v2,w;
	cout<<"PLease input the edge(\"-1 -1 -1\" to end):  "<<endl;
	while(1){
		cin>>v1>>v2>>w;
		if(v1==-1){
			break;
		}
		else{
			g.insert_edge(v1-1,v2-1,w);
		}
	}
	system("pause");
	while(1){
		system("cls");
		cout<<"Graph:   1. Traverse     2.  Dijstra   0.  Quit"<<endl;
		cout<<"demand$:~~~    ";
		cin>>n;
		if(n==1){
			cout<<"Please input begin vertex:  "<<endl;
			cin>>n;
			g.DFS(n-1);
			g.BFS(n-1);			
		}
		else if(n==2){
			cout<<"Please input begin vertex:  "<<endl;
			cin>>n;
			g.Dij(n);
		}
		else if(n==0){
			break;
		}
		else{
			cout<<"Wrong demand!"<<endl;
		}
		system("pause");		
	}
}