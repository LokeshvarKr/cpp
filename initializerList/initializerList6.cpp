#include<iostream>
using namespace std;
class Base{
	int x;
public:
	Base(){
		cout<<"Base default constrctor"<<endl;
	}
	Base(int i){
		x=i;
		cout<<"Base parameterized constrctor"<<endl;
	}
	Base(const Base &b){
		cout<<"Base copy constrctor"<<endl;
		this->x=b.x;
	}
	Base& operator = (const Base &b){
		cout<<"Base assignment operator"<<endl;
		this->x=b.x;
		return *this;
	}
};

class Derived{
	Base b;
public:
	Derived(){
		cout<<"Derived default constrctor"<<endl;
	}

	// without using initializer list (5 functions call happens)
	/*Derived(Base a){
		b=a;
		cout<<"Derived parameterized constrctor"<<endl;
	}*/

	//using initializer list (4 function call happens)
	Derived(Base a):b(a){
		cout<<"Derived parameterized constrctor"<<endl;
	}
};



int main(){

	Base b(10);
	Derived d(b);

	return 0;
}