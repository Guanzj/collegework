#include<stdio.h>
int main()
{
int grades;

scanf("%d",&grades);

if(grades>=90)
printf("A");
if(grades>=80&&grades<=89)
printf("B");
if(grades>=70&&grades<=79)
printf("C");
if(grades>=60&&grades<=69)
printf("D");
if(grades<60)
printf("E");

}
