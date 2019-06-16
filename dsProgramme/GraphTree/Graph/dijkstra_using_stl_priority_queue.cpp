
#include<iostream>
#include<climits>
#include<vector>
#include<queue>
#include<utility>
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
	priority_queue< pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
	//store distance and vertex from source
	pq.push({distance[source],source});

	for(int i=0;i<V;i++){
		//first element is min element
		pair<int,int> p=pq.top();
		pq.pop();
		int u=p.second;
		done[u]=true;
		for(pair<int,int> v: graph[u]){

			if(done[v.first]==false && distance[v.first] > distance[u] + v.second){
				distance[v.first] = distance[u] + v.second;
				parent[v.first]=u;
				pq.push({distance[v.first],v.first});	
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