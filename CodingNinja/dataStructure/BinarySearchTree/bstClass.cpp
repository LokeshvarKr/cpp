#include<iostream>
#include"BinaryTreeNode.h"
using namespace std;

class BST{
	private:
	BinaryTreeNode<int> *root;
	
	public:
	BST(){
	root=NULL;
	}
	~BST(){
	delete root;
	}

	private:
	bool searchData(int data,BinaryTreeNode<int> *root){
		if(root==NULL)return false;
		if(root->data==data)return true;
		if(data < root->data)return searchData(data,root->left);
		return searchData(data,root->right);
	}

	public:
	bool searchData(int data){
		return searchData(data,root);
	
	}
	
	private:
	BinaryTreeNode<int> *insertData(int data,BinaryTreeNode<int> *root){
		if(root==NULL){
		BinaryTreeNode<int> *node=new BinaryTreeNode<int>(data);
		return node;
		}
		
		if(root->data > data){
		root->left=insertData(data,root->left);
		return root;
		}

		else if(root->data < data){
		root->right=insertData(data,root->right);
		return root;
		}
		
	}

	public:
	BinaryTreeNode<int> *insertData(int data){
	this->root=insertData(data,this->root);
	return root;
	}

	private:
	BinaryTreeNode<int> *deleteData(int data,BinaryTreeNode<int> *root){

		if(root==NULL)return NULL;
	
		if(root->data > data){
		root->left=deleteData(data,root->left);
		return root;
		}
		
		else if(root->data < data){
		root->right=deleteData(data,root->right);
		return root;
		}
		
		else{
			if(root->left==NULL && root->right==NULL){
			delete root;
			return NULL;
			}
			else if(root->left==NULL){
			BinaryTreeNode<int> *temp=root->right;
			root->right=NULL;
			delete root;
			return temp;
			}
			else if(root->right==NULL){
			BinaryTreeNode<int> *temp=root->left;
			root->left=NULL;
			delete root;
			return temp;
			}
			else{
				BinaryTreeNode<int> *minNode=root->right;
				
				while(minNode->left!=NULL){
				minNode=minNode->left;
				}

				int minData=minNode->data;
				root->data=minData;
				root->right=deleteData(minData,root->right);
							
				return root;
			}

		}

	}
	
	public:
	BinaryTreeNode<int> *deleteData(int data){
		this->root=deleteData(data,this->root);
		
	}
	
	private:
	void printTree(BinaryTreeNode<int> *root){

	if(root==NULL)return;

	cout<<root->data<<":";
	if(root->left)cout<<"L"<<root->left->data;
	if(root->right)cout<<",R"<<root->right->data;
	cout<<endl;
	printTree(root->left);
	printTree(root->right);

	}

	public:
	void printTree(){
		printTree(this->root);
	}

	private:
	void inorderPrint(BinaryTreeNode<int> *root){
		if(root==NULL)return;
	inorderPrint(root->left);
	cout<<root->data<<" ";
	inorderPrint(root->right);
	}

	public:
	void inorderPrint(){
	inorderPrint(this->root);
	}


};

int main(){

BST b;

int a[10];
for(int i=0;i<10;i++)
a[i]=i+1;

for(int i=0;i<10;i++)
b.insertData(a[i]);

b.printTree();
cout<<endl;
b.deleteData(2);

b.printTree();
cout<<endl;
return 0;
}



