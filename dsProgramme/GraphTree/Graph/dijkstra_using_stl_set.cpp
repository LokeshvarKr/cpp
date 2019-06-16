
#include<iostream>
#include<climits>
#include<vector>
#include<set>
using namespace std;

void dijkstra(int V,int E,int source,vector< pair<int,int> > graph[]){
	

	int distance[V];
	for(int i=0;i<V;i++){
		distance[i]=INT_MAX;
	}

	distance[source]=0;

	//store distance and vertex from source
	set<pair<int,int> > distance_set;
	distance_set.insert({distance[source],source});

	while(!distance_set.empty()){
		//first element is min element
		pair<int,int> node= *(distance_set.begin());

		int u=node.second;
		//delete this ele from the distance set
		distance_set.erase(distance_set.begin());

		for(pair<int,int> v: graph[u]){

			if(distance[v.first] > distance[u] + v.second){

				if(distance[v.first]!=INT_MAX){
					//delete is vertex from set and after updation we will insert this again
					distance_set.erase(distance_set.find({distance[v.first],v.first}));
				}
				
				distance[v.first] = distance[u] + v.second;
				distance_set.insert({distance[v.first],v.first});
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