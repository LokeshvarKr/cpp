/*

Code : Min Cost Path

Given an integer matrix of size m*n, you need to find out the value of minimum cost to reach from the cell (0, 0) to (m-1, n-1).
From a cell (i, j), you can move in three directions : (i+1, j), (i, j+1) and (i+1, j+1).
Cost of a path is defined as the sum of values of each cell through which path passes.
Input Format :

Line 1 : Two integers, m and n
Next m lines : n integers of each row (separated by space)

Output Format :

Minimum cost

Constraints :
1 <= m, n <= 20
Sample Input 1 :

3 4
3 4 1 2
2 1 8 9
4 7 8 1

Sample Output 1 :

13


*/



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




//memoization

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


//dynamic

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
