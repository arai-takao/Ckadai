#include <stdio.h>
#define	HAN	' '

void spaceDel(char *x);

void main(void)
{
	
	char	mozi[]="A B  C   D E FG  ";
	char	mozi2[]="A  B  B C D  B";
	char	mozi3[]="I have a pen";
	
	spaceDel(mozi);
	printf("%s\n",mozi);
	spaceDel(mozi2);
	printf("%s\n",mozi2);
	spaceDel(mozi3);
	printf("%s\n",mozi3);
	
}

void spaceDel(char *x)
{
	char	*y=x;
	int 	i,count=0;
	
	for(i=0;x[i]!='\0';i++)
	{
		if(x[i]!=HAN){
			*y=x[i];
			y++;
			count++;
		}
		
	}
	
	*y='\0';
	
}