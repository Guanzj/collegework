#include <stdio.h>
#include <stdlib.h>

double average( int a[][4], int rows ){
    double sum=0.0;
	int i,j;
    for(i=0;i<rows;i++)
        for(j=0;j<4;j++)
            sum+=a[i][j];
		return sum/(rows*4); 
}

int main(){
    int array1[2][4]={{0,1,2,3},{4,5,6,7}};
	int array2[2][5]={{0,1,2,3,0},{4,5,6,7,0}};
    double avg;
	avg = average(array1, 2);
	printf("avg of array1 =%f\n",avg);

	avg = average(array2, 2);
	printf("avg of array2 =%f\n",avg);

	system("pause");
	return 0;
}
