#include <stdio.h>

typedef struct{
	char id[10];
	char name[20];
	double score;
}student_t;



//从文件filename输入（读入）学生信息
//函数返回值：=0，打开文件错误； =n，读入的学生的数量
int input(student_t sts[],char *filename){
	int n=0;
	FILE *fp=fopen(filename,"r");   //以文本读的方式打开指定的文件
	
	if(fp==NULL){
		printf("open input file fail\n");
		return 0;  //文件打开错误，返回0
	}
	
	while(fscanf(fp,"%s %s %lf",sts[n].id, sts[n].name,&sts[n].score)==3){
		n++;
	}
	fclose(fp);

	return n;	//返回读入的学生数
}

//按成绩升序生排序
void sort(student_t sts[],int n){
	int i,j,k;

	//选择排序
	for(i=0;i<n-1;i++){
		for(k=i,j=i;j<n;j++){
			if(sts[j].score<sts[k].score)  //这里是升序排序：低分在前，高分在后
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

//将学生信息写入文件
//函数返回值：=0，打开文件错误；=1，写入文件成功
int output(student_t sts[],int n,char *filename){
	int i;
	FILE *fp=fopen(filename,"w"); //以文本的形式创建文件
	if(fp==NULL){
		printf("open input file fail\n");
		return 0;
	}
	for(i=0;i<n;i++){
		//-10：左靠齐，宽度固定为10字符；-20：左靠齐，宽度固定为20字符；
		fprintf(fp,"%-10s %-20s %.1f\n",sts[i].id, sts[i].name,sts[i].score);  
	}
	
	fclose(fp);
	return 1;
}

#define  MAX_STUDENT 100  //宏定义数组的大小

int main(){
	student_t students[MAX_STUDENT];
	int count=0;

	//从文件score.txt中读入所有学生的信息
	count=input(students,"score.txt");

	//对学生按成绩排序
	sort(students,count);

	//将排序后学生信息输出到文件score1.txt中
	output(students,count,"score1.txt");
	
	return 0;
	printf
}