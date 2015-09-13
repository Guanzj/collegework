/*
	复合赋值运算符演示
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	int x=5;

	printf("x=%d\n",
		x+=5
		//x-=5
		//x*=5
		//x/=5
		//x%=5
		);

/*
	//在0-100摄氏度，每隔5度显示摄氏温度对应的华氏温度
	int c;
	float temperature;
	for(c=0; c<=100; c+=5)
	{
        temperature = c* 9.0/5+32;
        printf("c=%d ,temperature=%.1f\n", c, temperature);
	}
*/

/*
	//--------使用余数来控制
	int c;
	float temperature;
	for(c=0; c<=100; c++)
	{
		if(c%5==0)
		{
			temperature = c* 9.0/5+32;
			printf("c=%d ,temperature=%.1f\n", c, temperature);
		}
	}
*/


	system("pause");
	return 0;
}
