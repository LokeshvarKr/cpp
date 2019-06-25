#include <iostream>
using namespace std;
#include<algorithm>
class edge{
  public:
  	int v1;
  	int v2;
  	int w;
  	edge(){
  		v1=0;
  		v2=0;
  		w=0;
  	}
};
int Find(int x,int *parent){
	if(parent[x]!=x){
		return Find(parent[x],parent);
	}
	return parent[x];
}
void Union(int x,int y,int *parent){
		parent[x]=y;
}
bool compareWeight(edge e1,edge e2){
  return e1.w < e2.w;
}
void kruskal(edge *edgeList,int v,int e){
  edge *mst=new edge[v-1]; 
  int *parent=new int [v];
  for(int i=0;i<v;i++){
    parent[i]=i;
  }
  int j=0;
  sort(edgeList,edgeList+e,compareWeight);
  for(int i=0;i<e;i++){
  	int x=Find(edgeList[i].v1,parent);
  	int y=Find(edgeList[i].v2,parent);
    if(x!=y){
      Union(x,y,parent);
      mst[j]=edgeList[i];
      j++;
    }
    if(j==v)
      break;
  }
  
  for(int i=0;i<v-1;i++){
    if(mst[i].v1 < mst[i].v2){
      cout<<mst[i].v1<<" "<<mst[i].v2<<" "<<mst[i].w<<endl;
    }
    else{
      cout<<mst[i].v2<<" "<<mst[i].v1<<" "<<mst[i].w<<endl;
    }
  }
  
  delete [] mst;
  delete [] parent;
  
}
int main(){
  int v,e;
  cin >> v >> e;

  edge *edgeList=new edge [e];
  for(int i=0;i<e;i++){
    int f,s,w;
    cin>>f>>s>>w;
    edgeList[i].v1=f;
    edgeList[i].v2=s;
    edgeList[i].w=w;
    
  }
  
	kruskal(edgeList,v,e);
  
  delete [] edgeList;
  return 0;

}

