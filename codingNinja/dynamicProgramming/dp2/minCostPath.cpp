#include <iostream>
#include <vector>
#include <climits>
using namespace std;


/*int helper_func(int **input,int i,int j,int m,int n){
  
  if(i==m-1 && j==n-1)return input[i][j];
  if(i>m-1 || j>n-1)return INT_MAX;
  
 
  return input[i][j]+min(min( helper_func(input,i,j+1,m,n) , helper_func(input,i+1,j+1,m,n) ),
                          helper_func(input,i+1,j,m,n));
  
}
int minCostPath(int **input, int m, int n) {
  return helper_func(input,0,0,m,n);
}

*/

/*
int helper_func(int **input,int **ans,int i,int j,int m,int n){
  if(i==m-1 && j==n-1){
    ans[i][j]=input[i][j];
    return ans[i][j];
  }
  if(i>m-1 ||  j>n-1)
    return INT_MAX;
  
  if(ans[i][j]!=-1)
    return ans[i][j];
  
  else {
  ans[i][j]=input[i][j]+min(min(helper_func(input,ans,i,j+1,m,n),helper_func(input,ans,i+1,j+1,m,n)),
                            helper_func(input,ans,i+1,j,m,n));
 
  return ans[i][j];
  }
}
int minCostPath(int **input, int m, int n) {

  int **ans=new int *[m];
  for(int i=0;i<m;i++){
    ans[i]=new int [n];
    for(int j=0;j<n;j++){
      ans[i][j]=-1;
    }
  }
  
  int answer= helper_func(input,ans,0,0,m,n);
  for(int i=0;i<m;i++)
    delete []ans[i];
  
  delete [] ans;
    
  return answer;
}

*/

int minCostPath(int **input, int m, int n) {

  int **ans=new int *[m];
  for(int i=0;i<m;i++){
    ans[i]=new int [n];
    for(int j=0;j<n;j++){
      ans[i][j]=-1;
    }
  }
  
 
  for(int i=m-1;i>=0;i--){
    
    for(int j=n-1;j>=0;j--){
      
      if(i==m-1 && j==n-1)
        ans[i][j]=input[i][j];
      
     else if(i==m-1 && j<n-1)
        ans[i][j]=input[i][j]+ans[i][j+1];
      
      else if(i<m-1 && j==n-1)
        ans[i][j]=input[i][j]+ans[i+1][j];
      
      else ans[i][j] = input[i][j] + min( min( ans[i][j+1] , ans[i+1][j+1] ) , ans[i+1][j] );
    }
  }
  
  int ansRet=ans[0][0];
  
  for(int i=0;i<m;i++)
    delete []ans[i];
  delete [] ans;
    
  return ansRet;
}