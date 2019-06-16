
#include<iostream>
#include<climits>
#include<vector>
using namespace std;


int find_min(int distance[],bool is_included[],int V){
	int min_index=-1;
	for(int i=0;i<V;i++){
		if(is_included[i]==false && (min_index==-1 || distance[min_index] > distance[i])){
			min_index=i;
		}
	}

	return min_index;
}
void dijkstra(int V,int E,int source,vector< pair<int,int> > graph[]){
	int *distance=new int [V];
	int *parent=new int[V];
	bool *is_included=new bool[V];
	for(int i=0;i<V;i++){
		distance[i]=INT_MAX;
		is_included[i]=false;
		parent[i]=-1;
	}

	distance[source]=0;

	for(int i=0;i<V;i++){
		int u=find_min(distance,is_included,V);
		is_included[u]=true;
		for(pair<int,int> v: graph[u]){
			if(is_included[v.first]==false && distance[v.first] > distance[u] + v.second){
				distance[v.first] = distance[u] + v.second;
				parent[v.first]=u;
			}
		}
	}

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