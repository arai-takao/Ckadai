/*--------------------------------------------*

	制作者：荒井敬生
	制作日：2017/04/26
	課題No.12

*---------------------------------------------*/

#include	<stdio.h>
#define		MAX		10

void main(void)
{
	static int data[MAX] = {5,10,15,20,25,30,35,40,45,50};
	int		work, now, before ,copy;
	int		I;
	
	
	printf("Data Input => ");
	scanf("%d",&work);		//データの入力
	
	now = (MAX - 1) / 2; //探す場所入れます
	before = now;
	
	while(1)
	{
		if(work == data[now])
		{
			printf("Found Number:%d\n",now ); //データが見つかったら表示
			break;
		}
		else if(work < data[now]) 							//探したいデータが、今見てるデータより小さい
		{
			if(before < now) 								//かつ、以前の位置が、今の位置より小さい　(それより小さいところにはデータはない)
			{
				copy = now;									//今の位置残しときます。以前の位置も計算で使いたいし、今の位置はこれから書き換えちゃうし
				now = before + ((now - before) / 2);		//今の位置の方が大きいので、以前の位置で引いて　２で割るよ　以前の位置足して、今と以前の中間点だすよ
				before = copy;								//以前の位置とっておくよ
			}else{ 											//そうじゃなかったらもっと小さいとこ探すよ
				before = now;								//以前の位置を計算で使わないなら、もう書き換えていいよ
				now  = now / 2;								//２で割って中間さがそう
			}
			
		}
		else if(work > data[now]) 							//探したいデータが、今見てるデータより大きい
		{
			if(before > now) 								//かつ、以前の位置が今の位置より大きい　（それより大きいところにはデータはない）
			{
				copy = now;									//今の位置残しときます。以前の位置も計算で使いたいし、今の位置はこれから書き換えちゃうし
				now = now + ((before - now) / 2);			//以前の位置の方が大きいので、今の位置で引いて　２で割るよ　今の位置足して、今と以前の中間点だすよ
				before = copy;
			}else{ 											//そうじゃなかったらもっと大きいとこさがすよ
				before = now;
				now  = now + (MAX - now) / 2;				//全部の数から今の位置を引いて、割って足して、今と最大の中間点出すよ
			}
		}
		
		if(now == before) //以前の位置と今の位置が重なったら、つまりそれは残念なお知らせだ
		{
			printf("Data Not Found\n"); //見つかりませんでした
			break;
		}
	}
}
