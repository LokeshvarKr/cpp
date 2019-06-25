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

