#include <stdio.h>

int main () 
{
    int i, sum=0,fac=1;


    for(i=1; i<=10; i++)  //ѭ�� 1-10
    {//���Ͻṹ
        sum = sum + i; 
        fac = fac * i;
    }

	
	printf("1-10�ĺ�=%d\n",sum);
	printf("1-10�Ļ�=%d\n",fac);
	

	return 1;
}

