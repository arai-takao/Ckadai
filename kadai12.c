/*--------------------------------------------*

	����ҁF�r��h��
	������F2017/04/26
	�ۑ�No.12

*---------------------------------------------*/

#include	<stdio.h>
#define		MAX		10

void main(void)
{
	static int data[MAX] = {5,10,15,20,25,30,35,40,45,50};
	int		work, now, before ,copy;
	int		I;
	
	
	printf("Data Input => ");
	scanf("%d",&work);		//�f�[�^�̓���
	
	now = (MAX - 1) / 2; //�T���ꏊ����܂�
	before = now;
	
	while(1)
	{
		if(work == data[now])
		{
			printf("Found Number:%d\n",now ); //�f�[�^������������\��
			break;
		}
		else if(work < data[now]) 							//�T�������f�[�^���A�����Ă�f�[�^��菬����
		{
			if(before < now) 								//���A�ȑO�̈ʒu���A���̈ʒu��菬�����@(�����菬�����Ƃ���ɂ̓f�[�^�͂Ȃ�)
			{
				copy = now;									//���̈ʒu�c���Ƃ��܂��B�ȑO�̈ʒu���v�Z�Ŏg���������A���̈ʒu�͂��ꂩ�珑���������Ⴄ��
				now = before + ((now - before) / 2);		//���̈ʒu�̕����傫���̂ŁA�ȑO�̈ʒu�ň����ā@�Q�Ŋ����@�ȑO�̈ʒu�����āA���ƈȑO�̒��ԓ_������
				before = copy;								//�ȑO�̈ʒu�Ƃ��Ă�����
			}else{ 											//��������Ȃ�����������Ə������Ƃ��T����
				before = now;								//�ȑO�̈ʒu���v�Z�Ŏg��Ȃ��Ȃ�A�������������Ă�����
				now  = now / 2;								//�Q�Ŋ����Ē��Ԃ�������
			}
			
		}
		else if(work > data[now]) 							//�T�������f�[�^���A�����Ă�f�[�^���傫��
		{
			if(before > now) 								//���A�ȑO�̈ʒu�����̈ʒu���傫���@�i������傫���Ƃ���ɂ̓f�[�^�͂Ȃ��j
			{
				copy = now;									//���̈ʒu�c���Ƃ��܂��B�ȑO�̈ʒu���v�Z�Ŏg���������A���̈ʒu�͂��ꂩ�珑���������Ⴄ��
				now = now + ((before - now) / 2);			//�ȑO�̈ʒu�̕����傫���̂ŁA���̈ʒu�ň����ā@�Q�Ŋ����@���̈ʒu�����āA���ƈȑO�̒��ԓ_������
				before = copy;
			}else{ 											//��������Ȃ�����������Ƒ傫���Ƃ���������
				before = now;
				now  = now + (MAX - now) / 2;				//�S���̐����獡�̈ʒu�������āA�����đ����āA���ƍő�̒��ԓ_�o����
			}
		}
		
		if(now == before) //�ȑO�̈ʒu�ƍ��̈ʒu���d�Ȃ�����A�܂肻��͎c�O�Ȃ��m�点��
		{
			printf("Data Not Found\n"); //������܂���ł���
			break;
		}
	}
}
