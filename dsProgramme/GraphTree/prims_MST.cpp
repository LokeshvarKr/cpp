//PRIMS MST ALGORITHM
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
	int *position;
	Node *HeapArray;
};

bool IsInQueue(Heap *Queue,int v)
{
	if(Queue->position[v]<Queue->size)
		return true;
	else
		return false;
}
bool IsQueueEmpty(Heap *Queue)
{
	if(Queue->size<1)
		return true;

	else 
		return false;
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
		position[s[p].v]=smallest;
		position[s[smallest].v]=p;

		Node temp1=s[p];
		s[p]=s[smallest];
		s[smallest]=temp1;

		MinHeapify(Queue,smallest);
	}

}
void DecreaseKey(Heap *Queue,int v,int w)
{
	Node *s=Queue->HeapArray;
	int *position=Queue->position;
	int p=position[v];
		
	s[p].key=w;

	while(p>0 && s[(p-1)/2].key > s[p].key)
	{
		position[s[p].v]=(p-1)/2;
		position[s[(p-1)/2].v]=p;

		Node temp1=s[p];
		s[p]=s[(p-1)/2];
		s[(p-1)/2]=temp1;

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
	
	MinHeapify(Queue, 0);
	
	return v;

}
void MST_PRIMS(Graph *G)
{
	int *parent=new int [G->V];
	int *key=new int [G->V];
		
	for(int i=0;i<G->V;i++)
	{
		parent[i]=-1;
		key[i]=INT_MAX;
	}	
	
	Heap *Queue = new Heap;

	Queue->size=G->V;
	Queue->position=new int [G->V];
	Queue->HeapArray= new Node [G->V];
	
	for(int i=0;i<G->V;i++)
	{
		Queue->position[i]=i;
		Queue->HeapArray[i].key=INT_MAX;
		Queue->HeapArray[i].v=i;
	}

	//Initialize singe source;
	key[0]=0;
	Queue->HeapArray[0].key=0;
	
	while(!IsQueueEmpty(Queue))
	{
		int u=ExtractMin(Queue);
		
		Vertex *temp=G->Adj[u];
		
		while(temp!=NULL)		
		{
			int v=temp->ver;
			
			if(IsInQueue(Queue,v) && key[v] > temp->weight)
			{
				key[v]=temp->weight;
				parent[v]=u;
				DecreaseKey(Queue,v,temp->weight);
			}
		
			temp=temp->next;
		}

	}

	int sum=0;
	cout<<"The Prims-MST is :"<<endl;
	cout<<"Source vertex is 0"<<endl;
	for(int i=1;i<G->V;i++){
	cout<<parent[i]<<"-"<<i<<endl;
	sum=sum+key[i];
	}
	cout<<"Total sum of MST is = "<<sum<<endl;

}
int main()
{
	int V,E,p,q,w;
	Graph *G=new Graph;
	cout<<"Enter no. of vertices and edges"<<endl;
	cin>>G->V>>G->E;
	G->Adj=new Vertex *[G->V];
	for(int i=0;i<G->V;i++)
		G->Adj[i]=NULL;

	cout<<"Enter edges:"<<endl;
	for(int i=0;i<G->E;i++)
	{
		cout<<"Enter an edge and its weight"<<endl;
		cin>>p>>q>>w;
		Vertex *t1=new Vertex;
		Vertex *t2=new Vertex;
			
		t1->ver=q;
		t1->weight=w;
		t1->next=NULL;

		t2->ver=p;
		t2->weight=w;
		t2->next=NULL;

		Vertex *temp1,*temp2;

		temp1=G->Adj[p];
		if(temp1==NULL)
			G->Adj[p]=t1;
		else
		{
			while(temp1->next!=NULL)
				temp1=temp1->next;
			temp1->next=t1;
		}
	

		temp2=G->Adj[q];
		if(temp2==NULL)
			G->Adj[q]=t2;
		else
		{
			while(temp2->next!=NULL)
				temp2=temp2->next;
			temp2->next=t2;
		}

	}

	MST_PRIMS(G);

  return 0;

}

