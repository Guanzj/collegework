/*
	�����������������Ҫ����x�洢��С������y�洢�ϴ������Ȼ�����
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	int x=5,y=3,tmp;

	scanf("%d %d",&x,&y);


	//���x>y,�򽻻�x��y��ֵ
	if(x>y){
		tmp=x;
		x=y;
		y=tmp;
	}
	printf("x=%d, y= %d\n",x,y);
	

	/*
	//----------���͵Ĵ���
	if(x>y)
	{
		x=y;
		y=x;
	}
	printf("x=%d, y= %d\n",x,y);
	*/	

	system("pause");
	return 0;
}