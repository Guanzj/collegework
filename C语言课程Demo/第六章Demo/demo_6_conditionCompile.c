/*
	演示
*/

#include <stdio.h>

#define Let_Static  //编译选项

//#define Out_Debug  //编译选项


void inc(){

#ifdef Let_Static    //如果定义了Let_Static，则count定义成静态变量
	static int count=0; //定义静态局部变量
#else                //如果没有定义Let_Static，则count定义成自动（普通）变量
	int count=0;  //自动（普通）局部变量
#endif

	count++;

#ifdef  Out_Debug 
	printf("Variable count=%d\n",count);
#endif

}


int main(){
	int i;
	
	for(i=0;i<10;i++){
		inc();
	}

	return 0;
}