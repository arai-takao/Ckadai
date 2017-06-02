/*--------------------------------------------*

	����ҁF�r��h��
	������F2017/04/19
	�ۑ�No.10

*---------------------------------------------*/

/* �C���N���[�h */
#include <stdio.h>
#include <string.h>

#define	MAX	5


void	sort1(int data[MAX]);
void	sort2(int data[MAX]);
int		sort3(int *data,int);


void main(void)
{
	
	int data[]={9,21,119,45,3,45,33,76,88,1,2,56,4,5};//�z��ɐ��������
	int i;
	
	sort3(data,(sizeof data / sizeof data[0]));
	for(i = 0;i < (sizeof data / sizeof data[0]);i++)printf("%3d\n",data[i]);
	
}

/*--------------------------------------------*
	�����	�F�r��h��
	�����	�F2017/04/19
	�֐���	�F�o�u���\�[�g1
	�@�\�T�v�F�z��̒��̃f�[�^���~���Ƀ\�[�g����
*---------------------------------------------*/
void	sort1(int data[MAX])
{
	int	copy;
	int	i,j;
	
	
	for(i = 0;i < MAX;i++)		//i��data�̂͂��ɍs���܂łP����
	{
		for(j=0;j < MAX;j++){	//i�̒��ŁAj��data�̂͂��ɍs���܂łP����
			
			if(data[i] > data[j])	//data��i�Ԗڂ�j�Ԗڂ��傫�����������
			{
		 		copy = data[i]; 
				data[i] = data[j];
				data[j] = copy;
			}
			
		}
		
	}
	//for(i=0;i<MAX;i++)printf("%3d\n",data[i]);

	//return	data; 
}


/*--------------------------------------------*
	�����	�F�r��h��
	�����	�F2017/04/19
	�֐���	�F�o�u���\�[�g2
	�@�\�T�v�F�z��̒��̃f�[�^���~���Ƀ\�[�g����
			  1��菭�����[�v�񐔂����Ȃ�
*---------------------------------------------*/

void	sort2(int data[MAX])
{
	int	copy;
	int	i,j;
	
	for(i = 0;i < MAX;i++)	//i��data�̂͂��ɍs���܂łP����
	{	
		for(j = i;j < MAX;j++)	//i�̒��ŁAj��data��i�Ԗڂ���͂��ɍs���܂łP����
		{
			
			if(data[i] > data[j])	//data��i�Ԗڂ�j�Ԗڂ��傫�����������
			{
		 		copy = data[i];
				data[i] = data[j];
				data[j] = copy;
			}
			
		}
		
	}
	
}


/*--------------------------------------------*
	�����	�F�r��h��
	�����	�F2017/04/19
	�֐���	�F�N�C�b�N�\�[�g �o���ĂȂ�
	�@�\�T�v�F�z��̒��̃f�[�^���~���Ƀ\�[�g����
			  
*---------------------------------------------*/

int		sort3(int *data,int DataNum)
{	
	int	right, left, center, copy, point;
	
	
	center = DataNum / 2; 	//data���̒��ԁA�����_�ȉ��͐؂�̂Ă��
	point = data[center];		//data�̒��Ԃɓ����Ă��鐔����point�ɓ�����
	right = 0;
	left = DataNum;	
	
	static int count = 0;
	count++;
	
	if(DataNum <= 1)
	{
		return 0;
	}
	
	//printf("datanum:%d\n",DataNum);
	while(1)
	{	
			
		//data�̉E�ʒu��point��菬������������̕K�v�͂Ȃ��̂ŉE�ʒu�������߂��
		if(data[right] <= point)
		{
			right++;
		}
		//data�̍��ʒu��point���傫����������̕K�v�͂Ȃ��̂ō��ʒu�������߂��
		if(data[left] >= point)
		{
			left--;
		}
		
		//�E�ʒu��point���傫���ƍ��ʒu��point��菬�����������ゾ��B���̂��Ƃ��ꂼ��i�߂��
		if((data[right] >= point) && (data[left] <= point))
		{
			/*printf("copy:%d\n",copy);
			printf("data[right]:%d\n",data[right]);
			printf("data[left]:%d\n",data[left]);*/
			
			copy = data[right];
			data[right] = data[left];	
			data[left] = copy;
			
		}
		
		//�E�ʒu�ƍ��ʒu�����������烋�[�v�I���A�����l�ł���
		if(right >= left)
		{
			break;
		}
	}
	
	//printf("right :%d\n",right);
	//printf("left :%d\n\n",left);
	
	sort3(data,right - 1);
	sort3(&data[right],(DataNum - right));
	
	return 1;
}
