#include <stdio.h>
#define	STR	50

void speacedel(void);

void main(void)
{

	speacedel();
	
}

void speacedel(void)
	{
		
	static	char	a[STR]="A B  C   D E FG  ";
	char		b[STR];
	int		bpoint;
	int		i;

	//char		s[]="\n";

	bpoint=0;

	for(i=0;i<STR;i++){
	
		//if(a[i]!=s[1]){

		if(a[i]!=' '){
			b[bpoint]=a[i];
			bpoint++;

		}		
	}

	printf("%s\n",b);
		
	}





























/*""���ƃ|�C���^�Ƃ̔�r�ł��߂Ƃ�����B
�@''�Ȃ�ok�B""���ƃ|�C���^�ɂȂ��Ă�炵���B
�@�z��ɂ�����ok.
�@���̂Ƃ��킴��null�ƂЂ����������STR��30�Ƃ�50�̂Ƃ��������������i���{�ꕶ�����o���j
�@null�������Ƃ̃A�h���X�����ł�H
*/