#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int i;
	printf( "the RAND_MAX is %d.\n", RAND_MAX );
    printf( "Five numbers generated as follows:\n" );
	srand(time(NULL));
	for(i=0;i<5;i++)
		printf("%d ",rand());
	printf("\n");
	system("pause");
	return 0;
}