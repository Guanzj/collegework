#include <stdio.h>

int main(){
	int i,n,max=0,min=100,avg=0;

	//printf("���������ֵĸ���:");
	scanf("%d",&n);

	//printf("������%d���������������ǵ���Сֵ�����ֵ��ƽ��ֵ:\n");

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