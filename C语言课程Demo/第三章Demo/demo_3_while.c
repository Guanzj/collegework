/*
	while�����ʾ
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	double sum=0;      //��¼����ֵ    1.sum����ʼ�������ʲô���⣿

	int flag=0;        //���Ʊ�־

	int n=1; //����ѭ���Ŀ��ƺͼ���    2.n����ʼ�������ʲô���⣿

	while(n<=100){    // ����ʹ�õ�����������ʾ     
		sum=sum+sin(1.0/n);     //�����ۼ�  3. ���д��1/n�����ʲô���⣿
		n=n+1;                  //��1       4. ���û�������������ʲô���⣿
	}	

/*
	flag=1;
	while(flag)         //ʹ�õ������ı�־������ѭ������
	{
		sum=sum+sin(1.0/n);     
		n++;

		if(n>100)
		{
			flag=0;
		}
	}
*/

/*
	n=1;
	while(1)      //ʹ�� n>100 �� break ������ѭ������
	{
		sum=sum+sin(1.0/n);     
		n++;

		if(n>100)
		{
			break;
		}
	}
*/

	printf("sum=%f\n",sum);
	system("pause");
	return 0;
}
