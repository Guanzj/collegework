#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int i;



	for(i=0; i<=8; i++)  //��ʾbreak
	{  
		if( i%2 )
		{
			break;
		}
		printf("i=%d  ", i);
	}

	printf("\n============================\n");
	printf("finally i=%d\n", i);


/*
	for(i=0; i<=8; i++) //��ʾcontinue
	{  
		if( i%2 )
		{
			continue;
		}

		printf("i=%d ", i);
	}
	printf("\n============================\n");
	printf("finally i=%d\n", i);	
 */   

    system("pause");
    return 0;
}
