#include<iostream>
using namespace std;

class vehicle{
private:
	int numTyre;

protected:
	int numGear;

public:
	string color;



private:

protected:

public:
	vehicle(){
		cout<<"vehicle: defualt consturctor"<<endl;
	}
	vehicle(int x){
		cout<<"vehicle: parameterized consturctor"<<endl;
	}
	~vehicle(){
		cout<<"vehicle: destructor"<<endl;
	}

};
class car : public vehicle{
private:

protected:

public:
	int headLight;

private:

protected:

public:
	car(){
		cout<<"car: defualt consturctor"<<endl;
	}
	car(int x){
		cout<<"car: parameterized consturctor"<<endl;
	}
	~car(){
		cout<<"car: destructor"<<endl;
	}

};

class sportCar: public car{
private:

protected:

public:


private:

protected:

public:
	sportCar(){
		cout<<"sportCar: defualt consturctor"<<endl;
	}
	sportCar(int x){
		cout<<"sportCar: parameterized consturctor"<<endl;
	}
	~sportCar(){
		cout<<"sportCar: destructor"<<endl;
	}
	
};


int main(int argc, char const *argv[])
{
	sportCar s;

	return 0;
}
