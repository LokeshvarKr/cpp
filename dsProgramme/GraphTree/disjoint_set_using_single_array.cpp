#include<iostream>
using namespace std;
void PRINT(int A[],int n)
{
	for(int i=0;i<n;i++)
	cout<<A[i]<<" ";
}
void MAKESET(int A[],int n)
{
	for(int i=0;i<n;i++)
		A[i]=-1;
}
int FINDSET(int A[],int x)
{
	if(A[x]>=0)
	return FINDSET(A,A[x]);
	
	return x;
}
void UNION(int A[],int x,int y)
{
	int p=FINDSET(A,x);
	int q=FINDSET(A,y);

	if(A[p]<A[q])
		A[y]=p;
	else if(A[p]>A[q])
		A[x]=q;

	else		//(A[p]==A[q])
	{
		A[y]=A[y]-1;
		A[x]=q;
	}
}
int main()
{
	int n;
	cout<<"Enter no. of elements "<<endl;

	cin>>n;

	int A[n];
	
	MAKESET(A,n);
	
	int a,x,y,p,var;
	
	while(1)
	{
		cout<<"Enter 1 for FIND-SET operation"<<endl;
		cout<<"Enter 2 for Union operation"<<endl;
		cout<<"Enter 3 for Quiet "<<endl;

		cin>>a;

		switch(a)
		{
				var=0;
			case 1 :
				cout<<"Enter an element to perform FIND-SET operation"<<endl;
				cin>>x;
				p=FINDSET(A,x);
				cout<<p<<endl;
				break;
			case 2 :
				cout<<"Enter two elements to perform UNION operation"<<endl;
				cin>>x>>y;
				UNION(A,x,y);
				PRINT(A,n);
				break;
			case 3 :
				var=1;
				break;
		}
			 
	

	if(var==1)
	break;
	}



return 0;

}
