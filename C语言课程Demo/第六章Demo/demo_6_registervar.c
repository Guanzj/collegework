/*
	��ʾ�Ĵ����������÷�
*/


#include <stdio.h>


int main(){

	register int i;  //�Ĵ��������������ڴ��з���ģ����Ƿ��䵽��CPU�еļĴ����������ٶȺܿ죬ͬʱ������ȡַ��������&

	
	
	for(i=0;i<1000;i++){
		printf("register variable");
	}

	{
		//register int test;
		//scanf("%d",&test);  //�Ĵ�������������ȡ��ַ
	}

	return 0;
}