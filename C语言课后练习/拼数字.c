#include<stdio.h>
#include <string.h>
#include<math.h>//Ã·Ωª¥ÌŒÛ

/*int pow(int a,int b)
{   int c=1,i;
	for(i=1;i<=b;i++)
	{   
		
		c*=a;
	}
	return c;
}*/
int main()
{											
	int i,j=0,k,s,b=0;
	int len;
	char a[100],sum[100];
	while (1)
	{
		gets(a);
		if (a[0]=='\0')
			break;
		len=strlen(a);
	//j=-1;
		b=0;
		for(i=0;i<len;i++)													
		{
			if(a[i]>='0'&&a[i]<='9')
				b=b*10+(a[i]-'0');
		}
		if(b==0)
			printf("%d\n",b);
		/*for(k=0;j>0;j--,k++)
		{
			b+=(sum[j-1]-'0')*pow(10,k);
		}
		*/
		else
		{	
			s=1;
			for(i=1;i<b;i++)
			{
				if(b%i==0)
					s=i;
			}
			if(s==1)
				printf("%d",b);
			else
			printf("%d\n",s);
		}
		}
		return 0;
}

		

	