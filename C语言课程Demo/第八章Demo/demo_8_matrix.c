/*
	演示从文件中读入矩阵数据，并将转置矩阵写入另一个文件
*/


#include <stdio.h>
#define MAX_ROW 10
#define MAX_COL 10

int main(){
	FILE *fp;
	int row,col,i,j;
	int a[MAX_ROW][MAX_COL];

	fp=fopen("a.txt","r");//打开原始矩阵文件
	if(fp==NULL){
		printf("open input file fail\n");
		return 1;
	}

	//先从文件中读入矩阵的行、列
	fscanf(fp,"%d %d",&row,&col);


	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			fscanf(fp,"%d",&a[i][j]); //依次输入原始矩阵元素
		}
	}
	fclose(fp); //关闭文件

	fp=fopen("at.txt","w"); //打开转置矩阵文件，不存在则创建
	if(fp==NULL){
		printf("open output file fail\n");
		return 1;
	}

	fprintf(fp,"%d %d\n",col,row);//输出转置矩阵行列值

	for(i=0;i<col;i++){
		for(j=0;j<row;j++){
			fprintf(fp,"%d ",a[j][i]); //依次输出转置矩阵元素
		}
		fprintf(fp,"\n"); //输出一行后换行
	}
	fclose(fp);
	return 0;
}