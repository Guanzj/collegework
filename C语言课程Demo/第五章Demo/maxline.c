#include <stdio.h>
#include <string.h>
int main(){
    char line[100],max_line[100];
    int max_line_len=0;
    while(gets(line)!=NULL){
        if(strlen(line)>max_line_len){
            strcpy(max_line,line);
            max_line_len=strlen(line);
        }
    }
    printf("max line length is %d\n",max_line_len);
    printf("max line is: %s\n", max_line);
    return 0;
}
