
#include <stdio.h>
int main(void)
{
	
	int image[256][256];
	int a[16] = {0};
	int m,n,i,j;
	FILE *fp = fopen("image.in", "r+");
	fscanf (fp,"%d %d",&m,&n);

	for (i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			fscanf (fp,"%d",&image[i][j]);
			a[image[i][j]] ++;
		}
	}
	for (i=0; i<16; i++)
	{
		printf("%d %d\n",i,a[i]);
	}
	return 0;
}