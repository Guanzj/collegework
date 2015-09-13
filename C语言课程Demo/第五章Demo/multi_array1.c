#include <stdio.h>
#include <stdlib.h>

int maxa(int a[],int n){
	int i,maxv=a[0];

	for(i=1;i<n;i++)
		if(a[i]>maxv)maxv=a[i];

	return maxv;
}

int main(){
	int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int row=0;
	for(row=0;row<3;row++){
		int row_max=maxa(a[row],3);
		printf("the max of row %d is %d\n",row,row_max);
	}

	return 0;
}