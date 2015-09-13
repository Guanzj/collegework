#include <stdio.h>
#include <stdlib.h>

int main(){
	double f;
	int c;


	for(c=0; c<=100; c=c+5){
		f = c* 9.0/5+32;
		printf("c=%d ,f=%.1f\n", c, f);
	}	
	
	system("pause");
	return 0;
}
