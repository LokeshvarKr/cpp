#include<iostream>
#include<climits>
using namespace std;
struct Vertex
{
	int ver;
	int weight;
	Vertex *next;
};
struct Graph
{
	int V;
	int E;
	Vertex **Adj;
};
struct Node
{
	int v;
	int key;
};
struct Heap
{
	int size;
	Node *HeapArray;
	int *position;
};
bool IsInQueue(Heap *Queue,int v)
{
	if(Queue->position[v] < Queue->size)
		return true;
	else
		return false;
}
bool IsQueueEmpty(Heap *Queue)
{
	if(Queue->size<1)
	return true;
	else return false;
}
void MinHeapify(Heap *Queue,int p)
{
	Node *s=Queue->HeapArray;
	int n=Queue->size;
	int *position=Queue->position;
	
	int l=2*p+1;
	int r=2*p+2;
	
	int smallest;

	if(l<n && s[l].key < s[p].key)
		smallest=l;
	else 
		smallest=p;
	
	if(r<n && s[r].key < s[smallest].key)
		smallest=r;
	if(smallest!=p)
	{	
		position[s[smallest].v]=p;
		position[s[p].v]=smallest;

		Node temp=s[p];
		s[p]=s[smallest];
		s[smallest]=temp;
		
		MinHeapify(Queue,smallest);
	}

}
void DecreaseKey(Heap *Queue,int v,int w)
{
	Node *s=Queue->HeapArray;
	int n=Queue->size;
	int *position=Queue->position;

	int p=position[v];
	
	s[p].key=w;
	
	while(p>0 && s[(p-1)/2].key > s[p].key)
	{
		position[s[(p-1)/2].v]=p;
		position[s[p].v]=(p-1)/2;

		Node temp=s[p];
		s[p]=s[(p-1)/2];
		s[(p-1)/2]=temp;

		p=(p-1)/2;
	}

}
int ExtractMin(Heap *Queue)
{
	Node *s=Queue->HeapArray;
	int n=Queue->size;
	int *position=Queue->position;

	int v=s[0].v;
	s[0]=s[n-1];
	
	position[s[n-1].v]=0;
	position[v]=n-1;

	n=n-1;
	Queue->size=n;

	MinHeapify(Queue,0);
	return v;

}
/*void Relax(Heap *Queue,int *d,int *p,int u,int v,int w)
{
	if(d[v]>d[u]+w)
	{
		d[v]=d[u]+w;
		p[v]=u;
		DecreaseKey(Queue,v,d[v])
	}


}*/
void Dijkstra_for_sortest_path(Graph *G)
{
	int *d=new int[G->V];
	int *p=new int[G->V];

	for(int i=0;i<G->V;i++)
	{
		d[i]=INT_MAX;	//distance
		p[i]=-1;	//parent
	}
	
	d[0]=0;
	
	Heap *Queue=new Heap;

	Queue->size=G->V;
	Queue->HeapArray=new Node [G->V];
	Queue->position=new int [G->V];

	for(int i=0;i<G->V;i++)
	{
		Queue->HeapArray[i].v=i;
		Queue->HeapArray[i].key=INT_MAX;
		Queue->position[i]=i;
	}
	Queue->HeapArray[0].key=0;

	while(!IsQueueEmpty(Queue))
	{
		int u=ExtractMin(Queue);
		Vertex *temp=G->Adj[u];
		
		while(temp!=NULL)
		{
			int v=temp->ver;
			//Relax(u,v,temp->weight);
			
			if(IsInQueue(Queue,v) && d[v] > d[u] + temp->weight)
			{
				d[v]=d[u]+temp->weight;
				p[v]=u;
				DecreaseKey(Queue,v,d[v]);
			}
			temp=temp->next;
		}

	}

	cout<<"The sortest path is "<<endl;
	for(int i=0;i<G->V;i++)
	cout<<p[i]<<"-"<<i<<endl;
	
}
int main()
{
	Graph *G=new Graph;

	cout<<"Enter No. of vertices and edges for Directed Graph"<<endl;
	cin>>G->V>>G->E;

	G->Adj=new Vertex *[G->V];
	
	for(int i=0;i<G->V;i++)
		G->Adj[i]=NULL;

	cout<<"Enter Edges of Directed graph"<<endl;
	for(int i=0;i<G->E;i++)
	{
		Vertex *v=new Vertex;
		int p,q,w;	
		cout<<"Enter an Edge and its weight"<<endl;
		cin>>p>>q>>w;

		v->ver=q;
		v->weight=w;
		v->next=NULL;

		Vertex *temp=G->Adj[p];

		if(temp==NULL)
			G->Adj[p]=v;
		
		else
		{
			while(temp->next!=NULL)
				temp=temp->next;
		
			temp->next=v;
		}
	}

	Dijkstra_for_sortest_path(G);

return 0;

}
