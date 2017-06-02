#include <stdio.h>
#define	MAX	5

void	sort1(int data[MAX]);

void main(void)
{
	
	int data[MAX]={9,21,119,45,3};
	int i;
	sort1(data);
	for(i=0;i<MAX;data++){
		i++;
		printf("%d",data[]);
	}
	//for(i=0;i<MAX;i++)printf("%3d\n",data[i]);
	
}

void	sort1(int data[MAX])
{
	int	copy;
	int	i,j;
	int a[MAX];
	
	for(i=0;i<MAX;data++)
	{
		a[i]=*data;
		i++;
	
		/*for(j=0;j<MAX;j++){
			
			if(data[i]>data[j])
			{
		 		copy=data[i];
				data[i]=data[j];
				data[j]=copy;
			}
			
		}
		*/
	}
	for(i=0;i<MAX;i++)printf("%3d\n",a[i]);

	//return	data;
}
























/*
関数の引数に要素数を指定した配列をいれても、受け取った関数内ではポインタとして使える
引数の記法は配列でも内部的にはポインタらしい
ポインタで宣言していないのにポインタとして使えてしまう
当然だが、配列の[]を無くすとただのintの宣言になるのでだめ 

あくまで配列を引数としているとき、ポインタを受け取っているのと同じということ
つまり、その引数を関数内部で直接使うと、配列が直接書き換わる
配列に代入してるから値渡しだろ、とか思ってると死ぬ（体験談）
そこが注意が必要

そうでなくても混乱するので、ポインタを使ったほうが明解だと思われ
あえて明示するときとか？

とうぜん戻り値で配列名を返したかったら関数宣言ポインタ型にしないとだめ
配列そのものなんて返せないし

引数は内部的には全てポインタ（参照渡し）という話もあった（ネットで）


*/