/*
	��ʾ�����������÷�
*/


#include <stdio.h>

double area(const double r,double c);


//��������������ĳ����ܸı����������ֵ����������Ԥ�������޸�PI��ֵ�����µ�Bug
const  double PI=3.1415926;

int main(){


	int i=0;  		
	
	for(i=0;i<=30;i++){
			
		printf("%d ��=%f ����\n",i,i*1.0/180.0*PI);
	}

	printf("The area =%f\n",area(2,3,4));
	
	return 0;
}

//�������βΣ���ڲ���������ɳ�������Ԥ�������ж��βθı������Bug����
double area(const double r,double c) 
{
	//r=4;   //���벻��ͨ��
	c=5;
	return PI*r*r;
}