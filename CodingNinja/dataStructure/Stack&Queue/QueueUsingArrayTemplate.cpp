#include<iostream>
using namespace std;
template <typename T>

class queue{
	T *data;
	int Front;
	int Rear;
	int capacity;

public:
	queue(int capacity){
	data=new T[capacity];
	this->capacity=capacity;
	Front=0;
	Rear=0;
	}

	void enqueue(T x){
	if((Rear+1)%capacity==Front)
		{
		cout<<"Error 'overflow' "<<endl;
		return ;
		}
	else 	
		{
		data[Rear]=x;
		Rear++;
		}
	}

	void dequeue(){
	if(Front==Rear)
		{
		cout<<"Error 'underflow' "<<endl;
		return ;
		}
	Front=(Front+1)%capacity;

	}

	T front(){
	if(Front==Rear)
		{
		cout<<"Error 'queue is empty' so returning 0  "<<endl;
		return 0;
		}
	return data[Front];

	}


	int size(){
	if(Front==Rear)return 0;
	else if(Rear>Front)return Rear-Front;
	else return (capacity-(Front-Rear-1));
	}
	bool empty(){
	if(Front==Rear)return true;
	return false;
	}

	bool full(){
	if((Rear+1)%capacity==Front)return true;
	return false;
	}
};

int main(){


queue <int > q(4);
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
cout<<q.full()<<endl;
cout<<q.empty()<<endl;
cout<<"front "<<q.front()<<endl;
q.enqueue(30);
cout<<"size "<<q.size()<<endl;
return 0;

}
