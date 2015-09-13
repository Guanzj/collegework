#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	double sum=0;
	int n=1;

	
	do{
		sum=sum+sin(1.0/n++);
		n=n+1;
	}while(n<=100);


/*
	while(n<=100)
	{
		sum=sum+sin(1.0/n++);
		n=n+1;
	}
*/

	printf("sum=%f\n",sum);
	system("pause");
	return 0;
}
