//copy input instance 10 3 20 30 40 2 50 60 3 70 80 90 2 100 110 0 0 3 120 130 140 2 150 160 0 0 0 0 0 0 0 0

#include<iostream>
#include<queue>
#include "TreeNode.h"

// find nextlarger element of given number in the tree
//method (1) using queue

TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n) {
   
    if(root==NULL)return NULL;
  	
  TreeNode<int> *temp,*ans;
 
  if(root->data>n)
 	ans=root;
  else
    ans=NULL;
  
  queue<TreeNode<int>*> q;
  
  q.push(root);
  
  while(!q.empty()){
    temp=q.front();
     q.pop();
    
    if(temp->data > n){
      if(ans==NULL)
      ans=temp;
      else if(temp->data < ans->data)
        ans=temp;
    }
    
    for(int i =0; i < temp->children.size(); i++){
    q.push(temp->children.at(i));
  	}
   
  }
 return  ans;

}


// find nextlarger element of given number in the tree
//method (2) using recursion

TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n) {
	
  if(root==NULL)return NULL;
  
  TreeNode<int> *ans=NULL,*temp=NULL;
  if(root->data > n)
    ans=root;
  
  for(int i=0; i < root->children.size();i++){
    temp=nextLargerElement(root->children.at(i),n);
    if(temp){
      	if(ans==NULL)
        ans=temp;
    	else if(temp->data < ans->data)
      	ans=temp;
    }
  }
  
  return ans;
}
 
//find the total no. of leaf in the tree
int numLeafNodes(TreeNode<int>* root) {
	if(root==NULL)return 0;
  	if(root->children.size()==0)
      return 1;
  int k=0;
  for(int i=0;i<root->children.size();i++){
    k+=numLeafNodes(root->children.at(i));
  }
  return k;
}


// find height of tree
int height(TreeNode<int>* root){
  if(root==NULL)return 0;
  int h1=1;
  int h=0;
  for(int i=0;i<root->children.size();i++){
    h1=height(root->children.at(i));
    if(h1>h)
      h=h1;
  }
  return h+1;
}

// is two tree are identical

bool isIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
   
  	if(root1==NULL && root2==NULL)return true;
  	if(root1==NULL || root2==NULL) return false;
  	if(root1->data!=root2->data)return false;
  
  	int n1=root1->children.size();
  	int n2=root2->children.size();
  
  if(n1!=n2)return false;
  
  bool ans=true;
  for(int i=0;i<n1;i++){
    ans=isIdentical(root1->children.at(i),root2->children.at(i));
    if(ans==false)
      return false;
  }
  return ans;
}


//find the node whose children and itself sum is greater 

//Method (1)
TreeNode<int>* maxSumNode(TreeNode<int> *root){
   
  if(root==NULL)return NULL;
  TreeNode<int> *ans=NULL,*temp=NULL;
	int x,max=0;
  
  queue<TreeNode<int>*> q;
  q.push(root);
  
  while(!q.empty()){
    temp=q.front();
    q.pop();
      x=temp->data;
    for(int i=0;i<temp->children.size();i++){
    x+=temp->children.at(i)->data;
    q.push(temp->children.at(i));
  	}
    if(x>max){
      max=x;
      ans=temp;
    }
  }
  return ans;
}


// Method (2)

/*
class Pair{
  public:
  TreeNode<int> *node;
  int sum;
};
Pair helperFunctionForMaxSumNode(TreeNode<int>* root){
   
  TreeNode<int> *ans=NULL;
	int max=0;
  
  ans=root;
  max=root->data;

 
  for(int i=0;i<root->children.size();i++){
  max+=root->children.at(i)->data;
  }
  
   Pair p1;
  
  for(int i=0;i<root->children.size();i++){
  p1=helperFunctionForMaxSumNode(root->children.at(i));
    if(p1.sum > max){
      ans=p1.node;
      max=p1.sum;
    }
  }
  
  p1.node=ans;
  p1.sum=max;
  
  return p1;
}

TreeNode<int>* maxSumNode(TreeNode<int> *root){
  if(root==NULL)return NULL;
  Pair ans=helperFunctionForMaxSumNode(root);
  return ans.node;
}
*/


//find the max node value of tree
TreeNode<int>* maxDataNode(TreeNode<int>* root) {
  if(root==NULL)return NULL;
  
  TreeNode<int> *max=root;
  	 TreeNode<int> *temp;
  	for(int i=0;i<root->children.size();i++){
      temp=maxDataNode(root->children.at(i));
     	if(temp->data>max->data)
          max=temp;
    }
  return max;
}


//find no. of nodes greater than x
int nodesGreaterThanX(TreeNode<int> *root, int x){
	if(root==NULL)return 0;
  	int ans=0;
  	if(root->data>x)
      	ans=1;
  	for(int i=0;i<root->children.size();i++){
   	ans+=nodesGreaterThanX(root->children.at(i),x);
  	}
  return ans;
}

//find sum of all nodes
int sumOfNodes(TreeNode<int>* root){
    	int sum=root->data;
  	for(int i=0;i<root->children.size();i++){
	sum+=sumOfNodes(root->children.at(i));
	}
  	return sum;
}

//find no. of nodes in the tree
int NumbersOfNode(TreeNode<int> *root){
	if(root==NULL)return 0;
	int k=0;
	for(int i=0;i<root->children.size();i++){
	k=k+NumbersOfNode(root->children.at(i));
	}
	return (k+1);
}


//take input level wise
TreeNode<int>* takeTreeInputLevelwise(){

	int rootdata,n;
	cout<<"Enter data"<<endl;
	cin>>rootdata;

	TreeNode<int> *root=new TreeNode<int>(rootdata);
	
	queue<TreeNode<int>*> pendingNodes;

	pendingNodes.push(root);

	while(!pendingNodes.empty()){
	TreeNode<int> *resumeNode=pendingNodes.front();
	pendingNodes.pop();
	cout<<"Enter no. of child of "<<resumeNode->data<<endl;
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<"Enter children of "<<resumeNode->data<<endl;
		cin>>rootdata;
		TreeNode<int> *child=new TreeNode<int>(rootdata);
		resumeNode->children.push_back(child);
		pendingNodes.push(child);
		}

	}
return root;
}


//take input for tree 
TreeNode<int>* inputTree()
{
	int rootdata,n;
	cout<<"Enter data"<<endl;
	cin>>rootdata;
	TreeNode<int> *root=new TreeNode<int>(rootdata);
	cout<<"Enter no. of children of "<<rootdata<<endl;
	cin>>n;

	for(int i=0;i<n;i++){
	TreeNode<int> *child=inputTree();
	root->children.push_back(child);
	}

	return root;
}

//preOrder traversal
void preOrderTraversal(TreeNode<int> *root){
	if(root==NULL)return;
	cout<<root->data<<" ";
	for(int i=0;i<root->children.size();i++){
	preOrderTraversal(root->children.at(i));
	}
}


//posrOrder traversal
void postOrder(TreeNode<int>* root){
    
  if(root==NULL)return;
  for(int i=0;i<root->children.size();i++){
    postOrder(root->children.at(i));
  }
  cout<<root->data<<" ";

}

//print all at level k
void printAtLevel_k(TreeNode<int> *root,int k){
	if(root==NULL)return;
	if(k==0){
	cout<<root->data<<" ";
	return;
	}
	for(int i=0;i<root->children.size();i++){
	printAtLevel_k(root->children.at(i),k-1);
	}
}


//print level wise
void printLevelWise(TreeNode<int>* root){
	queue<TreeNode<int>*>q;
	q.push(root);
	while(!q.empty()){
	TreeNode<int> *node=q.front();
	cout<<node->data<<":";
    	int n=node->children.size();
    		if(n>0){
      		int i=0;
    			while(i<n-1){
      			cout<<node->children.at(i)->data<<",";
      			q.push(node->children.at(i));
      			i++;
    			}
    
    		cout<<node->children.at(n-1)->data;
    		q.push(node->children.at(n-1));
      
    		}
	cout<<endl;
	q.pop();
	}
  
}

//print tree
void printTree(TreeNode<int>* root)
{
	if(root==NULL)return; //this is edge case not a base case;
	
	cout<<root->data<<":";
	for(int i=0;i<root->children.size();i++){
		cout<<root->children.at(i)->data<<",";
	}
	cout<<endl;

	for(int i=0;i<root->children.size();i++){
		printTree(root->children.at(i));
	}

}

int main()
{

	TreeNode<int> *root=takeTreeInputLevelwise();

	cout<<"Tree is "<<endl;
	printTree(root);

	cout<<"print levelwise"<<endl;
	printLevelWise(root);

	cout<<"Numers of Nodes :--- "<<endl;
	cout<<NumbersOfNode(root)<<endl;
	
	int k;
	cout<<"print all nodes at level k : enter k"<<endl;
	cin>>k; 
	printAtLevel_k(root,k);
	cout<<endl;
	
	cout<<"pre order traversal"<<endl;
	preOrderTraversal(root);
	cout<<endl;

	
return 0;
}
