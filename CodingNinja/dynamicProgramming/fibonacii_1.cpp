#include<iostream>
using namespace std;

int fib(int n){
int *a=new int [n+1];
	a[0]=0;
	a[1]=1;
	
	for(int i=2;i<=n;i++){
	a[i]=a[i-1]+a[i-2];
	}

	return a[n];

}
int main(){
int n;
cout<<"Enter n"<<endl;
cin>>n;
cout<<fib(n)<<endl;
return 0;
}
