/*--------------------------------------------*

	����ҁF�r��h��
	������F2017/05/12
	�ۑ�No.13

*---------------------------------------------*/

#include <stdio.h>
#define		MAX		256
#define		HEX		16
#define		COMP	0xFFFF

/*�v���g�^�C�v�錾*/
void itohex(int, char*);
void itohexEX(int, char*);

void main(void)
{
	int		work;
	char	buf[MAX];
	
	//printf("buf[0]:%x\n",&buf[0]);
	
	//buf[0] = 1;
	//printf("buf[0]:%x\n",&buf[0]);
	
	printf("DEC input => ");
	scanf("%d",&work);
	itohexEX(work,buf);
	printf("HEX output=> %s\n",buf);
	
}


/*--------------------------------------------*
	�����	�F�r��h��
	�����	�F2017/05/15
	�֐���	�Fitohex
	�@�\�T�v�F10�i���̐�����16�i���̕�����ɕϊ��@���̐����Ή�
*---------------------------------------------*/
void itohex(int dec,char *buf)
{
	int		i, j, h;
	int		d;      					//���͂��ꂽ���̌v�Z�悤�̗e����̂���
	char	c[MAX];						//���ɓ���Ƃ��z�񂾂�
										//�\�i����0~15�ɑΉ�����char�^�̔z�����
	char	copy[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	
	j = 0;
	d = dec;
	
	//printf("buf[0]:%x\n",&buf[0]);
	
	if(d < HEX)							//���͂��ꂽ����16�����Ȃ炻���z��ɓ�����A�Ԃ����Ⴏ�����ŏI��肾��
	{
		c[0] = copy[d];
	}
		
	//printf("d:%d\n",d);
	for(i = 0;d >= HEX;i++)				//�v�Z�Ώۂ̐���16�����ɂȂ�܂Ń��[�v����
	{
		
		h = d % HEX;					//�v�Z�Ώۂ�16�Ŋ���������������
		
		//printf("prv copy[d %% HEX]:%c\n",copy[h]);
		c[i] = copy[h];					//�O�ɏo�������ɑΉ�����16�i���̐���
		//printf("prv c[i]:%c\n",c[i]);
		
		d = d / HEX;					//�v�Z�Ώۂ�16�Ŋ����đ����
		if(d < HEX)						//���������ʂ�16������������A���������̔z��ɂ���ă��[�v�I���
		{
			i++;
			c[i] = copy[d];
			break;
			//printf("%d i:%d\n",__LINE__,i);
			//printf("%d d:%d\n",__LINE__,d);
		}
		//printf("%d i:%d\n",__LINE__,i);
	}
	
	//printf("%d i:%d\n",__LINE__,i);
	
	/*
	printf("c[0]:%c\n",c[0]);
	printf("c[1]:%c\n",c[1]);
	printf("c[2]:%c\n",c[2]);
	printf("c[3]:%x\n",c[3]);
	*/
	
	for(;i >= 0;i--)					//���ɓ���Ă�z��̒��g���t���ɂ��ďo�͗p�̂Ƃ��ɂ���Ă���
	{
		//printf("%d i:%d\n",__LINE__,i);
		buf[j] = c[i];
		j++;
	}
	//printf("buf[0]:%c\n",buf[0]);
	
	buf[j] = '\0';						//�Ō�ɃG���G�k��Y����
	
}


/*------------------------------------------------------------------------*
	�����	�F�r��h��
	�����	�F2017/05/15
	�֐���	�FitohexEX
	�@�\�T�v�F10�i���̐�����16�i���̕�����ɕϊ�
			  ���̐���������܂���EX.......�����������������ł�
*-------------------------------------------------------------------------*/
void itohexEX(int dec,char *buf)
{
	int		i, j, h;
	int		d;      					//���͂��ꂽ���̌v�Z�悤�̗e����̂���
	char	c[MAX];						//���ɓ���Ƃ��z�񂾂�
										//�\�i����0~15�ɑΉ�����char�^�̔z�����
	char	copy[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	
	j = 0;
	d = dec;
	
	
	if(0 <= d)								//���͐��������R���Ȃ�
	{
		if(d < HEX)							//���͂��ꂽ����16�����Ȃ炻���z��ɓ�����A�Ԃ����Ⴏ�����ŏI��肾��
		{
			c[0] = copy[d];
		}
	}
	else									//���̐���������
	{
		d = COMP + (d + 1);					//���͐�����2�̕␔�ɕϊ�
	}
	
	for(i = 0;d >= HEX;i++)				//�v�Z�Ώۂ̐���16�����ɂȂ�܂Ń��[�v����
	{	
		h = d % HEX;					//�v�Z�Ώۂ�16�Ŋ��������܂��������
		
		c[i] = copy[h];					//�O�ɏo�������ɑΉ�����16�i���̐�����ꕨ�ɓ���Ă���
		
		d = d / HEX;					//�v�Z�Ώۂ�16�Ŋ����đ����
		if(d < HEX)						//���������ʂ�16������������A���������̔z��ɂ���ă��[�v�I���
		{
			i++;
			c[i] = copy[d];
			break;
		}
	}
	
	for(;i >= 0;i--)					//���ɓ���Ă�z��̒��g���t���ɂ��ďo�͗p�̂Ƃ��ɂ���Ă���
	{
		buf[j] = c[i];
		j++;
	}
	
	buf[j] = '\0';						//�Ō�ɃG���G�k��Y����
	
}