
/*
Code : Staircase using Dp

A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Input format :

Integer n (No. of steps)

Constraints :
n <= 70
Sample Input 1:

4

Sample Output 1:

7
*/


//Dynmic

/*
long staircase(int n){
   
  
  long *a=new long  [n+1];
  
  a[0]=0;
  a[1]=1;
  a[2]=2;
  a[3]=4;
  long  ans;
  
  for(int i=4;i<=n;i++){
    a[i]=a[i-3]+a[i-2]+a[i-1];
    
  }
  
 ans=a[n];
  delete [] a;
  
  
  return ans;
    
}

*/


long staircase(int n){
   
  long a1=1,a2=2,a3=4,a;  

  if(n==1)return a1;
  if(n==2)return a2;
  if(n==3)return a3;
  
  for(int i=4;i<=n;i++){
    a=a1+a2+a3;
    
    a1=a2;
    a2=a3;
    a3=a;
  }
  
  
  return a;
    
}

