#include<iostream>
using namespace std;
int CircularlySortedArraySearch(int arr[],int n,int item)
{
	int low=0,high=n-1,mid;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(item==arr[mid])
			return mid;

		else if(arr[low]<=arr[mid])
		{
			if(item>=arr[low] && item<arr[mid])
				high=mid-1;
			else    low=mid+1;
		}
		else		//(arr[mid]<arr[high])
		{
			if(item>arr[mid] && item <= arr[high])
				low=mid+1;
			else
				high=mid-1;
		}

	}
	return -1;

}
int main()
{
	int n;
	cout<<"Enter no. of element in array"<<endl;
	cin>>n;

	int *arr=new int [n];

	for(int i=0;i<n;i++)
		cin>>arr[i];

	int item;
	cout<<"Enter item to be search"<<endl;
	cin>>item;
	int r=CircularlySortedArraySearch(arr,n,item);
	if(r==-1)
	cout<<"Not found "<<endl;
	else
	cout<<"Found at index  "<<r<<endl;

return 0;

}
