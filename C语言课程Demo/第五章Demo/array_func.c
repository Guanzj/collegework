#include <stdio.h>
#include <stdlib.h>

double average( double a[], int n){
    double sum=0.0;
    int i;
    for(i=0;i<n;i++)  sum+=a[i];
    return sum/n;
}

int main(){
    double score[100],avg;
	int n,i;
    //��������
    scanf("%d",&n);//����
	for(i=0;i<n;i++){
		scanf("%f",&score[i]);//��������ɼ�
	}
    avg=average(score,100);
	printf("avg=%f\n",avg);
	system("pause");
	return 0;
}
