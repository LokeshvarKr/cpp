class TrieNode{
    public:
    int count;
    TrieNode **children;
    TrieNode(){
        count=0;
        children=new TrieNode*[26];
        for(int i=0;i<26;i++){
            children[i]=NULL;
        }
    }
};
void insert(TrieNode *root,string s){
    for(char c:s){
        int index=c-'a';
        if(root->children[index]==NULL){
            root->children[index]=new TrieNode();
        }
        root->count+=1;
        root=root->children[index];
    }
}
string getPrefix(TrieNode *root,string s){
    string prefix="";
    for(char c:s){
        int index=c-'a';
        prefix+=c;
        if(root->children[index]->count==1){
            break;
        }
        root=root->children[index];
    }
    return prefix;
}
vector<string> Solution::prefix(vector<string> &A){
    TrieNode *root=new TrieNode();
    for(int i=0;i<A.size();i++){
        insert(root,A[i]);
    }
    vector<string> output(A.size()); 
    for(int i=0;i<A.size();i++){
        output[i]=getPrefix(root,A[i]);
    }
    return output;
}
