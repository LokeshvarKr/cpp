

//ambiguity relsolve technique using 'virtual' keyword;

#include<iostream>
using namespace std;
class a{
public:
	/*
	a(){
		cout<<"a: constructor"<<endl;
	}*/

	a(int x){
		cout<<"a: parameterized constructor through "<<x<<endl;
	}

	~a(){
		cout<<"a:destructor"<<endl;
	}

	void print(){
		cout<<"this is a"<<endl;
	}
};

class b:virtual public a{
public:
	
	b():a(3){
		cout<<"b:constructor"<<endl;
	}

	
	~b(){
		cout<<"b:destructor"<<endl;
	}
	
	
};

class c:virtual public a{
public:
	c():a(4){
		cout<<"c:constructor"<<endl;
	}
	~c(){
		cout<<"c:destructor"<<endl;
	}
	
	
};

class d:public b,public c{
public:
	d():a(5){
		cout<<"d:constructor"<<endl;
	}
	~d(){
		cout<<"d:destructor"<<endl;
	}
	
};


int main(int argc, char const *argv[])
{
	d obj;
	
	return 0;
}












