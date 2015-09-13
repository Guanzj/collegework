/*
	演示用函数的形式判断一个整数是否是完数
*/

#include <stdio.h>
#include <stdlib.h>

int isPerfectNumber(int n){ //返回1是完数；返回0不是完数
    int i,sum;

    for(i=1,sum=0;i<=n/2;i++){
        if(n%i==0)
            sum+=i;
    }

    //return sum==n;  //如果是完数，则返回1；否则返回0

	//return sum==n? 1:0;  //另一种形式

	if(sum==n)     //又一种形式
		return 1;
	else
		return 0;
}

int main()
{
	int n;

	for(n=1;n<=10000;n++)
	{
		//调用函数判断n是不是完数 
		if(isPerfectNumber(n))
			printf("%d\n",n);
	}
	system("pause");
	return 0;
}
