
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
