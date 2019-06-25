/*


Longest consecutive subsequence  (asked in amazon)
          
Given an array of integers, find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.

Input:

The first line of input contains T, number of test cases.

First line of line each test case contains a single integer N.

Next line contains N integer array.

Output:

Print the output of each test case in a seprate line.

Constraints:

1<=T<=100
1<=N<=100
0<=a[i]<=500

Example:

Input:

2
7
2 6 1 9 4 5 3
7
1 9 3 10 4 20 2

Output:

6
4
*/

#include<iostream>
#include<unordered_map>
using namespace std;

int longestConsecutiveSubarray(int *a,int n){
        
        unordered_map<int,bool> s;
        int ans=0;
        
        int i=0;
        while(i<n){
         s[a[i]]=true;   
         i++;
        }
        i=0;
        for(;i<n;i++){
            if(s.count(a[i]-1)==0){
                int j=a[i];
                
                while(s.count(j) > 0)
                j++;
                
                ans=max(ans,j-a[i]);
            }
        }
        
        return ans;
}
int main()
{
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        int *a=new int[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        
        
        cout<<longestConsecutiveSubarray(a,n)<<endl;
        delete [] a;
    }
    
	return 0;
}
