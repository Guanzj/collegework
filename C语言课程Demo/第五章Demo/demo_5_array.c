/*
	����Ķ��塢ʹ��
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int i;

	//��������
	int a[5];
	int tempArray[10], score[58];

	//����Ķ���
	//int n=4;
	//int b[n];


	//ʹ������Ԫ��
	a[4]=0;

	//��ѭ����ʹ������Ԫ��
	for(i=0;i<5;i++){
		score[i]=i*2;
		printf("score[%d]=%d\n",i,score[i]);
	}


    //��ѭ����ʹ������Ԫ��
	for(i=0;i<4;i++){
		a [i] = i;		//��i+1��Ԫ�ظ�ֵΪi
		a[4] += a[i] ;  //��5��Ԫ�أ��±�Ϊ4����¼ǰ������Ԫ�صĺ�
		printf("a[%d]=%d\n",i,a[i]);
	}

	printf("a[%d]=%d\n",i,a[i]);
	printf("\n");


	//��������׵�ַ�����ֵ�Ч����
	printf("the address of array is %x\n",a);		//ֱ��ʹ��������
	printf("the address of array is %x\n",&a);		//ȡ�������ĵ�ַ
	printf("the address of array is %x\n",&a[0]);	//ȡ��һ��Ԫ�صĵ�ַ
	printf("\n");


	//����ÿ��Ԫ�صĵ�ַ���׵�ַ�Ĺ�ϵ
	for(i=0;i<5;i++){
		printf("the address of a[%d] is %x\n",i,&a[i]); //ȡiԪ�صĵ�ַ
	}
	return 0;
}