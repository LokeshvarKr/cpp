/*
Loot Houses

A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
Input Format

Line 1 : An integer N 
Line 2 : N spaced integers denoting money in each house

Output Format

 Line 1 : Maximum amount of money looted

Input Constraints

1 <= n <= 10^4
1 <= A[i] < 10^4

Sample Input :

6
5 5 10 100 10 5

Sample Output 1 :

110



*/
int max(int a,int b){
  if(a>b)return a;else return b;
}
/*
int getMaxMoney(int arr[], int n){

	
 if(n==0)return 0;
 if(n==1)return arr[0];

  
  return max(arr[0] + getMaxMoney(arr+2,n-2) , getMaxMoney(arr+1,n-1));
  
}
*/

/*
int getMaxMoney(int arr[], int n){

	
  int *ans=new int[n+1];
  
  for(int i=0;i<=n;i++)ans[0]=0;
  
  ans[1]=arr[0];
  ans [2]=max(arr[1],arr[0]);
  
  for(int i=3;i<=n;i++){
    
    ans[i]=max(arr[i-1]+ans[i-2],ans[i-1]);
  }
 
    return ans[n];
  
}
*/
int helper(int *arr,int *ans,int n){
  if(n==0){
    ans[n]=0;
    return ans[n];
  }
  if(n==1){
    ans[n]=arr[n-1];
    return ans[n];
  }
  if(ans[n]!=-1)return ans[n];
  else {
    ans[n]=max(arr[n-1]+helper(arr,ans,n-2) ,helper(arr,ans,n-1));
    return ans[n];
  }
}
int getMaxMoney(int arr[],int n){
  int ans[n+1]; 
  for(int i=0;i<=n;i++)ans[i]=-1;
  
 	return helper(arr,ans,n);
  
}
  
  
  
  
  
  
  
  
  
  
