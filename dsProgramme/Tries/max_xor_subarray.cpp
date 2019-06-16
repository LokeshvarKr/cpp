#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    int pre_xor;
    TrieNode *left;
    TrieNode *right;
    TrieNode(){
        left=right=NULL;
        pre_xor=0;
    }
    ~TrieNode(){
        delete left;
        delete right;
    }
};

void insert(TrieNode *root,int pre_xor){
    for(int i=31;i>=0;i--){
        int b=(pre_xor>>i)&1;
        if(b==0){
            if(root->left==NULL){
                root->left=new TrieNode();
            }
            root=root->left;
        }
        else{
            if(root->right==NULL){
                root->right=new TrieNode();
            }
            root=root->right;
        }
    }
    
    root->pre_xor=pre_xor;
}

int query(TrieNode *root,int pre_xor){
    for(int i=31;i>=0;i--){
        int b=((pre_xor>>i)&1);
        if(b==0){
            if(root->right){
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
        else{
            if(root->left){
                root=root->left;
            }
            else{
                root=root->right;
            }
        }
    }
    return pre_xor ^ root->pre_xor;
}
int main() {
    int n;
    cin>>n;
    int *a=new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    TrieNode *root=new TrieNode();
    insert(root,0);
    int pre_xor=0;
    int result=0;
    for(int i=0;i<n;i++){
        pre_xor=pre_xor ^ a[i];
        insert(root,pre_xor);
        result=max(result,query(root,pre_xor));
    }
    
    cout<<result<<endl;
    
    delete [] a;
    delete root;
    return 0;
    
}