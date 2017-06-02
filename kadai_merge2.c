#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define		ROW		4
#define		NUM		5
#define		FILE_A	"test1.dat"
#define		FILE_B	"test2.dat"
#define		FILE_C	"test3.dat"
#define		MODE	"r+b"

typedef struct
{
	 char  num[NUM];	/* 数字 */
	 char  kind;		/* 種別 */
	 char  crlf[2];		/* 改行ｺｰﾄﾞ*/
}FILE_BUF;

//関数の宣言　ファイルからFILE_BUF構造体配列に全て読みだす
int GetFileTex(FILE*,FILE_BUF*);

int main(void)
{
	
	FILE			*a_fp;
	FILE			*b_fp;
	FILE			*c_fp;
	FILE_BUF		mbuf[(ROW * 2) + 1];
	FILE_BUF		copybuf;
	int				p;
	int				i,j;
	
	p = 0;
	
	
	//NULLぽいんた比較のほうがいい？
	if((a_fp = fopen(FILE_A,MODE)) == 0)		//ファイル名*aをオープン。駄目だったら終了する
	{
		printf("%s file open error\n",FILE_A);
		return 0;
	}
	if((b_fp = fopen(FILE_B,MODE)) == 0)		//ファイル名*bをオープン。駄目だったら終了する
	{
		printf("%s file open error\n",FILE_B);
		fclose(a_fp);					//*aを閉じる
		return 0;
	}
	if((c_fp = fopen(FILE_C,MODE)) == 0)		//ファイル名*cをオープン。駄目だったら終了する
	{
		printf("%s file open error\n",FILE_C);
		fclose(a_fp);					//*aを閉じる
		fclose(b_fp);					//*bを閉じる
		return 0;
	}
	
	
	//ファイルひとつめを構造体配列に読み込む
	if((p = GetFileTex(a_fp,mbuf)) == -1)
	{
		printf("%s file data error\n",FILE_A);
		fclose(a_fp);
		fclose(b_fp);
		fclose(c_fp);
		return 0;
	}
	
	//ファイルふたつめを、前のファイルデータの続きから構造体配列に読み込む
	if(GetFileTex(b_fp,&mbuf[p]) == -1)
	{
		printf("%s file data error\n",FILE_B);
		fclose(a_fp);
		fclose(b_fp);
		fclose(c_fp);
		return 0;
	}
	
	//不要になったファイル１、２を閉じる
	fclose(a_fp);
	fclose(b_fp);
	
	//バブルソートで構造体の配列を昇順にソートする
	for(i = 0;i < (ROW*2);i++)
	{
		for(j = i;j < (ROW*2);j++)
		{
			if((atoi(mbuf[i].num)) > (atoi(mbuf[j].num)))//構造体メンバnumを数値化して比較を行う
			{
				//構造体の入れ替え
				copybuf = mbuf[i];
				mbuf[i] = mbuf[j];
				mbuf[j] = copybuf;
			}
			else if(atoi(mbuf[i].num) == atoi(mbuf[j].num))//メンバnumの数値が同じ時はメンバkindのアルファベットで入れ替え
			{
				if(mbuf[i].kind > mbuf[j].kind)//アルファベットの比較　A～Zの順で並べる
				{
					//構造体の入れ替え
					copybuf = mbuf[i];
					mbuf[i] = mbuf[j];
					mbuf[j] = copybuf;
				}
			}
		}
	}
	
	mbuf[ROW*2].num[0] = '\0';//最後の構造体の先頭にNULL文字を入れる。
	printf("%s",mbuf);//画面に構造体データを出力
	
	if((fprintf(c_fp,"%s",mbuf)) < 0)//ファイルに構造体を出力、出来なかったらエラー表示
	{
		printf("file output error\n");
	}
	
	fclose(c_fp);//書き込み用ファイル閉じる
	return 1;
}
/*---------------------------------------------------*
	制作者	：荒井敬生
	制作日	：2017/05/24
	関数名	：GetFileTex
	機能概要：
		FILE_BUF構造体の配列にファイルの内容を全て書く
*----------------------------------------------------*/
int GetFileTex(FILE *f,FILE_BUF *fb)
{
	//ファイルからの入力を一度配列に持つべきか、そのほうが楽そう
	int	i,k;					//ループ用変数i
	int	j = 0;					//構造体代入回数記録用変数
	int	cou = 0;				//構造体numへの数字代入回数記録変数
	int	cou2 = 0;				//空白文字代入回数記録変数
	int	m = 0;					//numに最後に入った番号を保持する変数
	
	char buf[sizeof(FILE_BUF)];//ファイルデータ一時格納用の配列
	//野戸谷さんの探し方もしてみる
	
	while(1)
	{
		memset(buf,'\0',sizeof(FILE_BUF));//一時格納用配列の初期化　ループごと
		if((fgets(buf,sizeof(FILE_BUF)+1,f)) == NULL)	//ファイルから一行を読み取り配列へ　NULLだったらｊ返して終了
		{
			return j;//ファイルが終わったら構造体配列の何番目まで入れたか返す
		}		
		for(i = 0;!isupper(buf[i]);i++)	//大文字アルファベットがbuf[i]に出てくるまでループ
		{
			if(isdigit(buf[i]))//buf[i]が数字だったら構造体numに代入して数字の代入回数を加算
			{
				fb[j].num[i] = buf[i];
				cou++;
			}
			else if((' ' == buf[i]) && (0 == cou))//数字まだnumに入っていない時のみ空白文字代入が可
			{
				fb[j].num[i] = buf[i];
				cou2++;
			}
			else
			{
				return -1;//数字文字や空白文字の条件を満たさなければ、読み取ったデータがおかしいので-1を返して終了
			}
		}
	/*	
		m = (cou + cou2);
		if(m < 5)		//入力文字が少なかった時、空白で補完
		{
			for(k = (m - 1);0 <= k;k--)
			{
				fb[j].num[k + ((NUM -1) - k)] = fb[j].num[k];
				fb[j].num[k] = ' ';
			}
		}
	*/	
		if(isupper(buf[i])) //配列の数字の次の場所がA～Zの文字だったら入れる。そうで無かったら終了
		{
			fb[j].kind = buf[i];
			i++;
		}
		else
		{
			return -1;//大文字アルファベットの条件を満たさなければ-1を返して終了
		}
		fb[j].crlf[0] = buf[i];		//改行コード、ふた文字を入れる
		fb[j].crlf[1] = buf[i + 1];
		
		j++;//構造体代入回数を加算
		
		//カウントの初期化
		cou = 0;
		cou2 = 0;
	}
}