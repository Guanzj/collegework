/*
	演示在程序中使用指针时，要判断指针是否为空，以免出现Bug
*/
#include <stdio.h>

//---------------------------
//  swap函数返回值：=0，有错误；=1，交换成功
//---------------------------
int swap( int *x, int *y)
{

	int t;

	//要先对函数参数的  指针参数 进行空指针检查，如果是空指针，则返回错误标志
	if(x==NULL || y==NULL)
	{
		//printf("Error:: Pointer is NULL !\n");  //也可以输出错误信息
		return 0;  //x和y，只要有一个为空指针，就返回错误标志
	}
	
	t = *x;   // *x实际上是对x指向的内存进行操作，也就main中的a的内存进行操作
	*x = *y;  // *y实际上是对y指向的内存进行操作，也就main中的a的内存进行操作
	*y = t;  

	return 1;   //数据交换成功	
}

int main(){
	int a=5;
	int b=3;

	//两个指针，应该先初始化为空指针
	int *aPointer=NULL;
	int *bPointer=NULL;

	aPointer=&a;   //aPointer指向变量a
	//bPointer=&b;   //bPointer指向变量b
	
	printf( "a= %d; b= %d\n", a, b );

	//如果swap函数返回值为1，说明交换成功
	if( swap(aPointer, bPointer) == 1 )   
	{
		printf( "a= %d; b=%d\n", a, b );
	}
	else //如果swap函数返回值为非1，说明函数内部出现了问题
	{
		printf("Error!\n");
	}

	return 0;
}
