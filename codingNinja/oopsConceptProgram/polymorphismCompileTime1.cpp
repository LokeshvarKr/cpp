
//function overriding (resolve at compile time)
#include<iostream>
using namespace std;

class a{
public:
	void print(){
		cout<<"hello a"<<endl;
	}
	
};
class b:public a{
public:
	void print(){
		cout<<"hello b"<<endl;
	}
	
};

int main(){
	b obj;
	obj.print();
	return 0;
}