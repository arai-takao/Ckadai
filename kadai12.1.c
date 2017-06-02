/*--------------------------------------------*

	制作者：荒井敬生
	制作日：2017/04/27
	課題No.12 affected Hirano

*---------------------------------------------*/

#include	<stdio.h>
#define		MAX		10

void main(void)
{
	static int data[MAX] = {5,10,15,20,25,30,35,40,45,50};
	int		work, high, low, point;
	int		I;
	
	
	printf("Data Input =>");
	scanf("%d",&work);		//データの入力
	
	high = MAX - 1;				//データの最大のとこいれるよ
	low = 0;					//データの最小のとこいれるよ
	point = (high + low) / 2; 	//探す位置をいれるよ　データの中間だね
	
	
	while(1)
	{
		if( work == data[point])	//探すデータと今見てるデータ比べるよ、一緒だったら表示だよ
		{
			printf("Found Number:%d\n",point ); //データが見つかったら表示
			break;
		}else if(work < data[point])//探してるデータの方が小さいときは
		{
			high = (point - 1);		//最大を　今見てるとこの１つ小さいとこにするよ　今見てるとこは探す必要ないからね
		}else if(work > data[point])//探してるデータの方が大きいときは
		{
			low = (point + 1);		//最小を　今見てるとこの１つ大きいとこにするよ　今見てるとこは探す必要ないからね
		}
		
		
		point = (high + low) / 2;	//最少と最大を足して2で割るよ、そうするとそれらの中間がのだって
		
		
		
		if(high < low)				//highがlowより小さくなっちゃったら終わりだ、残念だよ
		{
			printf("Data Not Found\n"); //見つかりませんでした
			break;
		}		
	}
}
