/*
	��ʾ�ڴ�����
*/


#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


//��ȷ��input����

int *input( int n){ //����n��int���ڴ�ռ䣬������n�������и�ֵ
	int *p=NULL,i;

	p=(int *)malloc(sizeof(int) * n);  //����sizeof(int) * n���ֽ�

	//�������ɹ�
	if(p!=NULL){
		for(i=0;i<n;i++){
			scanf("%d",p+i);  //����n��������ֵ���ڴ�
		}
	}

	return p; //ע�ⷵ�ص��п�����NULL
}

//�����input����
/*
int *input(int n){
	int a[100]={0},i;
	
	for(i=0;i<n;i++){
		scanf("%d",a+i);
	}
	
	return a;	//a�Ǿֲ����������������꣬a��ӵ�е��ڴ���ͷŵ��ˣ�
				//���Բ�����Ϊ����ֵ���ظ�һ��ָ�������a���ڴ���в���,���򣬳����������ص��ڴ����Bug
}
*/

int main(){
	int *data,a[10];
	int n,i;

	scanf("%d",&n);
	data=input(n);
	printf("alloc address is %x\n",data);

	//ֻ���ж������ڴ�ɹ�����ܶ����뵽���ڴ���в���
	if(data!=NULL){
		memset(a,0,sizeof(int)*10);		//������a�������ڴ渳ֵΪ0
		memcpy(a,data,n*sizeof(int));   //����ԭ�ͣ� memcpy( void *dest, const void *src, size_t count )
										//��src��count���ֽ����ݿ�����dest

		//���n������
		for(i=0;i<10;i++){
			printf("a[%d]=%d\n",i,a[i]);
		}

		//!!!!!!!  �������뵽���ڴ棬һ��Ҫ�ͷŵ�����������
		free(data); //�ͷ��ڴ�
		data=NULL;  //�����ͷŵ��ڴ��Ҫ��ָ�븳ֵΪNULL������������ʹ��dataʱ����Bug
		
		/*  //��γ��������ͷź���ڴ���ʳ���
		printf("after free address is %x\n",data);
		for(i=0;i<n;i++){
			printf("data[%d]=%d\n",i,data[i]);
		}
		*/		
	}


	return 0;
}