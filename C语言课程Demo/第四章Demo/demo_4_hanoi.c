/*
	��ŵ��������ʾ
*/

#include <stdio.h>
#include <stdlib.h>

int move_count=0;//ͳ���ƶ�����

//�ƶ�һ��Բ�̵ĺ�����
//���ô˺���ʱfrom������ֻ��һ��Բ�̣�Ŀ������Ϊ�գ�����ֱ���ƶ�

void move_plate(int plate,	//Բ�̱��
				char from,	//Դ������
				char to)	//Ŀ������
{
	printf("step %d: move plate %d from %c to %c\n",move_count+1,plate, from, to);
	move_count++;


}

//�ƶ���ŵ���ĵݹ麯��
void hanoi(int n,		//Բ�̸���
		   char from,	//��ʼ��������һ���ַ���ʾ
		   char tmp,	//��ת��������һ���ַ���ʾ
		   char to)		//Ŀ����������һ���ַ���ʾ
{
	if(n==1){//�ݹ��������
		move_plate(1,from, to);//ֻ��һ��Բ��ʱ����ֱ�Ӵ�from�ƶ���to
	}
	else{
		hanoi(n-1,from, to, tmp);//�Ƚ�����n-1��Բ�̴�from�����ƶ���tmp����
		move_plate(n, from, to);//Ȼ�󽫵�n��Բ�̴�from�����ƶ���to����
		hanoi(n-1,tmp, from, to);//���tmp�����ϵ�n-1��Բ�̴��ƶ���to����
	}
}
//������
int main(){

	int n=1;

	printf("please input the number��n=");
	scanf("%d",&n);  //���뺺ŵ�����̵ĸ���

	hanoi(n,'X','Y','Z'); //�ݹ����

	printf("move_count=%d\n",move_count); // ��ӡ�ܹ��ƶ��˼�����


	system("pause");
	return 0;
}