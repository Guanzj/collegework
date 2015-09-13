#include <stdio.h>
#include <string.h>


typedef struct{
	char id[10];
	char name[20];
	double score;
}student_t;


int main(){
	
	student_t st;
	strcpy(st.id,"03101001");
	strcpy(st.name,"li ming");
	st.score=90;	

	printf("sizeof(st)=%d\n",sizeof(st));
	printf("address of st.id=%d\n",&st.id);
	printf("address of st.name=%d\n",&st.name);    //name的地址与前面是连续的，因为char型的长度为1字节，按字节对齐就行
	printf("address of st.score=%d\n",&st.score);  //score的地址是跟前面不连续的，因为起始地址必须补齐为double(8字节)长度的整数倍来对齐

	return 0;
}