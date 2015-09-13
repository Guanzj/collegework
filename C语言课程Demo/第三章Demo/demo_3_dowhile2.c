#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	double sum=0;
	int n=1;


//-----------------------—› æwhile ”Î do whileµƒ≤Ó“Ï-------------

	n=3;
	while( n<3 )
	{
		sum=sum+n;
		printf("n=%d\n", n);
		n=n+1;
	}

/*
	n=3;
	do
	{
		sum=sum+n;
		printf("n=%d\n",n);
		n=n+1;
	} while(n<3);
*/

	printf("sum=%f\n",sum);
	system("pause");
	return 0;
}
