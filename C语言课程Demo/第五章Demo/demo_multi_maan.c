/*
	��һ������ʽ������
*/

#include <stdio.h>
#include <stdlib.h>

int min_index( int a[], int n ){ //��������Сֵ��������Сֵ��Ӧ��λ��
    int i ;
	int index=0; //�����һ��Ԫ������Сֵ

    for(i=1;i<n;i++)
	{
        if(a[i]<a[index])
		{
			index=i; //����и�С��Ԫ�������index
		}
	}

	return index;  //��������a[n]�е���Сֵ���±�
}

int main(){
    int a[4][3]={{11,13,121},{407,72,88},{23,58,1},{134,30,62} };
    int row,count=0,col,i;

	
	//�ҳ�ÿ���е���Сֵ�����ж����Ƿ���ͬ���е����ֵ�����㣩
	for(row=0;row<4;row++)
	{
		int minInRow=0; //��¼һ���е���Сֵ�����±�
		int maxInCol=0;//��¼һ�������ֵ

		//-------�ҵ�ǰ���е���С��ֵ�����±���minInRow��¼
		for(i=0;i<3;i++)
		{
			if(a[row][i] < a[row][minInRow])
			{
				minInRow=i;  //��¼һ���е���Сֵ����
			}
		}

		//���е��ˣ�a[row][minInRow]Ϊ��ǰ�У�row�У��е���Сֵ,������ΪminInRow

		//--------���ҵ��ĵ�ǰ���е���Сֵ���ж����Ƿ������������е����ֵ
		//maxInCol=minInRow;//��¼һ�������ֵ
		maxInCol=row;//��¼һ�������ֵ
		//�ж�a[row][minInRow]���������У�minInRow�У����Ƿ������ֵ
		for(i=0;i<4;i++)
		{
			if( a[i][minInRow] > a[row][minInRow])
			{
				maxInCol=i; //��¼һ�������ֵ
			}
		}

		//��������е����ֵ��a[row][minInRow]����a[row][minInRow]������
		if(maxInCol==row)
		{
			printf("row=%d,col=%d,value=%d\n",row, minInRow,a[row][minInRow]); //���
            count++; //�����������
		}	
	}

    if(count==0)
	{
		printf("no\n"); //û������
	}

	/*
	
    for(row=0;row<4;row++){
        col=min_index( a[row], 3); //�ҵ�һ����Сֵ���ڵ���

        for(i=0;i<4 && a[i][col]<=a[row][col];i++); //�������Ƿ��и���Ԫ��,ע���ʱ��a[row][col]�ǵ�ǰ��(row��)�е���Сֵ

        if( i==4 ){ //û�и����Ԫ�أ�˵����a[row][col]��col���е����ֵ��Ҳ����һ������
            printf("row=%d,col=%d,value=%d\n",row, col,a[row][col]);
            count++; //�����������
        }
    }

    if(count==0)
	{
		printf("no\n"); //û������
	}
	*/
	

	system("pause");
    return 0;
}
