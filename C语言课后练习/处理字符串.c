#include<stdio.h>
#include<string.h>
int main()
{
  int i,j,k,h;
  char a[100],b[100],c[100],d[10];
  char m;
  gets (a);
  for(i=1,j=0,k=0;a[i]!='\0';++i)
  {
    if(a[i]>a[0])
	{ 
	 b[j]=a[i];
	 b[j+1]='\0';
	 ++j;
	}
	else if(a[i]<=a[0])
	{
	 c[k]=a[i];
	 c[k+1]='\0';
	 ++k;
	}
  }
  for(i=0;i<k-1;++i)
  { 
     for(h=i+1,j=i;h<k;++h)
		 if(c[h]<c[j])
			 j=h;
		 if(j!=i)
		 {
		   m=c[i];
		   c[i]=c[j];
		   c[j]=m;
		 }
  }
  d[0]=a[0];
  d[1]='\0';
  strcat(b,d);
  strcat(b,c);
 
 puts (b);
return 0;  
}