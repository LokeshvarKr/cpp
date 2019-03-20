#include<iostream>
using namespace std;
void fib(int n)
{
	int prev=0,current=1,next=1;
	cout<<current<<" "<<next<<" ";
	for(int i=3;i<=n;i++)
	{
		prev=current;
		current=next;
		next=prev+current;
		cout<<next<<" ";
	}

}
int RecFib(int n)
{
	if(n<=2)
	return 1;
	
	return RecFib(n-1)+RecFib(n-2);

}
int main()
{
	int n;
	int x;
	int var=0;
	while(1)
	{
		
	cout<<"Entre 1 for find fib of n"<<endl;
	cout<<"Enter 2 for print fib series"<<endl;
	cout<<"Enter 3 for quit"<<endl;
	cin>>x;
	switch(x)
	{
	case 1 :	
		cout<<"Enter a number "<<endl;
		cin>>n;
		cout<<RecFib(n)<<endl;
		break;
	case 2 : 
		cout<<"Enter number of term "<<endl;
		cin>>n;
		fib(n);
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
