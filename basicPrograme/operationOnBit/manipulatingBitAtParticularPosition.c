#include<stdio.h>
#define NEWLINE printf("\n");
#define SPACE putchar(' ');

void displayBits(int x)
{
	int mask;
	for(int i=31;i>=0;i--)
	{
		mask=1<<i;
		putchar((x&mask)?'1':'0');
		if(i%8==0)
		SPACE
	}
}
int main()
{
	int bit,mask,x,y,position,c;
	goto level;

	level:
		printf("chose an potion\n");
		printf("1. For hexadecimal input \n2. For integer \n");
		scanf("%d",&c);

	if(c==1)
	{
		printf("Enter a hexadecimal number\n");
		scanf("%x",&x);
	}
	else if(c==2)
	{
		printf("Enter an integer value\n");
		scanf("%d",&x);
	}
	else
	{
		printf("Please choose correct option\n");
		goto level;
	}
	printf("Enter position of bit (in integer only) to be manipulate\n");
	scanf("%d",&position);
	

	mask=1<<position;

	//test particular bit
	if(x&mask)
		bit=1;
	else
		bit=0;

	printf("(Test) bit at position %d is %d\n",position,bit);
	displayBits(x);
	NEWLINE
	
	//set bit at particular position
	y=x|mask;
	printf("bit is set at position %d is :\n",position);
	displayBits(y);
	NEWLINE

	//clear bit at par....
	y=x&~mask;
	printf("bit clear at position %d is :\n",position);
	displayBits(y);
	NEWLINE

	//invert bit at par....
	y=x^mask;
	printf("inverted bit at position %d is :\n",position);
	displayBits(y);
	NEWLINE
	return 0;
}
