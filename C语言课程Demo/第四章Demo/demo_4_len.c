/*
	演示数组元素作为实参传入函数，求折线长度
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//==================================================
// 功能：求两个点之间的长度
//第一个点（x1,y1）,第二个点（x2,y2）
//==================================================
double seg_len(double x1,double y1,double x2,double y2){
    return sqrt(  (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)  );
}

int main(){
    double x[5]={0,2,3,4,6};
    double y[5]={1,2,2,1,1};
    double polyline_len=0;

    int i;
    for(i=0;i<4;i++){ //注意循环4次，对应4条折线
        polyline_len+=seg_len(x[i], y[i], x[i+1], y[i+1]);
    }

    printf("polyline length = %f\n",polyline_len);
    return 0;
} 
