#include<stdio.h>
int main()
{
	int row,i,j,space,a=1;
	printf("Enter no. of row \n");
	scanf("%d",&row);

	for(i=0;i<row;i++)
	{

		for(space=1; space<=row-i; space++)
			printf("    ");

		for(j=0;j<=i;j++)
			{
				if(i==0 || j==0)
					a=1;
				else
					a=a*(i-j+1)/j;

				printf("%4d    ",a);
			}
		
		printf("\n");

	}

return 0;

}
