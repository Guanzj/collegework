#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int a,b=0,c=0; 
    

	a=3,b=5,c=6,c=a+b;  //不建议这样写
	printf("a=%d b=%d c=%d\n",a,b,c);

	{
		double sum;
		int n;

		for( n=1, sum=0 ;n<=100;n=n+1){  //循环语句里用
			sum=sum+sin(1.0/n);
		}	
		printf("sum=%f\n",sum);
	}

    system("pause");
    return 0;
}
