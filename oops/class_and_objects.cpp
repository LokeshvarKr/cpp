#include<iostream>
#include<stdlib.h>
using namespace std;
class A{
public:
	static int x;
	A(){
		x++;
	}
	~A(){
		x--;
	}
};
int A::x=0;
int main(){

	cout<<A::x<<endl; 
	cout<<"========================"<<endl;
	
	A a,b,c,d;
	cout<<A::x<<endl;
	cout<<"========================"<<endl;

	A *o1=(A*)malloc(sizeof(A));
	cout<<A::x<<endl;
	cout<<"because malloc() doesn't call constructor"<<endl;
	cout<<"========================"<<endl;

	A *o2=new A();
	cout<<A::x<<endl;
	cout<<"new class constructor (this is the difference between malloc() and new "<<endl;
	cout<<"========================"<<endl;

	//lets free the memory of o2 using free() (c style)
	free(o2);
	cout<<A::x<<endl;
	cout<<"because free() doesn't call distructor"<<endl;
	cout<<"========================"<<endl;
	
	//lets delete the memory of o1 using delete keyword ( memory of o1 is allocated by malloc())
	delete o1;
	cout<<A::x<<endl;
	cout<<"========================"<<endl;

	return 0;
}