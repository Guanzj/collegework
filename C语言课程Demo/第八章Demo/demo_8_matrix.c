/*
	��ʾ���ļ��ж���������ݣ�����ת�þ���д����һ���ļ�
*/


#include <stdio.h>
#define MAX_ROW 10
#define MAX_COL 10

int main(){
	FILE *fp;
	int row,col,i,j;
	int a[MAX_ROW][MAX_COL];

	fp=fopen("a.txt","r");//��ԭʼ�����ļ�
	if(fp==NULL){
		printf("open input file fail\n");
		return 1;
	}

	//�ȴ��ļ��ж��������С���
	fscanf(fp,"%d %d",&row,&col);


	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			fscanf(fp,"%d",&a[i][j]); //��������ԭʼ����Ԫ��
		}
	}
	fclose(fp); //�ر��ļ�

	fp=fopen("at.txt","w"); //��ת�þ����ļ����������򴴽�
	if(fp==NULL){
		printf("open output file fail\n");
		return 1;
	}

	fprintf(fp,"%d %d\n",col,row);//���ת�þ�������ֵ

	for(i=0;i<col;i++){
		for(j=0;j<row;j++){
			fprintf(fp,"%d ",a[j][i]); //�������ת�þ���Ԫ��
		}
		fprintf(fp,"\n"); //���һ�к���
	}
	fclose(fp);
	return 0;
}