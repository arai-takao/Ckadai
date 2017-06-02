#include <stdio.h>

void main(void)
{
	
	int	kuku[9][9];
	int i,j;
	
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){	
			
			kuku[i][j]=(i+1)*(j+1);
			
			if((i+1)*(j+1)<10){
				
				printf(" %d ",kuku[i][j]);
				
			}else{
				
				printf("%d ",kuku[i][j]);
				
			}
			
		}
		
		printf("\n");
		
	}
	
}