#include<iostream>
#include<stack>
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
struct graph
{
	int v;
	int e;
	Edge **adj;

};

std::stack<int>S;
/*void PRINT(Graph *G)
{
	if(G==NULL)
	return;
	for(int i=0;i<G->V;i++)
	{
		Edge *temp1=G->Adj[i];
		cout<<"Adj of "<<i<<" are:"<<endl;
		while(temp1!=NULL)
		{
			cout<<temp1->ver<<" ";
			temp1=temp1->next;
		}
		cout<<endl;
	}

}
void print(graph *g)
{
	if(g==NULL)
	return;
	for(int i=0;i<g->v;i++)
	{
		Edge *temp1=g->adj[i];
		cout<<"Adj of "<<i<<" are:"<<endl;
		while(temp1!=NULL)
		{
			cout<<temp1->ver<<" ";
			temp1=temp1->next;
		}
		cout<<endl;
	}

}*/
void dfs_visit(Graph *G,int u,int *p,int *d,int *f,char *color,int *t)
{	
	color[u]='G';
	(*t)=(*t)+1;
	d[u]=(*t);		

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
	S.push(u);
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

graph* TransposeOfGraph(Graph *G)
{
	graph *g=new graph;
	
	g->v=G->V;
	g->e=G->E;
	
	g->adj=new Edge *[g->v];
	
	for(int i=0;i<g->v;i++)
		g->adj[i]=NULL;

	Edge *temp1, *temp2;
	for(int i=0;i<g->v;i++)
	{
		temp1=G->Adj[i];
		
		while(temp1!=NULL)
		{
			int t=temp1->ver;
			
			temp2=g->adj[t];
									
			Edge *t1=new Edge;

			t1->ver=i; 			
			t1->next=NULL;			
			
			if(temp2==NULL)
				g->adj[t]=t1;
			else
			{
				while(temp2->next!=NULL)
					temp2=temp2->next;
				
				temp2->next=t1;
			}
		
			temp1=temp1->next;
		}
	}
	return g;

}
void DFSonTransposed(graph *g)
{
	bool *visited = new bool [g->v];

	for(int i=0;i<g->v;i++)
		visited[i]=false;	

	stack<int>stack;
	while(!S.empty())
	{
		int t=S.top();
		S.pop();
	if(visited[t]==false)
	{
		cout<<endl;
		stack.push(t);

		while(!stack.empty())
		{
			int t1=stack.top();
				stack.pop();
			if(visited[t1]==false)
			{
				visited[t1]=true;
				cout<<t1<<" ";
			}
				Edge *temp=g->adj[t1];
				while(temp!=NULL)
				{
					int t2=temp->ver;
					if(visited[t2]==false)
					{
						visited[t2]=true;
						cout<<t2<<" ";
						stack.push(t2);
					} 
					temp=temp->next;
				}
			
		
		
		}
	}

	
	}


}
void StronglyConnectedComponent(Graph *G)
{
	DFS(G);
	graph *g=TransposeOfGraph(G);
	DFSonTransposed(g);
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

		int a,b;
		Edge *temp1, *temp2;

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
	
	cout<<"Strongly connected components are :"<<endl;
	StronglyConnectedComponent(G);

return 0;

}
