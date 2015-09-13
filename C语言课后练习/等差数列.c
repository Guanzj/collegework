#include<stdio.h>
#include<math.h>
int main()
{   int num[100],a[100];
    int n,i,j,x,y,flag,temp;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
	{   flag=1;
		scanf("%d",&num[i]);
		for(j=1;j<=num[i];j++)
		  scanf("%d",&a[j]);
	    for (x=1;x<num[i];x++)
		{for(y=1;y<=num[i]-x;y++)
			{
				if(a[y]>a[y+1])
				{  temp=a[y+1];
					a[y+1]=a[y];
					a[y]=temp;
				}
			}
		}
		for (j=1;j<=num[i]-2;j++)
		{
			if((a[j+1]-a[j])!=(a[j+2]-a[j+1]))
			flag=0;			
		}
		if (!flag)
			printf("no\n");
		else 
			printf("%d\n",a[j]-a[j-1]);
	}
	return 0;
}
