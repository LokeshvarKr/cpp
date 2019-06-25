#include<climits>

int min(int a,int b){
  return a<b?a:b;
}
int findMaxSquareWithAllZeros(int** arr, int row, int col){
    
	int **ans=new int*[row];
  for(int i=0;i<row;i++){
    ans[i]=new int[col];
    for(int j=0;j<col;j++){
      ans[i][j]=-1;
    }
  }
  
  
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      if((i==0 || j==0) && arr[i][j]==0)
        ans[i][j]=1;
      else {
        	if(arr[i][j]==0)
        		ans[i][j]=1+min( min( ans[i-1][j] , ans[i][j-1] ) , ans[i-1][j-1] );
        	else
              	ans[i][j]=0;
      }
    }
  }
  
  int max=INT_MIN;
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      if(ans[i][j]>max)
        max=ans[i][j];
    }
  }
  
  for(int i=0;i<row;i++){
    delete [] ans[i];
  }
  	delete [] ans;
  
  return max;
    
}