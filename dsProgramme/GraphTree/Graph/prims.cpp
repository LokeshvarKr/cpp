#include<iostream>
#include<climits>
using namespace std;
void prims_mst(int source,int V, int **graph){

	//initialize all vertex
	int *parent=new int[V];
	int *key=new int[V];
	bool *inMST=new bool[V];

	for(int i=0;i<V;i++){
		parent[i]=-1;
		key[i]=INT_MAX;
		inMST[i]=false;
	}

	//implement

	cout<<"parent and vertex"<<endl;
	for(int i=0;i<V;i++){
		cout<<parent[i]<<" "<<i<<endl;
	}
	
	cout<<endl;

	delete [] inMST;
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