#include<iostream>
#include<climits>
using namespace std;
int minCoin(int a[],int n, int v){
if(v==1)
return 1;
if(n==1)return a[0];

int ans1=INT_MAX;
if(a[0]<=v)
return 1+min(minCoin(a,n,v-a[0]),minCoin(a+1,n-1,v));
else
return minCoin(a+1,n-1,v);

}
int main(){
int n;
cin>>n;
int *a=new int[n];
for(int i=0;i<n;i++)
cin>>a[i];
int v;
cin>>v;
cout<<minCoin(a,n,v)<<endl;
return 0;
}
