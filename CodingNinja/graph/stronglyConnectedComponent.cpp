#include<iostream>
#include<stack>
#include<unordered_set>
#include<vector>
using namespace std;
//strongly connected components
//kosaraju's algorithm 

void dfs1(vector<int> *graph,int start,int v,bool *visited,stack<int> &s){
	visited[start]=true;
	for (int i = 0; i < graph[start].size(); ++i){
		int next=graph[start][i];
		if(visited[next]==false){
			dfs1(graph,next,v,visited,s);
			s.push(next);
		}
	}
}
void dfs2(vector<int> *graph,int start,int v,bool *visited,unordered_set<int> *component){
	visited[start]=true;
	component->insert(start);
	for (int i = 0; i < graph[start].size(); ++i){
		int next=graph[start][i];
		if(visited[next]==false){
			dfs2(graph,next,v,visited,component);
		}
	}
}
vector<int> * transposeOfGraph(vector<int> *graph,int v){
	vector<int> *tgraph=new vector<int>[v]();

	for(int i=0;i<v;i++){
		for(int j=0;j<graph[i].size();j++){
			tgraph[graph[i][j]].push_back(i);
		}
	}

	return tgraph;
}
unordered_set<unordered_set<int>*> *stonglyConnectedComponents(vector<int> *graph,int v){
	bool *visited=new bool [v];
	for (int i = 0; i < v; ++i){
		visited[i]=false;
	}
	stack<int> s;
	for (int i = 0; i < v; i++){
		if(visited[i]==false){
			dfs1(graph,i,v,visited,s);
			s.push(i);
		}
	}
	
	vector<int> *tgraph=transposeOfGraph(graph,v);

	for (int i = 0; i < v; ++i){
		visited[i]=false;
	}
	unordered_set<unordered_set<int>*> *output = new unordered_set<unordered_set <int>*>();

	while(!s.empty()){
		int vertex=s.top();
		s.pop();
		if(visited[vertex]==false){
			unordered_set<int> *component=new unordered_set<int> ();
			dfs2(tgraph,vertex,v,visited,component);
			output->insert(component);
		}
	}

	delete [] tgraph;
	return output;
}
int main(){
	int v,e;
	cin>>v>>e;
	vector<int> *graph=new vector<int>[v]();
	for(int i=0;i<e;i++){
		int f,s;
		cin>>f>>s;
		graph[f].push_back(s);
	}
	

	unordered_set<unordered_set<int>*> *components= stonglyConnectedComponents(graph,v);
	cout<<"scc are ---:"<<endl;
	unordered_set<unordered_set<int>*> :: iterator it1=components->begin();
	while(it1!=components->end()){
		unordered_set<int>* component=*it1;
		unordered_set<int> :: iterator it2=component->begin();
		while(it2!=component->end()){
			cout<<*it2<<" ";
			it2++;
		}
		cout<<endl;
		it1++;
	}

	//delete all dynamic allocated memory
	it1=components->begin();
	while(it1!=components->end()){
		unordered_set<int> *component=*it1;
		delete component;
		it1++;
	}
	delete components;
	delete [] graph;
	return 0;
}