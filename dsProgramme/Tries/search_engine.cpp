/*

Search Engine

Let us see how search engines work. Consider the following simple auto complete
feature. When you type some characters in the text bar, the engine automatically
gives best matching options among it's database. Your job is simple. Given an incomplete
search text, output the best search result.
Each entry in engine's database has a priority factor attached to it. We consider a 
result / search suggestion best if it has maximum weight and completes the given incomplete 
search query. For each query in the input, print the maximum weight of the string in the database, 
that completes the given incomplete search string. In case no such string exists, print -1.

INPUT
First line contains two integers n and q, which represent number of database entries and 
number of search queries need to be completed. Next n lines contain a string s and an integer weight,
which are the database entry and it's corresponding priority.
Next q lines follow, each line having a string t, which needs to be completed.

OUTPUT
Output q lines, each line containing the maximum possible weight of the match for given query, 
else -1, in case no valid result is obtained.

CONSTRAINTS
1 ≤ n, weight, len(s), len(t) ≤ 10^6
1 ≤ q ≤ 10^5
total length of all strings in database entries ≤ 10^6
total length of all query strings ≤ 10^6

SAMPLE INPUT
2 1
hackerearth 10
hackerrank 9
hacker

SAMPLE OUTPUT
10

*/
#include <bits/stdc++.h>
using namespace std;
#define SIZE 26
class TrieNode{
    public:
        int weight;
        char data;
        TrieNode **child;
        TrieNode(char data,int weight){
            this->weight=weight;
            this->data=data;
            child=new TrieNode* [SIZE];
            for(int i=0;i<SIZE;i++){
                child[i]=NULL;
            }
        }
        ~TrieNode(){
            for(int i=0;i<SIZE;i++){
                delete child[i];
            }
            delete [] child;
        }
};

void  insert(TrieNode *root,string s,int weight){
    for(int i=0;i<s.length();i++){
        int index=s[i]-'a';
        if(root->child[index] == NULL){
            root->child[index] = new TrieNode(s[i],weight);
        }
        else if(root->child[index]->weight < weight){
            root->child[index]->weight = weight;
        }
        root=root->child[index];
    }
    
}

int search(TrieNode *root,string s){
    for(int i=0;i<s.length();i++){
        int index=s[i]-'a';
        if(root->child[index]==NULL){
            return -1;
        }
        root=root->child[index];
    }
    return root->weight;
}
int main(){
    TrieNode *root=new TrieNode(-1,'$');
    int n,q;
    cin>>n>>q;
    string s;int weight;
    for(int i=0;i<n;i++){
        cin>>s>>weight;
        insert(root,s,weight);
    }
    for(int i=0;i<q;i++){
        cin>>s;
        weight=search(root,s);
        cout<<weight<<endl;
    }
    delete root;
    return 0;
}
