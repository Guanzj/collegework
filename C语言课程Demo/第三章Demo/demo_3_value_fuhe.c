/*
	���ϸ�ֵ�������ʾ
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	int x=5;

	printf("x=%d\n",
		x+=5
		//x-=5
		//x*=5
		//x/=5
		//x%=5
		);

/*
	//��0-100���϶ȣ�ÿ��5����ʾ�����¶ȶ�Ӧ�Ļ����¶�
	int c;
	float temperature;
	for(c=0; c<=100; c+=5)
	{
        temperature = c* 9.0/5+32;
        printf("c=%d ,temperature=%.1f\n", c, temperature);
	}
*/

/*
	//--------ʹ������������
	int c;
	float temperature;
	for(c=0; c<=100; c++)
	{
		if(c%5==0)
		{
			temperature = c* 9.0/5+32;
			printf("c=%d ,temperature=%.1f\n", c, temperature);
		}
	}
*/


	system("pause");
	return 0;
}
