
int balancedBTs(int h) {
if(h<=1)
  return 1;
  int x,y;
  int mod=1000000007;
  x=balancedBTs(h-1);
  y=balancedBTs(h-2);
  
  int temp1=(int)(((long)(x)*x)%mod);
  int temp2=(int)(((long)(x)*y*2)%mod);
  int ans=(temp1+temp2)%mod;
  return ans;
}
