/*
	演示命令行参数的使用
*/


#include <stdio.h>

int main(int argc, char *argv[]){
	char *s1,*s2;

	if(argc!=3){  //命令行中，如果程序名后面没有输入2个字符串，则提示出错。注意： argc记录的字符串数量中，包含程序名本身
		printf("need two string.\n");
		return 1;
	}

	s1=argv[1];
	s2=argv[2];
	while(*s1==*s2 && *s1 && *s2){  //检查两个字符串相同的前缀
		s1++;s2++;
	}

	*s1=0; //在最后一个相同的字符后面增加一个字符串结束符 '\0' (数值0)，则argv[1]指向的字符串即相同的前缀
	if(s1-argv[1])  //指针s1与指针argv[1]之间有距离，则说明有相同的前缀
	{
		printf("prefix is : %s\n",argv[1]);
	}
	else            //指针s1与指针argv[1]之间无距离，则说明没有相同的前缀
	{
		printf("no same prefix.\n");
	}

	return 0;
}