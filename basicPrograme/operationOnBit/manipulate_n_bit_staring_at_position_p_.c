#include<stdio.h>
#define NEW_LINE printf("\n");
void displayBits(int x)
{
	int i,mask;
	for(i=31;i>=0;i--)
	{
		mask=1<<i;
		putchar((x&mask)?'1':'0');
		if(i%8==0)
		putchar(' ');
	}
}
int main()
{
	int x,y,mask,i,n,p;

	printf("Enter a numbe in hexadecimal (on which operation has to perform)\n");
	scanf("%x",&x);
	printf("How many bits want to manipulate ?\n");
	scanf("%d",&n);
	printf("Enter starting position\n");
	scanf("%d",&p);
	
	displayBits(x);
	NEW_LINE

	mask=~(~0<<n)<<p-n+1;	

	printf("set operation\n");
	y=x|mask;
	displayBits(y);
	NEW_LINE

	printf("clear operation\n");
	y=x&~mask;
	displayBits(y);
	NEW_LINE

	printf("Invert operation\n");
	y=x^mask;
	displayBits(y);
	NEW_LINE

	return 0;
}
