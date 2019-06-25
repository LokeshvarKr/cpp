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
