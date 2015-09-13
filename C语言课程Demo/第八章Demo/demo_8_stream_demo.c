/*
	演示以文本流、二进制流处理数据和文件
*/

#include <stdio.h>

int main(){

	FILE *fp; //文件指针
	int n=123456;

	fp=fopen("out1.txt","w");  //打开一个文本文件，用于写入数据
	fprintf(fp,"%d",n);    //向文件中写入整数n
	fclose(fp);		//关闭文件			

	fp=fopen("out2.txt","wb");  //打开一个二进制文件，用于写入数据
	fwrite(&n,sizeof(int),1,fp); //向文件中写入整数n
	fclose(fp);     //关闭文件

	return 0;
}
