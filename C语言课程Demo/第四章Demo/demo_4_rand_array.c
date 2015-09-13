
/*
	演示数组作为参数传给函数。
*/

#include <stdio.h>
#include <stdlib.h>

void rand_int( int a[], int n ){
    int i;
    srand(time(0));
	
    for( i = 0; i < n; i++ )
	{
        a[i] = rand()%100;
	}

	//输出数组
	printf("-----------in rand_int-----------\n");
    for( i = 0; i < n; i++ )
	{
        printf("a[%d]=%d\n",i,a[i]);
	}

	printf("\n");
}


int main(){
    int rand_num [10];
	int i;

    rand_int(rand_num, 10);

	printf("-----------in main-----------\n");
	for(i=0;i<10;i++)
	{
		printf("rand_num[%d]=%d\n",i,rand_num[i]);
	}
	printf("\n");
}
