/*
	演示在一个范围内产生随机数
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int i, low=20, high=50;

	printf( "the RAND_MAX is %d.\n", RAND_MAX );
    printf( "Five numbers generated as follows:\n" );


	srand(time(NULL));　//种子


	for(i=0;i<5;i++)
		printf("%d ",low+(rand()%(high-low)));    //产生[low,high]之间的随机数



	printf("\n");
	system("pause");

	return 0;
}