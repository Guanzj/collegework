/*
	�ж�һ�����Ƿ�������
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i,n=11;


	 //------------------------------���д��
	for(i=2;i<n;i++){
		if(n%i==0){//�ж�i�ǲ���n������ 
			break; //i�����ӣ�˵�����������������˳�ѭ�� 
		}
	}	

	if(i==n) //i�Ѿ�����n�ˣ���û���ҵ����ӣ�˵��������
		printf("%d is prime.\n",n);
	else
		printf("%d is not prime.\n",n);

/*
	//--------����������д��
	{

	int primeFlag=1;   //�ø���־����ʾ�Ƿ�����������ʼֵ=1��Ϊ��������������淢�ֲ�����������=0��

	for(i=2;i<n;i++){
		if(n%i==0){//�ж�i�ǲ���n������ 
			primeFlag=0;   //�������ӣ���������
			break; //�˳�ѭ�� 
		}
	}

	if(primeFlag==1) //i�Ѿ�����n�ˣ���û���ҵ����ӣ�˵��������
		printf("%d is prime.\n",n);
	else
		printf("%d is not prime.\n",n);

	}
*/		
	system("pause");
	return 0;
}
