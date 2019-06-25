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

};

class b{
public:
	b(){
		cout<<"b:constructor"<<endl;
	}
	~b(){
		cout<<"b:destructor"<<endl;
	}
	
};

class c{
public:
	c(){
		cout<<"c:constructor"<<endl;
	}
	~c(){
		cout<<"c:destructor"<<endl;
	}
	
};

class d:public a,public b,public c{
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
	return 0;
}