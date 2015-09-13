#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
}point_t;

int main(){
	point_t *pt=(point_t *)malloc(sizeof(point_t)); 
	if(!pt)
	{
		return 0;
	}

	(*pt).x=10;
	(*pt).y=10;
	printf("pt : (%d,%d)\n",(*pt).x,(*pt).y);

	pt->x=20;
	pt->y=20;
	printf("pt : (%d,%d)\n",pt->x,pt->y);

	if(pt){
		free(pt);
		pt=NULL;
	}

	return 0;
}