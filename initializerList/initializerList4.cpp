#include<iostream>
using namespace std;

class One{
	int _x;
public:
	One(int x) : _x{x} {}
};

class Two{
	One a;
public:
	Two(One x) : a{x} {}
};

int main(){
	One one(10);
	Two two(one);
	return 0;
}