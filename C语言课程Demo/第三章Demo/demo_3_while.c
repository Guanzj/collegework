/*
	while语句演示
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	double sum=0;      //记录最终值    1.sum不初始化会出现什么问题？

	int flag=0;        //控制标志

	int n=1; //用作循环的控制和计算    2.n不初始化会出现什么问题？

	while(n<=100){    // 可以使用单步跟踪来演示     
		sum=sum+sin(1.0/n);     //用作累加  3. 如果写成1/n会出现什么问题？
		n=n+1;                  //增1       4. 如果没有这条语句会出现什么问题？
	}	

/*
	flag=1;
	while(flag)         //使用第三方的标志来控制循环结束
	{
		sum=sum+sin(1.0/n);     
		n++;

		if(n>100)
		{
			flag=0;
		}
	}
*/

/*
	n=1;
	while(1)      //使用 n>100 和 break 来控制循环结束
	{
		sum=sum+sin(1.0/n);     
		n++;

		if(n>100)
		{
			break;
		}
	}
*/

	printf("sum=%f\n",sum);
	system("pause");
	return 0;
}
