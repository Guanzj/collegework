/*
	演示指针作为函数参数的操作
*/
#include <stdio.h>

//
void swap( int *x, int *y ){

	int t;
	t = *x;   // *x实际上是对x指向的内存进行操作，也就main中的a的内存进行操作
	*x = *y;  // *y实际上是对y指向的内存进行操作，也就main中的a的内存进行操作
	*y = t;  
	
}

int main(){
	int a=5, b=3;


	/*
	//---------------野指针  取值和赋值都会出Bug
	int *p;
	//printf("%d", *p);
	*p=2;
	//---------------野指针
	*/

	/*
	//----------------空指针  取值和赋值都会出Bug
	int *p=NULL;		
	printf("%d", *p);
	*p=2;
	*/

	
	printf( "a= %d; b= %d\n", a, b );

	swap(&a, &b);  // 由于把a和b的地址传进了参数，可以认为把对a和b的操作权传了进去，所以a和b的值能够真正的交换
	printf( "a= %d; b=%d\n", a, b );

	return 0;
}
