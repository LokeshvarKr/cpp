#include<iostream>
using namespace std;

class Base{
public:
	int x;
};

struct Derived : Base{

};

// above is equilalent to ===> struct Derived : public Base {}; 

int main(){
	Derived d;
	d.x=20;
	return 0;
}