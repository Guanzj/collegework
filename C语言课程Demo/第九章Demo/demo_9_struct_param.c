#include <stdio.h>

typedef struct{
	int x;
	int y;
}point_t;

void move1(point_t pt,int dx,int dy){
	pt.x+=dx;
	pt.y+=dy;
}

void move2(point_t *pt,int dx,int dy){
	pt->x+=dx;
	pt->y+=dy;
}

int main(){
	point_t pt1={10,10};

	printf("pt1: (%d,%d)\n",pt1.x,pt1.y);

	move1(pt1,5,5);
	printf("pt1: (%d,%d)\n",pt1.x,pt1.y);
	
	move2(&pt1,5,5);
	printf("pt1: (%d,%d)\n",pt1.x,pt1.y);

	return 0;
}