/*

Largest BST

Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree.
Return the height of largest BST.
Input format :

Line 1 : Elements in level order form (separated by space)

(If any node does not have left or right child, take -1 in its place)

Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2


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

#include<climits>

class bst_tuple {
  public:
  	int min;
  	int max;
  	int h;
  	bool bst;
  
};


bst_tuple largestBSTSubtree_helper(BinaryTreeNode<int> *root){
  
   bst_tuple ans;
  
  if(root==NULL){
    ans.min=INT_MAX;
    ans.max=INT_MIN;
    ans.h=0;
    ans.bst=true;
    return ans;
  }
  
  bst_tuple ans1,ans2;
  
  ans1=largestBSTSubtree_helper(root->left);
  ans2=largestBSTSubtree_helper(root->right);
  

  if(ans1.bst && ans2.bst){
    if(root->data > ans1.max && root->data < ans2.min){
      ans.h=1+max(ans1.h,ans2.h);
      ans.min=min( min(ans1.min , root->data) , ans2.min);
      ans.max=max( max(ans2.max , root->data) , ans1.max);
      ans.bst=true;
    }
    else {
      ans.h=max(ans1.h,ans2.h);
      ans.min=min( min(ans1.min , root->data) , ans2.min);
      ans.max=max( max(ans2.max , root->data) , ans1.max);
      ans.bst=false;
    }
    
  }
  
  else {
      ans.h=max(ans1.h,ans2.h);
      ans.min=min( min(ans1.min , root->data) , ans2.min);
      ans.max=max( max(ans2.max , root->data) , ans1.max);
      ans.bst=false;
  }
  
  return ans;
  
}



int largestBSTSubtree(BinaryTreeNode<int> *root) {
    if(root==NULL)return 0;
  
 bst_tuple ans = largestBSTSubtree_helper(root);
  return ans.h;

}




