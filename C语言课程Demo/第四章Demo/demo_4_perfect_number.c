/*
	��ʾ�ú�������ʽ�ж�һ�������Ƿ�������
*/

#include <stdio.h>
#include <stdlib.h>

int isPerfectNumber(int n){ //����1������������0��������
    int i,sum;

    for(i=1,sum=0;i<=n/2;i++){
        if(n%i==0)
            sum+=i;
    }

    //return sum==n;  //������������򷵻�1�����򷵻�0

	//return sum==n? 1:0;  //��һ����ʽ

	if(sum==n)     //��һ����ʽ
		return 1;
	else
		return 0;
}

int main()
{
	int n;

	for(n=1;n<=10000;n++)
	{
		//���ú����ж�n�ǲ������� 
		if(isPerfectNumber(n))
			printf("%d\n",n);
	}
	system("pause");
	return 0;
}
