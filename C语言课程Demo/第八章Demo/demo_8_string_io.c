/*
	��ʾ��
	��1�����ı��ļ�
	��2�����ַ�������ʽ����һ���ļ����ж�ȡ�ַ�����������ȡ��������д�뵽��һ���ļ���
*/
#include <stdio.h>

int main(){
	FILE *fpr=fopen("input3.txt","r");  //ֻ����ʽ���ı��ļ�
	FILE *fpw=fopen("output3.txt","w"); //д�ķ�ʽ�����ı��ļ�
	char buf[100];      //������

	//������ļ������⣬�򷵻�
	if(fpr==NULL||fpw==NULL){
		printf("open file error\n");
		return 0;
	}

	//��Դ�ļ�ÿ�ζ�ȡ������100���ַ����ַ���
	while(fgets(buf,100,fpr)!=NULL){
		fputs(buf,fpw); //���ַ���д��Ŀ���ļ�
	}

	//flush���ݵ����̣����ر��ļ�
	fclose(fpr);
	fclose(fpw);

	return 0;
}