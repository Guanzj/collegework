/*
	文本文件的打开、读写
*/

#include <stdio.h>

int main(){
	FILE *fpr=fopen("input2.txt","r");   //打开一个文本文件，用于读取
	FILE *fpw=fopen("output2.txt","w");  //打开一个文本文件，用于写
	char ch;

	//如果出现任何打开文件失败的情况，应返回
	if(fpr==NULL||fpw==NULL){
		printf("open file error\n");
		return 0;
	}

	while((ch=fgetc(fpr))!=EOF){  //从input2.txt中一个字节一个字节的读内容
		fputc(ch,fpw);    //将读到的每个字节，写入文件output2.txt
	}

	//将两个文件关闭（操作系统将缓冲区中的所有内容写入文件，并关闭文件）
	fclose(fpr);
	fclose(fpw);
	return 0;
}
