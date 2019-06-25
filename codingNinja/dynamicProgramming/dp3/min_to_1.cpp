/*Code : Min Steps to 1 using DP
Send Feedback
Given a positive integer n, find the minimum number of steps s, that takes n to 1. You can perform any one of the following 3 steps.

1.) Subtract 1 from it. (n= n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n%2==0, then n= n/2 ) ,
3.) If its divisible by 3, divide by 3. (if n%3 == 0, then n = n / 3 ). 

The time complexity of your code should be O(n).
Input format :

Line 1 : A single integer i.e. n

Output format :

Line 1 : Single integer i.e number of steps

Constraints :
1 <= n <= 10^5
Sample Input 1 :

4

Sample Output 1 :

2 

Sample Output 1 Explanation :
For n = 4
Step 1 : n = 4/2 = 2
Step 2 : n = 2/2 = 1
Sample Input 2 :

7

Sample Output 2 :

3

Sample Output 2 Explanation :
For n = 7
Step 1 : n = 7 ­ - 1 = 6
Step 2 : n = 6 / 3 = 2
Step 3 : n = 2 / 2 = 1

*/

//


#include<climits>
/*
//Brute fource (method 1)
int countStepsTo1(int n){

	if(n==1)
      return 0;
  int ans1=INT_MAX,ans2=INT_MAX,ans3=INT_MAX;
  	if(n%3==0)
  	ans1=countStepsTo1(n/3);
  	if(n%2==0)
    ans2=countStepsTo1(n/2);
  	
 	ans3=countStepsTo1(n-1);
  
  return 1+min(ans1,min(ans2,ans3));
  	
}
*/


/*
//memoiation top down approach
#include<climits>
int helperCount(int *a,int n){
   if(n==1)
     return 0;
  if(a[n]!=0)
    return a[n];
  else
  {
    int ans1=INT_MAX,ans2=INT_MAX,ans3=INT_MAX;
  
  	ans1=helperCount(a,n-1);
  	if(n%2==0)
    ans2=helperCount(a,n/2);
    if(n%3==0)
 	ans3=helperCount(a,n/3);
  
  a[n]=1+min(ans1,min(ans2,ans3));
    return a[n];
  }	
}
int countStepsTo1(int n){

  int *a=new int[n+1];
  
  for(int i=0;i<=n;i++)
    a[i]=0;
  
  return helperCount(a,n);
  
  
}

*/


//Dynamic bottom up approach
//method 3(more ifficient) bottom down approach DP

int countStepsTo1(int n){

   int *a=new int [n+1];
  
  	a[1]=0;
  	a[0]=0;
  	
  
  int ans1,ans2,ans3;
  for(int i=2;i<=n;i++){
  ans1=INT_MAX;ans2=INT_MAX;ans3=INT_MAX;
    
    ans1=a[i-1];
    
    if(i%2==0)
      ans2=a[i/2];
    if(i%3==0)
      ans3=a[i/3];
    
    a[i]=1+min(ans1,min(ans2,ans3));
  }
  
  return a[n];

}

