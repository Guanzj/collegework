/*
	��ʾ��ʽ���ķ�ʽ���ı��ļ���������
*/


#include <stdio.h>

int main(){
	FILE * fp=fopen("test.txt","r");  //���ı��ļ�test.txt
	int n;

	//�ļ��򿪴��󣬷���
	if(fp==NULL)     
	{
		printf("open file error\n");
		return 0;
	}

	//��ʽ���ķ�ʽ����ÿһ������
	while(fscanf(fp,"%d",&n)!=EOF)
	{
		printf("%d ",n);  //�������������Ļ
	}

	printf("\n");       

	//�ر��ļ�
	fclose(fp);
	return 0;
}