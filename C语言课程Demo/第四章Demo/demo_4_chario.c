/*
	��ʾgetch()��putch()���÷����Լ�Сдת��д
*/
#include <stdio.h>
#include <stdlib.h>

int main(){

	while(1){
		char ch=getchar();  //�Ӽ��̻���������׼������stdio����ȡһ��һ���ַ�

		if(ch<'a'||ch>'z') //���������ַ�����Сд�ַ���Χ��������while
			break;

		ch='A'+(ch-'a');
		putchar(ch);	//���׼��������ת����Ĵ�д�ַ�
	}

	printf("\n");

	getch();  //����������ó�����ͣ�������ȴ������������ü���������������������У�
	printf("=========go on===============\n");
	
	return 0;
}