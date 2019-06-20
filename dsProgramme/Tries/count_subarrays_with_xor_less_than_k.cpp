#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
    int pre_xor;
    int leaf_count;
    TrieNode *left,*right;
    TrieNode(){
        left=right=NULL;
        pre_xor=0;
        leaf_count=0;
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
            root->leaf_count+=1;
            root=root->left;
        }
        else{
            if(root->right==NULL){
                root->right=new TrieNode();
            }
            root->leaf_count+=1;
            root=root->right;
        }
    }
    
    root->pre_xor=pre_xor;
}

int query(TrieNode *root,int pre_xor,int k){
    int count=0;
    for(int i=31;i>=0;i--){
        int x=((pre_xor>>i)&1);
        int y=((k>>i)&&1);
        if(x==1 && y==1){
            if(root->right){
                count+=root->right->leaf_count;
            }
            root=root->left;
        }
        else if(x==1 && y==0){
            if(root->right){
                root=root->right;
            }
        }
        else if(x==0 && y==1){
            if(root->left){
                count+=root->left->leaf_count;
                root=root->right;
            }
        }
        else if(x==0 && y==0){
            root=root->left;
        }
    }
    
    return count;
        
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
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
            result += query(root,pre_xor,k);
            insert(root,pre_xor);
        }

        cout<<result<<endl;

        delete [] a;
        delete root;
    }
    return 0;
    
}