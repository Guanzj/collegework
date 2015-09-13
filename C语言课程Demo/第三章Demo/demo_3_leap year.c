#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int year=0;

	scanf("%d",&year);
	
	//-----判断输入的年份是否是闰年
	if( year%400==0 || 
		(year%4==0 && year%100!=0) 
		) 
		printf ("%d年是闰年\n", year);  //输出这个
	else
		printf ("%d年不是闰年\n", year);  //输出这个

		
	system("pause");
	return 0;
}
