#include<iostream>
using namespace std;
template <typename T>

class queue{
	T *data;
	int Front;
	int Rear;
	int capacity;
	int totalSize;

public:
	queue(){
	data=new T[4];
	capacity=4;
	Front=-1;
	Rear=0;
	totalSize=0;
	}

	bool empty(){
	if(Front==-1)return true;
	return false;
	}

	void enqueue(T x){
	
		if(totalSize==capacity){
			T *newData=new T [2*capacity];
			int i=0;
			while(i<capacity){
			newData[i++]=data[Front];
			Front=(Front+1)%capacity;
			}
		delete [] data;
		data=newData;
		Front=0;
		Rear=totalSize-1;
		capacity*=2;
		}

		data[Rear]=x;
		Rear++;
		totalSize++;
		if(Front==-1) Front=0;
	}


	void dequeue(){
		if(Front==-1){
		cout<<"Error 'underflow' "<<endl;
		return ;
		}
	Front=(Front+1)%capacity;
	totalSize--;
	}

	T front(){
		if(Front==-1){
		cout<<"Error 'queue is empty' so returning 0  "<<endl;
		return 0;
		}
	return data[Front];
	}


	int size(){
	return totalSize;
	}

};

int main(){


queue <int > q;
cout<<q.empty()<<endl;
q.enqueue(10);
q.enqueue(15);
cout<<"size "<<q.size()<<endl;
q.dequeue();
q.enqueue(30);
q.enqueue(20);
cout<<"front "<<q.front()<<endl;
cout<<"size "<<q.size()<<endl;
q.enqueue(40);
q.enqueue(28);
q.dequeue();
q.dequeue();
cout<<"size "<<q.size()<<endl;
cout<<q.empty()<<endl;
cout<<"front "<<q.front()<<endl;
q.enqueue(30);
cout<<"size "<<q.size()<<endl;
return 0;

}
