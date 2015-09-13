#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],b[100];
	int i,len,j=0;
	while(1)
	{
		gets(a);
		len=strlen(a);
		if(len==0)
			break;
		for(i=0,j=0;i<len;i++)
		{
			switch(a[i])
			{
			case '(':
			case '[':
			case '{':
				b[j++]=a[i];
				break;
			case ')':
				if(j==0||b[j--]!='(')
					printf("no\n");
				else
					
					break;
			case ']':
				if(j==0||b[j--]!='[')
				
					printf("no\n");
				else
					
					break;
				
			case '}':
				if(j==0||b[j--]!='{')
					
					printf("no\n");
				else
					
					break;
				
			default:
				break;
			}
		}
		if(j==0)
			printf("yes\n");
		else
			printf("no\n");		
	/*	if(len==0)
			break;
		if(a[0]=='('&&a[len-1]==')')
			printf("yes\n");
		else if(a[0]=='['&&a[len-1]==']')
			printf("yes\n");
		else if(a[0]=='{'&&a[len-1]=='}')
			printf("yes\n");
		else
			printf("no\n");
	*/	
	}
	return 0;
}

		