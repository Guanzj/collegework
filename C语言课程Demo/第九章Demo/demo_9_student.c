#include <stdio.h>

typedef struct{
	char id[10];
	char name[20];
	double score;
}student_t;



//���ļ�filename���루���룩ѧ����Ϣ
//��������ֵ��=0�����ļ����� =n�������ѧ��������
int input(student_t sts[],char *filename){
	int n=0;
	FILE *fp=fopen(filename,"r");   //���ı����ķ�ʽ��ָ�����ļ�
	
	if(fp==NULL){
		printf("open input file fail\n");
		return 0;  //�ļ��򿪴��󣬷���0
	}
	
	while(fscanf(fp,"%s %s %lf",sts[n].id, sts[n].name,&sts[n].score)==3){
		n++;
	}
	fclose(fp);

	return n;	//���ض����ѧ����
}

//���ɼ�����������
void sort(student_t sts[],int n){
	int i,j,k;

	//ѡ������
	for(i=0;i<n-1;i++){
		for(k=i,j=i;j<n;j++){
			if(sts[j].score<sts[k].score)  //�������������򣺵ͷ���ǰ���߷��ں�
			{
				k=j;
			}
		}
		if(k!=i){
			student_t st=sts[i];
			sts[i]=sts[k];
			sts[k]=st;
		}
	}
}

//��ѧ����Ϣд���ļ�
//��������ֵ��=0�����ļ�����=1��д���ļ��ɹ�
int output(student_t sts[],int n,char *filename){
	int i;
	FILE *fp=fopen(filename,"w"); //���ı�����ʽ�����ļ�
	if(fp==NULL){
		printf("open input file fail\n");
		return 0;
	}
	for(i=0;i<n;i++){
		//-10�����룬��ȹ̶�Ϊ10�ַ���-20�����룬��ȹ̶�Ϊ20�ַ���
		fprintf(fp,"%-10s %-20s %.1f\n",sts[i].id, sts[i].name,sts[i].score);  
	}
	
	fclose(fp);
	return 1;
}

#define  MAX_STUDENT 100  //�궨������Ĵ�С

int main(){
	student_t students[MAX_STUDENT];
	int count=0;

	//���ļ�score.txt�ж�������ѧ������Ϣ
	count=input(students,"score.txt");

	//��ѧ�����ɼ�����
	sort(students,count);

	//�������ѧ����Ϣ������ļ�score1.txt��
	output(students,count,"score1.txt");
	
	return 0;
	printf
}