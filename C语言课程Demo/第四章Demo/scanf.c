#include <stdio.h>
#include <stdlib.h>

int main(){
	int x;
	float y;
	double z;
	
	scanf("%d %f %lf\n", &x ,&y ,&z);
	printf("x=%d, y=%f, z=%f\n", x, y, z);

	system("pause");
	return 0;
}