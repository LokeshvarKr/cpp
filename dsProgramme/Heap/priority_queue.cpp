
//implementaion of max priority queue
#include<iostream>
using namespace std;
template<typename T>
class PriorityQueue{
	int size;
	int capacity;
	T *arr;
public:
	PriorityQueue(){
		this->size=0;
		this->capacity=5;
		arr=new T [capacity];
	}
	~PriorityQueue(){
		delete [] arr;
	}

private:
	void swap(T *a,T *b){
		T temp=*a;
		*a=*b;
		*b=temp;
	}
	void max_heapify(int n,int i){
		int left=2*i+1;
		int right=2*i+2;
		int maxIndex=i;
		if(left < n && arr[left] > arr[maxIndex]){
			maxIndex=left;
		}
		if(right < n && arr[right] > arr[maxIndex]){
			maxIndex=right;
		}
		if(maxIndex!=i){
			swap(arr+i,arr+maxIndex);
			max_heapify(n,maxIndex);
		}
	}
	void increase_key(int i){
		int parent=(i-1)/2;
		while(i>0 && arr[parent] < arr[i]){
			swap(arr+i,arr+parent);
			i=parent;
			parent=(i-1)/2;
		}
	}
	void extract_max(){
		if(size == 0)return;
		arr[0]=arr[size-1];
		size=size-1;
		max_heapify(size,0);
	}
public:
	int getSize(){
		return this->size;
	}
	void push(T data){
		if(size < capacity){
			size+=1;
			arr[size-1]=data;
			increase_key(size-1);
		}
	}
	T top(){
		if(size > 0){
			return arr[0];
		}
	}
	void pop(){
		extract_max();
	}
	
};
int main(){
	PriorityQueue<int> pq;
	pq.push(4);
	cout<<pq.top()<<endl;
	pq.push(2);
	cout<<pq.top()<<endl;
	pq.push(8);
	cout<<pq.top()<<endl;
	pq.push(10);
	pq.push(2);
	cout<<pq.top()<<endl;
	cout<<pq.getSize()<<endl;
	pq.pop();
	pq.pop();
	pq.pop();
	cout<<pq.top()<<endl;
	cout<<pq.getSize()<<endl;
	return 0;
}