#include <stdio.h>
#define WIDTHMAX	10

void main(void)
{
	
	int	i,j;
	int	in;
	
	i = 0;
	
	while(1)
	{
		if(0 < i)
		{
			for(j = 0;j < i;j++)
			{
			printf(" ");
			}
			
			printf("¡");
			
		}
		i++;
		if(50>i)
		{
			i=0;
		}
		
		scanf("%d",&in);
		if(1 == in)
		{
			break;
		}
	}
}
		