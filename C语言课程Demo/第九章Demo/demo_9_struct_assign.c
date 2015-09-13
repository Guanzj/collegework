#include <stdio.h>
#include <string.h>

typedef struct{
	int *x;
	int y;
}point_t;

int main(){
	int n=10,m=20; 
	point_t pt1={&n,10},pt2={&m,20};
	
	printf("pt1.x=%d\t",*pt1.x);
	printf("pt1.y=%d\n",pt1.y);
	
	printf("pt2.x=%d\t",*pt2.x);
	printf("pt2.y=%d\n",pt2.y);

	pt2=pt1;  // 整体赋值，等效于：pt2.x=pt1.x; pt2.y=pt2.y;
	
	printf("=========after: pt2=pt1 ==\n");

	printf("pt1.x=%d\t",*pt1.x);
	printf("pt1.y=%d\n",pt1.y);
	
	printf("pt2.x=%d\t",*pt2.x);
	printf("pt2.y=%d\n",pt2.y);


	*pt1.x=30;   //因为pt2.x和pt1.x指向同一个地址，所以*pt2.x的值也变成了30
	pt1.y=30;

	printf("=========final==========\n");

	printf("pt1.x=%d\t",*pt1.x);
	printf("pt1.y=%d\n",pt1.y);
	
	printf("pt2.x=%d\t",*pt2.x);
	printf("pt2.y=%d\n",pt2.y);

	return 0;
}