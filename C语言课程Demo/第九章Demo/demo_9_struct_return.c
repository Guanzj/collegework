#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int x;
	int y;
}point_t;

point_t random_point(){
	point_t pt;
	pt.x=rand()%100;
	pt.y=rand()%100;
	return pt;
}

int main(){
	point_t pt1,pt2;

	pt1=random_point();
	pt2=random_point();
	printf("pt1: (%d,%d)\n",pt1.x,pt1.y);
	printf("pt2: (%d,%d)\n",pt2.x,pt2.y);


	return 0;
}