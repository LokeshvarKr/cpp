#include<iostream>
#include<string.h>
using namespace std;
void swap(char *a,char *b)
{
    char t=*a;
	*a=*b;
	*b=t;
}
void permute(char *str,int l,int r)
{
	if(l==r)
	cout<<str<<endl;
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(str+l,str+i);
			permute(str,l+1,r);
			swap(str+l,str+i);
		}
	}

}
int main()
{
	char str[50];
	cout<<"Enter a string to find permuttion"<<endl;
	cin>>str;
	cout<<"Permutation of  "<<str<<endl;
	permute(str,0,strlen(str)-1);
	
	return 0;

}
