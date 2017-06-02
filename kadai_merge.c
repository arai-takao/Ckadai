/*--------------------------------------------*

	制作者	：荒井敬生
	制作日	：2017/05/22
	更新	：2017/05/24
	課題ファイルマージ

*---------------------------------------------*/
#include <stdio.h>
#include <ctype.h>
#define		NUM		5

struct FILE_BUF
{
	 char  num[NUM];	/* 数字 */
	 char  kind;    /* 種別 */
	 char  crlf[2];	/* 改行ｺｰﾄﾞ */
};

int FileMerge(char*,char*,char*,char*); //二つのファイルを合わせ一つのファイルに出力
int GetLine(FILE*,struct FILE_BUF*);



void main(void)
{
	//ファイルマージ関数呼び出し
	if(FileMerge("test1.dat","test2.dat","test3.dat","r+b") == -1)
	{
		printf("file merge failure\n");
	}
	
}

/*--------------------------------------------------------------*
	制作者	：荒井敬生
	制作日	：2017/05/24
	関数名	：FileMerge
	機能概要：
	4ケタの数字と一文字のアルファベットの様式で、数字の昇順で
	ソートされている二つのファイルをマージする
		
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
	
	//NULLぽいんた比較のほうがいい？
	if((a_fp = fopen(a,m)) == 0)		//ファイル名*aをオープン。駄目だったら終了する
	{
		printf("%s file open error\n",a);
		return 0;
	}
	if((b_fp = fopen(b,m)) == 0)		//ファイル名*bをオープン。駄目だったら終了する
	{
		printf("%s file open error\n",b);
		fclose(a_fp);					//*aを閉じる
		return 0;
	}
	if((c_fp = fopen(c,m)) == 0)		//ファイル名*cをオープン。駄目だったら終了する
	{
		printf("%s file open error\n",c);
		fclose(a_fp);					//*aを閉じる
		fclose(b_fp);					//*bを閉じる
		return 0;
	}
	
	
	if(GetLine(a_fp,&abuf) == -1)		//データが読み取れなかったらファイルを閉じて終了
	{
		printf("%s file data error\n",a);
		fclose(a_fp);
		fclose(b_fp);
		fclose(c_fp);
		return 0;
	}
	if(GetLine(b_fp,&bbuf) == -1)		//データが読み取れなかったらファイルを閉じて終了
	{
		printf("%s file data error\n",b);
		fclose(a_fp);
		fclose(b_fp);
		fclose(c_fp);
		return 0;
	}
	
	while(1)							//ファイル名*cに全ての行を書きだすループ
	{
		if(atoi(abuf.num) <= atoi(bbuf.num))//数字比較まだ
		{
			fputs(abuf.num,c_fp);					//ファイル*aの構造体をファイル*cに出力
			if(GetLine(a_fp,&abuf) == 0)			//ファイル*aを読み込んだときEOFだったら
			{
				fclose(a_fp);						//ファイル*aを閉じる
				while(f)
				{
					f = GetLine(b_fp,&bbuf);
					fputs(bbuf.num,c_fp);			//ファイル*aの構造体をファイル*cに出力
				}
				break;
			}

		}
		else
		{
			fputs(bbuf.num,c_fp);					//ファイル*bの構造体をファイル*cに出力
			if(GetLine(b_fp,&bbuf) == 0)			//ファイル*bを読み込んだときEOFだったら
			{
				fclose(a_fp);						//ファイル*aを閉じる
				while(f)
				{
					f = GetLine(a_fp,&abuf);
					fputs(abuf.num,c_fp);			//ファイル*aの構造体をファイル*cに出力
				}
				break;
			}
		}
	}
	
	
	fclose(c_fp);
	
	return 1;
	
}

/*---------------------------------------------------*
	制作者	：荒井敬生
	制作日	：2017/05/24
	関数名	：GetLine
	機能概要：
		決められた様式で記述されたファイルの一行
		を、その様式に合ったFILE_BUF構造体へ入れる
*----------------------------------------------------*/
int GetLine(FILE *f,struct FILE_BUF *fb)
{
	//ファイルからの入力を一度配列に持つべきか、そのほうが楽そう
	int i = 0;
	int d = 0;
	
	char buf[sizeof(FILE_BUF)];
	
	if((buf = fgets(buf,sizeof(FILE_BUF),f)) == NULL)	//ファイルから一行を読み取り配列へ　NULLだったら0返して終了
	{
		return 0;
	}
	
	for(i = 0;i < NUM;i++)			//構造体のnumに数字部分を入れる空白文字は数字が入っていないときのみ可
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
	
	if('A' <= buf[i] <= 'Z') //配列の数字の次の場所がA～Zの文字だったら入れるそうで無かったら終了
	{
		fb->kind = buf[i];
	}
	else
	{
		return -1;
	}
	
	fb->crlf = "lf";		//改行コードを入れる
	
	return 1;
}