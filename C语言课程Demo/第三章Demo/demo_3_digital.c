#include <stdio.h>
#include <cstdlib>

int main()
{
	int n=178963;
	int d;


	//scanf("%d",&n);

	while(n>0)
	{
		d=n%10;//�õ���λ���� 		
		printf("%d\n",d); //�����ǰ���ֵĸ�λ��

		n/=10;//����n�ĸ�λ���� 
	}
	system("pause");
	return 0;
}
