#include<stdio.h>
int fact(int n)
{
	int i,f=1;
	if(n==0)
	return 1;

	for(i=n;i>0;i--)
		f=f*i;
		
	return f;

}
int comb(int n,int r)
{
	return (fact(n)/(fact(n-r)*fact(r)));

}
int main()
{
	int row,i,j,k,space;
	printf("Enter no. of row ");
	scanf("%d",&row);

	for(i=0;i<row;i++)
	{
		for(k=1;k<=row-i;k++)
			printf("    ");
		//for(space=1; space<=row-i; space++)
			//printf("    ");


		for(j=0;j<=i;j++)
			printf("%4d    ",comb(i,j));

		printf("\n");
	}

return 0;
}
