#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
  int a,i,j,b,***ch;
scanf("%d%d",&a,&b);
 int **ar=(int**)malloc(a*sizeof(int*));
 for(i=0;i<a;i++)
 *(ar+i)=(int*)malloc(b*sizeof(int));
 for(i=0;i<a;i++)
{
  for(j=0;j<b;j++)
scanf("%d",((ar+i)+j));
}
for(i=0;i<a;i++)
{
  for(j=0;j<b;j++)
  {
    ch=&ar+i;
  printf("%d\t",***(ch+j));
}
  printf("\n");
}

}
