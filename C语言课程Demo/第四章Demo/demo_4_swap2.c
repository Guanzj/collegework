#include <stdio.h>

int a=5, b=3;//ȫ�ֱ���a,b

void swap( ){
	int t;
	
	t = a;  a = b;  b = t;
}

int main(){

	int x=0; //��������main��
	int y=0; //��������main��

	printf( "before swap:  a= %d; b= %d\n", a, b );
	swap();
	printf( "after swap:  a= %d; b=%d\n", a, b );

	return 0;
}

void swap1(int *x,int *y)
{
	int temp;

	temp=*x; 
	*x=*y;
	*y=temp;
}

int main1(){

	int x=3; //��������main��
	int y=5; //��������main��

	printf( "before swap:  x= %d; y= %d\n", x, y );
	swap1(&x,&y);
	printf( "after swap:  x= %d; x=%d\n", x, y );

	return 0;
}
