#include <stdio.h>
#define	MAX	7
#define	STR	50

void plus(void)
{
	printf("start\n");
	
	int	i;
	int	total; /*合計*/


	total = 0;
	/*1から10まで加算する*/
	for( i=1 ; i<=10 ; i++){
		total += i;
	}
	/*合計を表示する*/
	printf("合計 = %d\n",total);
	
	printf("ent\n");
}

void mozi(void)
{
	printf("start\n");
	
	char	c;
	
	c='A';
	printf("%c\n",c);/*文字として表示*/
	printf("%d\n",c);/*10進数として表示*/
	printf("%x\n",c);/*16進数として表示*/
	
	printf("end\n");
	
}

void sankaku(void)
{
	printf("start\n");
	
	int	i,j;

	for(i=0; i<=MAX; i++){
		for(j=0; j<i; j++){
			printf("%d",i);
		}
		printf("\n");
	}
	
	printf("end\n");
}

void uriage(void)
{
	printf("start\n");
	
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

	printf("最大　%d万円\n",Maxval);
	printf("最小　%d万円\n",Minval);
	printf("平均　%d万円\n",Avgval);

	printf("end\n");
}

void speacedel(void)
{
	printf("start\n");
	
	static	char	a[STR]="A B  C   D E FG  ";
	char		b[STR];
	int		bpoint;
	int		i;

	//char		s[]="\n";

	bpoint=0;

	for(i=0;i<STR;i++){
	
		//if(a[i]!=s[1]){

		if(a[i]!=' '){
			b[bpoint]=a[i];
			bpoint++;

		}		
	}

	printf("%s\n",b);
		
	printf("end\n");
}
		
void main(void)
{

	plus();
	mozi();
	sankaku();
	uriage();
	speacedel();
	
	
}