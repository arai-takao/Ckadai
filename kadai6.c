#include <stdio.h>
#define	STR	50
#define	HAN	' '

char SpaceDel(char x[STR],char y[STR])
{

	int 	i;
	int		spoint;
	
	spoint=0;
	
	for(i=0;i<STR;i++){	
		if(x[i]!=HAN){
			y[spoint]=x[i];
			spoint++;
		}		
	}

	return y[0];
//	return y;
}

void main(void)
{

	static	char	a[STR]="A B  C   D E FG  ";
	static	char	b[STR]="A  B  B C D  B";
	static	char	c[STR]="I have a pen";
	char			y[STR];
	
	SpaceDel(a,y);
	printf("%s\n",y);
	SpaceDel(b,y);
	printf("%s\n",y);
	SpaceDel(c,y);
	printf("%s\n",y);
	
}
