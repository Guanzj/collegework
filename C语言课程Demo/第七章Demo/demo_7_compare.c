/*
	��ʾָ��ıȽ�
*/

#include <stdio.h>

void main()
{
	int a[10];
	int *p1=a
	int *p2=&a[10]; //p2ָ��������a֮��ĵ�ַ

	int i=0;

	while( p1<p2 ){
		*p1=i;	//��Ӹ�ֵ����p1ָ����ڴ渳ֵ
		p1++;	//ָ�������һ��Ԫ��
		i++;	
	}

	p1=a; //��ָ���ƶ���������׵�ַ
	for(i=0;i<10;i++)
	{
		printf("%d\n", *(p1+i) );
	}
} 
