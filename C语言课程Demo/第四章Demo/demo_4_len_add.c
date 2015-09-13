/*
	演示数组作为参数传入函数，求折线长度
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double poly_len( double x[], double y[], int n){   //数组形式 
//double poly_len( double *x, double y[], int n){  //可改成指针形式
    double len=0.0;
    int i;

	//求折线长度
    for(i=0;i<n-1;i++){
        len+=sqrt(pow(x[i]-x[i+1],2)+pow(y[i]-y[i+1],2));
	}

	/*
	//检验以数组名传递参数时，函数内对数组的操作是否对函数外的数组的值有影响
	
	for(i=0;i<n;i++)
	{
		x[i]=y[i]=0;
	}
	*/

	//返回折线长度
    return len;
}

int main(){
    double co_x[5]={0,2,3,4,6};
    double co_y[5]={1,2,2,1,1};    

    double len=poly_len( co_x, co_y, 5);
	//double len=poly_len( co_x, co_y, sizeof(co_x)/sizeof(co_x[0]));  //数组大小5，用sizeof来计算

    printf("polyline length = %f\n",len);
    return 0;
} 
