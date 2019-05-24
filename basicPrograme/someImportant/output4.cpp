#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int n=8;
	//height of the heap
	int h=ceil(log2(n+1))-1;
	cout<<h<<endl;
	return 0;
}