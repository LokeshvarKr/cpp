
#include<iostream>
using namespace std;

//when we have reference member variable
class A{
	const int &x;
	
public:
	// A(int i){x=i;} // error can't do like this
	A(int &i):x{i}{}
	// A(int i):x(i){} // also works but above one is best 
	void print(){
		cout<<x<<endl;
	}
};

int main(){
	int p=20;
	A a(p);
	a.print();
	return 0;
}