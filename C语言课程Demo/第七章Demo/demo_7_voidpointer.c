/*
	��ʾͨ��ָ�루voidָ�룩����ȷ�÷��ʹ����÷�
*/

#include <stdio.h>

int main(){
	int n=10, *p1;
	float f=2.5, *p2;
	void *gp1=&n, *gp2=&f;

	p1=(int *)gp1;
	p2=(float *)gp2;
	printf("%d %f\n",*p1, *p2); //��ȷ


	p1=(int *)gp2;
	p2=(float *)gp1;
	printf("%d %f\n",*p1, *p2); //���н������ȷ

	return 0;
}