#include<iostream>
#include<stdio.h>
using namespace std;


class Tree{
	private:
	class Node{
		public:
			int data;
			Node *left,*right;
			Node(int data){
				this->data=data;
				this->left=this->right=NULL;
			}
	};

	public:
	Node *root;
	Tree(){
		this->root=NULL;
	}

	private:
	 Node *insertNode(Node *root,int data){
		if(root==NULL){
			return new Node(data);
		}
		if(data <= root->data){
			root->left=insertNode(root->left,data);
		}
		else{
			root->right=insertNode(root->right,data);
		}
	}
	void createTree(int arr[],int n){
		for(int i=0;i<n;i++){
			root=insertNode(root,arr[i]);
		}
	}

	void serializeTree(Node *root,FILE *fp){
		if(root==NULL){
			fprintf(fp,"%d ",-1);
			return;
		}
		fprintf(fp,"%d ",root->data);
		serializeTree(root->left,fp);
		serializeTree(root->right,fp);
	}

	void deSerializeTree(Node* &root,FILE *fp){
		int data;
		if(!fscanf(fp,"%d ",&data)|| data==-1){
			return;
		}
		root=new Node(data);
		deSerializeTree(root->left,fp);
		deSerializeTree(root->right,fp);
	}

	void printArr(int *arr,int n){
		cout<<"Given array"<<endl;
		for(int i=0;i<n;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
	void inorderTraversalUtil(Node *root){
		if(root==NULL)return;
		inorderTraversalUtil(root->left);
		cout<<root->data<<" ";
		inorderTraversalUtil(root->right);
	}
	void inorderTraversal(Node *root){
		cout<<"Tree Structure (inorderTraversal) "<<endl;
		inorderTraversalUtil(root);
		cout<<endl;
	}

	public:
	void serializeDeserializeTree(int arr[],int n){
		printArr(arr,n);
		createTree(arr,n);
		inorderTraversal(root);

		FILE *fp= fopen("tree.txt","w");
		if(fp==NULL){
			cout<<"Unable to open new file"<<endl;
			return;
		}
		
		serializeTree(root,fp);

		fclose(fp);

		Node *temp_root=NULL;

		fp=fopen("tree.txt","r");

		deSerializeTree(temp_root,fp);

		inorderTraversal(temp_root);

	}


};
int main(){

	int arr[]={12,9,7,1,10,11,13,14,21,15};
	int n=sizeof(arr)/sizeof(arr[0]);
	Tree *tree=new Tree();
	tree->serializeDeserializeTree(arr,n);
	return 0;
}