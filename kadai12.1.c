/*--------------------------------------------*

	����ҁF�r��h��
	������F2017/04/27
	�ۑ�No.12 affected Hirano

*---------------------------------------------*/

#include	<stdio.h>
#define		MAX		10

void main(void)
{
	static int data[MAX] = {5,10,15,20,25,30,35,40,45,50};
	int		work, high, low, point;
	int		I;
	
	
	printf("Data Input =>");
	scanf("%d",&work);		//�f�[�^�̓���
	
	high = MAX - 1;				//�f�[�^�̍ő�̂Ƃ�������
	low = 0;					//�f�[�^�̍ŏ��̂Ƃ�������
	point = (high + low) / 2; 	//�T���ʒu��������@�f�[�^�̒��Ԃ���
	
	
	while(1)
	{
		if( work == data[point])	//�T���f�[�^�ƍ����Ă�f�[�^��ׂ��A�ꏏ��������\������
		{
			printf("Found Number:%d\n",point ); //�f�[�^������������\��
			break;
		}else if(work < data[point])//�T���Ă�f�[�^�̕����������Ƃ���
		{
			high = (point - 1);		//�ő���@�����Ă�Ƃ��̂P�������Ƃ��ɂ����@�����Ă�Ƃ��͒T���K�v�Ȃ������
		}else if(work > data[point])//�T���Ă�f�[�^�̕����傫���Ƃ���
		{
			low = (point + 1);		//�ŏ����@�����Ă�Ƃ��̂P�傫���Ƃ��ɂ����@�����Ă�Ƃ��͒T���K�v�Ȃ������
		}
		
		
		point = (high + low) / 2;	//�ŏ��ƍő�𑫂���2�Ŋ����A��������Ƃ����̒��Ԃ��̂�����
		
		
		
		if(high < low)				//high��low��菬�����Ȃ����������I��肾�A�c�O����
		{
			printf("Data Not Found\n"); //������܂���ł���
			break;
		}		
	}
}
