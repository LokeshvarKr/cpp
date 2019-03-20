#include<iostream>
#include<string>
#include"TrieNode.h"
using namespace std;
class Trie{
	private:
		TrieNode *root;

	public:
		Trie(){
			root=new TrieNode('\0');
		}
		
		~Trie(){
			delete root;
		}
		

	private:
		void insert(TrieNode *root,string word){
			
			//base case
			if(word.size()==0){
				root->isTerminal=true;
				return;
			}

			//small calculation
			TrieNode *child=NULL;
			int index=word[0]-'a';
			if(root->children[index]!=NULL){
				child=root->children[index];
			}
			else {
				child=new TrieNode(word[0]);
				root->children[index]=child;
			}

			//recursion
			insert(child,word.substr(1));

		}

    
    	bool search(TrieNode *root,string word) {
        	
      		//base case
      		if(word.size()==0){
        		if(root->isTerminal==true)
          			return true;
        		else 
        			return false;
      		}
      
      			//small calculation
      		int index=word[0]-'a';
      		TrieNode *child=NULL;
      		if(root->children[index]!=NULL){
          		child=root->children[index];
      		}
      		else
        		return false;
        
      
      		//recursion
      		return search(child,word.substr(1));
      
    	}

    	void remove(TrieNode *root,string word){
    		
    		//base case
    		if(word.size()==0){
    			root->isTerminal=false;
    			return;
    		}

    		//small calulation
    		int index=word[0]-'a';
    		TrieNode *child=NULL;
    		if(root->children[index]!=NULL){
    			child=root->children[index];
    		}
    		else		 
			return;

    		//recursion
    		remove(child,word.substr(1));

    		
    		//remove child node if it is useless
    		if(child->isTerminal==false){
    			for(int i=0;i<26;i++){
    				if(child->children[index]!=NULL)
    					return;
    			}

    		delete child;
    		root->children[index]=NULL;
		
		}

    	}

	public:
		void insert(string word){
			insert(root,word);
		}

		bool search(string word){
      			return search(root,word);
    		}

    		void remove(string word){
    			remove(root,word);
    		}

};

int main(){

Trie t;
t.insert("hi");
t.insert("ho");
t.remove("hi");
cout<<t.search("ho")<<endl;
/*
t.insert("humanity");
t.insert("hangama");
t.insert("yes");
t.insert("dictionary");
t.insert("my");
t.insert("mine");
t.insert("lovely");
t.insert("ramayana");
t.insert("mahabharata");
t.insert("elephant");
t.insert("innosence");
t.insert("guilty");
t.insert("panished");
t.insert("placement");
t.insert("recruiters");
t.insert("interview");
t.insert("interviewer");
t.insert("interviewee");

cout<<"hllo : "<<t.search("hllo")<<endl;
cout<<"hi : "<<t.search("hi")<<endl;
cout<<"interviewee : "<<t.search("interviewee")<<endl;
cout<<"interviewer : "<<t.search("interviewer")<<endl;
cout<<"recruitement : "<<t.search("recruitement")<<endl;
cout<<"hangama : "<<t.search("hangama")<<endl;

t.remove("interviewee");
//t.remove("interviewer");
t.remove("recruitement");
t.remove("hangama");

cout<<"after remove"<<endl;

cout<<"interviewee : "<<t.search("interviewee")<<endl;
cout<<"interviewer : "<<t.search("interviewer")<<endl;
cout<<"recruitement : "<<t.search("recruitement")<<endl;
cout<<"hangama : "<<t.search("hangama")<<endl;


cout<<"my : "<<t.search("my")<<endl;
cout<<"elephant : "<<t.search("elephant")<<endl;
cout<<"lovely : "<<t.search("lovely")<<endl;
cout<<"hllo : "<<t.search("hllo")<<endl;
cout<<"hi : "<<t.search("hi")<<endl;

*/
return 0;

}





















