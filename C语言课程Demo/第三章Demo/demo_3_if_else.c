#include <stdio.h>

int main(){
    int x=0;
	int continueY=0;

	int flag=0;

	//��x>0�������,�����x>0��; ��һ�������x���������

	scanf("%d",&x);

	continueY=continueY+1;

	flag=1;

/*	
	if(x>=0)       //if(1.1)  if(flag)   ���һ�������Բ��Ӵ�����	
		printf("x=%d\n",x);
	
	
*/
/*
	continueY=continueY+2*3;


	if(x>=0)       //if(1.1)  if(flag)  ���һ�������Բ��Ӵ�����
	{
		printf("�����x>=0\n");		
	}
	else
	{
		printf("�����x<0\n");
	}

*/

	/*
	if(x>=0)		//����Ƕ��
	{		
		if(x>0)
		{
			printf("�����x>0\n");
		}
		else
		{
			printf("�����x=0\n");
		}
	}
	else
	{			
		printf("�����x<0\n");
	}
*/

	
	//==========��Чд��
	if(x>0)		
	{
		printf("�����x>0\n");
	}
	else if(x==0)
	{
		printf("�����x=0\n");	 
	}
	else
	{
		printf("�����x<0\n");
	}

    system("pause");
    return 0;
}
