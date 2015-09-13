/*
	演示常数变量的用法
*/


#include <stdio.h>

double area(const double r,double c);


//常数变量，后面的程序不能改变这个变量的值，这样可以预防由于修改PI的值而导致的Bug
const  double PI=3.1415926;

int main(){


	int i=0;  		
	
	for(i=0;i<=30;i++){
			
		printf("%d 度=%f 弧度\n",i,i*1.0/180.0*PI);
	}

	printf("The area =%f\n",area(2,3,4));
	
	return 0;
}

//函数的形参（入口参数）定义成常变量，预防函数中对形参改变而导致Bug出现
double area(const double r,double c) 
{
	//r=4;   //编译不能通过
	c=5;
	return PI*r*r;
}