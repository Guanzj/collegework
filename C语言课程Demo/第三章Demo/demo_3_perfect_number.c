#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,i,sum;

	//扫描1-10000之间的所有整数
	for(n=1;n<=10000;n++)
	{
		//求n的因子之和 
		for(sum=0,i=1;i<=n/2;i++)
		{
			if(n%i==0)
				sum+=i;
		}
		//判断n是不是完数 
		if(sum==n)
			printf("%d\n",n);

        //!!!!!!注意，内外两个for循环控制变量（n,i）不能无故相互干扰

	}
	system("pause");
	return 0;
}
