
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
  
  
  
  
  
  
  
  
  
  