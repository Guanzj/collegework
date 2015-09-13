/*
	演示将指针作为函数参数，可以同时返回除数和余数
*/

#include <stdio.h>

void division(int dividend, 
				   int divisor, 
				   int *quotientp, 
				   int *remainderp)
{
	*quotientp = dividend / divisor;	//指针指向的内存记录除数
	*remainderp = dividend % divisor;	//指针指向的内存记录余数
}
	
int main(){
	int quot, rem,*p=NULL;

	//p=&quot;

	printf("%d\n",*p); // 对一个没有指向具体地址的内存操作，会出现Bug

	division(40, 3, &quot, &rem); //将quot和rem的地址传给函数的指针

	printf("40 divided by 3 yields quotient %d ", quot);
	printf("and remainder %d\n", rem);

	return 0;
}


