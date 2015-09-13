#include <stdio.h>


//用 \ 可以换行
#define  PI 3.1415\       
926

//注意换行后的空格
#define HELLO "hello \    
  world!\n"                   

//简单宏定义
#define A 3+5

//带参数的宏定义
#define MUL(X,Y) X*Y

//带参数的宏定义
#define max(a,b) (a)>(b)?(a):(b)


int main(){
	int a2=0;
	double s=PI*5*5;

	printf("%s",HELLO);

	printf("A=%d\n",A);

	printf("A*2=%d\n",A*2);  //展开后：A*2=3+5*2=13,  而不是 (3+5)*2=16

	printf("%d\n",MUL(5,3));  // =15
 
	printf("%d\n",MUL(5,3+2));  // 展开后：5*3+2=17，而不是（5）*（3+2）=25

	printf("%d\n",max(max(6,5),7));  //展开后：=（max(6,5)）>7 ? (max(6,5):(7))
									 //        = (6>5?6:5 )	>7 ? (6>5?6:5):(7)
									 //        =  6>7 ?  6:7
	                                 //        = 7    
	return 0;
}