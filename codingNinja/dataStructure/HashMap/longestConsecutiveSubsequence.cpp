#include<unordered_map>

vector<int> longestSubsequence(int *a, int n){
	
  unordered_map<int,int> s;
  
  int i=0;
  while(i<n){
    s[a[i]]=1;
    i++;
  }
  
  int ans=1,st=a[0];
  
  for(i=0;i<n;i++){
    if(s.count(a[i]-1)==0)
    {
      int j=a[i];
      while(s.count(j) > 0)
        j++;
      
      if(j-a[i] > ans){
        st=a[i];
        ans=j-a[i];
      }
    }
  }
  
    vector<int> v;
   i=0;
  while(i<ans){
    v.push_back(st+i);
    i++;
  }
  
  return v;
}