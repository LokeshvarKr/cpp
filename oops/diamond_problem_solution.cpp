#include<iostream>
using namespace std;
class Person{
public:
	int id;
	int age;
	Person(){
		cout<<"Person"<<endl;
	}
	void f1(){
		cout<<"f1"<<endl;
	}
};
class Student:virtual public Person{
public:
	Student(){
		cout<<"Student"<<endl;
	}
	void f2(){
		cout<<"f2"<<endl;
	}
};
class Faculty:virtual public Person{
public:
	Faculty(){
		cout<<"Faculty"<<endl;
	}
	void f3(){
		cout<<"f3"<<endl;
	}
};
class TeachingAssistance:virtual public Student,virtual public Faculty{
public:
	TeachingAssistance(){
		cout<<"TeachingAssistance"<<endl;
	}
	void f4(){
		cout<<"f4"<<endl;
	}
};
int main(){
	// TeachingAssistance *ta=new TeachingAssistance();
	TeachingAssistance t;
	t.id=4;
	cout<<t.id<<endl;
	t.f1();
	return 0;
}