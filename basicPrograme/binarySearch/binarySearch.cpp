#include<iostream>
using namespace std;
int binary_search(int a[],int n,int item)
{
	int low=0,up=n-1,mid;
	while(low <= up)
	{
		mid=(low+up)/2;
		if(item<a[mid])
			up=mid-1;
		else if(item>a[mid])
			low=mid+1;
		else
			return mid;
	}

	return -1;

}
int main()
{
	int n;
	cout<<"Enter no. of element "<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter array elements in increasing order"<<endl;
	for(int i=0;i<n;i++)
	cin>>a[i];
	int item;
	cout<<"Enter item to be searched"<<endl;
	cin>>item;
	int x=binary_search(a,n,item);
	if(x==-1)
	cout<<"item not found"<<endl;
	else
	cout<<"item is found at place "<<x<<endl;
	return 0;

}
