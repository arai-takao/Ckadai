/*--------------------------------------------*

	制作者：荒井敬生
	制作日：2017/05/16
	課題No.14

*---------------------------------------------*/

#include <stdio.h>
#define		MAX		256
#define		DEC		10

/*プロトタイプ宣言*/
void DecChar(int, char*);

void main(void)
{
	int		work;
	char	buf[MAX];
	
	
	printf("int DEC input => ");
	scanf("%d",&work);
	DecChar(work,buf);
	printf("Char DEC output=> %s\n",buf);
	
}

/*--------------------------------------------*
	制作者	：荒井敬生
	制作日	：2017/05/16
	関数名	：DecChar
	機能概要：10進数の数字を10進数文字列に変換するよ
*---------------------------------------------*/
void DecChar(int dec,char *buf)
{
	int		i, j, p;
	int		d;      					//入力された数の計算ようの容れものだよ
	char	c[MAX];						//仮に入れとく配列だよ
										//十進数の0~9に対応したchar型の配列作るよ
	char	copy[] = {'0','1','2','3','4','5','6','7','8','9'};
	
	j = 0;
	d = dec;
	
	
	if(0 > dec)							//入力数字がーだったら、自然数に変換しとくよ
	{
		d = (~d + 1);
	}
	
	for(i = 0;d != 0;i++)				//計算対象の数が0になるまでループだよ
	{			
		p = d % DEC;					//計算対象を10で割ったあまりをだすよ
		
		c[i] = copy[p];					//前に出した数に対応した10進数の数を入れ物に入れてくよ
		
		d = d / DEC;					//計算対象を10で割って代入だ
		
		if(0 == d)						//dが0だったらもう桁がないのでループ出るよ
		{
			if(0 > dec)					//入力数字がーなら最後にーを入れるよ
			{
				i++;
				c[i] = '-';
			}
			break;
		}
	}
	
	for(;i >= 0;i--)					//仮に入れてる配列の中身を逆さにして出力用のとこにいれてくよ
	{
		buf[j] = c[i];
		j++;
	}
	
	buf[j] = '\0';						//最後にエンエヌを忘れるな
	
}