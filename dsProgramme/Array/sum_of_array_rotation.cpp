
#include<iostream>
using namespace std;

void findSum(int *a,int n)
{
	int r=0,sum=0,max;
	for(int i=0;i<n;i++)sum+=a[i];
	for(int i=0;i<n;i++)r+=i*a[i];
	max=r;
	for(int j=1;j<n;j++)
	{
		r=r+sum-n*a[n-j];
		if(r>max)
		max=r;
	}
	cout<<max<<endl;

}
int main()
{
int n;
cin>>n;
int *a=new int[n];
for(int i=0;i<n;i++)cin>>a[i];
findSum(a,n);
delete a;
return 0;
}
