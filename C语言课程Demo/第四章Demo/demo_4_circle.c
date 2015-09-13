/*
	演示函数的定义和使用
  */

#include <stdio.h>
#include <stdio.h>
#include <math.h>
//double  __cdecl pow(double, double);

double c_area (double r) 
{    
	//return r*r*3.1416;  
	return pow(r, 2) * 3.1416;
	
	/*
	double area=r*r*3.1416;
	return area;
	*/
}

//打印半径为r的圆的面积
void printArea(double r)
{
	printf("%f, the area=%lf\n",r,3.1415926*r*r);
	
}

int main () 
{
	double v;

	/*
	//求半径为3.24,5的圆的面积
	printf("%f, the area=%f\n", 3.24,   c_area(3.24)  );
	printf("%f, the area=%f\n", 5.0,    c_area(5)     );


   //求底面半径为3.24，高为2.4的圆锥的体积
   v=2.4 * c_area( 3.24 ) / 3.0;
   printf("The volue=%lf\n",v);  
*/
	//演示无返回值函数
   	printArea(3.24);
	printArea(5);

	//演示多参数函数调用、和可能返回值函数
	//printf("the max of %d,%d  =%d\n",3,5, max(3,5));
	//printf("the max of %d,%d  =%d\n",11,4, max(11,4));

	//if(compare(10,5)==1)
	//{
	//	printf("10>5!!\n");
	//}

  
   return 0;
}



//打印半径为r的圆的面积，其中调用了前面定义的函数c_area()
void printArea2(double r)
{
	printf("%f, the area=%lf\n", c_area(r));  //调用了	c_area()
}

//返回a,b中的大值
int max(int a, int b)
{
	if(a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

//比较x，y的值的大小，如果x==y，则返回0，如果x>y,则返回1；如果 x<y，则返回-1；
int compare( int x, int y )
{
  if( x == y )    
	  return 0;
  else if( x > y )    
	  return 1;
  else    
	  return -1;
}





