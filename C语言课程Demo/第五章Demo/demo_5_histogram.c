#include <stdio.h>
#include <stdlib.h>

int main(){
	int img[256][256],a[256]={0};
	int m,n,k,i,j;
	
	
	scanf("%d %d %d",&m,&n,&k);    //����Ҷ�ͼ��Ĵ�С��ͼ��Ϊm*n,��Ӧ������Ϊimg[n][m]��,�Լ����صĻҶȼ���256��


	for(i=0;i<n;i++){   //i������ѭ��

		for(j=0;j<m;j++){//j������ѭ��
			scanf("%d",&img[i][j]);
			a[ img[i][j] ]++;
		}

	}

	//����Ҷ�ֱ��ͼ
	for(i=0;i<k;i++)
		printf("%d %d\n",i,a[i]);

	return 0;
}