/*
	��ʾ����ʽ�������
*/
#include <stdio.h>

int main(){
	char s[100];
	int i,n=0;
	FILE *fp;

	while((s[n]=getchar())!='\n'){  //�������ɸ��ַ���ֱ�����лس�
		s[n]=s[n]-'a'+'A';     //�������Сд��ĸת��Ϊ��д��ĸ
		putchar(s[n]);    //��ת����Ĵ�д��ĸ�����ƽ��
		n++;
	}

	printf("\n");
	fp=fopen("c:\\chars.txt","w");   //���ı��ļ���c:\\chars.txt

	//�����������д�뵽�ļ���
	for(i=0;i<n;i++){
		fprintf(fp,"%c",s[i]);
		fflush(fp);//ǿ��д��  �ڸ����֮ǰ��д�����ݣ���û������д������ļ�������д���˻�������
	}

	fputs("hello",fp);
	fclose(fp);     //�ر��ļ�ʱ����hello���������ӻ�����д������ļ���
	return 0;
}