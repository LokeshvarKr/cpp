#include<iostream>
#include<algorithm>
using namespace std;
bool TriplateSum(int *a,int n,int s)
{
	int l,r;
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		l=i+1;
		r=n-1;
		
		while(l<r)
		{
			
			if(a[i]+a[l]+a[r]==s)
			return true;
			else if(a[i]+a[l]+a[r]<s)
				l++;
				
			else
				r--;

		}
	
	}	

	return false;


}
int main()
{
	int n,sum;
	cout<<"Enter size of array"<<endl;
	cin>>n;

	int *a=new int[n];

	cout<<"Enter array elements"<<endl;
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	cout<<"Enter sum of triplate"<<endl;
	cin>>sum;

	if(TriplateSum(a,n,sum))
	cout<<"yes present"<<endl;
	else
	cout<<"No not present"<<endl;


	return 0;

}
