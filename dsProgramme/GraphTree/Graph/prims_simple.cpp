#include<iostream>
using namespace std;
#include<climits>


int find_min(int *key,int V,bool *visited){
	int min_index=-1;
	for(int i=0;i<V;i++){
		if(visited[i]==false && (min_index==-1 || key[min_index] > key[i])){
			min_index=i;
		}
	}
	return min_index;
}
void prims_mst(int source,int V, int **graph){

	//initialize all vertex
	int *parent=new int[V];
	int *key=new int[V];
	bool *visited=new bool[V];
	for(int i=0;i<V;i++){
		parent[i]=-1;
		key[i]=INT_MAX;
		visited[i]=false;
	}
	key[source]=0;

	for(int i=0;i<V;i++){
		int u=find_min(key,V,visited);
		visited[u]=true;
		for(int v=0;v<V;v++){
			if(visited[v]==false && graph[u][v]){
				if(graph[u][v] < key[v]){
					key[v]=graph[u][v];
					parent[v]=u;
				}
			}
		}
	}

	cout<<"parent and vertex"<<endl;
	for(int i=0;i<V;i++){
		cout<<parent[i]<<" "<<i<<endl;
	}

	delete [] visited;
	delete [] key;
	delete [] parent;
}

int main(){
	int V,E;
	cin>>V>>E;
	int **graph=new int*[V];
	for(int i=0;i<V;i++){
		graph[i]=new int [V];
		for(int j=0;j<V;j++){
			graph[i][j]=0;
		}
	}
	for(int i=0;i<E;i++){
		int a,b,w;
		cin>>a>>b>>w;
		graph[a][b]=w;
		graph[b][a]=w;
	}
	int source=0;
	prims_mst(source,V,graph);

	for(int i=0;i<V;i++){
		delete [] graph[i];
	}
	delete [] graph;
	return 0;
}