/*
2 vs 3

The fight for the best number in the globe is going to finally come to an end.The top two contenders for the best number are number 2 and number 3.It's the final the entire world was waiting for. Expectorates from all across the globe came to witness the breath taking finals.
The finals began in an astonishing way.A common problem was set for both of them which included both these number.The problem goes like this.
Given a binary string (that is a string consisting of only 0 and 1). They were supposed to perform two types of query on the string.
Type 0: Given two indices l and r.Print the value of the binary string from l to r modulo 3.

Type 1: Given an index l flip the value of that index if and only if the value at that index is 0.
The problem proved to be a really tough one for both of them.Hours passed by but neither of them could solve the problem.So both of them wants you to solve this problem and then you get the right to choose the best number in the globe.
Input:
The first line contains N denoting the length of the binary string .
The second line contains the N length binary string.Third line contains the integer Q indicating the number of queries to perform.
This is followed up by Q lines where each line contains a query.
Output:
For each query of Type 0 print the value modulo 3.
Constraints:
1<= N <=10^5

1<= Q <= 10^5

0 <= l <= r < N
Sample Input
5
10010
6
0 2 4
0 2 3
1 1
0 0 4
1 1
0 0 3
Sample Output
2
1
2
1

*/
#include<bits/stdc++.h>
using namespace std;

void builtTree(char *str, int *modValue,int *tree,int s,int e,int treeNode){
   if(s==e){
     if(str[s]=='0')
       tree[treeNode]=0;
     else 
       tree[treeNode]=1;
     
     return;
   }
   
   int mid=s+(e-s)/2;
   builtTree(str,modValue,tree,s,mid,treeNode*2);
   builtTree(str,modValue,tree,mid+1,e,treeNode*2+1);
   
  tree[treeNode]=((tree[treeNode*2] * modValue[e-mid])%3 + tree[treeNode*2+1])%3;
   
}
void update(char *str,int *modValue,int *tree,int s,int e,int treeNode,int index){
  //when s==e==index
  if(s==e){
    if(str[s]=='0'){
      str[s]='1';
      tree[treeNode]=1;
    }
    return;
  }
  int mid=s+(e-s)/2;
  if(index <= mid)
    update(str,modValue,tree,s,mid,treeNode*2,index);
  else
    update(str,modValue,tree,mid+1,e,treeNode*2+1,index);
  
  tree[treeNode]=((tree[treeNode*2]*modValue[e-mid])%3 + tree[treeNode*2+1])%3;
}



// UPDATED QUERY FUNCTION
// first element of pair represent ans for this range
// second element represents no. of digits in range

pair<int,int> query(int *modValue,int *tree,int s,int e,int treeNode,int l,int r){
  pair<int,int> ret;
  ret.first=0; ret.second=0;
  if(e < l || s > r)return ret;
  if(s>= l && e <=r){
    	ret.first=tree[treeNode];
    	ret.second=((e-s)+1);
    	return ret;
  }
  int mid=s+(e-s)/2;
  pair<int,int> ans1=query(modValue,tree,s,mid,treeNode*2,l,r);
  pair<int,int> ans2=query(modValue,tree,mid+1,e,treeNode*2+1,l,r);
  ret.first=((ans1.first*modValue[ans2.second])%3 + ans2.first)%3;
  ret.second=ans1.second + ans2.second;
  return ret; 
}

int main() {
	int n;cin>>n;
  	char *str=new char[n];
  	cin>>str;
  	int *tree=new int [4*n];
  	int *modValue=new int[n];// stores ((2)^i)%3
  int x=1;
  modValue[0]=1;
  for(int i=1;i<n;i++){
      x=(x*2)%3;
    modValue[i]=x;
  }
  
 builtTree(str,modValue,tree,0,n-1,1);
  int q;cin>>q;
  while(q--){
	int x;
    cin>>x;
    if(x==0){
      int y,z;
      cin>>y>>z;
      //int result=query(modValue,tree,0,n-1,1,y,z);
      // function return pair
      
      pair<int,int> result=query(modValue,tree,0,n-1,1,y,z);
      cout<<result.first<<endl;
      //cout<<result<<endl;
    }
    else{
     	int y;
      cin>>y;
      update(str,modValue,tree,0,n-1,1,y);
    }
  }
  
  delete [] str;
  delete [] modValue;
  delete [] tree;
  return 0;
}