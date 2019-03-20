#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

void dfs(vector<int> *edge,int start,int v,bool *visited,unordered_set<int> *component){
	visited[start]=true;
	component->insert(start);
	for (int i = 0; i < edge[start].size(); ++i){
		int next=edge[start][i];
		if(visited[next]==false){
			dfs(edge,next,v,visited,component);
		}
	}
}
unordered_set<unordered_set<int>*> * connectedComponent(vector<int> *edge,int v){
	
	bool *visited=new bool[v];
	for (int i = 0; i < v; i++){
		visited[i]=false;
	}

	unordered_set<unordered_set<int>*> *output = new unordered_set<unordered_set <int>*>();
	
	for (int i = 0; i < v; i++){
		if(visited[i]==false){
			unordered_set<int> *component=new unordered_set<int> ();
			dfs(edge,i,v,visited,component);
			output->insert(component);
		}
	}


	delete [] visited;
	return output;
}
int main(){
	int v,e;
	cin>>v>>e;
	vector<int> *edge=new vector<int>[v]();
	for(int i=0;i<e;i++){
		int f,s;
		cin>>f>>s;
		edge[f].push_back(s);
		edge[s].push_back(f);
	}

	unordered_set<unordered_set<int>*> *components= connectedComponent(edge,v);

	unordered_set<unordered_set<int>*> :: iterator it1=components->begin();
	
	while(it1!=components->end()){
		unordered_set<int>* component=*it1;
		unordered_set<int> :: iterator it2=component->begin();
		while(it2!=component->end()){
			cout<<*it2<<" ";
			it2++;
		}
		cout<<endl;
		//delete component;
		it1++;
	}
	
	//delete components;

	delete [] edge;

	return 0; 
}