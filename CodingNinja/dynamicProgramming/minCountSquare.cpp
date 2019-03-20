#include<iostream>
#include<climits>
/*

Code : Minimum Count

Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
Note : x^y represents x raise to the power y.
Input Format :

Integer N

Output Format :

Required minimum count

Constraints :
1 <= N <= 1000
Sample Input 1 :

12

Sample Output 1 :

3

Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.
Sample Input 2 :

9

Sample Output 2 :

1




*/
/*
//Brute force 
int minCount(int n){
    
    
    
  if(n==0)return 0;
  if(n==1)return 1;
  
  int min=INT_MAX,temp;
  
  for(int i=1; i*i<=n; i++){
    
   temp=minCount( n-(i*i));
    
    if(temp<min)
      min=temp;
  }
  
  return min+1;
    
}

*/


/*
//Memoization
int helper_min(int *a,int n){

  if(n==0)return 0;
  if(n==1)return 1;
  
    int min=INT_MAX,x;
    for(int i=1;i*i<=n;i++){
      x=n-i*i;
      if(a[x]!=-1)
      {
        if(a[x]<min)
          min=a[x];
      }
      else{
        a[x]=helper_min(a,n-i*i);
        if(a[x]<min)
          min=a[x];
      }
      
    }
    a[n]=1+min;
    return a[n];
  
}

int minCount(int n){
  int *a=new int [n+1];
  
  for(int i=0;i<=n;i++)a[i]=-1;
  
  int ans= helper_min(a,n);
	delete [] a;
  return ans;
}
*/



//Dynamic
int minCount(int n){
  
  int *a=new int[n+1];
  for(int i=0;i<=n;i++)a[i]=-1;
  
  a[0]=0;
  a[1]=1;
  int x,min;
  for(int i=2;i<=n;i++){
    min=INT_MAX;
  for(int j=1;j*j<=i;j++){
    	x=i-j*j;
          if(a[x]<min)
            min=a[x];
  	}
    	a[i]=1+min;
    
  }
  
  return a[n];
  
}

int main(){
int n;
cin>>n;
cout<<minCount<<endl;
return 0;
}










