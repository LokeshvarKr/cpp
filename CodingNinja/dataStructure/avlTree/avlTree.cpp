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
	
				Node(int data){
					this->data=data;
					this->left=NULL;
					this->right=NULL;
					this->height=1;
				}
		};

		//height of sub-tree (at particular node)
		int height(Node *node){
			if(node==NULL){
				return 0;
			}
			
			return node->height;
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
			return b;
		}

		Node *insert(Node *node,int data){
			if(node==NULL){
				Node *new_node=new Node(data);
				return new_node; 
			}
			if(data < node->data ){
				node->left=insert(node->left,data);
			}
			else{
				node->right=insert(node->right,data);
			}

			node->height=max(height(node->left),height(node->right)) + 1;

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

		void insert(int data){
			root=insert(root,data);
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

int main(){
	/*
	AVLTree tree;
	tree.insert(10);
	tree.insert(20);
	tree.insert(5);
	tree.inorderTraversal();
	
	*/
	AVLTree *tree=new AVLTree();
	int option;
	int data;
	while(true){
		cout<<"0 for quit"<<endl;
		cout<<"1 for insert"<<endl;
		cout<<"2 for inorderTraversal"<<endl;
		cout<<"3 for displayAVL"<<endl;
		cin>>option;
		if(option==0){
			break;
		}
		switch(option){
			case 1:
				cout<<"Enter data(integer)"<<endl;
				cin>>data;
				tree->insert(data);
				break;
			case 2:
				tree->inorderTraversal();
				break;
			case 3:
				tree->displayAVL();
				break;
			default:
				cout<<"wrong option"<<endl;
				break;
		}
	}
	
	return 0; 
}