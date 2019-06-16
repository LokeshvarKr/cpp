#include <iostream>
using namespace std;

class Student
{
	int roll;
	string name;
	float marks;
	
	public:
		Student(int roll,string name,float marks){
		cout<<"arg 3"<<endl;
		this->roll=roll;
		this->name=name;
		this->marks=marks;
	}
	Student(int roll){
		cout<<"arg 1"<<endl;
		this->roll=roll;
		this->name="";
		this->marks=0.0;
	}
	Student(){
		cout<<"arg 0"<<endl;
		this->roll=0;
		this->name="";
		this->marks=0.0;
	}


	//copy constructor
	Student(const Student &s){
		cout<<"copy constructor"<<endl;
		this->name=s.name;
		this->roll=s.roll;
		this->marks=s.marks;
	}

	void print(){
		cout<<"======================="<<endl;
		cout<<this->roll<<endl;
		cout<<this->name<<endl;
		cout<<this->marks<<endl;
		cout<<"======================="<<endl;
	}


};

int main(){
	cout<<"========================="<<endl;
	Student s1;
	Student s2(1,"lokesh",95);
	Student s3(5);
	Student s4=Student(2,"harsha",95);
	Student s5(s2);
	Student s6=s2;
	cout<<"========================="<<endl;
	
	// s1.print();
	// s2.print();
	// s3.print();
	// s4.print();
	// s5.print();
	// s6.print();


	return 0;
}