#include<iostream>
using namespace std;

int countWaysToMakeChange(int denominations[], int numDenominations, int value){

  if(value==0)  
  return 0;
  
  int x=0;
  
  for(int i=0;i<numDenominations;i++){
    if(value<=denominations[i]){
   		x=x+1+countWaysToMakeChange(denominations,numDenominations,value-denominations[i]);
    }
  }
  
  return x;
	
}
int main(){
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)cin>>a[i];
int v;
cin>>v;
cout<<countWaysToMakeChange(a,n,v)<<endl;
return 0;

}
