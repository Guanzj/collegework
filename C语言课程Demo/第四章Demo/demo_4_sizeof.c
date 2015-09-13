/*
	演示sizeof()的用法
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	

	int a[]={1,2,3};
	double b[]={0,0,0};

	int i;
	long longI;

	int size;



	size=sizeof(i);     //变量的长度
	size=sizeof(int);	//数据类型的长度
	size=sizeof(long);	//数据类型的长度

	size=sizeof(a);		//数组的长度
	size=sizeof(a[0]);


	size=sizeof(b);
	size=sizeof(b[0]);


	size=size;


	return;
}