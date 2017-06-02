#include <stdio.h>
#define	CHAR	8


void	main(void)
{

	char 	Ango[]="VZ@GTRP";
	int		i;
	
	for(i=0;Ango[i]!='\0';i++){
		
		Ango[i] = Ango[i] ^ 0x15;
		
	}
	
	printf("result:%s",Ango);

}
