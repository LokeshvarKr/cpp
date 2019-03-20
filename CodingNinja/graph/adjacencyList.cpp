#include<iostream>
using namespace std;
#include<string.h>
class vertex{
public:
	int ver;
	int w;
	vertex *next;
	vertex(int ver,int w){
		this->ver=ver;
		this->w=w;
		next=NULL;
	}
	~vertex(){
		if(this->next){
			delete this->next;
		}
	}
};
class Graph{
public:
	int v;
	int e;
	vertex **list;
	~Graph(){
		for(int i=0;i<v;i++){
			vertex *ver=list[i];
			delete ver;
		}
	}
};

void print(Graph *G){
	for(int i=0;i<G->v;i++){
		vertex *head=G->list[i];
		cout<<i<<" : ";
		while(head){
			cout<< head->ver <<" ";
			head=head->next;
		}
		cout<<endl;
	}
}

void dfsVisit(Graph *G,int u,int *time,int *discover,int *finish,string *color,int *parent){
	cout<<u<<" ";
	color[u]="gray";
	(*time)+=1;
	discover[u]=*time;
	vertex *head=G->list[u];
	while(head){
		int v=head->ver;
		if(color[v]=="white"){
			parent[v]=u;
			dfsVisit(G,v,time,discover,finish,color,parent);
		}
		head=head->next;
	}
	color[u]="black";
	(*time)+=1;
	finish[u]=*time;
}
void dfs(Graph *G){
	int v=G->v;
	string *color=new string[v];
	int *finish=new int [v];
	int *discover=new int [v];
	int *parent=new int [v];
	
	for(int i=0;i<v;i++){
		color[i]="white";
		finish[i]=-1;
		discover[i]=-1;
		parent[i]=-1;
	}
	
	int *time;
	*time=0;
	for(int i=0;i<v;i++){
		if(color[i]=="white"){
			dfsVisit(G,i,time,discover,finish,color,parent);
		}
	}

}
int main(){
	int v,e;
	cin>>v>>e;

	Graph *G=new Graph;
	G->v=v;
	G->e=e;
	
	G->list=new vertex *[v];
	for(int i=0;i<v;i++){
		G->list[i]=NULL;
	}
	
	for(int i=0;i<e;i++){
		int f,s,w;
		cin>>f>>s>>w;
		vertex *node;
		vertex *head;

		node=new vertex(s,w);
		head=G->list[f];
		
		if(head==NULL){
			G->list[f]=node;
		}
		else{
			while(head->next){
				head=head->next;
			}
			head->next=node;
		}

		head=G->list[s];
		node=new vertex(f,w);
		
		if(head==NULL){ 
			G->list[s]=node;
		}
		else{
			while(head->next){
				head=head->next;
			}
			head->next=node;
		}
	}

	print(G);
	dfs(G);
	delete G;
	return 0;

}