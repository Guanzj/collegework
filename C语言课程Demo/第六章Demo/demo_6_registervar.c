/*
	演示寄存器变量的用法
*/


#include <stdio.h>


int main(){

	register int i;  //寄存器变量不是在内存中分配的，而是分配到了CPU中的寄存器，所以速度很快，同时不能用取址符操作：&

	
	
	for(i=0;i<1000;i++){
		printf("register variable");
	}

	{
		//register int test;
		//scanf("%d",&test);  //寄存器变量，不能取地址
	}

	return 0;
}