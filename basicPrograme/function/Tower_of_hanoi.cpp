#include<iostream>
using namespace std;
void TOH(int n,char a,char b,char c)
{
	if(n==1)
	{
	cout<<"disk "<<n<<" is moved to "<<a<<"-->"<<c<<endl;
	return;
	}
	TOH(n-1,a,c,b);
	cout<<"disk "<<n<<" is moved to "<<a<<"-->"<<c<<endl;
	TOH(n-1,b,a,c);

}
int main()
{
	int n;
	cout<<"Enter no. of disk (to move A to C, B as auxiliary "<<endl;
	cin>>n;

	TOH(n,'A','B','C');

return 0;
}
