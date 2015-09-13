
/*
	演示随即函数rand()的使用方法
*/
#include <stdio.h>
#include <stdlib.h>

int main(){
	int i;

	//输出系统能够产生的随机数的最大值
	printf( "the RAND_MAX is %d.\n", RAND_MAX );

	//
    printf( "Five numbers generated as follows:\n" );

	//srand(time(0));//种个种子，避免由rand函数产生的随机数序每次都相同。time()

	for(i=0;i<5;i++)
		printf("%d ",rand()); //产生随机数


	printf("\n");

	return 0;
}