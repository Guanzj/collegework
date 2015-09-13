#include <stdio.h>
#include <stdlib.h>

int main(){
	int x=6;
	
	//-----判断6是否在[3,5)区间之外
	if(x<3 || x>=5 ) 
		printf ("use condition 1: %d is not in [3,5)\n", x);  //输出这个
	else
		printf ("use condition 1: %d is in [3,5)\n", x);

		
	system("pause");
	return 0;
}
