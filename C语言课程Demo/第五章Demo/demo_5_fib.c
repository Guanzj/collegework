/*
//使用数组求Fibonacci数列
*/


#include <stdio.h>
#include <stdlib.h>

int main(){
    int fib[40]={1,1},i;

	printf("==============从0开始循环============");
	//从0开始循环到39
    for(i=0;i<40;i++){
        if(i>1)//计算fib(n)
		{
            fib[i]=fib[i-1]+fib[i-2];
		}
        printf("Fib(%d)=%d\n",i,fib[i]);
    }

/*
	printf("==============从2开始循环============");
	
	printf("Fib(0)=%d\n",fib[0]);
	printf("Fib(1)=%d\n",fib[1]);

	//不计算前两项
    for(i=2;i<40;i++){    
            fib[i]=fib[i-1]+fib[i-2];
			printf("Fib(%d)=%d\n",i,fib[i]);
    }
*/	

	system("pause");
    return 0;
}
