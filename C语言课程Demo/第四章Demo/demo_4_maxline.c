/*
	�ӱ�׼��������������ַ�����������һ�С�
	��ʾ�ַ�����������gets,puts,strcpy,strcmp
*/

#include <stdio.h>
#include <string.h>
int main(){


    char line[100];      //��¼��ǰ������ַ����������������� 
	char max_line[100];  //��¼����ַ���

    int max_line_len=0;	 //��¼��ǰ����ַ����ĳ���

	//ʹ��ѭ����������ַ������ж�
    while(gets(line)!=NULL){  // ����һ���ַ���

		if( strcmp(line,"***end**")==0 )  //����������־�У�������ѭ�������������µ��ַ���
		{
			break;
		}			

        if(strlen(line)>max_line_len){   //�Ƚϵ�ǰ���ַ������ǲ��Ǳ���ǰ����ַ�������
            strcpy(max_line,line);      //�����ǰ�ַ����������򽫵�ǰ�ַ�����¼��max_line��
            max_line_len=strlen(line);	//��ˢ����Ŀǰ����ַ�������
        }
    }


    printf("max line length is %d\n",max_line_len);
    printf("max line is: %s\n", max_line);
    return 0;
}
