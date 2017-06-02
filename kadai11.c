/*--------------------------------------------*

	制作者：荒井敬生
	制作日：2017/04/25
	課題No.11

*---------------------------------------------*/

#include	<stdio.h>
#include	<string.h>
#define		BUFMAX		256
#define		PASS		3

void	Upper(char*);

void main(void)
{
	static char password[BUFMAX] = "VICTORY";	//パスワード
	char	buf[BUFMAX];						//入力エリア
	int		i;
	
	
	for(i=1; i<=PASS; i++)
	{
		
		printf("password input=>");
		scanf("%s",buf);				//パスワード入力
		Upper(buf);						//小文字入力は大文字に変えちゃうよ
		//printf("after upper:%s\n",buf);
		
		if(strcmp(buf,password) == 0)	//パスワードとの比較
		{
			printf("PASSWORD OK\n");	//一致
			break;		
		}
		if(i==PASS)
		{
			printf("PASSWORD NG\n");	//不一致
		}
	}
}

/*--------------------------------------------*
	制作者	：荒井敬生
	制作日	：2017/04/25
	関数名	：Upper
	機能概要：小文字を大文字にするよ  
*---------------------------------------------*/
void	Upper(char *str)
{
	int	i;
	
	//printf("Buf char:%s\n",str);
	
	for(i = 0; str[i] != '\0'; i++)//ポインタのi番目が\0じゃなかったらiに1足すよ
	{
		
		//printf("str[0] char:%c\n",str[0]);

		if(str[i] >= 97 && str[i] <= 122)//i番目の中身が小文字の範囲だったら大文字にしちゃうよ
		{
			//printf("conv before char:%c\n",str[i]);
			str[i] -= ' ';
			//printf("conv after char:%c\n",str[i]);
		}
	}
	//printf("Buf char:%s\n",str);
}