#include<iostream>
using namespace std;

class AVLTree{
	private:
		class Node{
			public:
				int data;
				Node *left;
				Node *right;
				int height;
				int size;
				Node(int data){
					this->data=data;
					this->left=NULL;
					this->right=NULL;
					this->height=1;
					this->size=1;
				}
		};

		//height of sub-tree (at particular node)
		int height(Node *node){
			if(node==NULL){
				return 0;
			}
			
			return node->height;
		}
		int size(Node *node){
			if(node==NULL){
				return 0;
			}
			return node->size;
		}
		//balance factor of node in tree
		int balanceFactor(Node *node){
			if(node==NULL){
				return 0;
			}
			return height(node->left)-height(node->right);

		}
		Node *leftRotate(Node *c){
			Node *b=c->right;
			Node *T2=b->left;

			b->left=c;
			c->right=T2;
			
			//height update 
			//update height first c then b
			c->height=max(height(c->left),height(c->right)) + 1;
			b->height=max(height(b->left),height(b->right)) + 1;
			c->size=size(c->left)+size(c->right)+1;
			b->size=size(b->left)+size(b->right)+1;
			return b;
		}

		Node *rightRotate(Node *c){
			Node *b=c->left;
			Node *T2=b->right;

			b->right=c;
			c->left=T2;
			
			//height update 
			//update height first c then b
			c->height=max(height(c->left),height(c->right)) + 1;
			b->height=max(height(b->left),height(b->right)) + 1;
			c->size=size(c->left)+size(c->right)+1;
			b->size=size(b->left)+size(b->right)+1;
			return b;
		}

		Node *insert(Node *node,int data,int *count){
			if(node==NULL){
				Node *new_node=new Node(data);
				return new_node; 
			}
			if(data < node->data){
				node->left=insert(node->left,data,count);
			}
			else{
				node->right=insert(node->right,data,count);
				*count=*count+size(node->left)+1;
			}

			node->height=max(height(node->left),height(node->right)) + 1;
			node->size=size(node->left)+size(node->right)+1;

			int bf=balanceFactor(node);

			//LL 
			if(bf > 1 && data < node->left->data){
				return rightRotate(node);
			}

			//RR
			if(bf < -1 && data > node->right->data ){
				return leftRotate(node);
			}

			//LR
			if(bf > 1 && data > node->left->data){
				node->left=leftRotate(node->left);
				return rightRotate(node);
			}

			//RL
			if(bf < -1 && data < node->right->data){
				node->right=rightRotate(node->right);
				return leftRotate(node);
			}

			return node;

		}

		void inorderTraversal(Node *node){
			if(node==NULL){
				return;
			}
			inorderTraversal(node->left);
			cout<<node->data<<" ";
			inorderTraversal(node->right);
		}
		void displayAVL(Node *node){
			if(node==NULL){
				return;
			}
			if(node->left==NULL){
				cout<<" . ";
			}
			else{
				cout<<node->left->data;
			}
			cout<<" <<== "<<node->data<<" ==>> ";

			if(node->right==NULL){
				cout<<" . ";
			}
			else{
				cout<<node->right->data;
			}

			cout<<endl;
			displayAVL(node->left);
			displayAVL(node->right);
		}


	public:
		
		Node *root;

		AVLTree(){
			this->root=NULL;
		}

		void insert(int data,int *count){
			root=insert(root,data,count);
		}



		void inorderTraversal(){
			if(root==NULL){
				cout<<"Tree is Empty"<<endl;
				return;
			}
			inorderTraversal(root);
			cout<<endl;
		}
		void displayAVL(){
			if(root==NULL){
				cout<<"Tree is Empty"<<endl;
				return;
			}
			displayAVL(root);
			cout<<endl;
		}

};

void countSmallerRight(int *a,int n){
	AVLTree *tree=new AVLTree();
	int *countAns=new int[n];
	for(int i=0;i<n;i++){
		countAns[i]=0;
	}
	for(int i=n-1;i>=0;i--){
		tree->insert(a[i],&countAns[i]);
	}
	for(int i=0;i<n;i++){
		cout<<countAns[i]<<" ";
	}
	cout<<endl;
	delete []countAns;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int *a=new int[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		countSmallerRight(a,n);
		delete [] a;
	}
	
	return 0; 
}