#include <stdio.h>

int main(){
    int x=-1,y=2,z=0;

//在x>0的情况下：如果y>1,则z=1；否则，z=2
//在x<=0的情况下：z=3

	if(x>0)     //最易读，最不容易混淆的写法
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
	if(x>0 && y>1)  //另一种写法
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
	if(x>0)     //最易读，最不容易混淆的写法
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
