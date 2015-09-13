/*
	演示参数传递过程中，对形参的操作，对实参没有影响
*/

#include <stdio.h>

void swap( int a, int b ){
	int t;
	
	t = a;  a = b;  b = t;
}

int main(){
	int a=5, b=3;

	printf( "before swap:  a= %d; b= %d\n", a, b );
	swap(a, b);
	printf( "after swap:  a= %d; b=%d\n", a, b );

	return 0;
}
