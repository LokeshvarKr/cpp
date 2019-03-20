
// eg 1 2 3 4 5 6  7 8 -1 100 9 -1 10 7 8 -1 11 -1 -1 -1 -1 -1 -1 -1 -1 -1 -1  12 13 -1 -1 -1 -1 


#include<iostream>
#include<queue>
#include "BinaryTreeNode.h"
using namespace std;

class Pair{
public:
int diameter;
int height;
	Pair(){
	diameter=0;
	height=0;
	}
};

class PairAns {
    public :
        int min;
        int max;
 };


//find min and max in binary tree
#include<climits>
PairAns minMax(BinaryTreeNode<int> *root) {
  	if(root==NULL){
     PairAns ans;
      ans.min=INT_MAX;
      ans.max=INT_MIN;
      return ans;
    }
  
  	PairAns left=minMax(root->left);
  	PairAns right=minMax(root->right);
  	PairAns rootAns;
  
  	rootAns.min=min(min(left.min,right.min),root->data);
  	rootAns.max=max(max(left.max,right.max),root->data);
  	return rootAns;
}


//convert each level as a linked list

/*
Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.

Sample Input :

5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output :

5 
6 10 
2 3 
9
*/
vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
  	vector<node<int>*> v;	
    if(root==NULL)return v;
  	
  	
  	queue<BinaryTreeNode<int>*> q;
  	q.push(root);
  	q.push(NULL);
  	node<int> *head=NULL,*h=NULL;
  
  while(!q.empty()){
    	
    head=NULL;
    h=NULL;
    while(q.front()){
      	
        BinaryTreeNode<int> *front=q.front();
      	q.pop();
        node<int> *temp=new node<int>(front->data);
        
        if(head==NULL){
      	head=temp;
         h=head;
        }
      
      else{
        h->next=temp;
        h=h->next;
      }
      
      if(front->left){
      q.push(front->left);
      }
      if(front->right){
        q.push(front->right);
      }
    }
    
    v.push_back(head);
    
    q.push(NULL);
    q.pop();
    if(q.front()==NULL) break;
    
  }

  return v;
}

//delete all leaf of tree
BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    if(root==NULL)return NULL;
  	if(root->left==NULL && root->right==NULL){
      delete root;
  	return NULL;
    }
  BinaryTreeNode<int> *temp1,*temp2;
  if(root->left){
	temp1=removeLeafNodes(root->left);
	root->left=temp1;
  }
  if(root->right){
  	temp2=removeLeafNodes(root->right);
  	root->right=temp2;
  }
  	
return root;
  
}


//Level order traversal

/*
Given a binary tree, print the level order traversal. Make sure each level start in new line.

Input format :

Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.

Output Format :

Elements are printed level wise, each level in new line (separated by space).

Sample Input :

5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1

Sample Output :

5 
6 10 
2 3 
9
*/
//method (1) more efficient code to print level wise
void printLevelATNewLine(BinaryTreeNode<int> *root) {
    if(root==NULL)return;
  	
  	queue<BinaryTreeNode<int>*> q;
  	q.push(root);
  	q.push(NULL);
  
  while(!q.empty()){
      while(q.front()){
      BinaryTreeNode<int> *front=q.front();
      q.pop();
      cout<<front->data<<" ";
      if(front->left){
        q.push(front->left);
      }
      if(front->right){
        q.push(front->right);
      }
    }
    cout<<endl;
    q.push(NULL);
    q.pop();
    if(q.front()==NULL)break;
    
  }
}

//method (2) basic approach using two queue to print level wise
void printLevelATNewLine(BinaryTreeNode<int> *root) {
    if(root==NULL)return;
  	
  	queue<BinaryTreeNode<int>*> q1,q2;
  	q1.push(root);
  
  while(!q1.empty() || !q2.empty()){
  	while(!q1.empty()){
      BinaryTreeNode<int> *front=q1.front();
      q1.pop();
      cout<<front->data<<" ";
      if(front->left){
        q2.push(front->left);
      }
      if(front->right){
        q2.push(front->right);
      }
    }
     cout<<endl;
  while(!q2.empty()){
      BinaryTreeNode<int> *front=q2.front();
      q2.pop();
      cout<<front->data<<" ";
      if(front->left){
        q1.push(front->left);
      }
      if(front->right){
        q1.push(front->right);
      } 
    }
      cout<<endl;
    
  }
}
//print tree in zig-zag (using two stak)

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
  if(root==NULL)return;
  
  stack<BinaryTreeNode<int>*> s1,s2;
  
  s1.push(root);
  
  while(!s1.empty() || !s2.empty()){
    
    while(!s1.empty()){
    	BinaryTreeNode<int> *front=s1.top();
    	s1.pop();
    	cout<<front->data<<" ";
    
    	if(front->left){
      	s2.push(front->left);
    	}
    
    	if(front->right){
      	s2.push(front->right);
    	}
    }
    cout<<endl;
    while(!s2.empty()){
        BinaryTreeNode<int> *front=s2.top();
		s2.pop();
      	
      	cout<<front->data<<" ";
    
    	if(front->right){
      	s1.push(front->right);
    	}
    
    	if(front->left){
      	s1.push(front->left);
    	} 
    }
    cout<<endl;
  }
}
 


//Print all nodes that don’t have sibling

/*Given a Binary Tree, print all nodes that don’t have a sibling (a sibling is a node that has same parent. In a Binary Tree, there can be at most one sibling). Root should not be printed as root cannot have a sibling.
*/

void nodesWithoutSibling(BinaryTreeNode<int> *root) {
    // Write your code here
	
  if(root==NULL || (root->left==NULL && root->right==NULL))return ;
   
  if(root->left && root->right==NULL){
    cout<<root->left->data<<endl;
    nodesWithoutSibling(root->left);
  }
  if(root->right && root->left==NULL){
    cout<<root->right->data<<endl;
    nodesWithoutSibling(root->right);
  }
  if(root->left && root->right){
        nodesWithoutSibling(root->left);
        nodesWithoutSibling(root->right);
    
  }
  
}


//check whether balanced or not
#include<utility>
#include<cmath>
pair<int,bool> helperFunc(BinaryTreeNode<int> *root){
  if(root==NULL){
    pair<int,bool> p;
    p.first=0;
    p.second=true;
    return p;
  }
  
  pair<int,bool> left=helperFunc(root->left);
  pair<int,bool> right=helperFunc(root->right);
  
  pair<int,bool> ans;
  
  if(left.second==false || right.second==false){
    ans.second=false;
    return ans;
  }
  
  int x=abs(left.first-right.first);
  if(x>1){
    ans.second=false;
    return ans;
  }
  
  ans.first=1+max(left.first,right.first);
   ans.second=true;
  return ans;
}
bool isBalanced(BinaryTreeNode<int> *root) {
    // Write your code here
	pair <int,bool> p=helperFunc(root);
  	return p.second;
}

//sum of all nodes
int sumOfAllNodes(BinaryTreeNode<int>* root) {
    // Write your code here
	if(root==NULL)return 0;
  	return root->data+sumOfAllNodes(root->left)+sumOfAllNodes(root->right);
   
  
}

//Diameter of tree time comp. o(n) solution 
Pair diameterOfBinaryTree(BinaryTreeNode<int> *root){
	if(root==NULL){
	Pair ans;
	return ans;
	}

	Pair left=diameterOfBinaryTree(root->left);
	Pair right=diameterOfBinaryTree(root->right);
	int h=1+max(left.height,right.height);
	int d=max(left.height+right.height,max(left.diameter,right.diameter));
	Pair p;
	p.height=h;
	p.diameter=d;
	return p;

}

//Diameter of tree time comp. o(n*h) i.e, best case o(nlogn) and worst case o(n^2) 


/*
int height(BinaryTreeNode<int> *root){

	if(root==NULL)return -1;

	return max(height(root->left),height(root->right))+1;

}

int diameterOfBinaryTree(BinaryTreeNode<int> *root){
	//Diameter of tree time comp. o(n*h) i.e, best case o(nlogn) and worst case o(n^2) 
	if(root==NULL || (root->left==NULL && root->right==NULL))return 0;

	int option1=height(root->left)+height(root->right)+2;
	int option2=diameterOfBinaryTree(root->left);
	int option3=diameterOfBinaryTree(root->right);
	
	return max(option1,max(option2,option3));

}
*/


 
//construct tree using inorder , preoreder
int search(int *inorder,int size,int x){
	
  for(int i=0;i<size;i++)
    if(inorder[i]==x)
      return i;
}
BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    
  if(preLength==0 && inLength==0)
    return NULL;
  BinaryTreeNode<int> *root=new BinaryTreeNode<int>(preorder[0]);
  int inRootIndex=search(inorder,inLength,preorder[0]);
  root->left=buildTree(preorder+1,inRootIndex,inorder,inRootIndex);
  root->right=buildTree(preorder+inRootIndex+1,preLength-inRootIndex-1,
                                            inorder+inRootIndex+1,inLength-inRootIndex-1);
  
  return root;

}


//construct tree using inorder ,postorder (postorder and preorder may subtree of the tree)
BinaryTreeNode<int> *helperFunc(int *post,int *in,int PostS,int PostE,int InS,int InE){
  
  if(PostS>PostE)return NULL;
  
  int rootData=post[PostE];
  int rootIndex=-1;

  //search rootIndex in preorder
  for(int i=InE;i>=InS;i--){
    if(in[i]==rootData){
      rootIndex=i;
      break;
    }
  }

  
  int r=InE-rootIndex;
  
  int lPostS=PostS;
  int lPostE=PostE-r-1;
  int lInS=InS;
  int lInE=InE-r-1;
  int rPostS=PostE-r;
  int rPostE=PostE-1;
  int rInS=InE-r;
  int rInE=InE;
  
  BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootData);
  
  root->left=helperFunc(post,in,lPostS,lPostE,lInS,lInE);
  root->right=helperFunc(post,in,rPostS,rPostE,rInS,rInE);
  
  return root;
  
}

BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder, int postLength, 
                                                    	int *inorder, int inLength) {
//construct tree using postorder and inorder
if(postLength==0 || inLength==0)return NULL;

  int PostS=0;
  int PostE=postLength-1;
  int InS=0;
  int InE=inLength-1;
  BinaryTreeNode<int> *root=helperFunc(postorder,inorder,PostS,PostE,InS,InE);
  return root;

}

//mirror the given tree (Method 1)
/*void mirrorBinaryTree(BinaryTreeNode<int>* root) {
  
 if(root==NULL)return;
  
  BinaryTreeNode<int> *leftChild=root->left;
  BinaryTreeNode<int> *rightChild= root->right;
  
  root->left=rightChild;
  root->right=leftChild;
  
  mirrorBinaryTree(root->left);
  mirrorBinaryTree(root->right);
  
}
*/


// mirror the given tee (method 2)
BinaryTreeNode<int> *mbt(BinaryTreeNode<int> *root){
  
   if(root==NULL || (root->left==NULL && root->right==NULL))return root;
  
  BinaryTreeNode<int> *leftChild=mbt(root->left);
  BinaryTreeNode<int> *rightChild=mbt(root->right);
  root->left=rightChild;
  root->right=leftChild;
  
  return root;
  
}
void mirrorBinaryTree(BinaryTreeNode<int>* root) {
//mirror of given tree see mtb()(helper function) above   
  root=mbt(root);

}

// find height of tree
int treeHeight(BinaryTreeNode<int> *root){
	if(root==NULL)
      return 0;
  	int x=treeHeight(root->left);
  	int y=treeHeight(root->right);
  return (1 + (x>y?x:y));
}



// check tree node is present?

/*
bool isNodePresent(BinaryTreeNode<int>* root, int x) {
   
	if(root==NULL)return false;
  	if(root->data==x )return true;
  	bool p=false;
  	bool q=false;
  	if(root->left)
       p=isNodePresent(root->left,x);
  	if(root->right)
      q=isNodePresent(root->right,x);
  
  	if(p||q) return true;
  return false;
}
*/


//check tree node is present?
// more efficient than above code
bool isNodePresent(BinaryTreeNode<int>* root, int x) {
	if(root==NULL)return false;
  	if(root->data==x )return true;
       if(isNodePresent(root->left,x) || isNodePresent(root->right,x))
  		return true;
  return false;
}


//find pair of Nodes of given sum
#include<vector>
#include<algorithm>
void treeToArray(BinaryTreeNode<int> *root,vector<int> *v){
  if(root==NULL)return ;
  v->push_back(root->data);
  treeToArray(root->left,v);
  treeToArray(root->right,v);
}
void nodesSumToS(BinaryTreeNode<int> *root, int sum) {
vector<int> *v =new vector<int>();
  
  treeToArray(root,v);
  
  sort(v->begin(),v->end());
  
 	int i=0,j=v->size()-1;
  	while(i<j){
      
      	if(v->at(i)+v->at(j)==sum){
      	cout<<v->at(i)<<" "<<v->at(j)<<endl;
    	}
    	if(v->at(i)+v->at(j)<sum){
      	i++;
    	}
      
    	else j--;
  }
  
}

//count tree nodes
int countNodes(BinaryTreeNode<int> *root){
if(root==NULL)return 0;
else return (1+countNodes(root->left)+countNodes(root->right));
}

BinaryTreeNode<int> *takeInputLevelWise(){

	int rootdata;
	cout<<"Enter data (-1 treated as NULL )"<<endl;
	cin>>rootdata;
	if(rootdata==-1)
	return NULL;

	BinaryTreeNode<int> *root=new BinaryTreeNode<int>(rootdata);

	queue<BinaryTreeNode<int>*> q;
	q.push(root);

	while(!q.empty()){
		BinaryTreeNode<int> *temp=q.front();
		q.pop();

		cout<<"Enter left child of "<<temp->data<<endl;
		cin>>rootdata;
		if(rootdata!=-1){
		BinaryTreeNode<int> *leftChild=new BinaryTreeNode<int>(rootdata);
		temp->left=leftChild;
		q.push(leftChild);
		}

		cout<<"Enter right child of "<<temp->data<<endl;
		cin>>rootdata;
		if(rootdata!=-1){
		BinaryTreeNode<int> *rightChild=new BinaryTreeNode<int>(rootdata);
		temp->right=rightChild;
		q.push(rightChild);
		}
	
	}

return root;

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




