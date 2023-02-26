#include<stdio.h>
int SL(int i,int j,int l)
{
  int k;
  if(l==0) return 0;
  k=i+j;
  i=j;
  j=k;
  l--;
  printf("\t%d",j);
  SL(i,j,l);
}
void main()
{
  printf("1 1");
  SL(1,1,38);
}
