/*
	ѡ������
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
	float score[100],t;
	int i,j,k,n,count=0;

	//�������ݵĸ���
	scanf("%d",&n);//����

	//�������������n������n���ɼ�
	for(i=0;i<n;i++){
		scanf("%f",&score[i]);//��������ɼ�
		if(score[i]<60)
		{
			count++;
		}
	}

	//����ѡ������
	for(i=0;i<n-1;i++){
		for(k=i+1,j=i;k<n;k++) //��n-i��Ԫ���е���Сֵ
		{
			if(score[k]<score[j])
			{
				j=k;
			}
		}

		if(j!=i){ //�����Сֵ���ǵ�i��Ԫ����score[i]��score[j]����
			t=score[i];
			score[i]=score[j];
			score[j]=t;
		}
	}

	//������
	printf("%d students <60\n%d students >=60\n",count,n-count);
	for(i=0;i<n;i++){
		printf("%f\n",score[i]);
	}
	
	system("pause");
	return 0;
}