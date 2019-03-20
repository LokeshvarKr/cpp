//cycle detection in graph using dfs
#include<iostream>
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
	Edge **Adj;

};
bool IsCycle(Graph *G,int i,bool *visited,bool *recSTACK)
{	
	if(visited[i]==false)
	{
		visited[i]=true;
		recSTACK[i]=true;

	Edge *temp=G->Adj[i];
	while(temp!=NULL)
	{
		int v=temp->ver;
		if(!visited[v] && IsCycle(G,v,visited,recSTACK))
			return true;

		if(recSTACK[v])
			return true;
	}

	}
	recSTACK[i]=false;
	return false;
}

bool CycleDetectionInDFS(Graph *G)
{
	bool *visited=new bool[G->V];
	bool *recSTACK=new bool[G->V];

	for(int i=0;i<G->V;i++)
	{
		visited[i]=false;
		recSTACK[i]=false;
	}

	for(int i=0;i<G->V;i++)
	{
		if(IsCycle(G,i,visited,recSTACK))
			return true;
		else 
			return false;
	}
}

int main()
{
	Graph *G=new Graph;
	
	cout<<"Enter No. of Vertices and Edges :"<<endl;
	cin>>G->V >> G->E;
	 
	G->Adj=new Edge *[G->V];

	for(int i=0;i<G->V;i++)
		G->Adj[i]=NULL;

	int a,b;

	Edge *temp1;
 
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
	
	bool x=CycleDetectionInDFS(G);

	if(x)
		cout<<"THERE IS A CYCLE"<<endl;
	else
		cout<<"THERE  IS NO CYCLE"<<endl;

	

return 0;

}
