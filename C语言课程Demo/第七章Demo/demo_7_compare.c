/*
	演示指针的比较
*/

#include <stdio.h>

void main()
{
	int a[10];
	int *p1=a
	int *p2=&a[10]; //p2指向了数组a之后的地址

	int i=0;

	while( p1<p2 ){
		*p1=i;	//间接赋值，对p1指向的内存赋值
		p1++;	//指针向后跳一个元素
		i++;	
	}

	p1=a; //将指针移动到数组的首地址
	for(i=0;i<10;i++)
	{
		printf("%d\n", *(p1+i) );
	}
} 
