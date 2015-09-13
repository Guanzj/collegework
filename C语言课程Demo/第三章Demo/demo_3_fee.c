/*
	阶梯电价计费，电价分三个档次，
	0～110度电，每度电0.5元；
	111～210度电，超出110部分每度电0.55元，
	超过210度电，超出210部分每度电0.70元，
	给出一个家庭一月用电量，请计算出应缴的电费。 
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int electricity=151;//电量

	//double price1=0.5,price2=0.55,price3=0.7;

	double price1=0.5;  //0～110度电价
	double price2=0.55; //111～210度电价
	double price3=0.7;	//超过210度电价

	double fee;

	scanf("%d",&electricity);
	
	//根据电量的值，来判断计算电费
	if(electricity<=110){         //0～110度电，每度电0.5元
		fee=electricity*price1;
	}
	else if(electricity>110 && electricity<=210){  //超过210度电，超出210部分每度电0.70元   
		fee=110*price1+(electricity-110)*price2;
	}
	else{	//超过210度电，超出210部分每度电0.70元	    
		fee=110*price1+(210-110)*price2+(electricity-210)*price3; 
	}

	//输出电费
	printf("electricity=%d, fee=%.2f\n",electricity, fee);

	system("pause");
	return 0;
}