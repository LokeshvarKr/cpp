#include<iostream>
#include<stdlib.h>
using namespace std;
struct Edge
{
	int s;	//source
	int d;	//dest
	int w;	//weight
};
struct Graph
{
	int V;
	int E;
	struct Edge *edge;
};
struct subset
{
	int r;	//rank
	int p;	//parent
};
int FindSet(struct subset *s,int x)
{
	if(s[x].p!=x)
		s[x].p=FindSet(s,s[x].p);
	return s[x].p;
}
void Union(struct subset *s,int x,int y)
{
	int p=FindSet(s,x);
	int q=FindSet(s,y);
	if(s[p].r>s[q].r)
		s[q].p=p;
	else
		s[p].p=q;
	if(s[p].r==s[q].r)
		s[q].r=s[q].r +1;

}
void Sort(struct Graph *G)
{
	struct Edge *edge=G->edge;
	struct Edge temp;
	int i,j;
	int flag=1;
	for(i=0;i<G->E-1;i++)
	{
		for(j=0;j<G->E-i-1;j++)
		{
			if(edge[j].w>edge[j+1].w)
				{
					temp=edge[j];
					edge[j]=edge[j+1];
					edge[j+1]=temp;
					
					flag=0;					
				}
		}
		
		if(flag==0)
		break;
	}

}          
void KRUSKAL(struct Graph *G)
{
	int i;
	int V=G->V;
	struct Edge *mst=new Edge[V-1];
	struct subset *s=new subset[V];
	Sort(G);
	
	for(i=0;i<V;i++)	//makeset()
	{
		s[i].r=0;
		s[i].p=i;
	}

	int e=0;
	i=0;
	struct Edge ed;
	while(e<V-1)
	{
		ed=G->edge[i++]; 
		if(FindSet(s,ed.s)!=FindSet(s,ed.d))
		{
			mst[e]=ed;
			Union( s, ed.s , ed.d);
		}
	}

		for(i=0;i<V-1;i++)
		{
		cout<<mst[i].s<<" "<<mst[i].d<<" "<<mst[i].w<<endl;
		}
	
}
int main()
{
	int i;	
	struct Graph *G=new Graph;
	cout<<"Enter No. Vertex"<<endl;
	cin>>G->V;
	cout<<"Enter No. of Edges"<<endl;
	cin>>G->E;
	int x,y,w;
	G->edge=new Edge[G->E];
	for(i=0;i< G->E;i++)
	{
	cout<<"Enter an edge with its weight(order as src,dest,weight)"<<endl;
	cin>>x>>y>>w;
		G->edge[i].s=x;
		G->edge[i].d=y;
		G->edge[i].w=w;
	}
	KRUSKAL(G);
	
	return 0;
}
