#include <stdio.h>
#include <stdlib.h>

int main(){

	int n=100;

	int score[100]={0};

	score[109]=3;
	printf("score[10]=%d\n",score[109]);

	score[-1]=4;
	printf("score[-100]=%d\n",score[-1]);


	
	system("pause");
	return 0;
}