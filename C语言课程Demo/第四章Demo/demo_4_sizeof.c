/*
	��ʾsizeof()���÷�
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



	size=sizeof(i);     //�����ĳ���
	size=sizeof(int);	//�������͵ĳ���
	size=sizeof(long);	//�������͵ĳ���

	size=sizeof(a);		//����ĳ���
	size=sizeof(a[0]);


	size=sizeof(b);
	size=sizeof(b[0]);


	size=size;


	return;
}