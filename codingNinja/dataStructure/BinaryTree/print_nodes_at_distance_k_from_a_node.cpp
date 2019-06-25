/*

Print nodes at distance k from node


Given a binary tree, a node and an integer K, print nodes which are at K distance from the the given node.
Input format :

Line 1 : Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Line 2 : Node

Line 3 : K

Output format : Answer nodes in different line

Sample Input :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
3
1
Sample Output :
9
6


*/

// Following is the Binary Tree node structure
/**************
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};
***************/
#include<vector>
#include<utility>
#include<string>
void getPathFromNodeToRoot(BinaryTreeNode<int>* root,int node,int k,vector<pair<BinaryTreeNode<int>*,string>> *v){
  if(root==NULL)return;
  if(root->data==node){
    pair<BinaryTreeNode<int>*,string> p(root,"both");
    v->push_back(p);
    return;
  }
  getPathFromNodeToRoot(root->left,node,k,v);
  
  if(v->size()>0){
    pair<BinaryTreeNode<int>*,string> p1(root,"left");
    v->push_back(p1);
    return;
  }
  else{
  	getPathFromNodeToRoot(root->right,node,k,v);
    
  	if(v->size()>0){
    	pair<BinaryTreeNode<int>*,string> p2(root,"right");
    	v->push_back(p2);
      	return;
    }
    else return;
  }
   
  
}

void printNode(BinaryTreeNode<int> *root,int k){
  if(root==NULL)return;
  if(k==0){
    cout<<root->data<<endl;
  	return;
  }
  
  printNode(root->left,k-1);
  printNode(root->right,k-1);
  
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    vector<pair<BinaryTreeNode<int>* , string > > *v=new vector<pair<BinaryTreeNode<int>*,string>>();
  	
  getPathFromNodeToRoot(root,node,k,v);

  for(int i=0; i < v->size(); i++){
    pair< BinaryTreeNode<int>*,string> p =v->at(i);
   
    if(p.second=="both"){
      printNode(p.first->left,k-1);
      printNode(p.first->right,k-1);
    }
    else if(p.second=="left"){
      if(k-i==0)
        cout<<p.first->data<<endl;
      else
    	printNode(p.first->right, k-(i+1));
    }
   	else {
      if(k-i==0)
        cout<<p.first->data<<endl;
      else
        printNode(p.first->left,k-(i+1));
    }
    
  }
  
}

