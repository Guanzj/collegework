/*
	��ʾ���ı��������������������ݺ��ļ�
*/

#include <stdio.h>

int main(){

	FILE *fp; //�ļ�ָ��
	int n=123456;

	fp=fopen("out1.txt","w");  //��һ���ı��ļ�������д������
	fprintf(fp,"%d",n);    //���ļ���д������n
	fclose(fp);		//�ر��ļ�			

	fp=fopen("out2.txt","wb");  //��һ���������ļ�������д������
	fwrite(&n,sizeof(int),1,fp); //���ļ���д������n
	fclose(fp);     //�ر��ļ�

	return 0;
}
