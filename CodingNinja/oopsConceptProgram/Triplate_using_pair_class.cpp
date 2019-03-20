#include<iostream>
using namespace std;
template<typename T1,typename T2>
class Pair{
	T1 x;
	T2 y;
public:
	void setx(T1 x){
	this->x=x;
	}

	void sety(T2 y){
	this->y=y;
	}

	T1 getx(){
	return x;
	}

	T2 gety(){
	return y;
	}

};

int main(){

Pair < Pair<int,int>,int> p; //triplates
p.sety(10);

Pair <int ,int> p1;
p1.setx(15);
p1.sety(20);

p.setx(p1);

cout<<p.getx().getx()<<" "<<p.getx().gety()<<" "<<p.gety()<<endl;

return 0;
}
