#include <stdio.h>
#include <string.h>

typedef struct{
	char id[10];
	char name[20];
	double score;
}student_t;

int main(){
	
	student_t st={"03101001","li ming",90};	 //ֱ�ӳ�ʼ��	
	//student_t st={"03101001"/*,"li ming",90*/};	 //��ȱʡֵ��ֱ�ӳ�ʼ��	


	//student_t st;		
	//һ������һ�������ĳ�ʼ��
	strcpy(st.id,"03101001");   //��ʼ��id
	strcpy(st.name,"li ming");	//��ʼ��name
	st.score=90;				//��ʼ��score	
	
	printf("st.id=%s\n",st.id);       
	printf("st.name=%s\n",st.name);
	printf("st.score=%f\n",st.score);


	//���Ľṹ������ķ���
	strcpy(st.name,"liu ming");	//��ʼ��name
	st.score=95;				

	printf("==========After change:============\n");
	printf("st.id=%s\n",st.id);       
	printf("st.name=%s\n",st.name);
	printf("st.score=%f\n",st.score);
	
	return 0;
}