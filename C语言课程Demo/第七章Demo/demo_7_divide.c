/*
	��ʾ��ָ����Ϊ��������������ͬʱ���س���������
*/

#include <stdio.h>

void division(int dividend, 
				   int divisor, 
				   int *quotientp, 
				   int *remainderp)
{
	*quotientp = dividend / divisor;	//ָ��ָ����ڴ��¼����
	*remainderp = dividend % divisor;	//ָ��ָ����ڴ��¼����
}
	
int main(){
	int quot, rem,*p=NULL;

	//p=&quot;

	printf("%d\n",*p); // ��һ��û��ָ������ַ���ڴ�����������Bug

	division(40, 3, &quot, &rem); //��quot��rem�ĵ�ַ����������ָ��

	printf("40 divided by 3 yields quotient %d ", quot);
	printf("and remainder %d\n", rem);

	return 0;
}


