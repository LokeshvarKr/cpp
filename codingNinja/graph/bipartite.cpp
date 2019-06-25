#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;
bool bipartite(vector<int> *graph , int v){
	bool *visited=new bool [v];
	for(int i=0;i<v;i++){
		visited[i]=false;
	}

	unordered_set<int> s[2];
	queue<int> pending;

	for(int i=0;i<v;i++){
		if(visited[i]==false){
			pending.push(i);
			s[0].insert(i);
			visited[i]=true;
			while(!pending.empty()){
				int current=pending.front();
				pending.pop();
				int currentSet=(s[0].count(current)>0 ? 0 : 1);

				for(int j=0;j<graph[current].size();j++){
					int neighbour=graph[current][j];
					if(s[0].count(neighbour)==0 && s[1].count(neighbour)==0){
						s[1-currentSet].insert(neighbour);
						pending.push(neighbour);
						visited[neighbour]=true;
					}
					else if(s[currentSet].count(neighbour) > 0){
						return false;
					}

				}

			}
		}
	}
	return true;
}
int main(){
	while(true){
		int v,e;
		cin>>v;
		if(v==0){
			break;
		}
		cin>>e;
		vector<int> *edge=new vector<int>[v]();
		for(int i=0;i<e;i++){
			int f,s;
			cin>>f>>s;
			edge[f-1].push_back(s-1);
			edge[s-1].push_back(f-1);
		}

		bool result=bipartite(edge,v);
		if(result){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}

		delete [] edge;
	}
	return 0;
}