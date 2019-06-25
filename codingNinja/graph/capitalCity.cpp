/*
CAPCITY

CAPCITY - Capital City
There are N cities in Flatland connected with M unidirectional roads. The cities are numbered from 1 to N. The Flat Circle of Flatland (FCF) wants to set up a new capital city for his kingdom. For security reasons, the capital must be reachable from all other cities of Flatland. FCF needs the list of all candidate cities. You are the chief programmer at FACM (Flat Association for Computing Machinery) responsible for providing the list to FCF as soon as possible.
Input
The first line of the input file contains two integers։ 1≤N≤100,000 and 1≤M≤200,000. Each of the following M lines contains two integers 1≤A, B≤N denoting a road from A to B.
Output
The output file contains an integer denoting the number of candidate cities followed by the list of candidate cities in increasing order.
Sample Input:
4 4
1 2
3 2
4 3
2 1
Sample Output:
2
1 2

*/
#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<int> *graph,int start,int v){
   bool *visited=new bool [v];
  	for(int i=0;i<v;i++){
    	visited[i]=false;
    }
  stack<int> s;
  s.push(start);
  visited[start]=true;
  while(!s.empty()){
    int current=s.top();
    s.pop();
    for(int i=0;i<graph[current].size();i++){
      int adj=graph[current][i];
      if(visited[adj]==false){
        s.push(adj);
        visited[adj]=true;
      }
    }
  }
  
  bool result=true;
  for(int i=0;i<v;i++){
    if(visited[i]==false){
      result=false;
      break;
    }
  }
  delete [] visited;
  return result;
}
bool dfs(vector<int> *graph,int start,bool *mark){
  stack<int> s;
  s.push(start);
  mark[start]=true;
  while(!s.empty()){
    int current=s.top();
    s.pop();
    for(int i=0;i<graph[current].size();i++){
      int adj=graph[current][i];
      if(mark[adj]==false){
        s.push(adj);
        mark[adj]=true;
      }
    }
  }
  
}
void capitalCity(vector<int> *graph,vector<int> *tgraph,int v){
   bool *mark=new bool [v];
  for(int i=0;i<v;i++){
    mark[i]=false;
  }
  
  for(int i=0;i<v;i++){
    if(mark[i]==false){
      bool result=dfs(tgraph,i,v);
      if(result){
			dfs(graph,i,mark);
      }
    }
  }
  
  int count=0;
  for(int i=0;i<v;i++){
    if(mark[i]==true){
      count++;
    }
  }
  cout<<count<<endl;
  for(int i=0;i<v;i++){
    if(mark[i]==true){
      cout<<i+1<<" ";
    }
  }
  
  delete [] mark;
}


int main()
{
	int n,m;
  cin>>n>>m;
  vector<int> *graph=new vector<int>[n] ();
  vector<int> *tgraph=new vector<int>[n] ();
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    graph[a-1].push_back(b-1);
    tgraph[b-1].push_back(a-1);
  }
  
  capitalCity(graph,tgraph,n);
  delete [] graph;
  delete [] tgraph;
	return 0;
}

