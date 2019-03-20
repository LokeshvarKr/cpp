
//ambiguity relsolve technique using scope resolution

#include<iostream>
using namespace std;
class a{
public:
	a(){
		cout<<"a: constructor"<<endl;
	}
	~a(){
		cout<<"a:destructor"<<endl;
	}

	void print(){
		cout<<"this is a"<<endl;
	}
};

class b:public a{
public:
	b(){
		cout<<"b:constructor"<<endl;
	}
	~b(){
		cout<<"b:destructor"<<endl;
	}
	void print(){
		cout<<"this is b"<<endl;
	}
	
};

class c:public a{
public:
	c(){
		cout<<"c:constructor"<<endl;
	}
	~c(){
		cout<<"c:destructor"<<endl;
	}
	void print(){
		cout<<"this is c"<<endl;
	}
	
};

class d:public b,public c{
public:
	d(){
		cout<<"d:constructor"<<endl;
	}
	~d(){
		cout<<"d:destructor"<<endl;
	}
	
};


int main(int argc, char const *argv[])
{
	d obj;
	// d.print();  here compiler will confuse
	//one sol use scope resolution
	obj.c::print();
	return 0;
}












