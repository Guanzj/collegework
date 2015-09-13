/*
	演示：
	（1）打开文本文件
	（2）以字符串的形式，从一个文件中中读取字符串，并将读取到的内容写入到另一个文件中
*/
#include <stdio.h>

int main(){
	FILE *fpr=fopen("input3.txt","r");  //只读方式打开文本文件
	FILE *fpw=fopen("output3.txt","w"); //写的方式建立文本文件
	char buf[100];      //缓冲区

	//如果打开文件有问题，则返回
	if(fpr==NULL||fpw==NULL){
		printf("open file error\n");
		return 0;
	}

	//从源文件每次读取不超过100个字符的字符串
	while(fgets(buf,100,fpr)!=NULL){
		fputs(buf,fpw); //将字符串写入目标文件
	}

	//flush数据到磁盘，并关闭文件
	fclose(fpr);
	fclose(fpw);

	return 0;
}