#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n,i,sum;

	//ɨ��1-10000֮�����������
	for(n=1;n<=10000;n++)
	{
		//��n������֮�� 
		for(sum=0,i=1;i<=n/2;i++)
		{
			if(n%i==0)
				sum+=i;
		}
		//�ж�n�ǲ������� 
		if(sum==n)
			printf("%d\n",n);

        //!!!!!!ע�⣬��������forѭ�����Ʊ�����n,i�������޹��໥����

	}
	system("pause");
	return 0;
}
