/*===================================
	��ʾ��ϵ���ʽ
	2012-10-15 by lgx
===================================*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=0;     

	a=5>3;
	printf("when 5>3 a=%d\n",a);

	a=5<3;
	printf("when 5<3 a=%d\n",a);

	if(5>3)
	{
		printf("5>3 is true!\n");
	}

	if(5<3)
	{
		printf("5<3 is false!\n");
	}

	//============��ʾ��==����
	printf("==========��ʾ��==����=======\n");
	{
		char testA='a';
		if(testA=='a')   //һ��ע�⡰=���͡�==��������
		{
			printf("testA=='a'\n");
		}
		else
		{
			printf("testA!='a'\n");
		}
	}
	system("pause");


	{
		int testB=100;
		if(testB==100)
		{
			printf("testB=%d\n",testB);
		}


		printf("==========��ʾ�����ʹ�á�==����=======\n");
		if(testB=99)
		{
			printf("testB=%d\n",testB);
		}
	}
    
    system("pause");
    return 0;
}
