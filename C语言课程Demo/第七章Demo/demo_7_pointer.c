/*
	演示指针的赋值、间接访问
*/

#include <stdio.h>

int main(){
	int *p, *q,  n=10, m, a[10];

	p=&n;
	q=p;
	
	m=*p+*q*n;  //等效于： m=n+n*n
	printf("m=%d\n",m);

	++*p; //等效于： ++n
	printf("n=%d,*p=%d,*q=%d\n",n,*p,*q);

	(*p)++;  //等效于：n++
	printf("n=%d,*p=%d,*q=%d\n",n,*p,*q);

	*p+=*q+n;  //等效于： n+=n+n
	printf("n=%d,*p=%d,*q=%d\n",n,*p,*q);

	q=&a[0];
	*q=*p/12;   //等效于： a[0]=n/12;

	printf("n=%d,*p=%d,*q=%d\n",n,*p,*q);

	return 0;
}