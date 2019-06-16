#include<iostream>
using namespace std;


//to initialize base class member variable from child class
class One{
public:
	int x;
	One(int i) : x{i} {}
};

class Two:One{
	int y;
public:
	//below constructor won't work
	/*Two(int i,int j){
		x=i;
		y=j;
	}*/
	//use initializer list to initialize members of base class
	Two(int i,int j) : One(i),y(j){}

};

int main(){
	Two two(2,4);
	return 0;
}