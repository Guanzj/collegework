#include <stdio.h>

int main(){
    int x=-1,y=2,z=0;

//��x>0������£����y>1,��z=1������z=2
//��x<=0������£�z=3

	if(x>0)     //���׶�������׻�����д��
	{
		if(y>1)
		{
			z=1;
		}
		else
		{
			z=2;
		}
	}
	else
	{
		z=3;
	}



/*
	if(x>0 && y>1)  //��һ��д��
	{
		z=1;
	}
	else if(x>0 && y<=1)
	{	
		z=2;
	}
	else
	{
		z=3;
	}
/*


/*
	if(x>0)     //���׶�������׻�����д��
	{
		if(y>1)
		{
			z=1;
		}
		else
		{
			z=2;
		}
	}
	else
	{
		z=3;
	}
*/

	printf("z=%d\n",z);
    
    system("pause");
    return 0;
}
