
/*bool func(int n,int x,int y){
   if(n==x || n==y || n==1)
    return true;
  
  bool p=false,q=false,r=false;
  if(n-1>=1)
    p=func(n-1,x,y)^1;
  if(n-x>=1)
  	q=func(n-x,x,y)^1;
  if(n-y>=1)
  	r=func(n-y,x,y)^1;
  
  if(p||q||r)
    return true;
  else return false;
}
string solve(int n, int x, int y){
  
 bool m=func(n,x,y);
  if(m) return "Beerus";
  else return "Whis";
    
}

*/

string solve(int n, int x, int y){
  
  bool ans [n+1];
  for(int i=0;i<=n;i++)ans[i]=false;
  
  for(int i=1;i<=n;i++){
    if(i==1 || i==x || i==y)ans[i]=true;
    else{
      bool p=false,q=false,r=false;
      if(i-1>=1)
        p=ans[i-1]^1;
      if(i-x>=1)
        q=ans[i-x]^1;
      if(i-y>=1)
        r=ans[i-y]^1;
      
      if(q||p||r)
      ans[i]=true;
      else
        ans[i]=false;
    }
    
    
  }
  
  
 bool m=ans[n];
  if(m) return "Beerus";
  else return "Whis";
    
}