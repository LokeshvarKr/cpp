#include <iostream>
using namespace std;

class Marks{
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
	
	friend istream& operator >> (istream &cin,Marks &m);
	friend ostream& operator << (ostream &out,Marks &m);


};

istream& operator >> (istream &din, Marks &m){
	din>>m.internal;
	din>>m.external;
	return din;
}

ostream& operator << (ostream &dout, Marks &m){
	dout<<"internal : "<<m.internal<<endl;
	dout<<"external : "<<m.external<<endl;
	return dout;
}

int main(){

	Marks m1,m2(20,30),m3(3,7);
	
	cin>>m1;
	cout<<m1;
	cout<<"================================"<<endl;
	cout<<m1<<m2;
	cout<<"================================"<<endl;
	cout<<m1<<"hello "<<"5"<<endl;
	return 0;
}