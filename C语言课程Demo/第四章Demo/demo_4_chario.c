/*
	演示getch()和putch()的用法，以及小写转大写
*/
#include <stdio.h>
#include <stdlib.h>

int main(){

	while(1){
		char ch=getchar();  //从键盘缓冲区（标准输入流stdio）读取一个一个字符

		if(ch<'a'||ch>'z') //如果输入的字符不在小写字符范围，则跳出while
			break;

		ch='A'+(ch-'a');
		putchar(ch);	//向标准输出流输出转换后的大写字符
	}

	printf("\n");

	getch();  //在这里可以让程序暂停下来，等待键盘有任意敲键动作后继续后面程序的运行；
	printf("=========go on===============\n");
	
	return 0;
}