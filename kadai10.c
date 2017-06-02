/*--------------------------------------------*

	制作者：荒井敬生
	制作日：2017/04/19
	課題No.10

*---------------------------------------------*/

/* インクルード */
#include <stdio.h>
#include <string.h>

#define	MAX	5


void	sort1(int data[MAX]);
void	sort2(int data[MAX]);
int		sort3(int *data,int);


void main(void)
{
	
	int data[]={9,21,119,45,3,45,33,76,88,1,2,56,4,5};//配列に数を入れるよ
	int i;
	
	sort3(data,(sizeof data / sizeof data[0]));
	for(i = 0;i < (sizeof data / sizeof data[0]);i++)printf("%3d\n",data[i]);
	
}

/*--------------------------------------------*
	制作者	：荒井敬生
	制作日	：2017/04/19
	関数名	：バブルソート1
	機能概要：配列の中のデータを降順にソートする
*---------------------------------------------*/
void	sort1(int data[MAX])
{
	int	copy;
	int	i,j;
	
	
	for(i = 0;i < MAX;i++)		//iがdataのはじに行くまで１足す
	{
		for(j=0;j < MAX;j++){	//iの中で、jがdataのはじに行くまで１足す
			
			if(data[i] > data[j])	//dataのi番目がj番目より大きかったら交換
			{
		 		copy = data[i]; 
				data[i] = data[j];
				data[j] = copy;
			}
			
		}
		
	}
	//for(i=0;i<MAX;i++)printf("%3d\n",data[i]);

	//return	data; 
}


/*--------------------------------------------*
	制作者	：荒井敬生
	制作日	：2017/04/19
	関数名	：バブルソート2
	機能概要：配列の中のデータを降順にソートする
			  1より少しループ回数が少ない
*---------------------------------------------*/

void	sort2(int data[MAX])
{
	int	copy;
	int	i,j;
	
	for(i = 0;i < MAX;i++)	//iがdataのはじに行くまで１足す
	{	
		for(j = i;j < MAX;j++)	//iの中で、jがdataのi番目からはじに行くまで１足す
		{
			
			if(data[i] > data[j])	//dataのi番目がj番目より大きかったら交換
			{
		 		copy = data[i];
				data[i] = data[j];
				data[j] = copy;
			}
			
		}
		
	}
	
}


/*--------------------------------------------*
	制作者	：荒井敬生
	制作日	：2017/04/19
	関数名	：クイックソート 出来てない
	機能概要：配列の中のデータを降順にソートする
			  
*---------------------------------------------*/

int		sort3(int *data,int DataNum)
{	
	int	right, left, center, copy, point;
	
	
	center = DataNum / 2; 	//data数の中間、小数点以下は切り捨てるよ
	point = data[center];		//dataの中間に入っている数字をpointに入れるよ
	right = 0;
	left = DataNum;	
	
	static int count = 0;
	count++;
	
	if(DataNum <= 1)
	{
		return 0;
	}
	
	//printf("datanum:%d\n",DataNum);
	while(1)
	{	
			
		//dataの右位置がpointより小さかったら交代の必要はないので右位置をすすめるよ
		if(data[right] <= point)
		{
			right++;
		}
		//dataの左位置がpointより大きかったら交代の必要はないので左位置をすすめるよ
		if(data[left] >= point)
		{
			left--;
		}
		
		//右位置がpointより大きくと左位置がpointより小さかったら交代だよ。そのあとそれぞれ進めるよ
		if((data[right] >= point) && (data[left] <= point))
		{
			/*printf("copy:%d\n",copy);
			printf("data[right]:%d\n",data[right]);
			printf("data[left]:%d\n",data[left]);*/
			
			copy = data[right];
			data[right] = data[left];	
			data[left] = copy;
			
		}
		
		//右位置と左位置が交差したらループ終わり、お疲れ様でした
		if(right >= left)
		{
			break;
		}
	}
	
	//printf("right :%d\n",right);
	//printf("left :%d\n\n",left);
	
	sort3(data,right - 1);
	sort3(&data[right],(DataNum - right));
	
	return 1;
}
