//priority Queue using min heap
#include<iostream>
using namespace std;
int n;
void MinHeapify(int *A,int i)
{
	int l=2*i+1;
	int r=2*i+2;
	int smallest,temp;
	if(l<n && A[l]<A[i])
		smallest=l;
	else
		smallest=i;
	if(r<n && A[r]<A[smallest])
		smallest=r;
	if(smallest!=i)
	{
		temp=A[i];
		A[i]=A[smallest];
		A[smallest]=temp;
		
		MinHeapify(A,smallest);
	}		

}
void ExtractMin(int *A)
{
	if(n<1)
	{
	cout<<"Error 'Underflow' "<<endl;
	return ;
	}
	
	int min=A[0];
	A[0]=A[n-1];
	n=n-1;
	MinHeapify(A,0);

	cout<<min<<endl;
}
void BuildMinHeap(int *A)
{
	for(int i=(n/2)-1;i>=0;i--)
		MinHeapify(A,i);
}
void HeapDecreaseKey(int *A,int i,int key,int n)
{
	if(key>A[i]){
	cout<<"Error 'New key is bigger than current key' "<<endl;
	return ;
	}
	int temp;
	A[i]=key;
	while(i>0 && A[(i-1)/2]<A[i])
		{
			temp=A[i];
			A[i]=A[(i-1)/2];
			A[(i-1)/2]=temp;
			i=(i-1)/2;
		}
	for(i=0;i<n;i++)
	{
		cout<<A[i]<<" ";
	
	}
		cout<<endl;

}
/*void HeapSort(int *A,int n)
{
	int temp;
	BuildMinHeap(A,n);
 	for(int i=n-1; i>0; i--)
	{
	  	temp=A[0];
		A[0]=A[i];
		A[i]=temp;
		n=n-1;
		MinHeapify(A,0,n);
	}

}*/
int main()
{
//int n;
cout<<"Enter no. of elements:"<<endl;
cin>>n;
int *A=new int[n];
cout<<"Enter elements of array"<<endl;
for(int i=0;i<n;i++)
cin>>A[i];
for(int i=0;i<n;i++)
cout<<A[i]<<" ";
cout<<endl;
BuildMinHeap(A);
int x,var,key,position;
while(1)
{

	cout<<"Enter 1 for extract Min functionity"<<endl;
	cout<<"Enter 2 for Increase key value"<<endl;
	cout<<"Enter 3 for Quite"<<endl;
	cin>>x;
	switch(x)
	{
		var=0;
	case 1 : ExtractMin(A);
		cout<<"Now the elements are:"<<endl;
		for(int i=0;i<n;i++)
			cout<<A[i]<<" ";
		cout<<endl;
		break;
	case 2 :cout<<"Enter key value and its position"<<endl;
		cin>>key>>position;
		 		
		HeapIncreaseKey(A,position-1,key,n);
		break;
	case 3 : var=1;
		 break;
	}
	if(var==1)
	break;
}
/*for(int i=0;i<n;i++)
	cout<<A[i]<<" ";
	cout<<endl;
*/
delete [] A;
return 0;
}
