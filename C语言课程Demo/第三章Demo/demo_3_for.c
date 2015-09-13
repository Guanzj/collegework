/*
	for循环演示
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	
	int flag=0;
	
	double sum=0;	
	int n;


	//计算1+2+3,演示跟踪
	for(n=1,sum=0;n<=3; n=n+1)
	{
		sum=sum+n;	
	}	

/*
	//---------------计算1至任意输入的整数之间的所有整数的和-----------
	scanf("%d",&flag);	

	for(n=1;n<=flag;n++)
	{
		sum=sum+n;
	}
*/

	printf("sum=%f\n",sum);
	system("pause");
	return 0;
}
