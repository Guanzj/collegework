/*
	�����ַ������浽�ַ�������
*/

#include <stdio.h>

int main(){
    char line[80]={0}; //�������ʼ��Ϊ0�ᵼ��ʲô�����

    int i;
    for(i=0;i<80;i++){
        scanf("%c",&line[i]); //����һ���ַ�
        if(line[i]=='\n')break;  //�����ַ��ǻ��з�ʱ��������
    }


    printf("the string is :%s",line);  //����ַ���
    return 0;
}
