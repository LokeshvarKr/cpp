//code is written in two ways
#include<iostream>
using namespace std;

int binary_search(int a[],int n,int item,bool first_search)
{
	int low=0,up=n-1,mid,result=-1;
	while(low<=up)
	{
		mid=(low+up)/2;
		if(item==a[mid])
		{
			result=mid;
			if(first_search)
			up=mid-1;
			else
			low=mid+1;
		}
		else if(item<a[mid])
			up=mid-1;
		else
			low=mid+1;
	}

	return result;

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
	
	int first=binary_search(a,n,item,true);
	if(first==-1)
	cout<<"item not found"<<endl;
	else
	{
		int last=binary_search(a,n,item,false);
		cout<<"item present  "<<last-first+1<<" times"<<endl;
	}

return 0;


}



/*
#include<iostream>
using namespace std;
int FindFirst(int a[],int n,int item)
{
	int low=0,up=n-1,mid,result=-1;
	while(low<=up)
	{
		mid=(low+up)/2;
		if(item==a[mid])
		{
			result=mid;
			up=mid-1;
		}
		else if(item<a[mid])
			up=mid-1;
		else
			low=mid+1;
	}

	return result;

}
int FindLast(int a[],int n,int item)
{
	int low=0,up=n-1,mid,result=-1;
	while(low<=up)
	{
		mid=(low+up)/2;
		if(item==a[mid])
		{
			result=mid;
			low=mid+1;
		}
		else if(item<a[mid])
			up=mid-1;
		else
			low=mid+1;
	}

	return result;

}
int count_occurence_of_a_Number(int a[],int n,int item)
{
	int first=FindFirst(a,n,item);

	if(first==-1)
		return 0;
	else
	{	
		int last=FindLast(a,n,item);
		return (last-first+1);
	}
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
	int x=count_occurence_of_a_Number(a,n,item);
	if(x==0)
	cout<<"item not found"<<endl;
	else
	cout<<"item is perent "<<x<<" times"<<endl;
	return 0;

}
*/
