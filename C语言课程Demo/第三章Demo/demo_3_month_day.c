#include <stdio.h>
#include <stdlib.h>

int main()
{
	int year=2010,month=11,days;

	int is_leap=0; //判断是否是闰年

	//输入年
	printf("year=");
	scanf("%d",&year);

	//输入月
	printf("monthr=");
	scanf("%d",&month);

	//根据输入的年，判断是否是闰年
	is_leap= year%400==0 || year%4==0&&year%100!=0;

	//根据输入的month,来判断该月有多少天
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