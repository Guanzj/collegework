/*
	������ʾ����ͨ������
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int a[10]={1,22,50,44,8,9,31,90,34,80};
    int target=50; 
    int found=0; //������־,=1ʱ��ʾ��������

    int i;
    for(i=0; i<10 && !found; i++){
        if( a[i]==target ) found=1;
    }

    if(found)
        printf("target found, pos=%d\n", i-1 );
    else
        printf("target not found\n");

	system("pause");
	return 0;
}