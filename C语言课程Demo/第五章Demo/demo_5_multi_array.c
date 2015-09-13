/*
	演示计算二维矩阵对角线之和，以及二维矩阵的元素读写操作
*/


#include <stdio.h>
#include <stdlib.h>

int main(){
	int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	//int a[3][3]={1,2,3,4,5,6,7,8,9}; //也可以这样初始化

	int sum=0;//记录对角线和值

	int i=0; //行
	int j=0; //列

	//计算对角线和值
	for(i=0;i<3;i++)
	{		
		for(j=0;j<3;j++)
		{
			if(i==j)
			{
				sum=sum+a[i][j];
			}
		}
		
	}

	//打印对角线和值
	printf("the sum=%d\n",sum);


	//------------------打印矩阵的值
	printf("=================print the matrix=================\n");
	for(i=0;i<3;i++)
	{		
		for(j=0;j<3;j++)
		{
			printf("%d  ",a[i][j]);
		}

		printf("\n");  //每一行打印完后，换行
		
	}


	

	return 0;
}