#include<iostream>
#include<stdlib.h>
using namespace std;
class A{
public:
	static int stackObjectCount;
	static int heapObjectCount;
	A(){
		stackObjectCount++;
	}
	~A(){
		stackObjectCount--;
	}

	void* operator new(size_t st){
		heapObjectCount++;
		stackObjectCount--;
	}
	void operator delete(void* ptr){
		heapObjectCount--;
		stackObjectCount++;
	}
};

int A::stackObjectCount=0;
int A::heapObjectCount=0;

int main(){

	cout<<"stack object count: "<<A::stackObjectCount<<endl; 
	cout<<"heap object count: "<<A::heapObjectCount<<endl; 
	cout<<"========================"<<endl;
	
	A a,b,c,d;
	cout<<"stack object count: "<<A::stackObjectCount<<endl; 
	cout<<"heap object count: "<<A::heapObjectCount<<endl; 
	cout<<"========================"<<endl;


	A *o1=new A();
	A *o2=new A();
	cout<<"stack object count: "<<A::stackObjectCount<<endl; 
	cout<<"heap object count: "<<A::heapObjectCount<<endl; 
	cout<<"========================"<<endl;

	delete o1;
	cout<<"stack object count: "<<A::stackObjectCount<<endl; 
	cout<<"heap object count: "<<A::heapObjectCount<<endl; 
	cout<<"========================"<<endl;

	
	return 0;
}