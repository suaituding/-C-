#include<stdio.h>
void main()
{
  int i,j;
  for(i=1;i<=9;i++)
  {
    for(j=1;j<=i;j++)
    printf("%d*%d=%-2d\t",j,i,j*i);
    printf("\n");
  }
}
