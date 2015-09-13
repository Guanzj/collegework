#include <stdio.h>
#include <stdlib.h>

int main(){
	int img[256][256],a[256]={0};
	int m,n,k,i,j;
	
	
	scanf("%d %d %d",&m,&n,&k);    //输入灰度图像的大小（图像为m*n,对应的数组为img[n][m]）,以及像素的灰度级（256）


	for(i=0;i<n;i++){   //i控制行循环

		for(j=0;j<m;j++){//j控制列循环
			scanf("%d",&img[i][j]);
			a[ img[i][j] ]++;
		}

	}

	//输出灰度直方图
	for(i=0;i<k;i++)
		printf("%d %d\n",i,a[i]);

	return 0;
}