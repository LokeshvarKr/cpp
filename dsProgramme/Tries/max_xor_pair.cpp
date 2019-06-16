#include<iostream>
#include<cmath>
using namespace std;

// trie data structure is used to solve this question;
class TrieNode{
public:
	TrieNode *left;	// indicate 0
	TrieNode *right;	// indicate 1
	TrieNode(){
		left=NULL;
		right=NULL;
	}
	~TrieNode(){
		delete left;
		delete right;
	}
};


void insert(TrieNode *root,int n){
	TrieNode *curr_node=root;
	for(int i=31;i>=0;i--){
		int b=((n>>i)&1);
		if(b==0){
			if(curr_node->left==NULL){
				curr_node->left=new TrieNode();
			}
			curr_node=curr_node->left;
		}
		else{
			if(curr_node->right==NULL){
				curr_node->right=new TrieNode();
			}
			curr_node=curr_node->right;
		}
	}
}

int find_max_xor(TrieNode *root,int n){
	TrieNode *curr_node=root;
	int curr_xor=0;
	for(int i=31;i>=0;i--){
		int b=((n>>i)&1);
		if(b==0){
			if(curr_node->right){
				curr_xor+=pow(2,i);
				curr_node=curr_node->right;
			}
			else{
				curr_node=curr_node->left;
			}
		}
		else{
			if(curr_node->left){
				curr_xor+=pow(2,i);
				curr_node=curr_node->left;
			}
			else{
				curr_node=curr_node->right;
			}
		}
	}

	return curr_xor;
}

int main(){
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	TrieNode *root=new TrieNode();
	for(int i=0;i<n;i++){
		insert(root,arr[i]);
	}

	int max_xor=0;
	for(int i=0;i<n;i++){
		int curr_xor=find_max_xor(root,arr[i]);
		if(max_xor < curr_xor){
			max_xor=curr_xor;
		}
	}
	cout<<max_xor<<endl;
	delete [] arr;
	delete root;
	return 0;
}
