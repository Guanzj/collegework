/*
	��ʾָ���*��++����ϲ���
*/


#include <stdio.h>

int main(){
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	int *p=a;
	int n=1111;

	printf("n=%d; p=%d\n",n, p);

	n=*p++;      //��Ч�ڣ�n=*p; p++;
	printf("n=%d; p=%d\n",n, p);

	n=*++p;      //��Ч�ڣ�p++; n=*p;
	printf("n=%d; p=%d\n",n, p);

	++*p;		//��Ч�� ++(*p), Ҳ��Ч��++a[2];
	printf("a[2]=%d; p=%d\n",a[2], p);

	return 0;
}