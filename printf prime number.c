#include<stdio.h>
int main()
{
    int i,j;
    for(i=1;i<101;i++)
    {
        for(j=2;j<i;j++)
            if(i%j==0) break;
        if(j==i)  printf("%-4d",i);  
    }
    return 0;
}