#include<stdio.h>
int main()
{
int num[20],a,n;


scanf("%d",&n);
for(a=0;a<n;a++)
scanf("%d",&num[a]);

for(a=0;a<n;a++)

{
	int abc= num[a];
    int tmp = 0;
    
    while(num != 0) 
	{
        tmp *= 10;
        tmp += num[a] % 10;
        num[a] /= 10;
    }
	if(tmp == abc) 
       printf("%d\n",abc);
	else
		printf("no\n");
}

return 0;
}