


#include<iostream>
#include<stack>
#include<vector>
using namespace std;



void dfs2(int i,vector<int> tGraph[],bool visited[]){
    visited[i]=true;
    for(int j:tGraph[i]){
        if(visited[j]==false){
            dfs2(j,tGraph,visited);
        }
    }
}

void dfs1(int i,vector<int> adj[],stack<int> &st,bool visited[]){
    visited[i]=true;
    for(int j:adj[i]){
        if(visited[j]==false){
            dfs1(j,adj,st,visited);
            st.push(j);
        }
    }
}

void transpose(int V,vector<int> graph[],vector<int> tGraph[]){
    for(int i=0;i<V;i++){
        for(int j:graph[i]){
            tGraph[j].push_back(i);
        }
    }
}
int kosaraju(int V, vector<int> adj[]){
    bool *visited=new bool [V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    stack<int> st;
    for(int i=0;i<V;i++){
        if(visited[i]==false){
            dfs1(i,adj,st,visited);
            st.push(i);
        }
    }
    
    
    vector<int> *tGraph=new vector<int>[V];
    transpose(V,adj,tGraph);
    
  
    
    for(int i=0;i<V;i++){
        visited[i]=false;
    }
    
    int components=0;
    while(!st.empty()){
        int i=st.top();st.pop();
        if(visited[i]==false){
            dfs2(i,tGraph,visited);
            components++;
        }
    }
    return components;
}

int main(){ 
    int V,E;
    cin>>V>>E;
    int m,n;
    vector<int> adj[V];
    for(int i=0;i<E;i++){
        cin>>m>>n;
        adj[m].push_back(n);
    }
    cout<<kosaraju(V, adj)<<endl;
    return 0;
}