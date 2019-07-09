//method 1
/*
bool find_node(TreeNode* root, int a,vector<int> &v){
   if(root==NULL)return false;
   if(root->val==a){
       v.push_back(root->val);
       return true;
   }
   if(find_node(root->left,a,v)){
       v.push_back(root->val);
       return true;
   }
   if(find_node(root->right,a,v)){
      v.push_back(root->val);
       return true;
   }
   return false;
 }
int Solution::lca(TreeNode* root, int a, int b){
   vector<int> v1;
   vector<int> v2;
   find_node(root,a,v1);
   find_node(root,b,v2);
   if(v1.size()==0 || v2.size()==0)return -1;
   int i=v1.size()-1;
  int j=v2.size()-1;
  while(i>=0 && j>=0 && v1[i] == v2[j]){
      i--;j--;
  }
   return v1[i+1];
}

*/

//method 2

bool find_node(TreeNode* root,int val){
    if(root==NULL)return false;
    if(root->val==val)return true;
    bool x=find_node(root->left,val);
    if(x)return true;
    return find_node(root->right,val);
}
TreeNode *LCA(TreeNode *root,int a,int b){
    if(root==NULL)return NULL;
    if(root->val==a || root->val==b)return root;
    TreeNode *left=LCA(root->left,a,b);
    TreeNode *right=LCA(root->right,a,b);
    if(left && right)return root;
    return (left ? left :right);
}
int Solution::lca(TreeNode* root, int a, int b){
    bool x=find_node(root,a);
    bool y=find_node(root,b);
    if(x==false || y==false){
        return -1;
    }
    TreeNode *ans=LCA(root,a,b);
    return ans->val;
}