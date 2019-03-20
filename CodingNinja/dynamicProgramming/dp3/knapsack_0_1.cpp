
/*
Code: Knapsack (Memoization and DP)

A thief robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith item weigh wi and is of value vi. What is the maximum value V, that thief can take ?
Input Format :

Line 1 : N i.e. number of items
Line 2 : N Integers i.e. weights of items separated by space
Line 3 : N Integers i.e. values of items separated by space
Line 4 : Integer W i.e. maximum weight thief can carry

Output Format :

Line 1 : Maximum value V

Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Sample Input 1 :

4
1 2 4 5
5 4 8 6
5

Sample Output :

13


*/





#include <iostream>
using namespace std;

//brute force
/*
int knapsack(int* weights, int* values, int n, int maxWeight){

if(maxWeight==0 || n==0 )return 0;
  
  if(weights[n-1]<=maxWeight)
  {
    return max(values[n-1]+knapsack(weights,values,n-1,maxWeight-weights[n-1]),
               knapsack(weights,values,n-1,maxWeight));
  }
  else
    return knapsack(weights,values,n-1,maxWeight);

}

*/




//dynamic

/*
int knapsack(int* weights, int* values, int n, int maxWeight){

	int **ans=new int *[n+1];
  
  	for(int i=0;i<=n;i++){
    ans[i] = new int[maxWeight+1];
    for(int j=0;j<=maxWeight;j++){
      ans[i][j]=-1;
    }
  }

 for(int i=0;i<=n;i++){
   
   for(int w=0;w<=maxWeight;w++){
     
     if(i==0||w==0)
       ans[i][w]=0;
     
     else if(weights[i-1]<=w)
         ans[i][w]=max(values[i-1]+ans[i-1][w-weights[i-1]] , ans[i-1][w]);
       else
         ans[i][w]=ans[i-1][w];

   }
 }
  
  int ansRet = ans[n][maxWeight];

  	for(int i=0;i<=n;i++){
      delete [] ans[i];
    }
  		delete [] ans;
  
  
  return ansRet;
}

*/


//dynamic space optimization (very efficient)

int knapsack(int* weights, int* values, int n, int maxWeight){

  
  if(n==0 || maxWeight==0)return 0;
  
	int *ans1=new int[maxWeight+1];
  	int *ans2=new int [maxWeight+1];

  for(int i=0;i<=maxWeight;i++){
    ans1[i]=0;
    ans2[i]=0;
  }
  
 for(int i=0;i<n;i++){
   
   for(int w=1;w<=maxWeight;w++){
     
      if(weights[i]<=w)
         ans2[w]=max(values[i]+ans1[w-weights[i]] , ans1[w]);
       else
         ans2[w]=ans1[w];
   }
   
   int *temp=ans1;
   ans1=ans2;
   ans2=temp;
   
 }
  
  int Ans = ans1[maxWeight];
  
  delete [] ans1;
  delete [] ans2;
  
  return Ans;
  
}

