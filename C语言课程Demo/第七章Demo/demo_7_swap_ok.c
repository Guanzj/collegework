/*
	��ʾ�ڳ�����ʹ��ָ��ʱ��Ҫ�ж�ָ���Ƿ�Ϊ�գ��������Bug
*/
#include <stdio.h>

//---------------------------
//  swap��������ֵ��=0���д���=1�������ɹ�
//---------------------------
int swap( int *x, int *y)
{

	int t;

	//Ҫ�ȶԺ���������  ָ����� ���п�ָ���飬����ǿ�ָ�룬�򷵻ش����־
	if(x==NULL || y==NULL)
	{
		//printf("Error:: Pointer is NULL !\n");  //Ҳ�������������Ϣ
		return 0;  //x��y��ֻҪ��һ��Ϊ��ָ�룬�ͷ��ش����־
	}
	
	t = *x;   // *xʵ�����Ƕ�xָ����ڴ���в�����Ҳ��main�е�a���ڴ���в���
	*x = *y;  // *yʵ�����Ƕ�yָ����ڴ���в�����Ҳ��main�е�a���ڴ���в���
	*y = t;  

	return 1;   //���ݽ����ɹ�	
}

int main(){
	int a=5;
	int b=3;

	//����ָ�룬Ӧ���ȳ�ʼ��Ϊ��ָ��
	int *aPointer=NULL;
	int *bPointer=NULL;

	aPointer=&a;   //aPointerָ�����a
	//bPointer=&b;   //bPointerָ�����b
	
	printf( "a= %d; b= %d\n", a, b );

	//���swap��������ֵΪ1��˵�������ɹ�
	if( swap(aPointer, bPointer) == 1 )   
	{
		printf( "a= %d; b=%d\n", a, b );
	}
	else //���swap��������ֵΪ��1��˵�������ڲ�����������
	{
		printf("Error!\n");
	}

	return 0;
}
