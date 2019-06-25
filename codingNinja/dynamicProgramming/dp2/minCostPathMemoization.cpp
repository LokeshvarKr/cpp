#include<iostream>
#include<cstring>
using namespace std;

/*
int ed(string s1,string s2,int **ans){
  
  int m=s1.length();
  int n=s2.length();
  if(m==0||n==0){
    ans[m][n]=max(m,n);
    return ans[m][n];
  }
  
  if(ans[m][n]!=-1)
    return ans[m][n];
  else {
    
  	if(s1[0]==s2[0]){
    	ans[m][n]=ed(s1.substr(1),s2.substr(1),ans);
    }
  	else {
    	int x=1+ed(s1.substr(1),s2,ans);
      	int y=1+ed(s1,s2.substr(1),ans);
      	int z=1+ed(s1.substr(1),s2.substr(1),ans);
      
      ans[m][n]=min(min(x,y),z);
    }
    
    return ans[m][n];
  
  }
  
  
}
int editDistance(string s1, string s2){

  int m=s1.length();
  int n=s2.length();
  
  int **ans=new int*[m+1];
  
  for(int i=0;i<=m;i++){
    ans[i]=new int[n+1];
    for(int j=0;j<=n;j++){
      ans[i][j]=-1;
    }
  }
  
  int AnsRet=ed(s1,s2,ans);
  
  for(int i=0;i<=m;i++){
    delete [] ans[i];
  }
  delete [] ans;
  
  return AnsRet;
}

*/

int editDistance(string s1, string s2){

  int m=s1.length();
  int n=s2.length();
  
  int **ans=new int*[m+1];
  
  for(int i=0;i<=m;i++){
    ans[i]=new int[n+1];
    for(int j=0;j<=n;j++){
      ans[i][j]=-1;
    }
  }
  
  for(int i=0;i<=m;i++){
    for(int j=0;j<=n;j++){
      
      if(i==0 || j==0)
        ans[i][j]=max(i,j);
      else {
			if(s1[i-1]==s2[j-1])
              ans[i][j]=ans[i-1][j-1];
        	else {
              ans[i][j]=1 + min( min( ans[i-1][j] , ans[i][j-1] ) , ans[i-1][j-1] );
            }
      }
    
    }
  }
  
  int AnsRet=ans[m][n];
  
  for(int i=0;i<=m;i++){
    delete [] ans[i];
  }
  delete [] ans;
  
  return AnsRet;
}
