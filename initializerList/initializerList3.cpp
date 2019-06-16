
#include<iostream>
using namespace std;

//when we have non-static const member variable
class Base{
	int x;
public:
	Base(int i){
		x=i;
	}
};

class Derived{
	Base a;
public:

	//blow line won't work
	//Derived(Base b){a=b;}
	//so use initializer list
	Derived(Base b):a{b}{}
};
int main(){

	Base base(10);
	Derived derived(base);
	return 0;
}