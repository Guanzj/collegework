/*
	演示枚举的使用方法
*/

#include <stdio.h>

enum WEEK_DAY{SUN,MON,TUE,WED,THU,FRI,SAT}; //默认从0开始（增1）赋值：0,1,2,3,4,5,6
enum WEEK_DAY{SUN=1,MON,TUE,WED,THU,FRI,SAT}; //从1开始（增1）赋值：1,2,3,4,5,6,7
//enum WEEK_DAY{SUN=1,MON,TUE,WED=5,THU,FRI,SAT}; //赋值：1,2,3, 5,6,7,8



int main(){
	
	int weekday=6;  //可以直接赋值个整数

	//int weekday=SAT;  //最正规的用法。

	printf("SUN=%d,MON=%d,TUE=%d,WED=%d,THU=%d,FRI=%d,SAT=%d\n",SUN,MON,TUE,WED,THU,FRI,SAT);

	switch(weekday){
	case SUN:
		printf("today is Sunday.\n");
        break;
	case MON:
		printf("today is Monnday.\n");
        break;
	case TUE:
		printf("today is Tuesday.\n");
		break;
	case WED:
		printf("today is Wednesday.\n");
		break;
	case THU:
		printf("today is Thursday.\n");
		break;
	case FRI:
		printf("today is Friday.\n");
		break;
	case SAT:
		printf("today is Saturday.\n");
		break;
	}

	return 0;

}
