/*
	从标准输入流读入多行字符串，输出最长的一行。
	演示字符串处理函数：gets,puts,strcpy,strcmp
*/

#include <stdio.h>
#include <string.h>
int main(){


    char line[100];      //记录当前输入的字符串，当作缓冲区用 
	char max_line[100];  //记录最长的字符串

    int max_line_len=0;	 //记录当前最长的字符串的长度

	//使用循环输入多行字符串并判断
    while(gets(line)!=NULL){  // 输入一行字符串

		if( strcmp(line,"***end**")==0 )  //遇到结束标志行，则跳出循环，不在输入新的字符串
		{
			break;
		}			

        if(strlen(line)>max_line_len){   //比较当前的字符串的是不是比以前的最长字符串还长
            strcpy(max_line,line);      //如果当前字符串更长，则将当前字符串记录到max_line中
            max_line_len=strlen(line);	//并刷新至目前的最长字符串长度
        }
    }


    printf("max line length is %d\n",max_line_len);
    printf("max line is: %s\n", max_line);
    return 0;
}
