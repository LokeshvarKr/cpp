#include<iostream>
using namespace std;

template <typename T>

class node{
public:
	T data;
	node <T> *next;

	node(T x){
	data=x;
	next=NULL;
	}
};

template <typename T>

class stack{

private:
	node<T> *TOP;
	int SIZE;
public:
	stack(){
	SIZE=0;
	TOP=NULL;
	}

	void push(T x){
		node<T> *n1=new node<T>(x);
		if(TOP==NULL)
		TOP=n1;
		else
		{
		n1->next=TOP;
		TOP=n1;
		}

		SIZE+=1;

	}

	T pop(){
		if(SIZE==0)
		return 0;
		else
		{
		node<T> *ans=TOP;
		TOP=TOP->next;	
		T x=ans->data;
		delete ans;
		SIZE-=1;
		return x;
		}
	}

	T top(){
		if(SIZE==0)
		return 0;
		else
		{	
			T x=TOP->data;
			return x;  
		}
	}

	int size()
	{
		return SIZE;
	}

	bool isEmpty(){
	if(SIZE==0)
	return true;
	else return false;
	}

};

int main(){

stack <int> s;
cout<<s.size()<<endl;
s.push(10);

cout<<s.top()<<endl;
cout<<s.size()<<endl;

}
