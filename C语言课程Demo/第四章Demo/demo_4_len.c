/*
	��ʾ����Ԫ����Ϊʵ�δ��뺯���������߳���
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//==================================================
// ���ܣ���������֮��ĳ���
//��һ���㣨x1,y1��,�ڶ����㣨x2,y2��
//==================================================
double seg_len(double x1,double y1,double x2,double y2){
    return sqrt(  (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)  );
}

int main(){
    double x[5]={0,2,3,4,6};
    double y[5]={1,2,2,1,1};
    double polyline_len=0;

    int i;
    for(i=0;i<4;i++){ //ע��ѭ��4�Σ���Ӧ4������
        polyline_len+=seg_len(x[i], y[i], x[i+1], y[i+1]);
    }

    printf("polyline length = %f\n",polyline_len);
    return 0;
} 
