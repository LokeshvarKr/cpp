#include<iostream>
#include<queue>
#include <stack>
using namespace std;

void bfs(bool **edges,int v){
	bool *visited=new bool[v];
	for(int i=0;i<v;i++){
		visited[i]=false;
	}

	queue<int> q;
	
for(int j=0;j<v;j++){
  if(visited[j]==false){
	q.push(j);
	visited[j]=true;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		cout<<x<<" ";
		for(int i=0;i<v;i++){
			if(i!=x && edges[x][i]==true && visited[i]==false){
				q.push(i);
				visited[i]=true;
			}
		}
	}
  }

}

	delete [] visited;
}


void dfs(bool **edges,int v){
	bool *visited=new bool[v];
	for(int i=0;i<v;i++){
		visited[i]=false;
	}
	stack<int> s;
	for(int j=0;j<v;j++){
		if(visited[j]==false){
			s.push(j);
			visited[j]=true;
			while(!s.empty()){
				int x=s.top();
				s.pop();
				cout<<x<<" ";
				for(int i=v-1;i>=0;i--){
					if(i!=x && edges[x][i]==true && visited[i]==false){
						s.push(i);
						visited[i]=true;
					}
				}
			}
		}
	}

}
void dfsUtil(bool **edges,int v,int start,bool *visited){
	cout<<start<<" ";
	visited[start]=true;
	for(int i=0;i<v;i++){
		if(i!=start && edges[start][i]==true && visited[i]==false){
			dfsUtil(edges,v,i,visited);
		}
	}
}
void dfsRecursive(bool **edges,int v){
	bool *visited=new bool[v];
	for(int i=0;i<v;i++){
		visited[i]=false;
	}

	for(int i=0;i<v;i++){
		if(visited[i]==false){
			dfsUtil(edges,v,i,visited);
		}
	}

	delete [] visited;
}
int main(){
	int v,e;
	cout<<"size of graph v and e "<<endl;
	cin>>v>>e;
	bool **edges=new bool *[v];
	for(int i=0;i<v;i++){
		edges[i]=new bool[v];
		for(int j=0;j<v;j++){
			edges[i][j]=false;
		}
	}

	for(int i=0;i<e;i++){
		int f,s;
		cin>>f>>s;
		edges[f][s]=true;
		edges[s][f]=true;
	}
	
	cout<<"dfsRecursive : ";
	dfsRecursive(edges,v);
	cout<<endl;
	
	cout<<"dfs : ";
	dfs(edges,v);
	cout<<endl;
	
	cout<<"bfs : ";
	bfs(edges,v);
	cout<<endl;
	
	for(int i=0;i<v;i++){
		delete [] edges[i];
	}
	delete [] edges;
	
	return 0;
}