#include<stdio.h>
void order(int a[],int n);
int main()
{
	int a[100],ou[100],ji[100];
	int num,oushu=0,jishu=0,i;
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=1;i<=num;i++)
	{
		if(a[i]%2==0)
		{   oushu=oushu+1;
			ou[oushu]=a[i];
		}
		else 
		{   jishu=jishu+1;
			ji[jishu]=a[i];
		}
	}
	order(ou,oushu);
	order(ji,jishu);
	return 0;
}
   
void order(int a[],int n)
{   int i,j,temp; 
	for (i=1;i<n;i++)
		{for(j=1;j<=n-i;j++)
			if(a[j]<a[j+1])
			{  temp=a[j+1];
				a[j+1]=a[j];
				a[j]=temp;
			}
		}
	for (i=1;i<=n;i++)
			printf("%d ",a[i]);
}
