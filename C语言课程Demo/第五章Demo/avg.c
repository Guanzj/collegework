#include <stdio.h>
#include <stdlib.h>

double average( double a[], int n){
    double sum=0.0;
	int i;
    for(i=0;i<n;i++)
        sum+=a[i];
    return sum/n;
}

int main(){
    double score[100],avg;
    //ÊäÈëÊý¾Ý
    //¡­
	avg=average(score,100);

	printf("avg=%f",avg);

	return 0;
}
