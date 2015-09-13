#include<stdio.h>
int main()
{
	int m,n,a[9],i,i2,j2,k,t,j;
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&n);
		j=0;
		while(n!=0)
		{
			a[j]=n%10;
			n=n/10;
			j=j+1;
		}
		for(i2=0;i2<j-1;i2++)
		{
			for(k=i2+1,j2=i2;k<j;k++)
			{
				if(a[k]>a[j2])
				{
					j2=k;
				}
			}
			if(j2!=i2)
			{
				t=a[i2];
				a[i2]=a[j2];
				a[j2]=t;
			}
		}
		for(i2=0;i2<j-1;i2++)
		{
			printf("%d,",a[i2]);
		}
		printf("%d",a[j-1]);
		printf("\n");
	}
	return 0;
}	













