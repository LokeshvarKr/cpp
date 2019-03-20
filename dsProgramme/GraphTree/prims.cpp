//Implementation of prims algorithm for finding minimum spanning tree
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
struct Heap
{
	int v;
	int key;
};

int n;
bool IsHeapEmpty()
{
	if(n<1)
	return true;
	else
	return false;
}
void MinHeapify(Heap *H,int *position,int i)
{
	int l=2*i+1;
	int r=2*i+2;
	int smallest;
	Heap temp;
	if(l<n && H[l].key<H[i].key)
		smallest=l;
	else
		smallest=i;
	if(r<n && H[r].key<H[smallest].key)
		smallest=r;
	if(smallest!=i)
	{
		position[i]=position[smallest];
		position[smallest]=position[i];
		temp=H[i];
		H[i]=H[smallest];
		H[smallest]=temp;
		
		MinHeapify(H,position,smallest);
	}		

}
int ExtractMin(Heap *H,int *position)
{
	/*if(n<1)
	{
	cout<<"Error 'Underflow' "<<endl;
	return ;
	}*/
	
	int min=H[0].v;
	H[0]=H[n-1];
	position[n-1]=0;
	n=n-1;
	MinHeapify(H,position,0);

	return min;
}
void HeapDecreaseKey(Heap *H,int *position,int i,int key)
{
	int p=position[i];
	if(key>H[p].key)
		return;
	Heap temp;
	H[p].key=key;
	while(p>0 && H[(p-1)/2].key > H[p].key)
		{

			position[p]=(p-1)/2;
			position[(p-1)/2]=p;
			temp=H[p];
			H[p]=H[(p-1)/2];
			H[(p-1)/2]=temp;
			p=(p-1)/2;
		}

}
/*void BuildMinHeap(int *A)
{
	for(int i=(n/2)-1;i>=0;i--)
		MinHeapify(A,i);
}*/
void PrimsMST(Graph *G)
{
	int V=G->V;
	int E=G->E;

	bool *visited=new bool[V];
	int *parent=new int[V];
	Heap *H=new Heap[V];
	int *position=new int[V];
	int *key = new int[V];
	
	for(int i=0;i<V;i++)
	{
		key[i]=INT_MAX;
		H[i].key=INT_MAX;
		H[i].v=i;
		position[i]=i;
		parent[i]=-1;
		visited[i]=false;
	}
	
	H[0].key=0;
	key[0]=0;
	
	n=G->V;
	
	Vertex *uAdjacent;
	int j,u;
	while(!IsHeapEmpty())
	{
		u=ExtractMin(H,position);
		cout<<"Extracted value is "<<u<<endl;
		visited[u]=true;
		
		uAdjacent=G->Adj[u];
		while(uAdjacent!=NULL)
		{
			j=uAdjacent->ver;
			if(!visited[j])
			{
				if(key[j] > uAdjacent->weight)
					{
						key[j]=uAdjacent->weight;
						parent[j]=u;
						cout<<"parent of "<<j<<" "<<u<<endl;
						HeapDecreaseKey(H,position,j,uAdjacent->weight);					
					}
			}
			uAdjacent=uAdjacent->next;
		}
	
	}
	int sum=0;
	cout<<"Prims MST is "<<endl;
	cout<<"Source vertex is 0"<<endl;
	cout<<"Edges"<<endl;
	for(int i=1;i<V;i++){
	cout<<parent[i]<<"-"<<i<<endl;
	sum=sum+key[i];
	}
	cout<<"Sum of MST is "<<sum;

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

for(int i=0;i<G->V;i++)
	{
		cout<<"Adjacent of "<<i<<" are"<<endl;
		Vertex *t=G->Adj[i];
		while(t!=NULL)
		{
			cout<<t->ver<<" "<<t->weight<<endl;
			t=t->next;
		}
		
	}	
		
	PrimsMST(G);


return 0;
}

