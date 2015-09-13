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

	pt2=pt1;  // ���帳ֵ����Ч�ڣ�pt2.x=pt1.x; pt2.y=pt2.y;
	
	printf("=========after: pt2=pt1 ==\n");

	printf("pt1.x=%d\t",*pt1.x);
	printf("pt1.y=%d\n",pt1.y);
	
	printf("pt2.x=%d\t",*pt2.x);
	printf("pt2.y=%d\n",pt2.y);


	*pt1.x=30;   //��Ϊpt2.x��pt1.xָ��ͬһ����ַ������*pt2.x��ֵҲ�����30
	pt1.y=30;

	printf("=========final==========\n");

	printf("pt1.x=%d\t",*pt1.x);
	printf("pt1.y=%d\n",pt1.y);
	
	printf("pt2.x=%d\t",*pt2.x);
	printf("pt2.y=%d\n",pt2.y);

	return 0;
}