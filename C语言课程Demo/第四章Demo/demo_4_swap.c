/*
	��ʾ�������ݹ����У����βεĲ�������ʵ��û��Ӱ��
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
