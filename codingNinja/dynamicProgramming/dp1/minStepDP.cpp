
#include<climits>
int count(int *a,int n){
  if(a[n]>=0)return a[n];
  if(n==1){
    a[n]=0;
    return a[n];
  }
  
  int a1=INT_MAX,b=INT_MAX,c=INT_MAX;
  if(n%2==0)
    a1=count(a,n/2);
  if(n%3==0)
    b=count(a,n/3);
  
  	c=count(a,n-1);
  
  a[n]=1+min(min(a1,b),c);
  return a[n];
  
}

int countStepsTo1(int n){

    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     */
  
  int *a=new int[n+1];
  
  for(int i=0;i<=n;i++)a[i]=-1;
  
  return count(a,n);
  
  delete [] a;

}

