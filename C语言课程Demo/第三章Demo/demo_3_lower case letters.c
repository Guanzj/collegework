#include <stdio.h>
#include <stdlib.h>

int main(){
	
	char testChar=0;

	scanf("%c",&testChar);


	/*
	//-----判断输入的字符是否是小写  97
	if(testChar>='a' && testChar<='z')	
	{
		printf("%c is lower case letter\n", testChar);
	}
	else{
		printf("%c is not lower case letter\n", testChar);
	}
	*/
   

/*	
	//-----判断输入的字符是小写、大写、还是数字、还是什么都不是
	if(testChar>='a' && testChar<='z')
		printf("%c is lower case letter\n", testChar);
	else if(testChar>='A' && testChar<='Z')
		printf("%c is uppercase letter\n", testChar);
	else if(testChar>='0' && testChar<='9' )
		printf("%c is number letter\n", testChar);
	else
		printf("%c is out of my judgement!!!!\n", testChar);
*/	

	//-----使用内码，ASCII码判断     从内存层面看，字符（字符串）的大小比较，就是比较它们的内码的大小。
	if(testChar>=97 && testChar<=122)
		printf("%c is lower case letter\n", testChar);
	else if(testChar>=65 && testChar<=90)
		printf("%c is uppercase letter\n", testChar);
	else if(testChar>=48 && testChar<=57 )
		printf("%c is number letter\n", testChar);
	else
		printf("%c is out of my judgement!!!!\n", testChar);


	
		
	system("pause");
	return 0;
}
