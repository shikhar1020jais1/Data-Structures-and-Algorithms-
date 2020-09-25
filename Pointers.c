#include<stdio.h>
void main()
{
  int **p,*a,b;
  b=10;
  a=&b;
  p=&a;
  printf("%d",**p);
}
