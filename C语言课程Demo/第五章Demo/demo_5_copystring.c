/*
	�����ַ������ַ�����
*/

#include <stdio.h>

#include <string.h>//�ַ���������

#include <memory.h>//�ڴ����������


int main() {
	
	char src[]="hello,world"; 
    int i = 0; 
    //char dst[100];     

	//----------dst��ʼ������������ʽ---------------
	//char dst[100]={'\0'};    //1
	//memset(dst,0,100);    //2

	//----------����������ʽ---------------



    while ( src[i] != '\0' ) { 
        dst[i] = src[i]; 
        ++i; 
    } 

    dst[i] = '\0'; //��ӽ�����־

	printf("%s\n",dst);



    return 0;
} 