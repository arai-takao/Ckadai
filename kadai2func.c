#include <stdio.h>

void mozi(void);

void main(void)
{

	mozi();
	
}

void mozi(void)
{
	
	char	c;
	
	c='A';
	printf("%c\n",c);/*文字として表示*/
	printf("%d\n",c);/*10進数として表示*/
	printf("%x\n",c);/*16進数として表示*/
	
}
