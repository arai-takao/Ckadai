#include <stdio.h>

void test(int*);
void test2(int b[55476978]);
void test3(int *test[]);
void test4(int*);

void main()
{
	int b[] = {0,1,2,3,4,5,6,7,8,9};
	//printf("b:%x\n",b);
	//printf("&b:%x\n",&b);
	
	//printf("-1:%c\n",'-1');
	int *a;
	a = b;
	//char a[10];
	
	test4(a);
	
}

void test(int b[])//ポインタの宣言と同様　あくまでも引数としてはだが　普通に書くと怒られる
{
	
	printf("b:%x\n",b);
	printf("*b:%d\n",*b);
}

void test2(int b[])//アドレス演算するとポインタの位置そのものが変わる。配列と同じ使い方なら変わらない
{
	int i = 7;
	printf("b:%x\n",&b);
	b++;
	printf("b++:%x\n",b);
	printf("\ni:%d\n",i);
	printf("b[i]:%x\n",b[i]);
	
	for(i=0;i<10;i++)
	{
		printf("b:%x\n",&b[i]);
		printf("b:%d\n",b[i]);
		printf("i:%d\n",i);
	}
}

void test3(int *test[]) //ポインタのポインタの宣言と同様 test3(&a);引数ポインタのアドレスで通る
{
	
	printf("b:%x\n",test);
	printf("*b:%x\n",*test);
	printf("**b:%x\n",**test);
	
}

void test4(int *a)
{
	int i;
	printf("a[5]:%d\n",a[5]);//for文は式の最後「｝」に加算などをする？ はじめに式に入らなければ加算などはされない
	
	for(i = 5;i < a[5];i++)//初期化は実行される
	{
		printf("ai:%d\n",i);
	}
	printf("bi:%d\n",i);
	
}
