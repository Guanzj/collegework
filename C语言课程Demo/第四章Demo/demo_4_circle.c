/*
	��ʾ�����Ķ����ʹ��
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

//��ӡ�뾶Ϊr��Բ�����
void printArea(double r)
{
	printf("%f, the area=%lf\n",r,3.1415926*r*r);
	
}

int main () 
{
	double v;

	/*
	//��뾶Ϊ3.24,5��Բ�����
	printf("%f, the area=%f\n", 3.24,   c_area(3.24)  );
	printf("%f, the area=%f\n", 5.0,    c_area(5)     );


   //�����뾶Ϊ3.24����Ϊ2.4��Բ׶�����
   v=2.4 * c_area( 3.24 ) / 3.0;
   printf("The volue=%lf\n",v);  
*/
	//��ʾ�޷���ֵ����
   	printArea(3.24);
	printArea(5);

	//��ʾ������������á��Ϳ��ܷ���ֵ����
	//printf("the max of %d,%d  =%d\n",3,5, max(3,5));
	//printf("the max of %d,%d  =%d\n",11,4, max(11,4));

	//if(compare(10,5)==1)
	//{
	//	printf("10>5!!\n");
	//}

  
   return 0;
}



//��ӡ�뾶Ϊr��Բ����������е�����ǰ�涨��ĺ���c_area()
void printArea2(double r)
{
	printf("%f, the area=%lf\n", c_area(r));  //������	c_area()
}

//����a,b�еĴ�ֵ
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

//�Ƚ�x��y��ֵ�Ĵ�С�����x==y���򷵻�0�����x>y,�򷵻�1����� x<y���򷵻�-1��
int compare( int x, int y )
{
  if( x == y )    
	  return 0;
  else if( x > y )    
	  return 1;
  else    
	  return -1;
}





