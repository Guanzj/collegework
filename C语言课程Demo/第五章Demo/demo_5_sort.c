/*
	选择排序
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	float score[100],t;
	int i,j,k,n,count=0;

	//输入数据的个数
	scanf("%d",&n);//人数

	//根据输入的人数n，输入n个成绩
	for(i=0;i<n;i++){
		scanf("%f",&score[i]);//依次输入成绩
		if(score[i]<60)
		{
			count++;
		}
	}

	//排序：选择排序法
	for(i=0;i<n-1;i++){
		for(k=i+1,j=i;k<n;k++) //找n-i个元素中的最小值
		{
			if(score[k]<score[j])
			{
				j=k;
			}
		}

		if(j!=i){ //如果最小值不是第i个元素则将score[i]和score[j]交换
			t=score[i];
			score[i]=score[j];
			score[j]=t;
		}
	}

	//输出结果
	printf("%d students <60\n%d students >=60\n",count,n-count);
	for(i=0;i<n;i++){
		printf("%f\n",score[i]);
	}
	
	system("pause");
	return 0;
}