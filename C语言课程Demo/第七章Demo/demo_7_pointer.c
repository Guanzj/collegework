/*
	��ʾָ��ĸ�ֵ����ӷ���
*/

#include <stdio.h>

int main(){
	int *p, *q,  n=10, m, a[10];

	p=&n;
	q=p;
	
	m=*p+*q*n;  //��Ч�ڣ� m=n+n*n
	printf("m=%d\n",m);

	++*p; //��Ч�ڣ� ++n
	printf("n=%d,*p=%d,*q=%d\n",n,*p,*q);

	(*p)++;  //��Ч�ڣ�n++
	printf("n=%d,*p=%d,*q=%d\n",n,*p,*q);

	*p+=*q+n;  //��Ч�ڣ� n+=n+n
	printf("n=%d,*p=%d,*q=%d\n",n,*p,*q);

	q=&a[0];
	*q=*p/12;   //��Ч�ڣ� a[0]=n/12;

	printf("n=%d,*p=%d,*q=%d\n",n,*p,*q);

	return 0;
}