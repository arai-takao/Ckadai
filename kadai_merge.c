/*--------------------------------------------*

	�����	�F�r��h��
	�����	�F2017/05/22
	�X�V	�F2017/05/24
	�ۑ�t�@�C���}�[�W

*---------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#define		NUM		5

struct FILE_BUF
{
	 char  num[NUM];	/* ���� */
	 char  kind;    /* ��� */
	 char  crlf[2];	/* ���s���� */
};

int FileMerge(char*,char*,char*,char*); //��̃t�@�C�������킹��̃t�@�C���ɏo��
int GetLine(FILE*,struct FILE_BUF*);



void main(void)
{
	//�t�@�C���}�[�W�֐��Ăяo��
	if(FileMerge("test1.dat","test2.dat","test3.dat","r+b") == -1)
	{
		printf("file merge failure\n");
	}
	
}

/*--------------------------------------------------------------*
	�����	�F�r��h��
	�����	�F2017/05/24
	�֐���	�FFileMerge
	�@�\�T�v�F
	4�P�^�̐����ƈꕶ���̃A���t�@�x�b�g�̗l���ŁA�����̏�����
	�\�[�g����Ă����̃t�@�C�����}�[�W����
		
*---------------------------------------------------------------*/
int FileMerge(char *a,char *b,char *c,char *m)
{
	int				f;
	FILE			*a_fp;
	FILE			*b_fp;
	FILE			*c_fp;
	struct FILE_BUF	abuf;
	struct FILE_BUF	bbuf;
	
	f = 1;
	
	//NULL�ۂ��񂽔�r�̂ق��������H
	if((a_fp = fopen(a,m)) == 0)		//�t�@�C����*a���I�[�v���B�ʖڂ�������I������
	{
		printf("%s file open error\n",a);
		return 0;
	}
	if((b_fp = fopen(b,m)) == 0)		//�t�@�C����*b���I�[�v���B�ʖڂ�������I������
	{
		printf("%s file open error\n",b);
		fclose(a_fp);					//*a�����
		return 0;
	}
	if((c_fp = fopen(c,m)) == 0)		//�t�@�C����*c���I�[�v���B�ʖڂ�������I������
	{
		printf("%s file open error\n",c);
		fclose(a_fp);					//*a�����
		fclose(b_fp);					//*b�����
		return 0;
	}
	
	
	if(GetLine(a_fp,&abuf) == -1)		//�f�[�^���ǂݎ��Ȃ�������t�@�C������ďI��
	{
		printf("%s file data error\n",a);
		fclose(a_fp);
		fclose(b_fp);
		fclose(c_fp);
		return 0;
	}
	if(GetLine(b_fp,&bbuf) == -1)		//�f�[�^���ǂݎ��Ȃ�������t�@�C������ďI��
	{
		printf("%s file data error\n",b);
		fclose(a_fp);
		fclose(b_fp);
		fclose(c_fp);
		return 0;
	}
	
	while(1)							//�t�@�C����*c�ɑS�Ă̍s�������������[�v
	{
		if(atoi(abuf.num) <= atoi(bbuf.num))//������r�܂�
		{
			fputs(abuf.num,c_fp);					//�t�@�C��*a�̍\���̂��t�@�C��*c�ɏo��
			if(GetLine(a_fp,&abuf) == 0)			//�t�@�C��*a��ǂݍ��񂾂Ƃ�EOF��������
			{
				fclose(a_fp);						//�t�@�C��*a�����
				while(f)
				{
					f = GetLine(b_fp,&bbuf);
					fputs(bbuf.num,c_fp);			//�t�@�C��*a�̍\���̂��t�@�C��*c�ɏo��
				}
				break;
			}

		}
		else
		{
			fputs(bbuf.num,c_fp);					//�t�@�C��*b�̍\���̂��t�@�C��*c�ɏo��
			if(GetLine(b_fp,&bbuf) == 0)			//�t�@�C��*b��ǂݍ��񂾂Ƃ�EOF��������
			{
				fclose(a_fp);						//�t�@�C��*a�����
				while(f)
				{
					f = GetLine(a_fp,&abuf);
					fputs(abuf.num,c_fp);			//�t�@�C��*a�̍\���̂��t�@�C��*c�ɏo��
				}
				break;
			}
		}
	}
	
	
	fclose(c_fp);
	
	return 1;
	
}

/*---------------------------------------------------*
	�����	�F�r��h��
	�����	�F2017/05/24
	�֐���	�FGetLine
	�@�\�T�v�F
		���߂�ꂽ�l���ŋL�q���ꂽ�t�@�C���̈�s
		���A���̗l���ɍ�����FILE_BUF�\���̂֓����
*----------------------------------------------------*/
int GetLine(FILE *f,struct FILE_BUF *fb)
{
	//�t�@�C������̓��͂���x�z��Ɏ��ׂ����A���̂ق����y����
	int i = 0;
	int d = 0;
	
	char buf[sizeof(FILE_BUF)];
	
	if((buf = fgets(buf,sizeof(FILE_BUF),f)) == NULL)	//�t�@�C�������s��ǂݎ��z��ց@NULL��������0�Ԃ��ďI��
	{
		return 0;
	}
	
	for(i = 0;i < NUM;i++)			//�\���̂�num�ɐ�������������󔒕����͐����������Ă��Ȃ��Ƃ��̂݉�
	{
		
		if(true == isdigit(buf[i]))
		{
			fb->num = buf[i];
			d++;
		}
		else if((' ' == buf[i]) && (0 == d))
		{
			fb->num = buf[i];
		}
		else
		{
			return -1;
		}
	}
	
	if('A' <= buf[i] <= 'Z') //�z��̐����̎��̏ꏊ��A�`Z�̕��������������邻���Ŗ���������I��
	{
		fb->kind = buf[i];
	}
	else
	{
		return -1;
	}
	
	fb->crlf = "lf";		//���s�R�[�h������
	
	return 1;
}