#include <stdio.h>


//�� \ ���Ի���
#define  PI 3.1415\       
926

//ע�⻻�к�Ŀո�
#define HELLO "hello \    
  world!\n"                   

//�򵥺궨��
#define A 3+5

//�������ĺ궨��
#define MUL(X,Y) X*Y

//�������ĺ궨��
#define max(a,b) (a)>(b)?(a):(b)


int main(){
	int a2=0;
	double s=PI*5*5;

	printf("%s",HELLO);

	printf("A=%d\n",A);

	printf("A*2=%d\n",A*2);  //չ����A*2=3+5*2=13,  ������ (3+5)*2=16

	printf("%d\n",MUL(5,3));  // =15
 
	printf("%d\n",MUL(5,3+2));  // չ����5*3+2=17�������ǣ�5��*��3+2��=25

	printf("%d\n",max(max(6,5),7));  //չ����=��max(6,5)��>7 ? (max(6,5):(7))
									 //        = (6>5?6:5 )	>7 ? (6>5?6:5):(7)
									 //        =  6>7 ?  6:7
	                                 //        = 7    
	return 0;
}