/*
	输入学生的个数n，然后申请内存，输入并保存n个学生的成绩，最后求n个学生的平均分
	演示内存申请
*/


#include <stdio.h>
#include <stdlib.h>
#include <memory.h>



int main(){
	int *data=NULL; //指针，用于指向申请到的用于保存学生成绩的内存
	int n=0;

	int i; 
	int temp=0;	

	scanf("%d",&n); //先输入学生的个数

	//根据学生数，申请内存。注意，内存的大小的单位是字节
	data=(int *)malloc( sizeof(int)*n ); 	
	
	//！！！！一定要判断内存是否申请成功
	//如果内存申请失败，则结束程序。
	if(data==NULL)
	{
		printf("内存申请失败！！！");
		return 0;
	}

	//输出申请到的内存的首地址
	printf("alloc address is %x\n",data);


	//将申请到的内存清零
	for(i=0;i<n;i++)
	{
		data[i]=0; //第一种清零的方式：使用数组下表的方式寻址
		//*(data+i)=0;  //第二种清零方式：用指针地址计算的方式寻址,这里注意，指针是按照int类型进行跳的，每次跳1个int元素，也就是4个字节
	}

	//第三种清零方式：memset是按照字节操作的，所以要清零从data开始的内存的大小为sizeof(int)*n
	//memset(data,0, sizeof(int)*n);
	
	//输入n个学生的成绩
	for(i=0;i<n;i++){
		scanf("%d", &data[i]);		//第一种输入方式
		//scanf("%d", data+i);		//第二种输入方式,用指针地址计算的方式寻址,这里注意，指针是按照int类型进行跳的，每次跳1个int元素，也就是4个字节
	}	


	//将输入的n个成绩输出, 并统计学生的总成绩
	printf("\n============学生的成绩==============\n");
	for(i=0;i<n;i++)
	{
		printf("student[%d] =%d\n",i, data[i]);
		temp+=data[i];
	}

	printf("\n============平均成绩==============\n");
	temp=temp/n;
	printf(" 平均成绩=%d\n", temp);


	//!!!!!!!  对于申请到的内存，一定要释放掉！！！！！
	if(data!=NULL)  //释放前，习惯性的判断要释放的指针是否为空，这样可以预防释放空指针Bug。
	{
		free(data); //释放内存
		data=NULL;  //并且释放掉内存后，要将指针赋值为NULL，以免后面继续使用data时出现Bug		
	}

	return 0;
}