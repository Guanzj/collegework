#include <stdio.h>
#include <stdlib.h>

int main()
{
  int x, y;
  double z;

  y = (x=5) + 8;   //赋值运算符: x=5,y=13
  printf("x=%d, y=%d\n",x,y);
  
  y = x = 5 + 8;   //赋值运算符优先级低于算术运算符，y=x=13
  printf("x=%d, y=%d\n",x,y);
  
  z=(x+y+1)/2;     //类型转换，（隐性），z=(13+13+1)/2=13.000000 
  printf("z=%f\n",z);

  z=(x+y+1.0f)/2;     //类型转换，（隐性），z=(13+13+1.0f)/2=13.000000 
  printf("z=%f\n",z);

  system("pause"); //cpu运行到此时 暂停
  return 0;
}
