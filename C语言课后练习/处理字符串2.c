#include<stdio.h>
#include<string.h>
int main()
{
	char a[100],b[100],c[100],d[100];
	int i,j=0,k=0,s,t,len;
	gets(a);
	len=strlen(a);
	for(i=1,j=0;i<len;i++)
	{
		if(a[i]>a[0])
		{
			b[j]=a[i];
			b[j+1]='\0';
			j++;
		}
		else if(a[i]<=a[0])
		{
			c[k]=a[i];
			c[k+1]='\0';
			k++;
		}
	}
	for(i=0;i<k-1;i++)
	{
		j=i;
		for(s=i+1;s<k;s++)
		{
			if(c[s]<c[j])
			{
				t=c[s];
				c[s]=c[j];
				c[j]=t;
			}
		}
	}
	d[0]=a[0];
	d[1]='\0';
	strcat(b,d);
	strcat(b,c);
	puts(b);
//aQWERsdfg7654!@#$hjklTUIO3210X98aY

	return 0;//
}
