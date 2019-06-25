#include<iostream>
#include<queue>
#include "BinaryTreeNode.h"
using namespace std;



// Print the data of bst in given range 
void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {

 if(root==NULL)return;
    if ( k1 < root->data )
     elementsInRangeK1K2(root->left, k1, k2);
 
   if ( k1 <= root->data && k2 >= root->data )
     cout<< root->data<<" " ;
 
   if ( k2 > root->data )
     elementsInRangeK1K2(root->right, k1, k2);
   
}
 

//construct a bst with sorted array
BinaryTreeNode<int>* bst(int *input, int low ,int up){
  if(low>up)
    return NULL;
  	int mid =(low+up)/2;
  BinaryTreeNode<int> *root=new BinaryTreeNode<int>(input[mid]);
  root->left=bst(input,low,mid-1);
  root->right=bst(input,mid+1,up);
  return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n) {
  
  if(n==0)return NULL;
  
  return bst(input,0,n-1);
  
}
//construct a sorted linkedlist from given bst
 
 template <typename T>
 class Node{
    public:
    T data;
    Node<T> *next;
    
    Node(T data){
        this -> data = data;
        this -> next = NULL;
    }
 };
#include<utility>
pair< Node<int>*,Node<int>* > bstToLinkedList(BinaryTreeNode<int> *root){
  
  
  pair<Node<int>*,Node<int>*> ansPair;
  if(root==NULL){
   	ansPair.first=NULL;
    ansPair.second=NULL;
    return ansPair;
  }
  
  Node<int> *newNode=new Node<int>(root->data);
  
  pair< Node<int>* , Node<int>* > leftPair=bstToLinkedList(root->left);
  pair< Node<int>* , Node<int>* > rightPair=bstToLinkedList(root->right);
  
  if(leftPair.second){
    leftPair.second->next= newNode;
    ansPair.first=leftPair.first;
  }
  else 
  {
    ansPair.first=newNode;
  }
  	newNode->next=rightPair.first;
  
  	if(rightPair.second)
  	ansPair.second=rightPair.second;
	else
      ansPair.second=newNode;
  
  return ansPair;
  
  
}
Node<int>* constructBST(BinaryTreeNode<int>* root) {
  if(root==NULL)return NULL;
  
  pair< Node<int>* , Node<int>* > ansPair=bstToLinkedList(root);
  return ansPair.first;
    
}

//check given tree is bst or not o(n) solution
// check the tree is bst or not (right method every cases will be covered )
#include<climits>
class Triplate{
  public:
    int max;
    int min;
    bool bst;
  Triplate(){
    min=INT_MAX;
    max=INT_MIN;
    bst=true;
  }
  
};
 
Triplate helper(BinaryTreeNode<int>* root)
{
	Triplate ans,ans1,ans2;  
  	if(root==NULL)
	    {
	      return ans;
	    }
 	
	  ans1=helper(root->left);
	  ans2=helper(root->right);
  
 	if(ans1.bst==false || ans2.bst==false)
	{
	    ans.bst=false;
	    return ans;
	}
	else
	{
 		if(ans1.max < root->data && ans2.min >= root->data)
  		{
    		ans.max=max(max(ans1.max,ans2.max),root->data);
    		ans.min=min(min(ans1.min,ans2.min),root->data);
       
     		return ans;
  		}
		else
	    	{
	      	ans.bst=false;
	      	return ans;
    		}
      
	
	}
  
}

bool isBST(BinaryTreeNode<int> *root){
       
  Triplate ans=helper(root);
  return ans.bst;
 
  
}  
//check given tree is bst or not 
//time compl. of this solution is same as above but code is much easy
//method 3
#include<climits>
bool isbst(BinaryTreeNode<int> *root,int min,int max){
  if(root==NULL)return true;
  if(root->data < min || root->data > max )
	return false;
 	return isbst(root->left,min,root->data-1) && isbst(root->right,root->data,max); 
}

bool isBST(BinaryTreeNode<int> *root){
  
  if(root==NULL)return true;
 return isbst(root,INT_MIN,INT_MAX); 
  
}

 
// check given tree is bst or not O(n^2) in worts and O(nlogn) best (i.e effectively O(n*h) ,his height ) solution
int minm(BinaryTreeNode<int> *root){
  if(root==NULL)
    return INT_MAX;
  return min(root->data,min(minm(root->left),minm(root->right)));
  
}

int maxm(BinaryTreeNode<int> *root){
  if(root==NULL)
    return INT_MIN;
  return max(root->data,max(maxm(root->left),maxm(root->right)));
  
}

bool isBST(BinaryTreeNode<int> *root){

  if(root==NULL)return true;
  
int leftmax=maxm(root->left);
int rightmin=minm(root->right);

return (leftmax < root->data) && (root->data <= rightmin) &&(isBST(root->left)) && (isBST(root->right)) ; 
  
  
}

//check bst or note wrong method (wrong method) don't do
// test case will fails 8 2 17 1 10 5 20 
/*
bool isBST(BinaryTreeNode<int> *root){
  
  	bool x=true,y=true;
  
  	if(root->left)
    {
      
      if(root->left->data  < root->data)
      	x=isBST(root->left);
      else
        return false;
    }
  
  	if(root->right)
    {
      if(root->right->data >= root->data)
        y=isBST(root->right);
	else
      return false;
    }
  
  if(x==true && y==true)
  return true;
  
   return false;
  
}
*/


//find path from root to given root

vector<int>* findPath(BinaryTreeNode<int> *root , int k){
   
  if(root==NULL) return NULL;
  
  vector<int> *v=new vector<int>();
  
  if(root->data==k)
  {  
    v->push_back(root->data);
    return v;
  }
  else if(k < root->data)
  {
    v=findPath(root->left,k);
    
    if(v)
      v->push_back(root->data);
    return v;
  }
  
  else //(k> root->data)
  {
   	v= findPath(root->right,k);
  
    if(v)
  		v->push_back(root->data);
   	return v;
  }
  
}

 BinaryTreeNode<int> *takeInput(){
	int rootdata;
	cout<<"Enter data (-1 treated as NULL)"<<endl;
	cin>>rootdata;

	if(rootdata==-1)return NULL;

	BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootdata);
	BinaryTreeNode<int> *leftChild=takeInput();
	BinaryTreeNode<int> *rightChild=takeInput();
	root->left=leftChild;
	root->right=rightChild;
	return root;
}

void printTreeLevelWise(BinaryTreeNode<int> *root){
	if(root==NULL) return; 
	
	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	
	while(!q.empty()){
		BinaryTreeNode<int> *temp=q.front();
		q.pop();

		cout<<temp->data<<":";
		if(temp->left){
		cout<<"L"<<temp->left->data<<" ";
		q.push(temp->left);
		}
	
		if(temp->right){
		cout<<"R"<<temp->right->data;
		q.push(temp->right);
		}
		
		cout<<endl;
	}

}
void printTree(BinaryTreeNode<int> *root){

	if(root==NULL)return;

	cout<<root->data<<":";
	if(root->left)cout<<"L"<<root->left->data;
	if(root->right)cout<<",R"<<root->right->data;
	cout<<endl;
	printTree(root->left);
	printTree(root->right);

}

int main(){

	BinaryTreeNode<int> *root=takeInputLevelWise();
	printTreeLevelWise(root);
	cout<<"No. of Nodes is "<<countNodes(root)<<endl;
	Pair p=diameterOfBinaryTree(root);
	cout<<"diameter is "<<p.diameter<<endl;
	delete root;
	return 0;

}


