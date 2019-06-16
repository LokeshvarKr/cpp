


/*
Help Me Pradyumana!
(Search Suggestion Problem)

Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his 
auto - correct more times than the auto - correct corrects him. Pradyumn is thinking to make 
his own app for mobile which will restrict auto - correct feature, instead it will provide auto - completion. 
Whenever Pradyumn types factorial, auto - correct changes it to fact. Pradyumn's App will show options such 
as fact, factorial, factory. Now, he can chose from any of these options. As Pradyumn is busy with his 
front - end work of his App. He asks you to help him. He said "You will be given set of words(words may 
repeat too but counted as one only). Now, as user starts the app, he will make queries(in lowercase letters only). 
So, you have to print all the words of dictionary which have the prefix same as given by user as input. And if no 
such words are available, add this word to your dictionary." As you know, Pradyumn want this app to be as smart as 
him :P So, implement a program for him such that he can release it on Fun Store.

INPUT CONSTRAINTS
1≤N≤30000
sum(len(string[i]))≤2∗10^5
1≤Q≤10^3

INPUT FORMAT
Single integer N which denotes the size of words which are input as dictionary
N lines of input, where each line is a string of consisting lowercase letter
Single integer Q which denotes the number of queries.
Q number of lines describing the query string on each line given by user

OUTPUT FORMAT
If auto - completions exists, output all of them in lexicographical order else 
output "No suggestions" without quotes

NOTE
All strings are lowercase

SAMPLE INPUT
3
fact
factorial
factory
2
fact
pradyumn

SAMPLE OUTPUT
fact
factorial
factory
No suggestions






*/

#include <bits/stdc++.h>
using namespace std;
#define SIZE 26
class TrieNode{
    public:
        char data;
        bool end_word;
        TrieNode **child;
        TrieNode(char data){
            this->data=data;
            this->end_word=false;
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

void  insert(TrieNode *root,string s){
    for(int i=0;i<s.length();i++){
        int index=s[i]-'a';
        if(root->child[index] == NULL){
            root->child[index] = new TrieNode(s[i]);
        }
        root=root->child[index];
    }
    root->end_word=true;
}

void dfs(TrieNode *root,string suggest){
    suggest += root->data;
    if(root->end_word==true){
        cout<<suggest<<endl;
    }
    for(int i=0;i<SIZE;i++){
        if(root->child[i]!=NULL){
        dfs(root->child[i],suggest);
        }
    }
}
void search(TrieNode *trie_root,string s){
    TrieNode *root=trie_root;
    string suggest="";
    for(int i=0;i<s.length();i++){
        int index=s[i]-'a';
        if(root->child[index]==NULL){
            cout<<"No suggestions"<<endl;
            insert(trie_root,s);
            return;
        }
        suggest+=s[i];
        root=root->child[index];
    }
    if(root->end_word==true){
        cout<<suggest<<endl;
    }
    for(int i=0;i<SIZE;i++){
        if(root->child[i] != NULL){
            dfs(root->child[i],suggest);
        }
    }
    
    
}
int main(){
    TrieNode *root=new TrieNode('$');
    int n,q;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        insert(root,s);
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>s;
        search(root,s);
    }
    delete root;
    return 0;
}
