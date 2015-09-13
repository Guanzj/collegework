#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m=32,n=48,i;
	int gcd=1;  //最大公约数初始值为1

	int min=m<n?m:n;  //缩小循环的次数
    
	
    //-------------method 1： 从小到大循环扫描
	for(i=2;i<=min;i++)
	{
		if(m%i==0 && n%i==0)//判断i是不是公约数：
			gcd=i;//gcd更新为更大的约数 
	}


	/*	
	//--------------method 2：从大到小扫描
	for(i=min;i>=2;i--)
	{
        if(m%i==0&&n%i==0)//判断i是不是公约数 
		{
       	    gcd=i;//i就是最大公约数，退出循环 
       	    break;  //注意，如果没有break, 会出现什么情况
        }
    }
	*/

    
	printf("the gcd of %d and %d is %d\n",m,n,gcd);
	system("pause");
	return 0;
}
