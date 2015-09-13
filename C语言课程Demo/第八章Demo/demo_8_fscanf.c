/*
	演示格式化的方式从文本文件读入数据
*/


#include <stdio.h>

int main(){
	FILE * fp=fopen("test.txt","r");  //打开文本文件test.txt
	int n;

	//文件打开错误，返回
	if(fp==NULL)     
	{
		printf("open file error\n");
		return 0;
	}

	//格式化的方式读入每一个整数
	while(fscanf(fp,"%d",&n)!=EOF)
	{
		printf("%d ",n);  //将整数输出到屏幕
	}

	printf("\n");       

	//关闭文件
	fclose(fp);
	return 0;
}