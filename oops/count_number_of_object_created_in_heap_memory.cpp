#include<iostream>
#include<stdlib.h>
using namespace std;
class A{
public:
	static int totalObjectCount;
	static int heapObjectCount;
	
	A(){
		totalObjectCount++;
	}
	~A(){
		totalObjectCount--;
	}
	void* operator new(size_t st){
		heapObjectCount++;
	}
	void operator delete(void* ptr){
		heapObjectCount--;
	}
	
};

int A::totalObjectCount=0;
int A::heapObjectCount=0;

int main(){

	cout<<"total object count: "<<A::totalObjectCount<<endl; 
	cout<<"heap object count: "<<A::heapObjectCount<<endl; 
	cout<<"========================"<<endl;
	
	A a,b,c,d;
	cout<<"total object count: "<<A::totalObjectCount<<endl; 
	cout<<"heap object count: "<<A::heapObjectCount<<endl; 
	cout<<"========================"<<endl;


	A *o1=new A();
	A *o2=new A();
	cout<<"total object count: "<<A::totalObjectCount<<endl; 
	cout<<"heap object count: "<<A::heapObjectCount<<endl; 
	cout<<"========================"<<endl;

	delete o1;
	cout<<"total object count: "<<A::totalObjectCount<<endl; 
	cout<<"heap object count: "<<A::heapObjectCount<<endl; 
	cout<<"========================"<<endl;

	
	return 0;
}