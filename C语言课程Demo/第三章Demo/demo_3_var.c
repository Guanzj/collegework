#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a; 
    a=10;

    printf("in outer compound, a=%d, address of a is %x\n",a,&a);
    
    { 	
		int a;
	
        printf("inner compound begin\n");
        
        a=100;
        printf("in inner compound, a=%d, address of a is %x\n",a,&a);
        printf("inner compound end\n");
    }
    
    printf("in outer compound, a=%d, address of a is %x\n",a,&a);
    
    system("pause");
    return 0;
}
