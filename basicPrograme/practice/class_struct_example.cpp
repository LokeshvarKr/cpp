#include<iostream>
using namespace std;

class Base{
public:
	int x;
};
class Derived : private Base{

	public:
		void fun(){
			x=30;
			cout<<x<<endl;
		}
};

 int main(){
 	Derived d;
 	d.fun();
 	return 0;
 }