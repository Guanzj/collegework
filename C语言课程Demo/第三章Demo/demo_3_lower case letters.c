#include <stdio.h>
#include <stdlib.h>

int main(){
	
	char testChar=0;

	scanf("%c",&testChar);


	/*
	//-----�ж�������ַ��Ƿ���Сд  97
	if(testChar>='a' && testChar<='z')	
	{
		printf("%c is lower case letter\n", testChar);
	}
	else{
		printf("%c is not lower case letter\n", testChar);
	}
	*/
   

/*	
	//-----�ж�������ַ���Сд����д���������֡�����ʲô������
	if(testChar>='a' && testChar<='z')
		printf("%c is lower case letter\n", testChar);
	else if(testChar>='A' && testChar<='Z')
		printf("%c is uppercase letter\n", testChar);
	else if(testChar>='0' && testChar<='9' )
		printf("%c is number letter\n", testChar);
	else
		printf("%c is out of my judgement!!!!\n", testChar);
*/	

	//-----ʹ�����룬ASCII���ж�     ���ڴ���濴���ַ����ַ������Ĵ�С�Ƚϣ����ǱȽ����ǵ�����Ĵ�С��
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
