#include<iostream>
using namespace std;
int helper_fib(int *a,int n){
if(n<=1)
return n;
if(a[n]!=-1)
return a[n];
else
{
a[n]=helper_fib(a,n-1)+helper_fib(a,n-2);
return a[n];
}
}
int fib(int n){
int *a=new int[n+1];
for(int i=0;i<=n;i++)
a[i]=-1;

return helper_fib(a,n);
}
int main(){
int n;
cout<<"Enter n"<<endl;
cin>>n;
cout<<fib(n)<<endl;
return 0;
}
