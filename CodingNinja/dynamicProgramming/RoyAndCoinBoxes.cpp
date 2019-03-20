/*
Roy and Coin Boxes

Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.

After M days, Roy has a query: How many coin boxes have atleast X coins.
He has Q such queries.
Input
First line contains N - number of coin boxes.
Second line contains M - number of days. Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
Each of next Q lines contain a single integer X.a
Output
For each query output the result in a new line.
Constraints
1 ≤ N ≤ 1000000

1 ≤ M ≤ 1000000

1 ≤ L ≤ R ≤ N

1 ≤ Q ≤ 1000000

1 ≤ X ≤ N
Sample Input
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2
Sample Output
6
0
0
4
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;cin>>n;
  int m;cin>>m;
  
  int *s=new int [n+1];
  int *e=new int [n+1];
  
  int *box=new int[n+1];//index are box no.
  int *coin=new int[n+1];//index are coins 
  int *atLeasetCoin=new int[n+1];//indexs are at least coins  
  for(int i=0;i<=n;i++){
    coin[i]=0;
    box[i]=0;
    atLeasetCoin[i]=0;
  }
  
  for(int i=0;i<=n;i++){
    s[i]=0;
    e[i]=0;
  }
  
  while(m--){
    int l,r;cin>>l>>r;
    s[l]+=1;e[r]+=1;
  }
  
  for(int i=1;i<=n;i++){
    box[i]=s[i]+box[i-1]-e[i-1];
   
  }

  for(int i=1;i<=n;i++){
    coin[box[i]]+=1;
  }
   atLeasetCoin[n]=coin[n];
  for(int i=n-1;i>=1;i--){
   atLeasetCoin[i]=coin[i]+ atLeasetCoin[i+1];
    
  }
  
  
  int q;cin>>q;
  while(q--){
    int x;
    cin>>x;
    cout<< atLeasetCoin[x]<<endl;
  }
  
  
  
  delete [] s;
  delete [] e;
  delete [] coin;
  delete [] box;
    return 0;
  
}

