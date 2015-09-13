/*
	求中位数
*/

#include <stdio.h>

int main(){
	int a[100];//保存输入数据
	int n,i;

	//输入数据的数量n
	scanf("%d",&n);

	//判断输入的n是否合理，1-n之间，预防数组越界
	if(n>100 || n<1)
	{
		printf("您输入的n值不合理\n");
		return 0;
	}

	//输入n个数据
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);


	//排序：选择排序法
	for(i=0;i<n-1;i++){
		int j,k;
		for(k=i,j=i+1;j<n;j++){
			if(a[j]<a[k])
			{
				k=j;
			}
		}
		if(k!=i){
			int t;
			t=a[i];
			a[i]=a[k];
			a[k]=t;
		}
	}

	//输出中位数
	if(n%2) //当n为奇数时,中位数的下标为：a[n/2]
		printf("%d\n",a[n/2]);
	else    //当n为偶数时,中位数的下标为：(a[n/2]+a[n/2-1]) /2
		printf("%d\n",(a[n/2]+a[n/2-1])/2);


	return 0;
}