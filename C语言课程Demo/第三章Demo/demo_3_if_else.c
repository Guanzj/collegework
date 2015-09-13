#include <stdio.h>

int main(){
    int x=0;
	int continueY=0;

	int flag=0;

	//在x>0的情况下,输出“x>0”; 进一步，输出x的正负情况

	scanf("%d",&x);

	continueY=continueY+1;

	flag=1;

/*	
	if(x>=0)       //if(1.1)  if(flag)   后跟一条语句可以不加大括号	
		printf("x=%d\n",x);
	
	
*/
/*
	continueY=continueY+2*3;


	if(x>=0)       //if(1.1)  if(flag)  后跟一条语句可以不加大括号
	{
		printf("输入的x>=0\n");		
	}
	else
	{
		printf("输入的x<0\n");
	}

*/

	/*
	if(x>=0)		//可以嵌套
	{		
		if(x>0)
		{
			printf("输入的x>0\n");
		}
		else
		{
			printf("输入的x=0\n");
		}
	}
	else
	{			
		printf("输入的x<0\n");
	}
*/

	
	//==========等效写法
	if(x>0)		
	{
		printf("输入的x>0\n");
	}
	else if(x==0)
	{
		printf("输入的x=0\n");	 
	}
	else
	{
		printf("输入的x<0\n");
	}

    system("pause");
    return 0;
}
