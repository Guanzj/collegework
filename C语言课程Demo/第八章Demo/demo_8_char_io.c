/*
	�ı��ļ��Ĵ򿪡���д
*/

#include <stdio.h>

int main(){
	FILE *fpr=fopen("input2.txt","r");   //��һ���ı��ļ������ڶ�ȡ
	FILE *fpw=fopen("output2.txt","w");  //��һ���ı��ļ�������д
	char ch;

	//��������κδ��ļ�ʧ�ܵ������Ӧ����
	if(fpr==NULL||fpw==NULL){
		printf("open file error\n");
		return 0;
	}

	while((ch=fgetc(fpr))!=EOF){  //��input2.txt��һ���ֽ�һ���ֽڵĶ�����
		fputc(ch,fpw);    //��������ÿ���ֽڣ�д���ļ�output2.txt
	}

	//�������ļ��رգ�����ϵͳ���������е���������д���ļ������ر��ļ���
	fclose(fpr);
	fclose(fpw);
	return 0;
}
