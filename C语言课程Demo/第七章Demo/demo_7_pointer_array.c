/*
	��ʾָ��������÷�
*/

#include <stdio.h>

int main(){
	char names1[100][20]={"Li ming","Liu xiaodong","Zhang bin","Zhang kefeng","Qiao ting"};
	char *names2[100]={"Li ming","Liu xiaodong","Zhang bin","Zhang kefeng","Qiao ting"};



	int i=0;
	printf("-----------names1-----------\n");
	for(i=0;i<5;i++){
		printf("address of names1[%d][0] is %d\n",i,&names1[i][0]);  //��ά�ַ����������������洢��
	}

	printf("-----------names2-----------\n");
	for(i=0;i<5;i++){
		printf("address of names2[%d][0] is %d\n",i,&names2[i][0]);  //ָ�������У�ÿ��Ԫ��ָ���ַ������Բ��ȳ�
		//printf("address of names2[%d][0] is %d\n",i,names2[i] );   //��Ч����һ�����
	}

	return 0;
}