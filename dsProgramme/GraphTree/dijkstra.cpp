#include<iostream>
#include<stdlib.h>
#include<climits>
using namespace std;
int findmin(int *distance, bool *visited,int V){
int min=-1;
for(int i=0;i<V;i++){
	if(!visited[i] && (min==-1 || distance[i]< distance[min])){
		min=i;
		}
	}
return min;
}
void Dijkstra(int **edges,int V)
{
	int *distance=new int[V];
	bool *visited=new bool[V];
	for(int i=0;i<V;i++){
		distance[i]=INT_MAX;
		visited[i]=false;
	}

	distance[0]=0;

	for(int i=0;i<V;i++){
	int min=findmin(distance,visited,V);
		visited[min]=true;
		for(int j=0;j<V;j++){
		if(edges[min][j]!=0 &&	!visited[j]){
			if(distance[j]>distance[min]+edges[min][j]){
				distance[j]=distance[min]+edges[min][j];
				}
			}
		}
	}	
for(int i=0;i<V;i++){
	cout<<i<<" "<<distance[i] <<endl;
	}
	
	delete [] visited;
	delete [] distance;

}
int main()
{
int V,E;
cout<<"Enter no. of vertices and edges "<<endl;
cin>>V>>E;
int **edges=new int *[V];
for(int i=0;i<V;i++){
	edges[i]=new int[V];
	for(int j=0;j<V;j++){
	edges[i][j]=0;
	}
}
for(int i=0;i<E;i++){
	int p,q,w;
	cout<<"Enter an edge an its weight"<<endl;
	cin>>p>>q>>w;
	edges[p][q]=w;
}
cout<<endl;
Dijkstra(edges,V);
for(int i=0;i<V;i++){
	delete [] edges[i];
}

	delete [] edges;

return 0;
}
