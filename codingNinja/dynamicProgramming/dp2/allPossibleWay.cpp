


#include<cmath>
int helper(int x,int n,int i){
  int p=x-pow(i,n);
  if(p==0)return 1;
  if(p<0)return 0;
  
  return helper(p,n,i+1)+helper(x,n,i+1);
}
int allWays(int x, int n) {
   
    return helper(x,n,1);
}