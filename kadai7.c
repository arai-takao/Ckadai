#include <stdio.h>
#define	HAN	' '

void spaceDel(char *x);

void main(void)
{
	
	char	mozi[]="A B  C   D E FG  ";
	char	mozi2[]="A  B  B C D  B";
	char	mozi3[]="I have a pen";
	
	spaceDel(mozi);
	spaceDel(mozi2);
	spaceDel(mozi3);
	
}

void spaceDel(char *x)
{
	char	*y=x;
	int 	i,count=0;
	
	for(i=0;x[i]!='\0';i++)//ｘをアドレスに＋＋した方が統一的、シンプル。あとから気づいた
	{
		if(x[i]!=HAN){
			*y=x[i];
			y++;
			count++;
		}
		
	}
	
	*y='\0';
	printf("%d",i);
	y-=count;//アドレス戻してる
	
	printf("%s\n",y);
}

/*
ポインタを配列的に使ったとき要素を[]で指定したときはポインタの指している
整数として使われる.通常変数モードになってる
アドレス計算したらそのままになる
メモリ上は配列で確保したメモリの前に文字列定数があるのかも、countのとこいじる
とそれっぽいのがある
読み込み専用めもりだと思うので読むことはできている？書き込むとどうなる
ポインタのアドレスみたら0Xで403030だった。ほかのソースでものそうなのでいつもそうかも
文字定数のアドレスは？


*/