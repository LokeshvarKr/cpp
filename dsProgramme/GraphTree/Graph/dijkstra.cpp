
#include<iostream>
#include<climits>
#include<set>
using namespace std;

void dijkstra(int V,int E,int source,vector< pair<int,int> > graph[]){
	

	int distance[V];
	int parent[V];
	int done[V];
	for(int i=0;i<V;i++){
		distance[i]=INT_MAX;
		done[i]=false;
		parent[i]=-1;
	}

	distance[source]=0;
	
	//implementation

	cout<<"distances from source vertex "<<source<<" :"<<endl;
	for(int i=0;i<V;i++){
		cout<<i<<" "<<distance[i]<<endl;
	}

	cout<<endl;

}

int main(){
	int V,E;
	cin>>V>>E;
	vector< pair<int,int> > *graph=new vector< pair<int,int> > [V];
	for(int i=0;i<E;i++){
		int u,v,w;
		cin>>u>>v>>w;
		graph[u].push_back({v,w});
	}
	int source=0;
	dijkstra(V,E,source,graph);

	delete [] graph;
	return 0;
}