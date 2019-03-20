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
