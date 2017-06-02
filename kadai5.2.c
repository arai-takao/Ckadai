#include <stdio.h>

int plus(int,int);


void main(void)
{
	
	int a;
	int b;
	int c;
	
	a=12345;
	b=56789;
	
	c=plus(a,b);
	
	printf("%d",c);
	
}

int plus(int a,int b)
{
	
	int c;
	
	c = a + b;
	
	return c;
}