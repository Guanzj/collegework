#include <stdio.h>
#include <stdlib.h>

int main()
{
	int year=2010,month=11,days;

	int is_leap=0; //�ж��Ƿ�������

	//������
	printf("year=");
	scanf("%d",&year);

	//������
	printf("monthr=");
	scanf("%d",&month);

	//����������꣬�ж��Ƿ�������
	is_leap= year%400==0 || year%4==0&&year%100!=0;

	//���������month,���жϸ����ж�����
	switch(month){
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		days=31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		days=30;
		break;
	case 2:
		days=is_leap?29:28;
		break;
	}

	printf("%d-%d has %d days\n",year,month,days);
	system("pause");
}