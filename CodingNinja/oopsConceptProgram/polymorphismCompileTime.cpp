#include <iostream>
using namespace std;
class a{
public:
	void print(){
		cout<<"nothing"<<endl;
	}
	void print(int x){
		cout<<x<<endl;
	}
	void print(int x,int y){
		cout<<x<<" "<<y<<endl;
	}


	// compiler can't differentiate with return type
	//so here we will get error
	//here will get error can't overload like this

	/*
	int print(){
		return 0;
	}
	*/

};

class b{
public:
	
	
};

int main(){
	a obj;
	obj.print();
	obj.print(1);
	obj.print(2,3);

	//here will get error can't overload like this
//	int y = obj.print();

	return 0;
}