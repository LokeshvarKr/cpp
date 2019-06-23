

//solution using dfs algo and hash_map data structure

#include<unordered_map>
#include<unordered_set>

void getParent(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &m){
    if(root==NULL)return;
    if(root->left){
        m[root->left]=root;
        getParent(root->left,m);
    }
    if(root->right){
        m[root->right]=root;
        getParent(root->right,m);
    }
}
vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    vector<int> output;
    if(root==NULL || target==NULL)output;
    
    unordered_map<TreeNode*,TreeNode* > m;
    getParent(root,m);

    unordered_set<TreeNode*> visited;
    //do bfs (on tree using the above hash)
    queue<TreeNode*> q;
    q.push(target);
    q.push(NULL);
    visited.insert(target);
    int level=0;
    TreeNode* temp;
    while(q.front()!=NULL){
        if(level==K){
            break;
        }
        
        temp=q.front();q.pop();
        if(temp->left && visited.find(temp->left)==visited.end()){
            q.push(temp->left);
            visited.insert(temp->left);
        }
        
        if(temp->right && visited.find(temp->right)==visited.end()){
            q.push(temp->right);
            visited.insert(temp->right);
        }
        
        if( (m.find(temp)!=m.end()) && (visited.find(m[temp])==visited.end())){
            q.push(m[temp]);
            visited.insert(m[temp]);
        }
        if(q.front()==NULL){
            q.pop();
            level+=1;
            q.push(NULL);
        }
    }
    cout<<endl;
    while(q.front()){
        output.push_back(q.front()->val);
        q.pop();
    }
    return output;
    
}