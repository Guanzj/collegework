/*
	��ʾ������Ϊ�������뺯���������߳���
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double poly_len( double x[], double y[], int n){   //������ʽ 
//double poly_len( double *x, double y[], int n){  //�ɸĳ�ָ����ʽ
    double len=0.0;
    int i;

	//�����߳���
    for(i=0;i<n-1;i++){
        len+=sqrt(pow(x[i]-x[i+1],2)+pow(y[i]-y[i+1],2));
	}

	/*
	//���������������ݲ���ʱ�������ڶ�����Ĳ����Ƿ�Ժ�����������ֵ��Ӱ��
	
	for(i=0;i<n;i++)
	{
		x[i]=y[i]=0;
	}
	*/

	//�������߳���
    return len;
}

int main(){
    double co_x[5]={0,2,3,4,6};
    double co_y[5]={1,2,2,1,1};    

    double len=poly_len( co_x, co_y, 5);
	//double len=poly_len( co_x, co_y, sizeof(co_x)/sizeof(co_x[0]));  //�����С5����sizeof������

    printf("polyline length = %f\n",len);
    return 0;
} 
