//Find connected component in undirected Graph
#include<iostream>
using namespace std;
struct subset
{
	int r;
	int p;
};

struct Edge
{
	int src;
	int dest;
};

struct Graph
{
	int V;
	int E;
	Edge *Adj;
};
int FindSet(int x,subset *s)
{
	if(s[x].p!=x)
		s[x].p=FindSet(s[x].p,s);
	return s[x].p;

}
void Union(int x,int y,subset *s)
{
	int a=FindSet(x,s);
	int b=FindSet(y,s);

	if(s[a].r > s[b].r)
		s[y].p=s[x].p;
	else
		s[x].p=s[y].p;
	if(s[a].r==s[b].r)
		s[y].r=s[y].r+1;

}
void connected_component(Graph *G)
{
	subset *s=new subset [G->V];

	for(int i=0;i<G->V;i++)
	{
		s[i].r=0;
		s[i].p=i;
	}
	
	Edge *edge=G->Adj;
	
	for(int i=0;i<G->E;i++)
	{
		int p=FindSet(edge[i].src,s);
		int q=FindSet(edge[i].dest,s);
	
		if(p!=q)
		Union(edge[i].src,edge[i].dest,s);
	}

	for(int i=0;i<G->V;i++)
		cout<<i<<" ";
	cout<<endl;

	for(int i=0;i<G->V;i++)
		cout<<s[i].p<<" ";
	cout<<endl;

	for(int i=0;i<G->V;i++)
		cout<<s[i].r<<" ";

	cout<<endl;
	int c=0;
	for(int i=0;i<G->V;i++)
	{
		for(int j=0;j<G->V;j++)
		{
			if(s[j].p==i)
			{
			cout<<j<<" ";
			c++;
			}
		}
		cout<<endl;
		if(c==G->V)
		break;
	}
	
}
int main()
{
	Graph *G=new Graph;
	
	cout<<"Enter No. of  vertices and Edges "<<endl;
	cin>>G->V>>G->E;
	
	G->Adj=new Edge [G->E];

	int p,q;
	cout<<"Enter Edges of Graph"<<endl;
	for(int i=0;i<G->E;i++)
	{
		cout<<"Enter an edge"<<endl;
		cin>>p>>q;
	
		G->Adj[i].src=p;
		G->Adj[i].dest=q;
	}

	connected_component(G);

return 0;

}
