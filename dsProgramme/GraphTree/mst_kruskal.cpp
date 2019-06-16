#include<iostream>
#include<vector>
#include<stdio.h>
#include<algorithm>
using namespace std;
class Edge{
public:
	int s,d,w;
};

class Subset{
public:
	int parent;
	int rank;
};

bool compare(Edge e1,Edge e2){
	return e1.w < e2.w;
}
int find_set(int x,Subset subset[]){
	if(subset[x].parent!=x){
		subset[x].parent=find_set(subset[x].parent,subset);
	}
	return subset[x].parent;
}
void Union(int u,int v,Subset subset[]){
	if(u!=v){
		if(subset[u].rank > subset[v].rank){
			subset[v].parent=u;
		}
		else{
			subset[u].parent=v;
			if(subset[u].rank==subset[v].rank){
				subset[v].rank+=1;
			}
		}

	}
}

void make_set(int V,Subset subset[]){
	for(int i=0;i<V;i++){
		subset[i].parent=i;
		subset[i].rank=0;
	}
}
void mst_kruskal(int V,int E,Edge edges[]){
	
	Edge *mst=new Edge[V-1];
	
	sort(edges,edges+E,compare);
	
	Subset *subset=new Subset[V];
	make_set(V,subset);	

	int i=0,k=0;
	while(k<V-1){
		Edge e=edges[i];
		i++;
		int p1=find_set(e.s,subset);
		int p2=find_set(e.d,subset);
		if(p1!=p2){
			mst[k]=e;
			k++;
			Union(p1,p2,subset);
		}
	}

	for(int i=0;i<V-1;i++){
		printf("%d %d %d\n",mst[i].s,mst[i].d,mst[i].w);
	}

	delete [] subset;
	delete [] mst;
}

int main(){
	int V,E;
	cin>>V>>E;
	Edge edges[E];
	for(int i=0;i<E;i++){
		scanf("%d %d %d ", &edges[i].s , &edges[i].d , &edges[i].w);
	}

	mst_kruskal(V,E,edges);


	return 0;
}

