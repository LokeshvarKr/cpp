#include <iostream>
using namespace std;
#include<queue>

void BFS(int **edge,int V,bool *visited){


  	queue<int>q;
  	q.push(0);
  	visited[0]=true;
  
  	while(!q.empty()){
    int st=q.front();
    q.pop();
    cout<<st<<" ";
   
    for(int i=0;i<V;i++){
      if(edge[st][i]==1 && visited[i]==false){
        q.push(i);
        visited[i]=true;
      }
    }
    
  }
  
  
}


int main() {
    int V, E;
    cin >> V >> E;

 	int **edge=new int *[V];
  	for(int i=0;i<V;i++){
      edge[i]=new int[V];
      for(int j=0;j<V;j++){
        edge[i][j]=0;
      }
    }
  
  
  for(int i=0;i<E;i++){
    int f,s;
    cin>>f>>s;
    edge[f][s]=1;
    edge[s][f]=1;
  }
  
  bool *visited=new bool[V];
  
  for(int i=0;i<V;i++){
    visited[i]=false;
  }
  
  BFS(edge,V,visited);
  
  
  delete [] visited;
  for(int i=0;i<V;i++)
  delete []edge[i];
  delete []edge;
  return 0;
}
