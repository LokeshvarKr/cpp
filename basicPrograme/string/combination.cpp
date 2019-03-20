#include<iostream>
using namespace std;
int k=0;
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}
int partition(int arr[],int p, int r)
{
	int x=arr[r];
	int i=p-1;
	int j=p;

		while(j<r)
		{
			if(arr[j] < x )
			{
				i++;
				swap((arr+i),(arr+j));
			}
			j++;
		}
	swap((arr+i+1),(arr+r));
	
	return i+1;

}
void qsort(int arr[],int p,int r)
{
	if(p<r)
	{
		int q=partition(arr,p,r);
		
		qsort(arr,p,q-1);
		qsort(arr,q+1,r);

	}

}
void printComb(int arr[],int data[],int start,int end,int index,int r)
{
	if(index==r)
	{	
		k++;
		for(int j=0;j<r;j++)
		cout<<data[j]<<" ";
	
		cout<<endl;	
	}

	for(int i=start; i<=end && end-i+1>=r-index; i++)
	{
		data[index]=arr[i];
		printComb(arr,data,i+1,end,index+1,r);
		if(i<end)
		{
			while(arr[i]==arr[i+1])
			i++;
		}
	}

}
void combination(int arr[],int n,int r)
{
	int data[r];
	qsort(arr,0,n-1);

	cout<<"sorted array is "<<endl;
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;

	cout<<"combinations are"<<endl;
	printComb(arr,data,0,n-1,0,r);

	cout<<"No. of combinations "<<k<<endl;

}
int main()
{
	int n,r;
	cout<<"Enter no. of element(value of n)"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter  elements"<<endl;
	for(int i=0;i<n; i++)	
	cin>>arr[i];
	cout<<"Enter no. of element to find combinations (value of r) "<<endl;
	cin>>r;
	combination(arr,n,r);
	
	return 0;
}
