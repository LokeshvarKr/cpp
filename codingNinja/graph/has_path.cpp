#include <iostream>
#include<queue>
using namespace std;
bool bfs(int **edge,int v,int x,int y){
  
  
  	bool *visited=new bool [v];
      for(int i=0;i<v;i++)
        visited[i]=false;
  
  queue<int> q;
  	q.push(x);
  	visited[x]=true;
  
  	while(!q.empty()){
      int st=q.front();
      q.pop();
      
      for(int i=0;i<v;i++){
        if(edge[st][i]==1 && i==y)
          return true;
        if(edge[st][i]==1 && visited[i]==false){
          q.push(i);
          visited[i]=true;
        }
        
      }
     
    }
  
  return false;
    	
}

bool hasPath(int **edge,int v,int x,int y){
  	if(edge[x][y]==1)
    	return true;
  
  	for(int i=0;i<v;i++){
      if(i==x){
        return bfs(edge,v,x,y);
      }
      continue;
    }
  return false;
  	
  
}

int main() {
    int v, e;
    cin >> v >> e;
  
  	int **edge=new int*[v];
  	for(int i=0;i<v;i++){
      edge[i]=new int[v];
      for(int j=0;j<v;j++){
        edge[i][j]=0;
      }
    }
  
  
  	for(int i=0;i<e;i++){
		int f,s;
      cin>>f>>s;
      edge[f][s]=1;
      edge[s][f]=1;
    }

  int x,y;
  cin>>x>>y;
  
  	if(hasPath(edge,v,x,y))
      cout<<"true";
  	else
		cout<<"false";
  
  return 0;
}
