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

void test(int b[])//�|�C���^�̐錾�Ɠ��l�@�����܂ł������Ƃ��Ă͂����@���ʂɏ����Ɠ{����
{
	
	printf("b:%x\n",b);
	printf("*b:%d\n",*b);
}

void test2(int b[])//�A�h���X���Z����ƃ|�C���^�̈ʒu���̂��̂��ς��B�z��Ɠ����g�����Ȃ�ς��Ȃ�
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

void test3(int *test[]) //�|�C���^�̃|�C���^�̐錾�Ɠ��l test3(&a);�����|�C���^�̃A�h���X�Œʂ�
{
	
	printf("b:%x\n",test);
	printf("*b:%x\n",*test);
	printf("**b:%x\n",**test);
	
}

void test4(int *a)
{
	int i;
	printf("a[5]:%d\n",a[5]);//for���͎��̍Ō�u�p�v�ɉ��Z�Ȃǂ�����H �͂��߂Ɏ��ɓ���Ȃ���Ή��Z�Ȃǂ͂���Ȃ�
	
	for(i = 5;i < a[5];i++)//�������͎��s�����
	{
		printf("ai:%d\n",i);
	}
	printf("bi:%d\n",i);
	
}
