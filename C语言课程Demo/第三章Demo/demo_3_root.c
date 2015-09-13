/*
	演示求根过程中 if 语句的使用
*/

#include <stdio.h>
#include <math.h>

int main(){
    double a=1,b=5,c=4;// two different real root
    //double a=2,b=5,c=4;//no real root
    //double a=1,b=4,c=4;// only one real root
    double condition;
    
	scanf("%lf %lf %lf",&a,&b,&c);
	//scanf("%f %f %f",&a,&b,&c);    //!!!Note: 输入格式不匹配，出现错误
	printf("a=%f b=%f c=%f\n",a,b,c);


	//计算判别式的值
    condition=pow(b,2)-4*a*c;

	//根据判别式的值，来判断不同的根的情况
    if(condition<0){
        printf("no real root\n");
    }
    else if(condition>0){
        printf("the two real root is %f and %f\n",
            (-b+sqrt(condition))/(2*a),
            (-b-sqrt(condition))/(2*a));
    }
    else{
        printf(" the only one real root is %f\n",
            -b/(2*a));
    }

	system("pause");
    return 0;
}
