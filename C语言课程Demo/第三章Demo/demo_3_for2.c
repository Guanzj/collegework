/*
	forѭ����ʾ
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	
	int flag=0;
	
	double sum=0;	
	int n;

	//--------����1���������������֮������������ĺ�,-----------
	scanf("%d",&flag);	


	//---------��for(;;)���㣬��ͬ��while(1)
	n=1;
	for(;;)
	{

		sum=sum+n;
		n=n+1;

		if(n>flag)    //
		{
			break;
		}

	}


/*
	//-----------��for(n=1; ;n++)
	for(n=1; ;n++)
	{
		if(n>flag)   //һ��ע�����жϺͺ��жϵ������������жϣ���Ϊfor�Ѿ�ִ����n++;
		{
			break;
		}

		sum=sum+n;		
	}
*/	

	printf("sum=%f\n",sum);
	system("pause");
	return 0;
}
