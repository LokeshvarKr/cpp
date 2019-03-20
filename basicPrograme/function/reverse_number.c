#include<stdio.h>
int reverse(int n)
{
	int a,r=0;
	while(n>0)
	{
	a=n%10;
	r=r*10+a;
	n/=10;
	}
	return r;

}
int main()
{
	int n;
	printf("Enter number\n");
	scanf("%d",&n);
	printf("%d",reverse(n));
	return 0;
}
