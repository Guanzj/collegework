#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m=32,n=48,i;
	int gcd=1;  //���Լ����ʼֵΪ1

	int min=m<n?m:n;  //��Сѭ���Ĵ���
    
	
    //-------------method 1�� ��С����ѭ��ɨ��
	for(i=2;i<=min;i++)
	{
		if(m%i==0 && n%i==0)//�ж�i�ǲ��ǹ�Լ����
			gcd=i;//gcd����Ϊ�����Լ�� 
	}


	/*	
	//--------------method 2���Ӵ�Сɨ��
	for(i=min;i>=2;i--)
	{
        if(m%i==0&&n%i==0)//�ж�i�ǲ��ǹ�Լ�� 
		{
       	    gcd=i;//i�������Լ�����˳�ѭ�� 
       	    break;  //ע�⣬���û��break, �����ʲô���
        }
    }
	*/

    
	printf("the gcd of %d and %d is %d\n",m,n,gcd);
	system("pause");
	return 0;
}
