/*
	����λ��
*/

#include <stdio.h>

int main(){
	int a[100];//������������
	int n,i;

	//�������ݵ�����n
	scanf("%d",&n);

	//�ж������n�Ƿ����1-n֮�䣬Ԥ������Խ��
	if(n>100 || n<1)
	{
		printf("�������nֵ������\n");
		return 0;
	}

	//����n������
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);


	//����ѡ������
	for(i=0;i<n-1;i++){
		int j,k;
		for(k=i,j=i+1;j<n;j++){
			if(a[j]<a[k])
			{
				k=j;
			}
		}
		if(k!=i){
			int t;
			t=a[i];
			a[i]=a[k];
			a[k]=t;
		}
	}

	//�����λ��
	if(n%2) //��nΪ����ʱ,��λ�����±�Ϊ��a[n/2]
		printf("%d\n",a[n/2]);
	else    //��nΪż��ʱ,��λ�����±�Ϊ��(a[n/2]+a[n/2-1]) /2
		printf("%d\n",(a[n/2]+a[n/2-1])/2);


	return 0;
}