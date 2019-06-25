





#include<climits>

//brute force

/*
int mcm_recursive(int *p,int s,int e){
  if(s==e)return 0;
  if(e-s==1)return 0;
  
  int min=INT_MAX;
  for(int i=s+1;i<e;i++){
  int x = mcm_recursive(p,s,i) + mcm_recursive(p,i,e) + p[s]*p[i]*p[e];
  
    if(x<min) min=x;
  }
   return min;
  
  
}
int mcm(int* p, int n){
  return mcm_recursive(p,0,n);
}

*/


/*
int mcm_memoization(int *p,int **ans,int s,int e){
  if(s==e || e-s==1){
    ans[s][e]=0;
  return ans[s][e];
    
  }
  
  if(ans[s][e]!=-1) 
    return ans[s][e];
  
  else {
    
  	int min=INT_MAX;
  	for(int i=s+1;i<e;i++){
    int x=mcm_memoization(p,ans,s,i)+mcm_memoization(p,ans,i,e)+p[s]*p[i]*p[e];
    if(x<min)min=x;
  	}
  	ans[s][e]=min;
  	return ans[s][e];
  }
  
}
int mcm(int* p, int n){

	int **ans=new int*[n+1];
  	
  for(int i=0;i<=n;i++){
    ans[i] =new int [n+1];
    for(int j=0;j<=n;j++){
      ans[i][j]=-1;
    }
  }
 
  int ansRet=mcm_memoization(p,ans,0,n);
  
  
  for(int i=0;i<=n;i++){
    delete [] ans[i];
  }
 
  delete [] ans;
  
  return ansRet;
  
}
*/

int mcm(int* p, int n){

	int **ans=new int*[n+1];
  	
  for(int i=0;i<=n;i++){
    ans[i] =new int [n+1];
    for(int j=0;j<=n;j++){
      ans[i][j]=-1;
    }
  }
 
  int min,x;
  for(int i=n-1;i>=0;i--)
  {
    for(int j=i+1;j<=n;j++)
    {
      
      if(j-i==1 || i==j)
        ans[i][j]=0;
      else 
      {
      		min=INT_MAX;
 
      		for(int k=i+1;k<j;k++)
        	{
        		 x= ans[i][k] + ans[k][j] + p[i]*p[k]*p[j];
        		if(x<min)
                  min=x;
      		}
        
      		ans[i][j]=min;
        
      }
      
  	}
  }
  
  int ansRet=ans[0][n];
  
  
  for(int i=0;i<=n;i++){
    delete [] ans[i];
  }
 
  delete [] ans;
  
  return ansRet;
  
}











