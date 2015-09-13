/*
	演示通用指针（void指针）的正确用法和错误用法
*/

#include <stdio.h>

int main(){
	int n=10, *p1;
	float f=2.5, *p2;
	void *gp1=&n, *gp2=&f;

	p1=(int *)gp1;
	p2=(float *)gp2;
	printf("%d %f\n",*p1, *p2); //正确


	p1=(int *)gp2;
	p2=(float *)gp1;
	printf("%d %f\n",*p1, *p2); //运行结果不正确

	return 0;
}