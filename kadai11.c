/*--------------------------------------------*

	����ҁF�r��h��
	������F2017/04/25
	�ۑ�No.11

*---------------------------------------------*/

#include	<stdio.h>
#include	<string.h>
#define		BUFMAX		256
#define		PASS		3

void	Upper(char*);

void main(void)
{
	static char password[BUFMAX] = "VICTORY";	//�p�X���[�h
	char	buf[BUFMAX];						//���̓G���A
	int		i;
	
	
	for(i=1; i<=PASS; i++)
	{
		
		printf("password input=>");
		scanf("%s",buf);				//�p�X���[�h����
		Upper(buf);						//���������͂͑啶���ɕς����Ⴄ��
		//printf("after upper:%s\n",buf);
		
		if(strcmp(buf,password) == 0)	//�p�X���[�h�Ƃ̔�r
		{
			printf("PASSWORD OK\n");	//��v
			break;		
		}
		if(i==PASS)
		{
			printf("PASSWORD NG\n");	//�s��v
		}
	}
}

/*--------------------------------------------*
	�����	�F�r��h��
	�����	�F2017/04/25
	�֐���	�FUpper
	�@�\�T�v�F��������啶���ɂ����  
*---------------------------------------------*/
void	Upper(char *str)
{
	int	i;
	
	//printf("Buf char:%s\n",str);
	
	for(i = 0; str[i] != '\0'; i++)//�|�C���^��i�Ԗڂ�\0����Ȃ�������i��1������
	{
		
		//printf("str[0] char:%c\n",str[0]);

		if(str[i] >= 97 && str[i] <= 122)//i�Ԗڂ̒��g���������͈̔͂�������啶���ɂ����Ⴄ��
		{
			//printf("conv before char:%c\n",str[i]);
			str[i] -= ' ';
			//printf("conv after char:%c\n",str[i]);
		}
	}
	//printf("Buf char:%s\n",str);
}