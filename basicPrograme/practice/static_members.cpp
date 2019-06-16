#include<iostream>
using namespace std;

class  Student{
public:
	int static count_object;
private:
	int roll;
	int name; 
public:
	Student(){
		count_object++;
	}
	~Student(){}
	void set_count_object(int x){
		count_object=x;
	}
};

int Student::count_object=0;
int main(){
	Student s1,s2,s3;
	cout<<Student::count_object<<endl;
	cout<<s1.count_object<<endl;

	s1.set_count_object(10);

	cout<<Student::count_object<<endl;
	cout<<s1.count_object<<endl;


	return 0;
}