/*
	��ʾstrlen��ʵ��
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


int strlen(const char *s ){ //ͳ���ַ����ĳ���
    int n = 0;
	
	while ( *s != '\0' ) 
	{
        ++s; ++n;
    }	

    return n;
}

/*
int strlen( char *s ){   //��һ������ʵ�ְ汾��ͳ���ַ�������
    char *p = s;
    while ( *p != '\0' ) 
        ++p;
    return p - s;
}
*/


