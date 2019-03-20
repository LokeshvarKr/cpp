
/*
int helper_countBTs(int *a,int h){
  if(h<=1)return 1;
  
  if(a[h]!=-1)
    return a[h];
  else
  {
    int mod=1000000007;
    int x=helper_countBTs(a,h-1);
    int y=helper_countBTs(a,h-2);
    
    int temp1=(int)(((long)(x)*x)%mod);
    int temp2=(int)(((long)(x)*y*2)%mod);
    
    int ans=(temp1+temp2)%mod;
    
    a[h]=ans;
    return a[h];
  }  
  
}

int binaryTreesOfHeightH(int h) {
    
  int *a=new int [h+1];
  
  for(int i=0;i<=h;i++) a[i]=-1;
  
  return helper_countBTs(a,h);

}

*/

//Dynamic bottom up approch

int binaryTreesOfHeightH(int h) {
  
  int *a=new int[h+1];
  
  a[0]=1;
  a[1]=1;
  int ans,x,y,temp1,temp2,mod=1000000007;
  for(int i=2;i<=h;i++){
    x=a[i-1];
    y=a[i-2];
    
    temp1=(int)(((long)(x)*x)%mod);
    temp2=(int)(((long)(x)*y*2)%mod);
    
    a[i]=(temp1+temp2)%mod;
  }
  
  ans=a[h];
  delete [] a; 
  return ans;
  
}










