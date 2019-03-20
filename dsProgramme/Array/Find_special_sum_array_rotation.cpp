/*

Find maximum value of Sum( i*arr[i]) with only rotations on given array allowed

Given an array, only rotation operation is allowed on array. We can rotate the array as many times as we want. Return the maximum possbile of summation of i*arr[i].

Example:

Input: arr[] = {1, 20, 2, 10}
Output: 72
We can 72 by rotating array twice.
{2, 10, 1, 20}
20*3 + 1*2 + 10*1 + 2*0 = 72

Input: arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9};
Output: 330
We can 330 by rotating array 9 times.
{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
0*1 + 1*2 + 2*3 ... 9*10 = 330

*/
#include<iostream>
using namespace std;
int sum(int *a,int n)
{
	int SUM=0;
	for(int i=0;i<n;i++)
	SUM=SUM+i*a[i];
return SUM;

}
int rotate(int *a,int n)
{
	int temp=a[0];
	for(int i=0;i<n-1;i++)
	a[i]=a[i+1];

	a[n-1]=temp;

}
int findSum(int *a,int n)
{
	int s;
	int max=sum(a,n);
	for(int i=0;i<n;i++)
	{
		rotate(a,n);
		s=sum(a,n);
		if(s>max)
		max=s;
	}
return max;
}
int main()
{
int n;
cin>>n;
int *a=new int[n];
for(int i=0;i<n;i++)cin>>a[i];
cout<<findSum(a,n)<<endl;
delete a;
return 0;
}



