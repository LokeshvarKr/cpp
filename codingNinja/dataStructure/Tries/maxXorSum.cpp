//using trie data structure 
//we are keeping max 2 value in each node
//left pointer is not null means bit 0 is present
//right pointer is not null means bit 1 is present

#include<iostream>
#include <cmath>
#include<climits>
using namespace std;

class TrieNode{
public:
	TrieNode *left;
	TrieNode *right;
	TrieNode(){
		this->left=NULL;
		this->right=NULL;
	}
	~TrieNode(){
		delete this->left;
		delete this->right;
	}
};

void insert(int n,TrieNode *head){
	TrieNode *current=head;
	for(int i=31;i>=0;i--){
		int b=(n>>i)&1;
		if(b==0){
			if(current->left==NULL){
				current->left=new TrieNode();
			}
			current=current->left;
		}
		else{
			if(current->right==NULL){
				current->right=new TrieNode();
			}	
			current=current->right;
		}
	}

}

int findMaxXorPairValue(TrieNode *head,int *a,int n){
	int maxXor=INT_MIN;
	for(int i=0;i<n;i++){
		int value=a[i];
		int currentXor=0;
		TrieNode *current=head;
		for(int j=31;j>=0;j--){
			int b=(value>>j)&1;
			if(b==0){
				if(current->right){
					currentXor+=pow(2,j);
					current=current->right;
				}
				else{
					current=current->left;
				}
			}
			else{
				if(current->left){
					currentXor += pow(2,j);
					current=current->left;
				}
				else{
					current=current->right;
				}
			}
		}
		if(maxXor < currentXor){
			maxXor=currentXor;
		}
	}
	return maxXor;
}

int main(){
	int n;
	cin>>n;
	int *a=new int[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	TrieNode *head=new TrieNode(); //head doesnot repersent any data in trie
	for(int i=0;i<n;i++){
		insert(a[i],head);
	}

	int maxXor=findMaxXorPairValue(head,a,n);
	cout<<maxXor<<endl;
	
	delete head;
	delete [] a;
	return 0;
}