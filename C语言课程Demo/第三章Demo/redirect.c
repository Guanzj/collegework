#include <stdio.h>

int main(){
	int i,n,max=0,min=100,avg=0;

	//printf("先输入数字的个数:");
	scanf("%d",&n);

	//printf("请输入%d个数字用于求他们的最小值、最大值、平均值:\n");

	for(i=0;i<n;i++){
		int item;
		scanf("%d",&item);
		avg+=item;
		if(item>max)
			max=item;
		if(item<min)
			min=item;
	}

	avg/=n;
	printf("max:%d\n",max);
	printf("min:%d\n",min);
	printf("avg:%d\n",avg);

	system("pause");

	return 0;
}