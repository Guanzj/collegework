#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int level=0;
		
	scanf("%d",&level);

	//根据输入的0-5之间的level值，来判断对应的成绩评价
	switch(level) {  //改成level+1演示表达式
	case 5:
		printf("excellent!!\n");
		break;            //注释掉演示没有break的情况		
	case 4:
		printf("good!!\n");
		break;
	case 3:
		printf("OK\n");
		break;
	case 2:
		printf("bad\n");
		break;
	case 1:
		printf("vary bad!\n");
		break;
	case 0:
		printf("why??????\n");
		break;
	default:
		printf("sorry,I don't know.\n");

	}

	/* 测试 char型也可以
	{

	char testA='b';
	switch(testA){
	case 'a':
		printf("A test");
		break;
	case 'b':
		printf("B test\n");
		break;
	default:
		break;
	}

	}
	*/
	

    system("pause");
    return 0;
}
