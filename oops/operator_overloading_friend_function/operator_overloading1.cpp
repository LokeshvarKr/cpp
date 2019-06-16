#include <iostream>
using namespace std;

class Marks{
public:
	int internal;
	int external;
public:
	Marks(){
		internal=0;
		external=0;
	}

	Marks(int internal,int external){
		this->internal=internal;
		this->external=external;
	}

	void display(){
		cout<<"internal : "<<internal<<endl;
		cout<<"external : "<<external<<endl;
	}
	Marks operator +(Marks const &m){
		Marks temp;
		temp.internal=internal+m.internal;
		temp.external=external+m.external;
		return temp;
	}

	Marks operator -(Marks const &m){
		Marks temp;
		temp.internal=internal-m.internal;
		temp.external=external-m.external;
		return temp;
	}
	
	//short-hand operator
	void operator +=(Marks m){
		this->internal += m.internal;
		this->external +=m.external;
	}

	void operator -=(Marks m){
		this->internal -= m.internal;
		this->external -=m.external;
	}

	//unary opretator
	//post increament
	Marks operator ++(int ){
		Marks old=*this;
		++internal;
		++external;
		return old;
	}
	//pre increament
	Marks operator ++(){
		++internal;
		++external;
		return *this;
	}

};

int main(){

	Marks m1(10,15),m2(20,30),m3;
	m1.display();
	m2.display();
	cout<<"============================="<<endl;
	m3=m1+m2;
	m3.display();
	m3=m1-m2;
	m3.display();

	cout<<"============================="<<endl;
	
	m1+=m2;
	m1.display();
	m1-=m2;
	m1.display();

	cout<<"============================="<<endl;

	(m1++).display();
	m1.display();

	cout<<"============================="<<endl;
	(++m1).display();
	m1.display();


	return 0;
}