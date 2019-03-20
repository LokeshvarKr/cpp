#include <bits/stdc++.h>
using namespace std;
/*
int maxBlassing(string b1,string b2,int n,int m,int l,int k){
  if(l < k && (n==0 || m==0)) return -1;
  if(l==k)return 0;
  
  if(b1[0]==b2[0]){
    
    int retAns1=maxBlassing(b1.substr(1),b2.substr(1),n-1,m-1,l+1,k);
    int retAns2=maxBlassing(b1.substr(1),b2.substr(1),n-1,m-1,l,k);
   	if(retAns1==-1 && retAns2==-1)return -1;
   	else{
      retAns1+=int(b1[0]);
		return max(retAns1,retAns2);
    }
  }
  else{
    int retAns1=maxBlassing(b1.substr(1),b2,n-1,m,l,k);
    int retAns2=maxBlassing(b1,b2.substr(1),n,m-1,l,k);
    return max(retAns1,retAns2);
  }
  
}
*/

int maxBlassingMemo(string b1,string b2,int ***ans,int n,int m,int i,int j,int l,int k){
  if(l < k && (i==n || j==m)) return -1;
  if(l==k)return 0;
  
  if(ans[i][j][l]!=-2)
    return ans[i][j][l];
  if(b1[i]==b2[j]){
    
    int retAns1=maxBlassingMemo(b1,b2,ans,n,m,i+1,j+1,l+1,k);
    int retAns2=maxBlassingMemo(b1,b2,ans,n,m,i+1,j+1,l,k);
   	
    if(retAns1==-1 && retAns2==-1)
      ans[i][j][l]=-1;
   	else{
      retAns1+=int(b1[i]);
		ans[i][j][l]=max(retAns1,retAns2);
    }
    
  }
  else{
    int retAns1=maxBlassingMemo(b1,b2,ans,n,m,i+1,j,l,k);
    int retAns2=maxBlassingMemo(b1,b2,ans,n,m,i,j+1,l,k);
    ans[i][j][l]= max(retAns1,retAns2);
  }
  
  return ans[i][j][l];
  
}


int main()
{
  int t;
  cin>>t;
  while(t--){
    string b1;
    string b2;
    cin>>b1>>b2;
    int k;
    cin>>k;
    int l=0;
    int n=b1.length();
    int m=b2.length();
    
    //recursive solution
    //int retAns=maxBlassing(b1,b2,n,m,l,k);
    
    int ***ans=new int**[n+1];
    for(int i=0;i<=n;i++){
      ans[i]=new int*[m+1];
      
      for(int j=0;j<=m;j++){
        ans[i][j]=new int[l+1];
        
        for(int k=0;k<=l;k++)
        ans[i][j][k]=-2;
        
      }
      
    }
   
    //memoization
    int retAns=maxBlassingMemo(b1,b2,ans,n,m,0,0,l,k);
    

   //dp tabulation
 /*
    for(int i=0;i<=n;i++){
     for(int j=0;j<=n;j++){
       for(int l=0;l<=k;l++){
         
       }
     }
   }
    
  */  
    
    
    if(retAns < 0){
      retAns=0;
    }
    
    cout<<retAns<<endl;
    
  }
    return 0;
}

