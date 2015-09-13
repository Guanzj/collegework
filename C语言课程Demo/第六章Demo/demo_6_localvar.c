#include <stdio.h>
#include <stdlib.h>

void func();

int main(){
	func();
	system("pause");
	return 0;
}

void func(){
	int i;
	for(i=0;i<10;i++){
		if(i%2){
			int k=i;
			printf("k=%d, address=%x\n",k,&k);
		}
		//printf("k=%d\n",k);
		//k++;
	}
	//i++;
}