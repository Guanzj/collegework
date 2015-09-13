/*
	输入字符，保存到字符数组中
*/

#include <stdio.h>

int main(){
    char line[80]={0}; //如果不初始化为0会导致什么结果？

    int i;
    for(i=0;i<80;i++){
        scanf("%c",&line[i]); //输入一个字符
        if(line[i]=='\n')break;  //输入字符是换行符时结束输入
    }


    printf("the string is :%s",line);  //输出字符串
    return 0;
}
