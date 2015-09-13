#include <stdio.h>
#include <string.h>

typedef struct{
	char id[10];
	char name[20];
	double score;
}student_t;

int main(){
	
	student_t st={"03101001","li ming",90};	 //直接初始化	
	//student_t st={"03101001"/*,"li ming",90*/};	 //带缺省值的直接初始化	


	//student_t st;		
	//一个分量一个分量的初始化
	strcpy(st.id,"03101001");   //初始化id
	strcpy(st.name,"li ming");	//初始化name
	st.score=90;				//初始化score	
	
	printf("st.id=%s\n",st.id);       
	printf("st.name=%s\n",st.name);
	printf("st.score=%f\n",st.score);


	//更改结构体变量的分量
	strcpy(st.name,"liu ming");	//初始化name
	st.score=95;				

	printf("==========After change:============\n");
	printf("st.id=%s\n",st.id);       
	printf("st.name=%s\n",st.name);
	printf("st.score=%f\n",st.score);
	
	return 0;
}