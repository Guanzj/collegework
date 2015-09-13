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

	//--------计算1至任意输入的整数之间的所有整数的和,-----------
	scanf("%d",&flag);	


	//---------用for(;;)计算，等同于while(1)
	n=1;
	for(;;)
	{

		sum=sum+n;
		n=n+1;

		if(n>flag)    //
		{
			break;
		}

	}


/*
	//-----------用for(n=1; ;n++)
	for(n=1; ;n++)
	{
		if(n>flag)   //一定注意先判断和后判断的区别，这里先判断，因为for已经执行了n++;
		{
			break;
		}

		sum=sum+n;		
	}
*/	

	printf("sum=%f\n",sum);
	system("pause");
	return 0;
}
