/*
	for—≠ª∑—› æ
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	double sum=0;
	int n;


	for(n=1;n<=100;n=n+1){
		sum=sum+sin(1.0/n);
	}	


	/*
	for(n=1;n<=100;n++){
		sum=sum+sin(1.0/n);
	}
	*/


	printf("sum=%f\n",sum);
	system("pause");
	return 0;
}
