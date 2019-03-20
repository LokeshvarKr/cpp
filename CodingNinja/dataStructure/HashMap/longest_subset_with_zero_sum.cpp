
/*
Longest subset zero sum

Given an array consisting of positive and negative integers, find the length of the longest continuous subset whose sum is zero.
NOTE: You have to return the length of longest subset .
Input Format :
Line 1 : Contains an integer N i.e. size of array

Line 2 : Contains N elements of the array, separated by spaces
Output Format
 Line 1 : Length of longest continuous subset 
Sample Input :
10 
 95 -97 -387 -435 -5 -70 897 127 23 284
Sample Output :
5


*/
#include<unordered_map>
using namespace std;
int lengthOfLongestSubsetWithZeroSum(int* arr, int size){
  
  unordered_map<int,int> map;
  
  
  int sum=0;
  int index=0;
  
  for(int i=0;i<size;i++){
    sum+=arr[i];
    
    if(arr[i]==0 && index==0)
      index=1;
    
    if(map.find(sum)!=map.end()){
      index=max(index,i-map[sum]);
    }
    else {
      map[sum]=i;
    }
    
  }
 return index;

}



