/*
	��ʾ�����в�����ʹ��
*/


#include <stdio.h>

int main(int argc, char *argv[]){
	char *s1,*s2;

	if(argc!=3){  //�������У��������������û������2���ַ���������ʾ����ע�⣺ argc��¼���ַ��������У���������������
		printf("need two string.\n");
		return 1;
	}

	s1=argv[1];
	s2=argv[2];
	while(*s1==*s2 && *s1 && *s2){  //��������ַ�����ͬ��ǰ׺
		s1++;s2++;
	}

	*s1=0; //�����һ����ͬ���ַ���������һ���ַ��������� '\0' (��ֵ0)����argv[1]ָ����ַ�������ͬ��ǰ׺
	if(s1-argv[1])  //ָ��s1��ָ��argv[1]֮���о��룬��˵������ͬ��ǰ׺
	{
		printf("prefix is : %s\n",argv[1]);
	}
	else            //ָ��s1��ָ��argv[1]֮���޾��룬��˵��û����ͬ��ǰ׺
	{
		printf("no same prefix.\n");
	}

	return 0;
}