/*
	演示缓冲式输入输出
*/
#include <stdio.h>

int main(){
	char s[100];
	int i,n=0;
	FILE *fp;

	while((s[n]=getchar())!='\n'){  //读入若干个字符，直至换行回车
		s[n]=s[n]-'a'+'A';     //将输入的小写字母转换为大写字母
		putchar(s[n]);    //将转换后的大写字母输出到平明
		n++;
	}

	printf("\n");
	fp=fopen("c:\\chars.txt","w");   //打开文本文件：c:\\chars.txt

	//将输入的内容写入到文件中
	for(i=0;i<n;i++){
		fprintf(fp,"%c",s[i]);
		fflush(fp);//强制写入  在该语句之前的写入内容，并没有真正写入磁盘文件，而是写到了缓冲区中
	}

	fputs("hello",fp);
	fclose(fp);     //关闭文件时，“hello”才真正从缓冲区写入磁盘文件。
	return 0;
}