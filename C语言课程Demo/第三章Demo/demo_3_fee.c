/*
	���ݵ�ۼƷѣ���۷��������Σ�
	0��110�ȵ磬ÿ�ȵ�0.5Ԫ��
	111��210�ȵ磬����110����ÿ�ȵ�0.55Ԫ��
	����210�ȵ磬����210����ÿ�ȵ�0.70Ԫ��
	����һ����ͥһ���õ�����������Ӧ�ɵĵ�ѡ� 
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int electricity=151;//����

	//double price1=0.5,price2=0.55,price3=0.7;

	double price1=0.5;  //0��110�ȵ��
	double price2=0.55; //111��210�ȵ��
	double price3=0.7;	//����210�ȵ��

	double fee;

	scanf("%d",&electricity);
	
	//���ݵ�����ֵ�����жϼ�����
	if(electricity<=110){         //0��110�ȵ磬ÿ�ȵ�0.5Ԫ
		fee=electricity*price1;
	}
	else if(electricity>110 && electricity<=210){  //����210�ȵ磬����210����ÿ�ȵ�0.70Ԫ   
		fee=110*price1+(electricity-110)*price2;
	}
	else{	//����210�ȵ磬����210����ÿ�ȵ�0.70Ԫ	    
		fee=110*price1+(210-110)*price2+(electricity-210)*price3; 
	}

	//������
	printf("electricity=%d, fee=%.2f\n",electricity, fee);

	system("pause");
	return 0;
}