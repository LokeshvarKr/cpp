


//implementation of hashmap using chaining 


#include<string>
using namespace std;

template <typename v>
class MapNode{
	public:
	string key;
	v value;
	MapNode<v> *next;
	
	MapNode(string key,v value){
	this->key=key;
	this->value=value;
	this->next=NULL;
	}

	~MapNode(){
	delete next;
	}

};

template <typename v>
class ourmap{
	public:
	MapNode<v> **Buckets;
	int count;
	int numBuckets;
	
	ourmap(){
	count=0;
	numBuckets=5;
	Buckets=new MapNode<v>* [numBuckets];

	for(int i=0;i<numBuckets;i++)
	Buckets[i]=NULL;

	}

	~ourmap(){
	for(int i=0;i<numBuckets;i++)
	delete Buckets[i];
	delete [] Buckets;
	}

	int size(){
	return count;
	}

	private:

	int getBucketIndex(string key){
	int hashCode=0;
	int currentCoeff=1;
	
	//"abc"=a*p^2 + b*p^1 + c*p^0 , where p is a prime.	
		for(int i=key.length()-1;i>=0;i--){
		hashCode = key[i] * currentCoeff;
		hashCode = hashCode % numBuckets;
		currentCoeff = (currentCoeff * 37) % numBuckets;
		}
	
	return hashCode%numBuckets;

	}

	void rehash(){
	MapNode<v>** temp=Buckets;
	Buckets=new MapNode<v>* [2 * numBuckets];
	for(int i=0; i<2*numBuckets; i++)
	Buckets[i]=NULL;
	
	int oldNumBuckets=numBuckets;
	numBuckets*=2;
	count=0;

	MapNode<v> *head=NULL;
		for(int i=0; i < oldNumBuckets;  i++){
			head=temp[i];
			while(head){
			string key=head->key;
			v value=head->value;
			insert(key,value);
			head=head->next;
			}
		}
	
	for(int i=0; i < oldNumBuckets; i++)
	delete temp[i];
	
	delete [] temp;

	}
	
	public:

	double getLoadFactor(){
	return (1.0*count)/numBuckets;	
	}

	v getValue(string key){
	int BucketIndex=getBucketIndex(key);
	MapNode<v> *head=Buckets[BucketIndex];
	
		while(head!=NULL && head->key!=key){
		head=head->next;
		}
		
		if(head!=NULL && head->key==key)
		return head->value;
		else return 0;

	}

	void insert(string key,v value){
	int BucketIndex=getBucketIndex(key);
	MapNode<v> *head=Buckets[BucketIndex];

		while(head!=NULL){
			if(head->key==key){
			head->value=value;
			return;
			}	
		head=head->next;
		
		}

	head=Buckets[BucketIndex];	
	MapNode<v> *node=new MapNode<v>(key,value);
	node->next=head;
	Buckets[BucketIndex]=node;
	count++;
	
	double loadFactor=((1.0)*count)/numBuckets;
	if(loadFactor >=0.7)
	rehash();	
	return;

	}

	
	v remove(string key ){
	int BucketIndex=getBucketIndex(key);
	MapNode<v> *head=Buckets[BucketIndex];
	MapNode<v> *prev=NULL;

		while(head!=NULL && head->key!=key){
		prev=head;
		head=head->next;
		}
		
		
		if(head!=NULL && head->key==key){
			if(prev==NULL){
			Buckets[BucketIndex]=head->next;
			head->next=NULL;
			v value=head->value;
			delete head;
			count--;
			return value;	
			}			
			else {
			prev->next=head->next;
			head->next=NULL;
			v value=head->value;
			delete head;
			count--;
			return value;
			}
			
		}

		else       		//if(head==NULL)
		return 0;

	}

};

