/*

Longest Increasing Subsequence

Given an array with N elements, you need to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in strictly increasing order.
Input Format

Line 1 : An integer N 
Line 2 : Elements of arrays separated by spaces

Output Format

Line 1 : Length of longest subsequence

Input Constraints

1 <= n <= 10^3

Sample Input :

6
5 4 11 1 16 8

Sample Output 1 :

3

Sample Output Explanation

Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).

Sample Input 2:

3
1 2 2

Sample Output 2 :

2

*/


using namespace std;

/*
int helper(int *arr,int n,int x,int i){
  if(i==n)return 0;
  if(arr[i]>=x)
    return max(1+helper(arr,n,arr[i],i+1),helper(arr,n,x,i+1));
  else return helper(arr,n,x,i+1);
}
 int lis(int arr[], int n) {
		
	return helper(arr,n,0,0);
 }
 
 
*/

int lis(int arr[], int n) {
  
  if(n==0)return 0; 
 int *ans=new int [n];
 
  ans[0]=1;
  int max;
  
  for(int i=1;i<n;i++){
    max=0;
    for(int j=i-1;j>=0;j--){
      if(arr[i]>arr[j]){
        if(ans[j]>max)
          max=ans[j];
      }
    }
    
    ans[i]=1+max;
  }
  
  max=0;
  for(int i=0;i<n;i++){
    if(ans[i]>max)
      max=ans[i];
  }
  
  delete [] ans;
	return max;  
}


