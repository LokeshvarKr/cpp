/*
Given an array of integers, find a combination of four elements in the array whose sum is equal to a given value X.

Input:
First line consists of T test cases. First line of every test case consists of an integer N, denoting the number of elements in an array. Second line consists of N spaced array elements. Third line of every test case X.

Output:
Single line output, print 1 if combination is found else 0.

Constraints:
1<=T<=100
1<=N<=100

Example:
Input:
1
6
1 5 1 0 6 0
7
Output:
1
*/
#include <iostream>
#include<algorithm>
using  namespace std;
int comb(int *a,int *data,int s,int e,int index,int r,int x)
{
    if(index==r)
    {
        int sum=0;
        for(int j=0;j<r;j++)
        sum=sum+data[j];
        
        if(sum==x)
        return 1;
        else
        return 0;
    }
    else
    {
        int p=0;
        for(int i=s;i<=e && e-i+1>=r-index;i++)
        {
            data[index]=a[i];
            p=comb(a,data,s+1,e,index+1,r,x);
            if(p==1)
            break;
            if(i<e)
            {
            while(a[i]==a[i+1])
                i++;
            }
            
        }
    
    return p;
    }
    
}
void comb_sum(int *a,int n,int r,int x)
{
    int data[r];
     sort(a,a+n);
    int p=0;
    p=comb(a,data,0,n-1,0,r,x);
    
    if(p==1)
    cout<<1<<endl;
    else
    cout<<0<<endl;
}

int main() 
{
	int t,n,x;
	cin>>t;
	for(int i=0;i<t;i++)
	{
	    cin>>n;
	    int *a=new int[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cin>>x;
	    comb_sum(a,n,4,x);
	    delete []a;
	}
	return 0;
}
