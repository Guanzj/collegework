/*
	��ʾ
*/

#include <stdio.h>

#define Let_Static  //����ѡ��

//#define Out_Debug  //����ѡ��


void inc(){

#ifdef Let_Static    //���������Let_Static����count����ɾ�̬����
	static int count=0; //���徲̬�ֲ�����
#else                //���û�ж���Let_Static����count������Զ�����ͨ������
	int count=0;  //�Զ�����ͨ���ֲ�����
#endif

	count++;

#ifdef  Out_Debug 
	printf("Variable count=%d\n",count);
#endif

}


int main(){
	int i;
	
	for(i=0;i<10;i++){
		inc();
	}

	return 0;
}