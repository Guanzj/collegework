//����
# include<stdio.h>
# include<string.h>
# include<stdlib.h>
# define N 20 // The max string length
# define M 20 //The max codestream number in the dictionary
# define L 20
struct wordstream
{
	char w[N];
}word[L];
void main()
{
	int code[M];//����������
	//int code[]={1,2,3,4,7,3};
	int i, k, t;
	int j;//�ʵ���׺����
	int cW;//��ǰ����
	int pW;//��ǰ����
	unsigned char C;//��ǰ�ַ�
	char p[20];//׺-����
	word[1].w[0] = 'A';//����ʵ�ĳ�ʼ��
	word[2].w[0] = 'B';
	word[3].w[0] = 'C';
	j = 4;
	//�����Ҫ�����������
	printf("\n Please input the codestream number:");
	scanf_s("%d", &k);
	printf("\n Please input the codestream number:");
	for (i = 0; i<k; i++)
		scanf_s("%d", (code + i));
	cW = code[0];
	printf("\n output the wordstream:%s", word[cW].w);
	pW = cW;
	for (i = 1; i<k; i++)
	{
		cW = code[i];
		if (cW<j)
		{
			printf("\n output the wordstream:%s", word[cW].w);//������ַ���
			C = word[cW].w[0];
			strcpy_s(p, (const char *)word[pW].w);
			t = strlen((const char *)p);
			p[t] = C;
			p[t + 1] = '\0';
			strcpy_s(word[j].w, (const char*)p);
			j = j + 1;
			pW = cW;
		}
		else
		{
			strcpy_s(p, (const char *)word[pW].w);
			C = word[pW].w[0];
			t = strlen((const char *)p);
			p[t] = C;
			p[t + 1] = '\0';
			strcpy_s(word[j].w, (const char *)p);
			printf("\n output the wordstream: %s", p);
			j = j + 1;
			pW = cW;
		}
	}
	for (i = 1; i<j; i++)
		printf("\n The dictionary is %s", word[i].w);
	printf("\n this is over\n");
	system("pause");
}