#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=4, b=6, c;
	int max,min;
	
	//��ʾ�������ʽ
	max = a > b ? a : b;	//max=6   
	min = a < b ? a : b;	//min=4

	printf("a=%d, b=%d, max=%d, min=%d\n", a ,b ,max , min );

	//��ʾ�����������ʽʱ�ļ��㲿��
    c=a>3 ? (a=a+1): (b=b+1);     
    printf("a=%d, b=%d, c=%d\n", a, b, c);  //a=5,b=6,c=5

    system("pause");
    return 0;
}
