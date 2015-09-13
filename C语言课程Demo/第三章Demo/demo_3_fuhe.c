#include <stdio.h>

int main () 
{
    int i, sum=0,fac=1;


    for(i=1; i<=10; i++)  //循环 1-10
    {//复合结构
        sum = sum + i; 
        fac = fac * i;
    }

	
	printf("1-10的和=%d\n",sum);
	printf("1-10的积=%d\n",fac);
	

	return 1;
}

