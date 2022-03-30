/***********Second Largest Element In Tree********************

Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output Format :
The first and only line of output contains data of the node with second largest data.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40
***************************************************************/


/************************************************************

    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

pair<TreeNode<int>*,TreeNode<int>*> getSecondLargestNodeUtil(TreeNode<int>* root){
    pair<TreeNode<int>*,TreeNode<int>*> result;
    result.first=root;
    result.second=NULL;
    
    for(int i=0; i<root->children.size(); i++){
		pair<TreeNode<int>*,TreeNode<int>*> p = getSecondLargestNodeUtil(root->children[i]);
        if(p.first->data > result.first->data){
            if((p.second) && (p.second->data > result.first->data)){
				result=p;
            }
            else{
                result.second=result.first;
                result.first=p.first;
            }
        }
        else{
            if(result.first->data!=p.first->data && (result.second==NULL || 
                p.first->data > result.second->data)){
            		result.second=p.first;
        	}
        }
    }
    
    return result;
}
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    if(root==NULL)return NULL;
    pair<TreeNode<int>*,TreeNode<int>*> p = getSecondLargestNodeUtil(root);
    return p.second;
}
