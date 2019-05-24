template <typename T>
class AVLTree{
private:
	class Node{
	public:
		T data;
		Node *left,*right;
		int height;
		Node(T data){
			this->data=data;
			this->left=NULL;
			this->right=NULL;
			this.height=0;
		}
		~Node(){
			delete this->left;
			delete this->right;
		}
	};

public:
	Node *root;
	AVLTree(){
		root=NULL;
	}
	~AVLTree(){
		delete root;
	}

private:
	void inorderUtil(Node *root){
		if(root==NULL)return;
		inorderUtil(root->left);
		cout<<root->data<<" ";
		inorderUtil(root->right);
	}
	void preOrderUtil(Node *root){
		if(root==NULL)return;
		cout<<root->data<<" ";
		preOrderUtil(root->left);
		preOrderUtil(root->right);
	}
	void postOrderUtil(Node *root){
		if(root==NULL)return;
		postOrderUtil(root->left);
		postOrderUtil(root->right);
		cout<<root->data<<" ";
	}
	Node* insertAVL(Node *root,T data){
		if(root==NULL)return new Node(data);
		if(data < root->data){
			insertAVL(root->left);
		}
		else if(data > root->data){
			insertAVL(root->right);
		}
	}
public:
	void insert(T data){
		head=insertAVL(root,data);
	}
	void inorder(){
		inorderUtil(root);
		cout<<endl;
	}
	void preOrder(){
		preOrderUtil(root);
		cout<<endl;
	}
	void postOrder(){
		postOrderUtil(root);
		cout<<endl;
	}

};