#include<iostream>
using namespace std;

template<typename K,typename V>
class HashMap{
	class Node{
	public:
		K key;
		V value;
		Node *next,*prev;
		Node(K key,V value){
			this->key=key;
			this->value=value;
			this->next=this->prev=NULL;
		}
		// ~Node(){
		// 	delete this->next;
		// }
	};

	int count;
	int bucket_capacity;
	int reallocation;
	int capacity_increament;
	Node **bucket;

public:
	HashMap(int capacity=10,int increament=10){
		count=0;
		reallocation=1;
		capacity_increament=increament;
		bucket_capacity=capacity;
		bucket=new Node*[bucket_capacity];
		for(int i=0;i<bucket_capacity;i++){
			bucket[i]=NULL;
		}
	}
	// ~HashMap(){
	// 	for(int i=0;i<bucket_capacity;i++){
	// 		delete bucket[i];
	// 	}
	// 	delete [] bucket;
	// }

private:
	int hash_function(K key){
		int index=0;
		for(int i=0;i<key.length();i++){
			index += ((int)key[i]);
		}
		index = index % bucket_capacity;
		return index;
	}

	void inserase_bucket_size(){
		reallocation++;
		int n=bucket_capacity;
		bucket_capacity += capacity_increament;

		Node **temp_bucket = new Node*[bucket_capacity];
		
		for(int i=0; i < bucket_capacity; i++){
			temp_bucket[i]=NULL;
		}
		int x=0;
		for(int i=0;i<n;i++){
			Node *head=bucket[i];
			while(head){
				Node *node=head;
				head=head->next;
				node->next=NULL;
				node->prev=NULL;
				int index=hash_function(node->key);
				x++;
				if(temp_bucket[index]==NULL){
					temp_bucket[index]=node;
				}
				else{
					node->next=temp_bucket[index];
					temp_bucket[index]->prev=node;
					temp_bucket[index]=node;
				}
			}
			bucket[i]=NULL;
		}
		// cout<<"x : "<<x<<endl;
		delete [] this->bucket;
		this->bucket=temp_bucket;
	}

	Node* search(K key){
		int index =hash_function(key);
		Node *head=bucket[index];
		while(head){
			if(head->key==key){
				return head;
			}
			head=head->next;
		}
		return NULL; 
	}


public:
	double load_factor(){
		return ((double)count/bucket_capacity);
	}

	int size(){
		return count;
	}

	int capacity(){
		return bucket_capacity;
	}
	int reallocation_count(){
		return reallocation;
	}
	
	void insert(K key,V value){
		Node *temp = search(key);
		if(temp){
			cout<<"key already exit"<<endl;
			return;
		}
		if(load_factor() > 0.5){
			inserase_bucket_size();
		}

		int index=hash_function(key);
		Node *node = new Node(key,value);
		if(bucket[index]==NULL){
			bucket[index]=node;
		}
		else{
			node->next=bucket[index];
			bucket[index]->prev=node;
			bucket[index]=node;
		}
		count++;
	}

	bool find(K key){
		Node *node = search(key);
		if(node)return true;
		return false;
	}

	V at(K key){
		Node *node=search(key);
		if(node)
			return node->value;
		else{
			cout<<"Error! Not Present"<<endl;
			exit(0);
		}
	}

	void remove(K key){
		int index=hash_function(key);
		Node *head=bucket[index];
		while(head){
			if(head->key==key){
				Node *temp1=head->prev;
				Node *temp2=head->next;
				if(temp1){
					temp1->next=temp2;
				}
				if(temp2){
					temp2->prev=temp1;
				}
				head->prev=NULL;
				head->next=NULL;
				delete head;
				if(temp1==NULL){
					bucket[index]=temp2;
				}
				count--;
				return;
			}
			head=head->next;
		}
	}



};


int main(){
	
	cout<<"============================="<<endl;
	// create hash map
	HashMap <string,int> hash_map(2,2);

	//insert() 
	hash_map.insert("raju",10);
	hash_map.insert("rahul",20);
	hash_map.insert("ranjan",13);
	hash_map.insert("rani",78);

	cout<<"size :"<<hash_map.size()<<endl;
	cout<<"capacity :"<<hash_map.capacity()<<endl;
	cout<<"load_factor :"<<hash_map.load_factor()<<endl;

	//find()
	if(hash_map.find("rahul")){
		cout<<"Present"<<endl;
	}
	else{
		cout<<"Not present"<<endl;
	}

	//at()
	int v=hash_map.at("raju");
	cout<<v<<endl;
	
	//remove()
	hash_map.remove("rahul");
	if(hash_map.find("rahul")){
		cout<<"Present"<<endl;
	}
	else{
		cout<<"Not present"<<endl;
	}

	cout<<"==========================="<<endl;


	//see the changes
	HashMap<string , string > hash_map_student(100,50);
	for(int i=1;i<=1000;i++){
		string key=to_string(i)+"name"+to_string(i);
		string value="m170"+to_string(i)+"ca";
		hash_map_student.insert(key, value);
	}

	cout<<"size :"<<hash_map_student.size()<<endl;
	cout<<"capacity :"<<hash_map_student.capacity()<<endl;
	cout<<"load_factor :"<<hash_map_student.load_factor()<<endl;
	cout<<"reallocation :"<<hash_map_student.reallocation_count()<<endl;


	cout<<"==========================="<<endl;

	for(int i=5;i<=1000;i=i+5){
		string key=to_string(i)+"name"+to_string(i);
		hash_map_student.remove(key);
	}

	cout<<"size :"<<hash_map_student.size()<<endl;
	cout<<"capacity :"<<hash_map_student.capacity()<<endl;
	cout<<"load_factor :"<<hash_map_student.load_factor()<<endl;

	cout<<"==========================="<<endl;
	for(int i=1;i<=1000;i++){
		if(i%5==0){
			continue;
		}
		string key=to_string(i)+"name"+to_string(i);
		bool x=hash_map_student.find(key);
		if(x==false)cout<<i<<": "<<key<<endl;
	}

	cout<<hash_map_student.size()<<endl;
	cout<<hash_map_student.at(to_string(703)+"name"+to_string(703))<<endl;
	cout<<hash_map_student.at(to_string(323)+"name"+to_string(323))<<endl;
	cout<<hash_map_student.at(to_string(421)+"name"+to_string(421))<<endl;
	cout<<hash_map_student.at(to_string(527)+"name"+to_string(527))<<endl;
	
	return 0;
}