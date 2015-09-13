/*
	演示指针数组的用法
*/

#include <stdio.h>

int main(){
	char names1[100][20]={"Li ming","Liu xiaodong","Zhang bin","Zhang kefeng","Qiao ting"};
	char *names2[100]={"Li ming","Liu xiaodong","Zhang bin","Zhang kefeng","Qiao ting"};



	int i=0;
	printf("-----------names1-----------\n");
	for(i=0;i<5;i++){
		printf("address of names1[%d][0] is %d\n",i,&names1[i][0]);  //二维字符数组是连续规整存储的
	}

	printf("-----------names2-----------\n");
	for(i=0;i<5;i++){
		printf("address of names2[%d][0] is %d\n",i,&names2[i][0]);  //指针数组中，每个元素指向字符串可以不等长
		//printf("address of names2[%d][0] is %d\n",i,names2[i] );   //等效于上一个语句
	}

	return 0;
}