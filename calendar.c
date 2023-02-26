#include<stdio.h>
#include<stdlib.h>
void Find(int i,int j)
{
    //printf("%d%d",i,j);
    int m,n,k,l;
    for(k=0,m=1900;m<i;m++)
    {
        if(m%100==0&&m%400==0||m%4==0&&m%100!=0)
            k+=366;
        else k+=365;
    }
    for(n=0;n<j;n++)
    {
        switch(n)
        {
            case 0:break;
            case 1:k+=31;break;
            case 2:
            if(m%100==0&&m%400==0||m%4==0&&m%100!=0)
                k+=29;
            else k+=28;
            break;
            case 3:k+=31;break;
            case 4:k+=30;break;
            case 5:k+=31;break;
            case 6:k+=30;break;
            case 7:k+=31;break;
            case 8:k+=31;break;
            case 9:k+=30;break;
            case 10:k+=31;break;
            case 11:k+=30;break;
        }
    }
    printf("\t日\t一\t二\t三\t四\t五\t六\n");
    for(n=(k%7+1)%7;n>0;n--)
        printf("\t ");
    switch(j)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:m=31;break;
        case 4:
        case 6:
        case 9:
        case 11:m=30;break;
        case 2:
        if(i%100==0&&i%400==0||i%4==0&&i%100!=0)
                m=29;
            else m=28;
        break;
    }
    for(n=1;n<=m;n++)
    {
        printf("\t%d",n);
        if((k%7+1)%7+n==7&&k!=0)
        {
            printf("\n");
            printf("\n");
            k=0;
            l=n;
        }
        if((n-l)%7==0&&n!=l&&n>7) 
        {
            printf("\n");
            printf("\n");
            l=n;
        }
    }
    printf("\n");
}

int main()
{
    int i;
    enum month {Jan=1,Feb,Mar,Apr,May,Jun,Jul,Aug,Sept,Oct,Nov,Dec} j;
    printf("请输入年、月：");
    scanf("%d%d",&i,&j);
    Find(i,j);
    system("pause");
    return 0;
}