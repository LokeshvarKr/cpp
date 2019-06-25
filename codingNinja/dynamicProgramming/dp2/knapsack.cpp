#include <iostream>
using namespace std;
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

