#include <stdio.h>

int main(){
	int *p,n=0x00000130;
	char *q;
	//void *gp1=&n;
	p=&n;
	q=p;

	printf("%d %c\n",*p,*q);


	printf("%d %d\n",*p,*q);

	return 0;
}