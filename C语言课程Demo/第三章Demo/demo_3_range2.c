#include <stdio.h>
#include <stdlib.h>

int main(){
	int x=6;
	
	//-----�ж�6�Ƿ���[3,5)����֮��
	if(x<3 || x>=5 ) 
		printf ("use condition 1: %d is not in [3,5)\n", x);  //������
	else
		printf ("use condition 1: %d is in [3,5)\n", x);

		
	system("pause");
	return 0;
}
