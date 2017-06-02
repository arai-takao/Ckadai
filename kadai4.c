#include <stdio.h>

void uriage(void);

void main(void)
{

	int	uriage[12];
	int	Maxval;
	int	Minval;
	int	Sum;
	int	Avgval;
	int	i;

	uriage[0]=110;
	uriage[1]=120;
	uriage[2]=130;
	uriage[3]=140;
	uriage[4]=150;
	uriage[5]=160;
	uriage[6]=170;
	uriage[7]=180;
	uriage[8]=190;
	uriage[9]=200;
	uriage[10]=210;
	uriage[11]=220;

	Maxval=uriage[5];
	Minval=uriage[5];
	Sum=0;
	Avgval=0;

	for(i=0;i<12;i++){

		if(uriage[i]>Maxval){
			Maxval=uriage[i];
		}

		if(uriage[i]<Minval){
			Minval=uriage[i];
		}

		Sum+=uriage[i];

	}

	Avgval=Sum/12;

	printf("Å‘å@%d–œ‰~\n",Maxval);
	printf("Å¬@%d–œ‰~\n",Minval);
	printf("•½‹Ï@%d–œ‰~\n",Avgval);

}

void uriage(void)
{
	
	
	
}
		
	