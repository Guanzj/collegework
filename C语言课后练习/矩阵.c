#include<stdio.h>
void main()
{
	
	int sum[20]={0},juzhen[21][21],a=0,b,c,d,i,r,t,number;
	
	
	
	scanf("%d",&number);
	for(i=0;i<number;i++)
		for(r=0;r<number;r++)
			scanf("%d",&juzhen[i][r]);//输入


	for(i=0;i<number;i++)
		for(r=0;r<number;r++)
		{	sum[a]+=juzhen[i][r];//行之和
		a++;}
		
	for(r=0;i<number;r++)
		for(i=0;r<number;i++)
		{	sum[a]+=juzhen[i][r];//列之和
		a++;}

	for(i=0,r=0;i<number&&r<number;i++,r++)//主对角线
	{sum[a]=juzhen[i][r];
	a++;}
	for(i=number-1,r=number-1;i>=number&&r>=0;i--,r--)//副对角线
	{sum[a]=juzhen[i][r];
	a++;}
	//排序


	for(b=0;b<=a;b++)
		for(c=b+1;c<=a;c++)
			if(sum[b]<sum[c])
			{t=sum[b];
			sum[b]=sum[c];
			sum[c]=t;}

	//输出

	for(d=0;d<a;d++)
		printf("%2d ",sum[d]);
	printf("\n");
}
