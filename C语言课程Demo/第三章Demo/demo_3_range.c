#include <stdio.h>
#include <stdlib.h>

int main(){
	int x=6;
	
	//判断6是否在[3,5)区间
	if(x>=3 && x<5 ) //正确的表示
		printf ("use condition 1: %d is in [3,5)\n", x);
	else
		printf ("use condition 1: %d is not in [3,5)\n", x);  //输出这个
	
	//--演示错误的关系表达式
	if(3<=x<5)   //错误的表示
	{
		printf ("use condition 2: %d is in [3,5)\n", x);      //输出这个
	}
	else
	{
		printf ("use condition 2: %d is not in [3,5)\n", x);   
	}
		
	system("pause");
	return 0;
}
