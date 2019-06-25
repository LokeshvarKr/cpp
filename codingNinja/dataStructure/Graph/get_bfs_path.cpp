/*

Code : Get Path - BFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
V is the number of vertices present in graph G and vertices are numbered from 0 to V-1.
E is the number of edges present in graph G.
Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
Note : Save the input graph in Adjacency Matrix.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Two integers a and b, denoting that there exists an edge between vertex a and vertex b (separated by space)
Line (E+2) : Two integers v1 and v2 (separated by space)
Output Format :
Path from v1 to v2 in reverse order (separated by space)
Constraints :
2 <= V <= 1000
1 <= E <= 1000
0 <= v1, v2 <= V-1
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3

*/

#include <iostream>
using namespace std;
#include<unordered_map>
#include<queue>
#include<vector>

vector<int> *get_bfs_path(bool **edge,int v,int x,int y){
  if(x==y){
    vector<int> *vec=new vector<int>();
   	vec->push_back(x);
    return vec;
  }
  
  bool *visited=new bool[v];
  for(int i=0;i<v;i++){
	visited[i]==false;	
  } 
  
  queue<int> q;
  unordered_map<int,int> parent; // to keep track of elements, entered by which parent
  
   q.push(x);
   visited[x]==true;
  
  bool done=false;
  
  while(!q.empty() && !done){
    int s=q.front();
    q.pop();
    
   	for(int i=0;i<v;i++){
      if(edge[s][i] && !visited[i]){
        q.push(i);
        visited[i]=true;
        parent[i]=s;
      	if(i==y){
        	done=true;
        	break;
      	}
      }  
    }
  }

  if(!done)
    return NULL;
  else{
  	vector<int> *vec=new vector<int> ();
  	vec->push_back(y);
   	int current=y;
  	while(current!=x){
    	current=parent[current];
    	vec->push_back(current);
  	}
  	return vec;
  }
  
}

int main()
{
  int v,e;
  cin >> v >> e;

 bool **edge=new bool*[v];
  
  for(int i=0;i<v;i++){ 
    edge[i]=new bool[v];
    for(int j=0;j<v;j++)
      	edge[i][j]=false;
  }
  
  for(int i=0;i<e;i++){
    int f,s;
    cin>>f>>s;
    edge[f][s]=true;
    edge[s][f]=true;
  }
  
  int x,y;
  cin>>x>>y;
  
  vector<int> *vec=get_bfs_path(edge,v,x,y);
 
  if(vec){
  	for(int i=0;i<vec->size();i++){
		cout<<vec->at(i)<<" ";	
  	}
  }
  

  delete vec;
  
  for(int i=0;i<v;i++)
    delete [] edge[i];
  delete [] edge;
  
  return 0;
}

