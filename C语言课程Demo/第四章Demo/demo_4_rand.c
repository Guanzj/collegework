
/*
	��ʾ�漴����rand()��ʹ�÷���
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	int i;

	//���ϵͳ�ܹ�����������������ֵ
	printf( "the RAND_MAX is %d.\n", RAND_MAX );

	//
    printf( "Five numbers generated as follows:\n" );

	//srand(time(0));//�ָ����ӣ�������rand�����������������ÿ�ζ���ͬ��time()

	for(i=0;i<5;i++)
		printf("%d ",rand()); //���������


	printf("\n");

	return 0;
}