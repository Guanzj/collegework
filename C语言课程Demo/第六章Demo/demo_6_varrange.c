#include <stdio.h>
#include <stdlib.h>

int a=10,b=10;   //全局变量

extern int c,d;  //外部全部变量


void func1(){
    printf("in func1: a=%d,b=%d\n",a,b);
	c=20;
	d=30;
}    

void func2(){
    int a=30,b=30;
    printf("in func2: a=%d,b=%d\n",a,b);
}

int c=1,d=1;    //全局变量，与前面的extern对应

void func3(int a,int b){
    printf("in fuc3:a=%d,b=%d\n",a,b);
}

#define OUT_Print

int main(){
    int a=20,b=20;   //局部变量
    printf("in main:a=%d,b=%d\n",a,b);


    func1();

    func2();

    func3(50,50);

    {
        int a=40,b=40; //复合结构中的局部变量
        printf("in compound:a=%d,b=%d\n",a,b);
    }
    system("pause");
}
