#include<iostream>
using namespace std;
void linear_search(int arr[],int n,int item)
{
	int i=0;
	while(arr[i]!=item)
		i++;
	if(i<n)
	cout<<arr[i]<<"  at position "<<i;
	else
	cout<<"Not found"<<endl;
}
int main()
{
	int n;
	cout<<"Enter size of array"<<endl;
	cin>>n;
	int arr[n+1];
	cout<<"Enter array elements"<<endl;
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int item; 
	cout<<"Enter item to be search"<<endl;
	cin>>item;
	arr[n]=item;
	linear_search(arr,n,item);

	return 0;
}
