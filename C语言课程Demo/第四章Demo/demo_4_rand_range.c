/*
	��ʾ��һ����Χ�ڲ��������
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int i, low=20, high=50;

	printf( "the RAND_MAX is %d.\n", RAND_MAX );
    printf( "Five numbers generated as follows:\n" );


	srand(time(NULL));��//����


	for(i=0;i<5;i++)
		printf("%d ",low+(rand()%(high-low)));    //����[low,high]֮��������



	printf("\n");
	system("pause");

	return 0;
}