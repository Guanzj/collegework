/*
	任意给定两个整数，要求用x存储较小的数，y存储较大的数，然后输出
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int x=5,y=3,tmp;

	scanf("%d %d",&x,&y);


	//如果x>y,则交换x、y的值
	if(x>y){
		tmp=x;
		x=y;
		y=tmp;
	}
	printf("x=%d, y= %d\n",x,y);
	

	/*
	//----------典型的错误
	if(x>y)
	{
		x=y;
		y=x;
	}
	printf("x=%d, y= %d\n",x,y);
	*/	

	system("pause");
	return 0;
}