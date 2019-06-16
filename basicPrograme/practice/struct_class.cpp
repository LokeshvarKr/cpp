#include<iostream>
using namespace std;

struct Base
{
	int x;
};

class Derived : Base{

};
// above is equilalent to ===> class Derived : private Base {}; 

int main(){
	Derived d;
	d.x=20;
	return 0;
}