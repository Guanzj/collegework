#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int year=0;

	scanf("%d",&year);
	
	//-----�ж����������Ƿ�������
	if( year%400==0 || 
		(year%4==0 && year%100!=0) 
		) 
		printf ("%d��������\n", year);  //������
	else
		printf ("%d�겻������\n", year);  //������

		
	system("pause");
	return 0;
}
