#include<iostream>
#include<climits>
using namespace std;
struct Edge
{
	int src;
	int dest;
	int weight;
};
struct Graph
{
	int V;
	int E;
	Edge *Adj;
};
void Relax(int u,int v,int w,int *d,int *p)
{
	if(d[v]>d[u]+w)
	{	
		d[v]=d[u]+w;
		p[v]=u;
	}

}
bool BellmanFord(Graph *G,int *d,int *p)
{
	int V=G->V;
	int E=G->E;

	//This will work as initialize single source
	for(int i=0;i<V;i++)
	{
		d[i]=INT_MAX;
		p[i]=-1;
	}
	d[0]=0;
	
	for(int i=0;i<V-1;i++)
	{
		for(int j=0;j<E;j++)
		Relax(G->Adj[j].src,G->Adj[j].dest,G->Adj[j].weight,d,p);

	}

	int u,v,w;
	for(int j=0;j<E;j++)
	{
			u=G->Adj[j].src;
			v=G->Adj[j].dest;
			w=G->Adj[j].weight;
		if(d[v]>d[u]+w)
			return false;
	}

	return true;
}
int main()
{
	Graph *G=new Graph;
	cout<<"Enter No. of vertices and No. of Edges"<<endl;
	cin>>G->V>>G->E;

	G->Adj=new Edge [G->E];	
	
	int a,b,w;
	for(int i=0;i<G->E;i++)
	{
		cout<<"Enter an edge and its weight"<<endl;
			cin>>a>>b>>w;
		G->Adj[i].src=a;
		G->Adj[i].dest=b;
		G->Adj[i].weight=w;
	}

	int *d=new int[G->V];
	int *p=new int [G->V];
	
	bool t=BellmanFord(G,d,p);
	if(t==false)
		cout<<"There is negative edge cycle in Graph i.e, 'No Sortest path exist'  "<<endl;

	else
	{
		cout<<"Source Vertex is 0"<<endl;
		cout<<"Edges"<<"	"<<"distance"<<endl;
		for(int i=1;i<G->V;i++)
		cout<<p[i]<<"-"<<i<<"	"<<d[i]<<endl;

	}

	


return 0;
}
