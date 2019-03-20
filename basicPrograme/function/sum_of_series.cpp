//x-x^3/3!+x^5/5!-x^7/7!......x^(2n-1)/(2n-1)!
#include<iostream>
#include<stdio.h>
#include<math.h>
long int fact(int n)
{
	long int f=1;
	if(n==0)
	return 1;

	for(int i=n;i>0;i--)
	f=f*i;

return f;

}
void sum_of_series(int n,int x)
{
	float sum=0;
	int sign;
	for(int i=1;i<=n;i++)
	{
		sign=(i%2==0)?-1:1;
	sum=sum+sign*(pow(x,2*i-1)/fact(2*i-1));
	}
	printf("%f",sum);
}
int main()
{
	int num, x;
	printf("To find sum of this series  x-x^3/3!+x^5/5!-x^7/7!......x^(2n-1)/(2n-1)!  \n  Enter n and x ");
	scanf("%d %d",&num,&x);
	sum_of_series(num,x);

	return 0;

}
