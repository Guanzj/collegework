#include <stdio.h>
#include <stdlib.h>

int main()
{
	char grade='F';
	int points=0;


	switch (grade) {
	case  'A':
		points = 4 ;
		break;
	case  'B':
		points = 3 ;
		break;
	case  'C':
		points = 2 ;
		break;
	case  'D':
		points = 1 ;
		break;
	case  'F':
	    points = 0 ;
	}

	if (points > 0)
        printf ("Passed, points earned = %d\n", points ) ;
	else
        printf ("Failed, no points earned\n" ) ;

	system("pause");
	return 0;
}