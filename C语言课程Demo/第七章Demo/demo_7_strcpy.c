/*
	��ʾstrcpy��ʵ��
*/


#include <stdio.h>
#include <string.h>

void my_strcpy (char *d, const char *s);  //��sָ����ַ�������d��

int main(){
	char s[100]="C Language";
	char d[100]={0};
	
	strcpy(d,s);
	printf("s:%s\n",s);	
	
	return 0;
}


void my_strcpy (char *d,  const char *s) //��sָ����ַ�������d��
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
void strcpy (char *d, const char *t) { //����ʵ�ְ汾2
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
void strcpy (char *d, const char *s) { //����ʵ�ְ汾3
	if(d==NULL || s==NULL)
	{
		return;
	}

    while ( *d++ = *s++ );
}
*/



