
#include<climits>
int countStepsTo1(int n){

    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     */

  if(n==1)return 0;
  
  int a=INT_MAX,b=INT_MAX,c=INT_MAX;
  if(n%2==0)
  a=1+countStepsTo1(n/2);
  if(n%3==0)
  b=1+countStepsTo1(n/3);
  
  c= 1+countStepsTo1(n-1);
  return min(min(a,b),c);
  
}

