#include<iostream>
using namespace std;
class Person{
public:
	int id;
	int age;
	Person(){
		cout<<"Person"<<endl;
	}
	void fun(){
		cout<<"fun() in Person"<<endl;
	}
};
class Student:protected Person{
public:
	Student(){
		cout<<"Student"<<endl;
	}
};
class Faculty:protected Person{
public:
	Faculty(){
		cout<<"Faculty"<<endl;
	}
};
class TeachingAssistance:protected Student,protected Faculty{
public:
	TeachingAssistance(){
		cout<<"TeachingAssistance"<<endl;
	}
}; 
int main(){
	// TeachingAssistance *ta=new TeachingAssistance();
	TeachingAssistance t;
	cout<<sizeof(t)<<endl;
	// t.id=5;   //compiler error Error (abiguous)
	// t.fun();   //compiler error Error (abiguous)
	
	return 0;
}