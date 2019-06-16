#include<iostream>

//tuple present in -std=c++11
#include<tuple>

using namespace std;
int main(){
	tuple<string , int ,int > t1{"Lokeshvar",50,60};
	cout << get<0>(t1) << endl;
	cout << get<1>(t1) << endl;
	cout << get<2>(t1) << endl;

	t1=make_tuple("Lokesh",1,2);
	cout << get<0>(t1) << endl;
	cout << get<1>(t1) << endl;
	cout << get<2>(t1) << endl;

	get<1>(t1)=500;
	get<2>(t1)=300;

	cout << get<0>(t1) << endl;
	cout << get<1>(t1) << endl;
	cout << get<2>(t1) << endl;

	return 0;
}