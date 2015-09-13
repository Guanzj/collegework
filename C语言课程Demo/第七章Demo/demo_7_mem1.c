/*
	演示内存申请
*/


#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


//正确的input函数

int *input( int n){ //申请n个int的内存空间，并输入n个数进行赋值
	int *p=NULL,i;

	p=(int *)malloc(sizeof(int) * n);  //申请sizeof(int) * n个字节

	//如果申请成果
	if(p!=NULL){
		for(i=0;i<n;i++){
			scanf("%d",p+i);  //输入n个整数赋值给内存
		}
	}

	return p; //注意返回的有可能是NULL
}

//错误的input函数
/*
int *input(int n){
	int a[100]={0},i;
	
	for(i=0;i<n;i++){
		scanf("%d",a+i);
	}
	
	return a;	//a是局部变量，函数调用完，a所拥有的内存就释放掉了，
				//所以不能做为返回值返回给一个指针继续对a的内存进行操作,否则，程序会出现严重的内存操作Bug
}
*/

int main(){
	int *data,a[10];
	int n,i;

	scanf("%d",&n);
	data=input(n);
	printf("alloc address is %x\n",data);

	//只有判断申请内存成功后才能对申请到的内存进行操作
	if(data!=NULL){
		memset(a,0,sizeof(int)*10);		//将数组a的所有内存赋值为0
		memcpy(a,data,n*sizeof(int));   //函数原型： memcpy( void *dest, const void *src, size_t count )
										//从src将count个字节内容拷贝到dest

		//输出n个整数
		for(i=0;i<10;i++){
			printf("a[%d]=%d\n",i,a[i]);
		}

		//!!!!!!!  对于申请到的内存，一定要释放掉！！！！！
		free(data); //释放内存
		data=NULL;  //并且释放掉内存后，要将指针赋值为NULL，以免后面继续使用data时出现Bug
		
		/*  //这段程序会造成释放后的内存访问出错
		printf("after free address is %x\n",data);
		for(i=0;i<n;i++){
			printf("data[%d]=%d\n",i,data[i]);
		}
		*/		
	}


	return 0;
}