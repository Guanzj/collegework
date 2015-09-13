#include <stdio.h>
#include <stdlib.h>

int main(){
	int freq[10]={0},i;
	char c;

	while((c=getchar())!=EOF){
		if(c>='0' && c<='9')
			freq[c-'0']++;
	}
	for(i=0;i<10;i++)
		printf("the number of %d is %d\n",i, freq[i]); 
	system("pause");
	return 0;
}