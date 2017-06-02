#include <stdio.h>
#define	STR	50

void main(void)
{

	static	char	a[STR]="A B  C   D E FG  ";
	char		b[STR];
	int		bpoint;
	int		i;

	//char		s[]="\n";

	bpoint=0;

	for(i=0;i<STR';i++){
	
		//if(a[i]!=s[1]){

		if(a[i]!=' '){
			b[bpoint]=a[i];
			bpoint++;

		}		
	}

	printf("%s\n",b);
	
}
















/*""だとだめ、ポインタになってるので整数と比較できないといわれる。
　''ならおｋ。
　コメントアウトのように、配列にいれてもできる。
　ただ要素数が30、50で、文字列末端に文字化けや数字が表示されれた。
　配列のnull以降のアドレスを読んでる？
*/















/*""だとポインタとの比較でだめといわれる。
　''ならok。""だとポインタになってるらしい。
　配列にいれればok.
　そのときわざとnullとひかくさせるとSTRが30とか50のときだけ文字化け（日本語文字が出た）
　null文字あとのアドレスをよんでる？
*/