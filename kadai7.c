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
	
	for(i=0;x[i]!='\0';i++)//�����A�h���X�Ɂ{�{������������I�A�V���v���B���Ƃ���C�Â���
	{
		if(x[i]!=HAN){
			*y=x[i];
			y++;
			count++;
		}
		
	}
	
	*y='\0';
	printf("%d",i);
	y-=count;//�A�h���X�߂��Ă�
	
	printf("%s\n",y);
}

/*
�|�C���^��z��I�Ɏg�����Ƃ��v�f��[]�Ŏw�肵���Ƃ��̓|�C���^�̎w���Ă���
�����Ƃ��Ďg����.�ʏ�ϐ����[�h�ɂȂ��Ă�
�A�h���X�v�Z�����炻�̂܂܂ɂȂ�
��������͔z��Ŋm�ۂ����������̑O�ɕ�����萔������̂����Acount�̂Ƃ�������
�Ƃ�����ۂ��̂�����
�ǂݍ��ݐ�p�߂��肾�Ǝv���̂œǂނ��Ƃ͂ł��Ă���H�������ނƂǂ��Ȃ�
�|�C���^�̃A�h���X�݂���0X��403030�������B�ق��̃\�[�X�ł��̂����Ȃ̂ł�����������
�����萔�̃A�h���X�́H


*/