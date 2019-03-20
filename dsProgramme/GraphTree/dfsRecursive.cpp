#include<iostream>
#include<stdio.h>
using namespace std;

struct Edge
{	
	int ver;
	Edge *next;
};

struct Graph
{
	int V;
	int E;
	int *time;
	int *d;
	int *f;
	int *p;
	char *color;
	Edge **Adj;

};
void dfs_visit(Graph *G,int u,int *p,int *d,int *f,char *color,int *t)
{	
	color[u]='G';
	(*t)=(*t)+1;
	d[u]=(*t);

	cout<<u<<" ";		

	Edge *temp=G->Adj[u];
	
	while(temp!=NULL)
	{
		int v=temp->ver;
		if(color[v]=='W')
		{
			p[v]=u;
			dfs_visit(G,v,p,d,f,color,t);
		}
		temp=temp->next;
	}
	(*t)=(*t)+1;
	f[u]=(*t);
	color[u]='B';
}
void DFS(Graph *G)
{
	int *d=G->d;
	int *p=G->p;
	int *f=G->f;
	char *color=G->color;
	int *t=G->time;

	for(int i=0;i<G->V;i++)
	{
		d[i]=0;
		f[i]=0;
		p[i]=-1;
		color[i]='W';
	}
	
	(*t)=0;	

	for(int i=0;i<G->V;i++){
		if(color[i]=='W')
		dfs_visit(G,i,p,d,f,color,t);
		}
}

int main()
{
	Graph *G=new Graph;
	
	cout<<"Enter No. of Vertices and Edges :"<<endl;
	cin>>G->V >> G->E;
	 
	G->Adj=new Edge *[G->V];

	G->p=new int [G->V];
	G->d=new int [G->V];
	G->f=new int [G->V];
    G->color=new char [G->V];
	G->time=new int;
	
	for(int i=0;i<G->V;i++)
		G->Adj[i]=NULL;

	int a,b,x;
	cout<<"Enter '1' for directed Graph"<<endl;
	cout<<"Enter '2' for Undirected Graph"<<endl;
	cin>>x;

	Edge *temp1, *temp2;
	if(x==1)
	{ 
		cout<<"Enter  Edges of directed Graph:"<<endl;
		for(int i=0;i<G->E;i++)
		{
			cout<<"Enter an Edge "<<endl;
			cin>>a>>b;
		
			Edge *t1=new Edge;
			t1->ver=b;
			t1->next=NULL;
		
			temp1=G->Adj[a];
			if(temp1==NULL)
				G->Adj[a]=t1;
			else
			{
				while(temp1->next!=NULL)
					temp1=temp1->next;

				temp1->next=t1;
			}

		}
	}
	if(x==2)
	{
		cout<<"Enter Edges for undirected Graph :"<<endl;
		for(int i=0;i<G->E;i++)
		{
			cout<<"Enter an Edge "<<endl;
			cin>>a>>b;
		
			Edge *t1=new Edge;
			Edge *t2=new Edge;

			t1->ver=b;
			t1->next=NULL;
			
			t2->ver=a;
			t2->next=NULL;
		
			temp1=G->Adj[a];
			if(temp1==NULL)
				G->Adj[a]=t1;
			else
			{
				while(temp1->next!=NULL)
					temp1=temp1->next;

				temp1->next=t1;
			}

			temp2=G->Adj[b];
			if(temp2==NULL)
				G->Adj[b]=t2;

			else
			{
				while(temp2->next!=NULL)
					temp2=temp2->next;

				temp2->next=t2;
			}

		}
	}

	DFS(G);

	cout<<endl;
	cout<<"Some other informations"<<endl;
	cout<<"parent	"<<"	"<<"Vertices	"<<"	"<<"discoverTime	"<<"	"<<"finishTime	"<<endl;

	for(int i=0 ;i<G->V; i++){
	cout<<G->p[i]<<"	"<<i<<"	"<<G->d[i]<<"	"<<G->f[i]<<endl;
	}

return 0;

}
