/*
	递归演示：求n的阶乘
*/

#include <stdio.h>
#include <stdlib.h>

/*====================
求n的阶乘的函数：递归形式
====================*/
int fac(int n){

	if(n==0)   //0 的阶乘为1，这是一个具体的值，函数返回
		return 1;

	return n*fac(n-1); //当n!=0时，递归调用n!=n*(n-1)!
}



int main(){
	
	int n=0;

	scanf("%d",&n);

	printf("%d! =%d\n",n,fac(n));  //求三的阶乘
	system("pause");
	return 0;
}