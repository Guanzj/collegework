/*
	拷贝字符串到字符数组
*/

#include <stdio.h>

#include <string.h>//字符串函数库

#include <memory.h>//内存操作函数库


int main() {
	
	char src[]="hello,world"; 
    int i = 0; 
    //char dst[100];     

	//----------dst初始化几种其它形式---------------
	//char dst[100]={'\0'};    //1
	//memset(dst,0,100);    //2

	//----------几种其他形式---------------



    while ( src[i] != '\0' ) { 
        dst[i] = src[i]; 
        ++i; 
    } 

    dst[i] = '\0'; //添加结束标志

	printf("%s\n",dst);



    return 0;
} 