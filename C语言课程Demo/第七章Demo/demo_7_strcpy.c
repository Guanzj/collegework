/*
	演示strcpy的实现
*/


#include <stdio.h>
#include <string.h>

void my_strcpy (char *d, const char *s);  //将s指向的字符拷贝到d中

int main(){
	char s[100]="C Language";
	char d[100]={0};
	
	strcpy(d,s);
	printf("s:%s\n",s);	
	
	return 0;
}


void my_strcpy (char *d,  const char *s) //将s指向的字符拷贝到d中
{  

	if(d==NULL || s==NULL)
	{
		return;
	}

    while ( (*d = *s) != '\0' ) {
        d++; s++;
    }
}


/*
void strcpy (char *d, const char *t) { //函数实现版本2
	if(d==NULL || s==NULL)
	{
		return;
	}

    while ( *d = *t ) {
        d++; t++;
    }
}
*/

/*
void strcpy (char *d, const char *s) { //函数实现版本3
	if(d==NULL || s==NULL)
	{
		return;
	}

    while ( *d++ = *s++ );
}
*/



