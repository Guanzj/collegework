/*
//ʹ��������Fibonacci����
*/


#include <stdio.h>
#include <stdlib.h>

int main(){
    int fib[40]={1,1},i;

	printf("==============��0��ʼѭ��============");
	//��0��ʼѭ����39
    for(i=0;i<40;i++){
        if(i>1)//����fib(n)
		{
            fib[i]=fib[i-1]+fib[i-2];
		}
        printf("Fib(%d)=%d\n",i,fib[i]);
    }

/*
	printf("==============��2��ʼѭ��============");
	
	printf("Fib(0)=%d\n",fib[0]);
	printf("Fib(1)=%d\n",fib[1]);

	//������ǰ����
    for(i=2;i<40;i++){    
            fib[i]=fib[i-1]+fib[i-2];
			printf("Fib(%d)=%d\n",i,fib[i]);
    }
*/	

	system("pause");
    return 0;
}
