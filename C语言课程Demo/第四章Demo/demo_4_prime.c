#include <stdio.h>
#include <stdlib.h>

int isPrime(int n);

int main()
{
	int n=8;
	
	if(isPrime(n))
		printf("%d is prime.\n",n);
	else
		printf("%d is not prime.\n",n);
		
	system("pause");
	return 0;
}

int isPrime(int n){
    int i;
    for(i=2; i<n; i++){
        if(n%i==0)break;
    }
    return i==n;
}
