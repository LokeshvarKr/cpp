#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void printBFS(int **edge,int n,bool *visited,int st){
	queue<int> q;
	q.push(st);
	visited[st]=true;

	while(!q.empty()){
		
		int current=q.front();
		cout<<current<<" ";
		q.pop();

		for(int i=0;i<n;i++){
			if(edge[current][i]==1 && !visited[i]){
				q.push(i);
				visited[i]=true;
			}
		}
	}
	
}
void printDFS(int **edge,int n,bool *visited,int st){

	stack<int> s;
	s.push(st);
	visited[st]=true;

	while(!s.empty()){
		int current=s.top();
		cout<<current<<" ";
		s.pop();
		
		for(int i=0;i<n;i++){
			if(edge[current][i]==1 && !visited[i]){
				s.push(i);
				visited[i]=true;
			}
		}
	}

}

void BFS(int **edge,int n){
	
	bool *visited=new bool [n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	
	for(int i=0;i<n;i++){
		if(!visited[i]){
			visited[i]=true;
			printBFS(edge,n,visited,i);
		}
	}


}

void DFS(int **edge,int n){

	bool *visited=new bool [n];
	for(int i=0;i<n;i++){
		visited[i]=false;
	}
	
	for(int i=0;i<n;i++){
		if(!visited[i]){
			printDFS(edge,n,visited,i);
		}
	}

}

int main(){

int n,e;
cout<<"Enter vertices and edges"<<endl;
cin>>n>>e;

int **edge=new int*[n];
for(int i=0;i<n;i++){
	edge[i]=new int[n];
	for(int j=0;j<n;j++){
		edge[i][j]=0;
	}
}

cout<<"Enter edges"<<endl;
for(int i=0;i<e;i++){
	int f,s;
	cin>>f>>s;
	edge[f][s]=1;
	edge[s][f]=1;
}

cout<<"BFS ----"<<endl;
BFS(edge,n);
cout<<endl;

cout<<"DFS ----"<<endl;
DFS(edge,n);
cout<<endl;

for(int i=0;i<n;i++){
	delete [] edge[i];
}
delete [] edge;
return 0;
}