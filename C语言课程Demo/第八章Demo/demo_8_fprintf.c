/*
	��ʾ�Ը�ʽ���ķ�ʽ���ı��ļ���������
*/


#include <stdio.h>

int main(){
	FILE * fp=fopen("lgx_temp.txt","w");  //����ֻ���ı��ļ�test.txt

	FILE *reRead=NULL;  //���´򿪵��ļ�ָ��
	int n;
	int i;
	int j;

	//�ļ��򿪴��󣬷���
	if(fp==NULL)     
	{
		printf("open file error\n");
		return 0;
	}	

	for(i=0;i<3;i++)
	{
		for(j=0;j<10;j++)
		{
			n=i*j;
			fprintf(fp,"%d ",n);  //�Ը�ʽ���ķ�ʽ���ļ��ж�ȡ���ݣ�������������
		}

		fprintf(fp,"\n");
	}

	//�ر��ļ�
	fclose(fp);

	//���ղŽ������ı��ļ�test.txt���´�
	reRead=fopen("test_out.txt","r");  

	//�ļ��򿪴��󣬷���
	if(reRead==NULL)     
	{
		printf("open file error\n");
		return 0;
	}	

	//��ȡ���ݣ����������Ļ
	for(i=0;i<3;i++)
	{
		for(j=0;j<10;j++)
		{			
			fscanf(fp,"%d",&n); //��ʽ���ķ�ʽ���ļ��ж�ȡ����
			printf("%d ",n);  //�������Ļ
		}

		printf("\n");		
	}

	fclose(reRead);

	return 0;
}