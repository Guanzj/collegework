#include <stdio.h>

int main(){
	char line[80]={0};
	
	int i;
	for(i=0;i<80;i++){
		scanf("%c",&line[i]);
		if(line[i]=='\n')break;
	}
	
	printf("%s\n",line);
	return 0;
}