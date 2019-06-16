#include<iostream>
#include<stdlib.h>
using namespace std;

class Point{
	int arr[3];
public:
	Point(int x=0,int y=0,int z=0){
		arr[0]=x;
		arr[1]=y;
		arr[2]=z;
	}
	void print(){
		cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<endl;
	}

	// overloading of [] can not be global
	int& operator [] (int position){
		if(position>=0 && position<=2){
			return arr[position];
		}
		else{
			cout<<"index is out of bound"<<endl;
			exit(0);
		}
	}
};


int main(){

	Point p(1,2,3);
	p.print();
	p[0]=10;
	p[1]=20;
	p[2]=30;
	cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<endl;

	return 0;
}