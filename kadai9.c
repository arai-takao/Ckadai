#include <stdio.h>

void	main(void)
{
	
	char 	Ango[]="VZ@GTRP";
	int		i;
	
	for(i=0;Ango[i]!='\0';i++){
		
		Ango[i] ^=  025;
		
	}
	
	printf("%s\n",Ango);
	
	printf("%d\n",'C');
	printf("%d\n",'V');
	
}