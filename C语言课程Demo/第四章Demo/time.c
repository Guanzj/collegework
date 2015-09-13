#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int i;
	srand(time(NULL));
	for(i=0;i<5;i++)
		printf("%d ",rand());
	printf("\n");
	system("pause");
	return 0;
}