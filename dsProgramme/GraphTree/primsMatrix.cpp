//prims algorithm for minimum spaning tree
#include<iostream>
#include<climits>
using namespace std;
int ExtractMin(int *key,bool *visited,int V)
{
	int min=-1;
	for(int i=0;i<V;i++)
	{
		if(!visited[i] && (min==-1 || key[i]<key[min]))
			min=i;
	}
return min;

}
void PrimsMST(int **edges,int V)
{	
	int *key=new int[V];
	int *parent=new int[V];
	bool *visited=new bool[V];
	
	for(int i=0;i<V;i++)
	{
		key[i]=INT_MAX;
		parent[i]=-1;
		visited[i]=false;
	}
	key[0]=0;
	
	int  u;
	for(int i=0;i<V;i++)
	{
 		u=ExtractMin(key,visited,V);
		visited[u]=true;
	   for(int j=0;j<V;j++)
	    {
		if(edges[u][j]!=0 && !visited[j] )
		  {
		    	if(key[j]>edges[u][j])
			{
				key[j]=edges[u][j];
				parent[j]=u;
			}
		   }
			
	     }

	}
	int sum=0;
	cout<<"Source vertex is 0"<<endl;
	cout<<"Edege"<<"	"<<"weight"<<endl;
	for(int i=1;i<V;i++)
	{
		
		cout<<parent[i]<<"-"<<i<<"	"<<edges[parent[i]][i]<<endl;
		sum=sum+edges[parent[i]][i];
	}
	cout<<"sum of MST is "<<sum<<endl;

delete [] visited;
delete [] parent;
delete [] key;

}
int main()
{
int V,E;
	cout<<"Enter no. of vertices and no. of edges :"<<endl;
	cin>>V>>E;
	int **edges=new int *[V];
	for(int i=0;i<V;i++){
		edges[i]=new int[V];
		for(int j=0;j<V;j++){
			edges[i][j]=0;
		}
	}
int p,q,w;
for(int i=0;i<E;i++){
	cout<<"Enter an edge and its weight :"<<endl;
	cin>>p>>q>>w;
	edges[p][q]=w;
	edges[q][p]=w;
}

PrimsMST(edges,V);

for(int i=0;i<V;i++)
	delete [] edges[i];

	
	delete [] edges;


return 0;
}
