#include<iostream>
using namespace std;
int main(){
	int *x=new int[100]();
	for(int i=0;i<100;i++){
		cout<<x[i]<<" ";
	}
	cout<<endl;
	int *y=new int[100];
	for(int i=0;i<100;i++){
		cout<<y[i]<<" ";
	}
	return 0; 
}