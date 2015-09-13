#include <stdio.h>
#include <cstdlib>

int main()
{
	int n=178963;
	int d;


	//scanf("%d",&n);

	while(n>0)
	{
		d=n%10;//得到个位数字 		
		printf("%d\n",d); //输出当前数字的个位数

		n/=10;//舍弃n的个位数字 
	}
	system("pause");
	return 0;
}
