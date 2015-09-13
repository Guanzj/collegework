/*
	演示指针的*和++的组合操作
*/


#include <stdio.h>

int main(){
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	int *p=a;
	int n=1111;

	printf("n=%d; p=%d\n",n, p);

	n=*p++;      //等效于：n=*p; p++;
	printf("n=%d; p=%d\n",n, p);

	n=*++p;      //等效于：p++; n=*p;
	printf("n=%d; p=%d\n",n, p);

	++*p;		//等效于 ++(*p), 也等效于++a[2];
	printf("a[2]=%d; p=%d\n",a[2], p);

	return 0;
}