#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int level=0;
		
	scanf("%d",&level);

	//���������0-5֮���levelֵ�����ж϶�Ӧ�ĳɼ�����
	switch(level) {  //�ĳ�level+1��ʾ���ʽ
	case 5:
		printf("excellent!!\n");
		break;            //ע�͵���ʾû��break�����		
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

	/* ���� char��Ҳ����
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
