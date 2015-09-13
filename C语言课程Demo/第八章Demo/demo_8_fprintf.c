/*
	演示以格式化的方式从文本文件读入数据
*/


#include <stdio.h>

int main(){
	FILE * fp=fopen("lgx_temp.txt","w");  //创建只读文本文件test.txt

	FILE *reRead=NULL;  //重新打开的文件指针
	int n;
	int i;
	int j;

	//文件打开错误，返回
	if(fp==NULL)     
	{
		printf("open file error\n");
		return 0;
	}	

	for(i=0;i<3;i++)
	{
		for(j=0;j<10;j++)
		{
			n=i*j;
			fprintf(fp,"%d ",n);  //以格式化的方式从文件中读取数据（这里是整数）
		}

		fprintf(fp,"\n");
	}

	//关闭文件
	fclose(fp);

	//将刚才建立的文本文件test.txt重新打开
	reRead=fopen("test_out.txt","r");  

	//文件打开错误，返回
	if(reRead==NULL)     
	{
		printf("open file error\n");
		return 0;
	}	

	//读取数据，并输出到屏幕
	for(i=0;i<3;i++)
	{
		for(j=0;j<10;j++)
		{			
			fscanf(fp,"%d",&n); //格式化的方式从文件中读取整数
			printf("%d ",n);  //输出到屏幕
		}

		printf("\n");		
	}

	fclose(reRead);

	return 0;
}