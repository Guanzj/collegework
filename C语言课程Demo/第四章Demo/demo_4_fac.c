/*
	�ݹ���ʾ����n�Ľ׳�
*/

#include <stdio.h>
#include <stdlib.h>

/*====================
��n�Ľ׳˵ĺ������ݹ���ʽ
====================*/
int fac(int n){

	if(n==0)   //0 �Ľ׳�Ϊ1������һ�������ֵ����������
		return 1;

	return n*fac(n-1); //��n!=0ʱ���ݹ����n!=n*(n-1)!
}



int main(){
	
	int n=0;

	scanf("%d",&n);

	printf("%d! =%d\n",n,fac(n));  //�����Ľ׳�
	system("pause");
	return 0;
}