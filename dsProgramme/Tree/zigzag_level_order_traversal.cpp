vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    stack<TreeNode*> s1,s2;
    s1.push(root);
    vector<vector<int> > output;
    vector<int> v;
    int level=1;
    while(s1.empty()==false){
        TreeNode *node=s1.top();s1.pop();
        v.push_back(node->val);
        if(level%2==1){
            if(node->left)s2.push(node->left);
            if(node->right)s2.push(node->right);
        }
        else{
            if(node->right)s2.push(node->right);
            if(node->left)s2.push(node->left);
        }
        if(s1.empty()){
            output.push_back(v);
            v.clear();
            level++;
            stack<TreeNode*> temp=s1;
            s1=s2;
            s2=temp;
        }
    }
    return output;
}
