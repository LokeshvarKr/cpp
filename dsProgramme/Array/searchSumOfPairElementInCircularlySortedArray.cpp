/*

Given a sorted and rotated array, find if there is a pair with a given sum

Given an array that is sorted and then rotated around an unknown point. Find if array has a pair with given sum ‘x’. It may be assumed that all elements in array are distinct.

Examples :

Input: arr[] = {11, 15, 6, 8, 9, 10}, x = 16
Output: true
There is a pair (6, 10) with sum 16

Input: arr[] = {11, 15, 26, 38, 9, 10}, x = 35
Output: true
There is a pair (26, 9) with sum 35

Input: arr[] = {11, 15, 26, 38, 9, 10}, x = 45
Output: false
There is no pair with sum 45.

*/
#include <iostream>
using namespace std;
int findPivot(int *a,int n)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        if(low==high)
        return high;
        if(a[low]<a[high])
        return high;
        mid=(low+high)/2;
        if(a[mid-1]<a[mid] && a[mid+1]<a[mid])
        return mid;
        else if(a[low]<a[mid])
        low=mid+1;
        else if(a[mid]<a[high])
        high=mid-1;
    }
    return -1;
}
void findSum(int *a,int n,int x)
{
    int p=findPivot(a,n);
    if(p==-1){cout<<"array is not in circularly sorted";return;}
    int i=(p+1)%n;
    int j=p;
    while(i!=j)
    {
        if(a[i]+a[j]==x){cout<<"found";return;}
        else if(a[i]+a[j]<x)i=(i+1)%n;
        else if(a[i]+a[j]>x)j=(j-1+n)%n;
    }
    if(i==j)
    cout<<"Not found";
    
}
int main() {
    int n,x;
    cin>>n>>x;
    int *a=new int[n];
    for(int i=0;i<n;i++)cin>>a[i];
    findSum(a,n,x);
	return 0;
}
