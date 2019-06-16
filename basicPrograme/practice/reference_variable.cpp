#include <iostream>
using namespace std;


int main(){
	int x=5;
	int z=10;
	// int &y=20;  //invalic
	int &y=z;
	// int &p; //invalid --> must initialize
	int &p=x; 
	cout<<x<<" "<<y<<" "<<p<<endl;
	return 0;
}