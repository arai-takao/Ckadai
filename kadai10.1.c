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
�֐��̈����ɗv�f�����w�肵���z�������Ă��A�󂯎�����֐����ł̓|�C���^�Ƃ��Ďg����
�����̋L�@�͔z��ł������I�ɂ̓|�C���^�炵��
�|�C���^�Ő錾���Ă��Ȃ��̂Ƀ|�C���^�Ƃ��Ďg���Ă��܂�
���R�����A�z���[]�𖳂����Ƃ�����int�̐錾�ɂȂ�̂ł��� 

�����܂Ŕz��������Ƃ��Ă���Ƃ��A�|�C���^���󂯎���Ă���̂Ɠ����Ƃ�������
�܂�A���̈������֐������Œ��ڎg���ƁA�z�񂪒��ڏ��������
�z��ɑ�����Ă邩��l�n������A�Ƃ��v���Ă�Ǝ��ʁi�̌��k�j
���������ӂ��K�v

�����łȂ��Ă���������̂ŁA�|�C���^���g�����ق����������Ǝv���
�����Ė�������Ƃ��Ƃ��H

�Ƃ�����߂�l�Ŕz�񖼂�Ԃ�����������֐��錾�|�C���^�^�ɂ��Ȃ��Ƃ���
�z�񂻂̂��̂Ȃ�ĕԂ��Ȃ���

�����͓����I�ɂ͑S�ă|�C���^�i�Q�Ɠn���j�Ƃ����b���������i�l�b�g�Łj


*/