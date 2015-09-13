/*
	判断一个数是否是素数
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,n=11;


	 //------------------------------简洁写法
	for(i=2;i<n;i++){
		if(n%i==0){//判断i是不是n的因子 
			break; //i是因子，说明该数不是素数，退出循环 
		}
	}	

	if(i==n) //i已经等于n了，还没有找到因子，说明是素数
		printf("%d is prime.\n",n);
	else
		printf("%d is not prime.\n",n);

/*
	//--------更易于理解的写法
	{

	int primeFlag=1;   //用个标志来表示是否是素数，初始值=1认为是素数，如果后面发现不是素数则另=0；

	for(i=2;i<n;i++){
		if(n%i==0){//判断i是不是n的因子 
			primeFlag=0;   //存在因子，不是素数
			break; //退出循环 
		}
	}

	if(primeFlag==1) //i已经等于n了，还没有找到因子，说明是素数
		printf("%d is prime.\n",n);
	else
		printf("%d is not prime.\n",n);

	}
*/		
	system("pause");
	return 0;
}
