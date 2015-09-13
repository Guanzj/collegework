/*
	演示静态变量的用法
*/


#include <stdio.h>

void inc(){

	//int count=0;   //普通（自动）局部变量，函数调用时才分配内存并初始化，函数结束时消失

	static int count;  //静态局部变量，编译时分配，并且地址固定不变，是一个“宏观”的变量，可以认为每次调用函数都用的同一个固定不变的变量


	count++;    //对于具有“宏观”特性的静态变量，每一次调用该函数时，都是对同一个地址的变量进行累积操作。


	printf("count=%d\n",count);
}

int main(){
	int i;
	
	//调用10次inc函数
	for(i=0;i<3;i++){
		inc();
	}


	return 0;
}