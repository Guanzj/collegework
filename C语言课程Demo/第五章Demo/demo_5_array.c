/*
	数组的定义、使用
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int i;

	//定义数组
	int a[5];
	int tempArray[10], score[58];

	//错误的定义
	//int n=4;
	//int b[n];


	//使用数组元素
	a[4]=0;

	//在循环中使用数组元素
	for(i=0;i<5;i++){
		score[i]=i*2;
		printf("score[%d]=%d\n",i,score[i]);
	}


    //在循环中使用数组元素
	for(i=0;i<4;i++){
		a [i] = i;		//第i+1个元素赋值为i
		a[4] += a[i] ;  //第5个元素（下标为4）记录前面所有元素的和
		printf("a[%d]=%d\n",i,a[i]);
	}

	printf("a[%d]=%d\n",i,a[i]);
	printf("\n");


	//获得数组首地址的三种等效方法
	printf("the address of array is %x\n",a);		//直接使用数组名
	printf("the address of array is %x\n",&a);		//取数组名的地址
	printf("the address of array is %x\n",&a[0]);	//取第一个元素的地址
	printf("\n");


	//数组每个元素的地址与首地址的关系
	for(i=0;i<5;i++){
		printf("the address of a[%d] is %x\n",i,&a[i]); //取i元素的地址
	}
	return 0;
}