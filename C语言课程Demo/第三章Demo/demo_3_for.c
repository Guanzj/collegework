/*
	forѭ����ʾ
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	
	int flag=0;
	
	double sum=0;	
	int n;


	//����1+2+3,��ʾ����
	for(n=1,sum=0;n<=3; n=n+1)
	{
		sum=sum+n;	
	}	

/*
	//---------------����1���������������֮������������ĺ�-----------
	scanf("%d",&flag);	

	for(n=1;n<=flag;n++)
	{
		sum=sum+n;
	}
*/

	printf("sum=%f\n",sum);
	system("pause");
	return 0;
}
