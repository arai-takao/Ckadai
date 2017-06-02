#include <stdio.h>
#define	CHAR	8

void	CharPrintVin(char str[]);

void	main(void)
{

	char 	Ango[]="VZ@GTRP";
	int		i;
	
	CharPrintVin(Ango);
	
	for(i=0;Ango[i]!='\0';i++){
		
		Ango[i] ^=  025;
		
	}
	
	printf("turn 0,2,4bit\n");
	CharPrintVin(Ango);

}

void	CharPrintVin(char str[])
{
	
	int		i,j,k;
	int		binar[CHAR],a;
	
	for(i=0;str[i]!='\0';i++)printf(":%c%3d\n",str[i],str[i]);
	
	for(i=0;str[i]!='\0';i++){
		
		printf(":%c",str[i]);
		
		for(j=0;j<CHAR;j++){	
			
			if(j == 0){
				
				binar[j]= str[i]%2;
				
				a=str[i]/2;
				
			}else{
				
				binar[j]= a%2;
				
				a=a/2;
				
			}			
		}
		
		for(k=CHAR-1;k>=0;k--)printf("%2d",binar[k]);
		
		printf("\n");
		
	}
	
}


