/*
	演示strlen的实现
*/


#include <stdio.h>
#include <string.h>

int strlen(const char *s );

int main(){
	char *p="C Language";
	char s[]="C Language";
	
	printf("length of p:%d\n",strlen(p) );
	printf("length of s:%d\n",strlen(s) );	
	
	return 0;
}


int strlen(const char *s ){ //统计字符串的长度
    int n = 0;
	
	while ( *s != '\0' ) 
	{
        ++s; ++n;
    }	

    return n;
}

/*
int strlen( char *s ){   //另一个函数实现版本，统计字符串长度
    char *p = s;
    while ( *p != '\0' ) 
        ++p;
    return p - s;
}
*/


