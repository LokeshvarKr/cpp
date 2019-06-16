#include<iostream>
using namespace std;
class Trie{

private:

	class TrieNode{

		public:
		
			char data;
			TrieNode **child;
			bool end_word;
			int height;
			
			TrieNode(char data){
				this->data=data;
				this->end_word=false;
				this->height=0;
				this->child=new TrieNode* [26];
				for(int i=0;i<26;i++){
					child[i]=NULL;
				}
			}

			TrieNode(char data,int height){
				this->data=data;
				this->end_word=false;
				this->height=height;
				this->child=new TrieNode* [26];
				for(int i=0;i<26;i++){
					child[i]=NULL;
				}
			}
		
			void initialize(){
				cout<<"hello"<<endl; 
			}
		
			~TrieNode(){
				for(int i=0;i<26;i++){
					delete child[i];
				}
				delete [] child;
			}

	};

	TrieNode *root;

public:

	Trie(){
		root=new TrieNode('$');
	}
	
	~Trie(){
		delete root;
	}

private:
	string toLower(string word){
		if(word.length()==0){
			return "";
		}
		string s="";
		for(int i=0;word[i]!='\0' && word[i]!=' ';i++){
			if(word[i]>=65 && word[i]<=95){
				s+=char(word[i]+32);
			}
			else{
				s+=word[i];
			}
		}
		return s;
	}
	
	void print(TrieNode *root){
		if(root==NULL){
			return;
		}
		cout<<"height = "<<root->height<<" data = "<<root->data<<" : ";
		for(int i=0;i<26;i++){
			if(root->child[i]!=NULL){
				cout<<root->child[i]->data<<" ";
			}
		}
		cout<<endl;
		for(int i=0;i<26;i++){
			if(root->child[i]!=NULL){
				print(root->child[i]);
			}
		}
	}

	void deleteWordUtil(TrieNode *root,string word){
		// some code 
	}

public:

	void insertWord(string word){
		word=toLower(word);
		TrieNode *temp=root;
		for(int i=0;i<word.length();i++){
			int index=word[i]-'a';
			if(temp->child[index]==NULL){
				temp->child[index]=new TrieNode(word[i],root->height+1);
			}
			temp=temp->child[index];
		}
		//mark leaf as end of word;
		temp->end_word=true;
	}
	
	bool searchWord(string word){
		word=toLower(word);
		TrieNode *temp=root;
		for(int i=0;i<word.length();i++){
			int index=word[i]-'a';
			if(temp->child[index]==NULL){
				return false;
			}
			temp=temp->child[index];
		}

		if(temp->end_word=true){
			return true;
		}
		return false;
	}

	void deleteWord(string word){
		if(word.length()==0){
			return;
		}
		word=toLower(word);
		deleteWordUtil(root,word);
	}

	void printTrie(){
		cout<<"======================================="<<endl;
		cout<<"Trie data"<<endl;
		cout<<"---------------------------------------"<<endl;
		print(root);
		cout<<"======================================="<<endl;
	}

};

int main(){
	
	Trie *trie=new Trie();
	string word;
	int x=1;
	
	while(x!=5){
		cout<<"1 to insert "<<endl;
		cout<<"2 to search "<<endl;
		cout<<"3 to delete "<<endl;
		cout<<"4 to print "<<endl;
		cout<<"5 to exit"<<endl;
		cin>>x;
		switch(x){
			case 1:
					cin>>word;
					trie->insertWord(word);
					break;
			case 2:
					cin>>word;
					if(trie->searchWord(word)){
						cout<<"Yes"<<endl;
					}
					else{
						cout<<"No"<<endl;
					}
					break;
			case 3:
					cin>>word;
					trie->deleteWord(word);
					break;
			case 4:
					trie->printTrie();
					break;
			default :
					x=5;
					break;
		}

	}

	delete trie;
	return 0;

}